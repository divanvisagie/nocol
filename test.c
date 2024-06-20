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

static void test_that_tests_work(void **state) {
  assert_non_null(true);
}

// Group all test cases together
int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_that_tests_work),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
