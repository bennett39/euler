/* A program to find the sum of all multiples of 3 or 5 less than 1000.
 *
 * Changing the factors (e.g. 3, 5) would be trivial, so this program is
 * extendable to other factors. The upper bound (e.g. 1000) is also easy
 * to change.
 *
 * Runtime: linear - O(n). The program checks every value between 1 and
 * n to see if it's a multiple. Not a big deal since we're only going to
 * n = 1000. No need to implement a more complicated solution. */

# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

/* Program functions */
int sum_of_multiples(int x);

/* Testing functions */
static char * all_tests();

/* Test counter. Incremented by minunit.h */
int tests_run = 0;

int main() {
    /* 
     * The reults of all_tests() from minunit.h will == 0 when all 
     * tests pass.
     * Otherwise, all_tests() will return a string describing the 
     * failure. 
    */
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    
    /* 
     * minunit.h counts the number of tests it ran, in order listed in
     * all_tests() below, until a test fails and all_tests quits. 
    */
    printf("Tests run %d\n", tests_run);

    return result != 0;
}

int sum_of_multiples(int x) {
    /* Since we're only going to 1000, the total likely won't exceed
     * 1,000,000, so we're good to use an int. */
    int total = 0;
    for (int i = 0; i < x; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            total += i;
        }
    }
    return total;
}


/* TESTS */

static char * test_2() {
    mu_assert("error 2 !>> 0", sum_of_multiples(2) == 0);
    return 0;
}

static char * test_10() {
    mu_assert("error 10 !>> 23", sum_of_multiples(10) == 23);
    return 0;
}

static char * test_16() {
    mu_assert("error 16 !>> 60", sum_of_multiples(16) == 60);
    return 0;
}

static char * test_19() {
    mu_assert("error 19 !>> 78", sum_of_multiples(19) == 78);
    return 0;
}

static char * test_31 () {
    mu_assert("error 31 !>> 225", sum_of_multiples(31) == 225);
    return 0;
}

static char * test_33() {
    mu_assert("error 33 !>> 225", sum_of_multiples(33) == 225);
    return 0;
}

static char * test_48() {
    mu_assert("error 48 !>> 543", sum_of_multiples(47) == 495);
    return 0;
}

static char * test_1000() {
    mu_assert("error 1000 !>> 233,168", sum_of_multiples(1000) == 233168);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_2);
    mu_run_test(test_10);
    mu_run_test(test_16);
    mu_run_test(test_19);
    mu_run_test(test_31);
    mu_run_test(test_33);
    mu_run_test(test_48);
    mu_run_test(test_1000);

    return 0;
}
