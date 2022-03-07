/*
 * Test case for chomp
 * Copyright (C) 2022 Paolo Perego <paolo@codiceinsicuro.it>
 *
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<stdlib.h>
#include<time.h>
#include<stdlib.h>
#include<check.h>
#include"../src/chomp.h"

START_TEST(test_chomp_negative_bytes)
{
    char *dst;
    int ret = chomp(dst, "test at lounge", -1);
    ck_assert_int_eq(ret, -1);
}
END_TEST

START_TEST(test_chomp_src_null_string)
{
    char dst[30];
    int ret = chomp(dst, NULL, 1);
    ck_assert_int_eq(ret, -1);
}
END_TEST

START_TEST(test_chomp_too_many_bytes)
{
    char *src="This is a test";
    char dst[30];

    int ret=chomp(dst, src, strlen(src)+1);
    ck_assert_int_eq(ret, -1);
}
END_TEST

START_TEST(test_chomp_works_1_byte)
{
    char *src="This is a test";
    char dst[30];

    memset(dst, 0, 30);
    int ret = chomp(dst, src, 1);
    ck_assert_int_eq(ret, 0);
    ck_assert_str_eq(dst, "This is a tes");

}

START_TEST(test_chomp_works_5_byte)
{
    char *src="This is a test";
    char dst[30];

    memset(dst, 0, 30);
    int ret = chomp(dst, src, 5);
    ck_assert_int_eq(ret, 0);
    ck_assert_str_eq(dst, "This is a");

}

Suite *chomp_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Chomp");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_chomp_src_null_string);
    tcase_add_test(tc_core, test_chomp_negative_bytes);
    tcase_add_test(tc_core, test_chomp_too_many_bytes);
    tcase_add_test(tc_core, test_chomp_works_1_byte);
    tcase_add_test(tc_core, test_chomp_works_5_byte);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;

    Suite *s;
    SRunner *sr;

    s = chomp_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
