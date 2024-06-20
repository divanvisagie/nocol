#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "args.h"

#define BUFFER_SIZE 1024

char *get_help() {
    return "Usage: nocol [OPTION]... [STRING]\n"
           "Strip colours from stdin\n"
           "\n"
           "Options:\n"
           "  -h, --help              Display this help and exit\n"
           "\n"
           "Examples:\n"
           "  echo 'hello' | lolcat | nocol\n";
}

// Function to strip ANSI color codes
void strip_colors(char *input) {
    char *src = input;
    char *dst = input;
    while (*src) {
        if (*src == '\033' || *src == '\x1b') {
            // Skip entire ANSI escape sequence
            src++;  // Skip '\033' or '\x1b'
            if (*src == '[') {
                src++;  // Skip '['
                while (*src && ((*src >= '0' && *src <= '9') || *src == ';')) {
                    src++;  // Skip parameter bytes
                }
                if (*src) {
                    src++;  // Skip the final character (e.g., 'm', 'K')
                }
            }
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';  // Null-terminate the resulting string
}

int main(int argc, char **argv) {
    Args *args = parse_args(argc, argv);
    if (args->help) {
        printf("%s\n", get_help());
        return 0;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        strip_colors(buffer);
        printf("%s", buffer);
    }

    return 0;
}

/* ### Key Changes:
1. **Streaming Input**: The `fgets` function is used to read input line by line, rather than reading the whole input into a single buffer.
2. **Color Stripping**: Implemented `strip_colors` function to remove ANSI color codes.
3. **Memory Management**: Avoided dynamic memory allocation for buffering input, since `fgets` and fixed buffer sizes suffice for streaming.

### Instructions:
1. Ensure `args.h` and its corresponding implementation file can handle command-line arguments as expected.
2. Compile the code using `gcc` (or another C compiler), for example:
   ```sh
   gcc -o nocol nocol.c args.c
   ```
3. Run the executable:
   ```sh
   echo 'hello' | lolcat | ./nocol
   ```

This implementation will now read and process each line from standard input, stripping out any ANSI escape sequences that are used for coloring the text. */
