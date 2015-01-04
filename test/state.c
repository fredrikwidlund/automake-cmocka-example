#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "state.h"

void test1()
{
  state *s;

  s = state_new();
  assert_non_null(s);
  assert_int_equal(state_get(s), 0);
  state_free(s);
}

void test2()
{
  state *s;
  int e;

  s = state_new();
  assert_non_null(s);

  e = state_set(s, 5);
  assert_int_equal(e, 0);
  assert_int_equal(state_get(s), 5);

  e = state_set(s, 42);
  assert_int_equal(e, -1);
  assert_int_equal(state_get(s), 5);
}

int main(void)
{
  const UnitTest tests[] = {
    unit_test(test1),
    unit_test(test2),
  };

  return run_tests(tests);
}
