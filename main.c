#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"

#define INITIAL_BUFFER_SIZE 1024

char *get_help() {
  char *help = "Usage: nocol [OPTION]... [STRING]\n"
               "Strip colours from stdin"
               "\n"
               "Options:\n"
               "  -h, --help              Display this help and exit\n"
               "\n"
               "Examples:\n"
               "  echo 'hello' | lolcat | nocol\n";
  return help;
}

int main(int argc, char **argv) {
  Args *args = parse_args(argc, argv);
  if (args->help) {
    char *help = get_help();
    printf("%s\n", help);
    return 0;
  }

  size_t buffer_size = INITIAL_BUFFER_SIZE;
  char *all_input = malloc(buffer_size);
  if (!all_input) {
    perror("malloc");
    return 1;
  }
  all_input[0] = '\0'; // Initialize empty string

  size_t len = 0;
  ssize_t read;
  char *line = NULL;

  while ((read = getline(&line, &len, stdin)) != -1) {
    size_t current_len = strlen(all_input);
    size_t total_len = current_len + read;
    if (total_len >= buffer_size) {
      buffer_size *= 2;
      all_input = realloc(all_input, buffer_size);

      if (!all_input) {
        perror("realloc");
        free(line);
        return 1;
      }
    }
    printf("%s", line);
    strncat(all_input, line, read);
  }
  free(line);
  
  return 0;
}
