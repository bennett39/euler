# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

# include <math.h>

/* Testing function prototype */
static char * all_tests();

/* Test counter. Incremented by minunit.h */
int tests_run = 0;

int main() {
    /* 
     * The reults of all_tests() from minunit.h will == 0 when all 
     * tests pass. Otherwise, all_tests() will return a string 
     * describing the failure. 
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

/* PROGRAM */
/* Idk how long the input might need to be, so long long for now. */
int number_of_divisors(unsigned long long x) {
    int divisors = 0;
    unsigned long root = sqrt(x);
    unsigned long i;

    for (i = 1; i <= root; i++) {
        if (x % i == 0) {
            if (i == x/i) {
                divisors++;
            }
            else {
                divisors += 2;
            }
        }
    }
    return divisors;
}

unsigned long long triangle_number_divisibility(int divisors) {
    if (divisors < 1) {
        return 0;
    }
    else if (divisors >= 1) {
        unsigned long long triangle_number = 1;
        unsigned long long i;

        for (i = 2; ; i++) {
            if (number_of_divisors(triangle_number) > divisors) {
                return triangle_number;
            }
            else {
                triangle_number += i;
            }
        }
    }
}


/* TESTS */
static char * test_divisors_1() {
    mu_assert("number_of_divisors(1) != 1", number_of_divisors(1) == 1);
    return 0;
}

static char * test_divisors_6() {
    mu_assert("number_of_divisors(6) != 4", number_of_divisors(6) == 4);
    return 0;
}

static char * test_trinum_1() {
    mu_assert("triangle_number_divisibility(1) != 3", \
            triangle_number_divisibility(1) == 3);
    return 0;
}

static char * test_trinum_5() {
    mu_assert("triangle_number_divisibility(5) != 28", \
            triangle_number_divisibility(5) == 28);
    return 0;
}

static char * test_trinum_500() {
    mu_assert("triangle_number_divisibility(500) != 76,576,500", \
            triangle_number_divisibility(500) == 76576500);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_divisors_1);
    mu_run_test(test_divisors_6);
    mu_run_test(test_trinum_1);
    mu_run_test(test_trinum_5);
    mu_run_test(test_trinum_500);

    return 0;
}
