#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"

Args* parse_args(int argc, char **argv) {
  Args *args = malloc(sizeof(Args));
  args->help = false;
  args->strip_prefix = false;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      args->help = true;
    }
    if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--strip-prefix") == 0) {
      args->strip_prefix = true;
    }
  }

  return args;
}
