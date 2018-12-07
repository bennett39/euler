# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

/* Program functions */
long long sum_even_fibs(long long total, int last, int current, int upper_bound);

/* Testing functions */
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
    
    long long solution = sum_even_fibs(0, 1, 1, 4000000);
    printf("Solution: %lli\n", solution);

    return result != 0;
}

long long sum_even_fibs(long long total, int last, int current, int upper_bound) {
    /* Since this will eventually add terms up to 4 million, a
     * conservative upper bound is 4 million * 4 million (aka 4
     * trillion). That's too big for an int. While we won't likely hit
     * the limit, I'll use a long long to store the sum */

    /* Recursive Fibonacci solution */
    int new = last + current;
    if (new > upper_bound) {
        return total;
    }
    
    if (new % 2 == 0) {
        total += new;
    }

    last = current;
    current = new;

    return sum_even_fibs(total, last, current, upper_bound);
}


/* TESTS */

static char * test_10() {
    mu_assert("error 10 !>> 10", sum_even_fibs(0, 1, 1, 10) == 10);
    return 0;
}

static char * test_50() {
    mu_assert("error 50 !>> 44", sum_even_fibs(0, 1, 1, 50) == 44);
    return 0;
}
/*
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
*/

static char * all_tests() {
    mu_run_test(test_10);
    mu_run_test(test_50);

    return 0;
}
