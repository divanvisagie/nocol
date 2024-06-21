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

static void test_prefix_stripper(void **state) {
  char input[] = "blah-blah: INFO hello";
  char *output = get_from_prefix(input);
  assert_string_equal(output, "INFO hello");

  char input2[] = "ERROR: hello";
  char *output2 = get_from_prefix(input2);
  assert_string_equal(output2, "ERROR: hello");

  char input3[] = "my-monorepo:: DEBUG: hello";
  char *output3 = get_from_prefix(input3);
  assert_string_equal(output3, "DEBUG: hello");
}

// Group all test cases together
int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_that_colors_are_stripped),
      cmocka_unit_test(test_that_carriage_returns_are_stripped),
      cmocka_unit_test(test_prefix_stripper),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
