#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeralCalculator.h"

START_TEST(test_I_plus_I_equals_II)
{
  const char* operand1 = "I";
  char result[10];

  add_roman_numeral(operand1, operand1, result);

  ck_assert_str_eq(result, "II");
}
END_TEST

Suite * calculator_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Calculator");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_I_plus_I_equals_II);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = calculator_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
