#include <stdbool.h>
#include <stdio.h>
// Including setjmp.h because it's required indirectly by CMocka for certain
// macros/longjmp operations.
#include <setjmp.h>
#include <cmocka.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "default.h"

static void test_that_colors_are_stripped(void **state) {
  char input[] = "\033[1;31mhello\x1b[0m";
  strip_colors(input);
  assert_string_equal(input, "hello");
}

static void test_that_carriage_returns_are_stripped(void **state) {
  char input[] = "hello\rworld";
  strip_colors(input);
  assert_string_equal(input, "helloworld");
}

// Group all test cases together
int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_that_colors_are_stripped),
      cmocka_unit_test(test_that_carriage_returns_are_stripped),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
