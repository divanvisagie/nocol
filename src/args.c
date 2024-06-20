#include <stdbool.h>
#include <stdlib.h>

#include "args.h"

Args* parse_args(int argc, char **argv) {
  Args *args = malloc(sizeof(Args));
  args->help = false;
  return args;
}
