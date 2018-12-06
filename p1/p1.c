# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

/* Program functions */
int sum_of_multiples(int x);

/* Testing functions */
static char * test_2();
static char * all_tests();

/* Test counter. Incremented by minunit.h */
int tests_run = 0;

int main() {
    /* 
     * The reults of all_tests() from mintest.h will == 0 when all 
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
     * mintest.h counts the number of tests it ran, in order listed in
     * all_tests() below, until a test fails and all_tests quits. 
    */
    printf("Tests run %d\n", tests_run);

    return result != 0;
}

int sum_of_multiples(int x) {
    int floor = x / 15;
    int remainder = x % 15;
    int total = 0;

    /* Floor conditions: sums past groupings of 15 */
    if (floor == 1) {
        total += 60;
    }
    else if (floor > 1) {
        total += 105 * (floor - 1) + 60;
    }

    /* Remainder loop: runs in constant time O(6) for all values of x */
    int r_arr[] = {3, 5, 6, 9, 10, 12};

    for (int i = 0; i < sizeof(r_arr)/sizeof(int); i++) {
        if (remainder > r_arr[i]) {
            total += floor * 15 + r_arr[i];
        }
        else {
            break;
        }
    }
    
    printf("NUMBER: %d\tFloor: %d\tRemainder: %d\tTotal: %d\n", \
            x, floor, remainder, total);

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

static char * test_33 () {
    mu_assert("error 33 !>> 225", sum_of_multiples(33) == 225);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_2);
    mu_run_test(test_10);
    mu_run_test(test_16);
    mu_run_test(test_19);
    mu_run_test(test_31);
    mu_run_test(test_33);

    return 0;
}
