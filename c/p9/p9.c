/* A program to find a Pythagorean triplet with a given sum, such
 * that a^2 + b^2 = c^2 and a + b + c = given value.
 *
 * Solution increments through possible values of a and b looking for
 * round values (integer) of c that sum to the given value. Function
 * then returns the product of a * b * c as an unsigned long.
 *
 * Runtime: Worst case, the algorithm runs in quaratic O(n^2) time, due
 * to the nested for loop. However, the loop includes a break statement
 * to limit the growth of the algorithm to O([n/2]^2).*/


# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../minunit.h"

/* Testing prototype */
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

/* PROGRAM */
/* Need a long to handle potential values in the tens of millions. */
unsigned long product_pythagorean_triplet(unsigned int triplet_sum) {
    unsigned int a, b;
    
    for (a = 1; a < triplet_sum; a++) {
        for (b = 1; b < triplet_sum; b++) {
            if (a + b >= triplet_sum) {
                break;
            }
            
            float c = sqrt(a*a + b*b);

            if (c == (int) c && a + b + c == triplet_sum) {
                return a * b * c;
            }
        }
    }
    
    return 0;
}

/* TESTS */
static char * test_zero() {
    mu_assert("Zero should equal zero", \
            product_pythagorean_triplet(0) == 0);
    return 0;
}

static char * test_12() {
    mu_assert("12 should give 60", \
           product_pythagorean_triplet(12) == 60);
    return 0;
}

static char * test_1000() {
    mu_assert("1000 should give 31,875,000", \
            product_pythagorean_triplet(1000) == 31875000);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_zero);
    mu_run_test(test_12);
    mu_run_test(test_1000);

    return 0;
}
