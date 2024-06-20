#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "args.h"
#include "default.h"

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

int main(int argc, char **argv) {
  setlocale(LC_ALL, "");

  Args *args = parse_args(argc, argv);
  if (args->help) {
    printf("%s\n", get_help());
    return 0;
  }

  char buffer[BUFFER_SIZE];
  while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
    strip_colors(buffer);
    printf("%s", buffer);
    fflush(stdout);
  }

  return 0;
}
