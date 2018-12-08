/* A program to find the sum of even numbers in the Fibonacci series,
 * given an upper bound.
 *
 * The program solves the problem recursively, changing and passing
 * values back into itself.
 *
 * Runtime: O(log n). Not log2(n), though. The Fib series
 * doesn't grow quadratically. It grows along the Golden Ratio, so 
 * log1.618(n). */

# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

/* Program functions */
long sum_even_fibs(long total, long last, long current, long upper_bound);

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

long sum_even_fibs(long total, long last, long current, long upper_bound) {
    /* Since this will eventually add terms up to 4 million, it's not
     * likely to exceed 2 billion. I'll use a long to store values */

    /* Recursive Fibonacci solution */
    long new = last + current;

    /* Base case when new number in Fib sequence is greater than 4
     * million, or whatever upper bound. */
    if (new > upper_bound) {
        return total;
    }
    
    /* Only even numbers get added to the total */
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

static char * test_4million() {
    mu_assert("error 4 million !>> 4613732", \
            sum_even_fibs(0, 1, 1, 4000000) == 4613732);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_10);
    mu_run_test(test_50);
    mu_run_test(test_4million);

    return 0;
}
