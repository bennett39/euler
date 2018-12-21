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
    if (x <= 0) {
        return 0;
    }
    else if (x > 0) {
        int divisors = 0;
        unsigned long root = sqrt(x);

        unsigned long i;
        for (i = 1; i <= root; i++) {
            if (x % i == 0) {
                unsigned long complement = x / i;
                if (i == complement) {
                    divisors++;
                }
                else {
                    divisors += 2;
                }
            }
        }
        return divisors;
    }
}


/* TESTS */
static char * test_divisors_1() {
    mu_assert("Error: 1 !>> 1", number_of_divisors(1) == 1);
    return 0;
}

static char * test_divisors_6() {
    mu_assert("Error: 6 !>> 4", number_of_divisors(6) == 4);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_divisors_1);
    mu_run_test(test_divisors_6);

    return 0;
}
