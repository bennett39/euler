/* A program to find the prime factors of a given input. 
 *
 * Actual Project Euler challenge was to find the greatest prime factor,
 * but I (mistakenly) implemented a function that finds ALL prime
 * factors, in ascending order. Therefore, getting the greatest factor
 * would be trivial. Just look at the last non-zero item in the output
 * array. */

# include <stdio.h>
# include <stdlib.h>

# include <math.h>
# include <string.h>

# include "../minunit.h"

/* Program functions */
int * prime_factors(long long number);

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
  
    printf("\n. . .\n");
    prime_factors(600851475143);
    
    return result != 0;
}

/* PROGRAM */

/* Returns a pointer to the single-dimension array `factors` */
/* Number argument goes up to 1 trillion, so needs to be a long long. */ 
int * prime_factors(long long number) {
    /* Array size of 40 to accommodate prime factors up to 1 trillion, since
     * log2(1 trillion) ~= 39 -- the largest possible array of prime
     * factors less than 1 trillion. (e.g. 2 ^ 39) */
    static int factors[40];
   
    if (number <= 3) {
        factors[0] = (int) number;
        return factors;
    }

    /* Strightforward while loop implementation in linear time. */
    int i = 2;
    static int counter = 0;

    /* Largest possible prime factor this loop might find is 
     * (smaller prime)^2 */
    while (i <= sqrt(number)) {
        if (number % i == 0) {
            factors[counter] = i;
            counter++;

            number = number / i;
            i = 2;
        }
        else {
            i++;
        }
    }
    
    if (i > sqrt(number)) {
        factors[counter] = (int) number;
    }
    
    return factors;
}


/* TESTS */
/*
static char * test_tk() {
    mu_assert("",);
    return 0;
}
*/
static char * test_0() {
    int *a;
    a = prime_factors(0);
    int b[40] = {0};
    
    mu_assert("0 should give {0, ...}", \
            memcmp(a, b, sizeof(a)) == 0);
    return 0;
}

static char * test_13195() {
    int *a;
    a = prime_factors(13195);
    int b[40] = {5, 7, 13, 29};

    mu_assert("13195 should give {5, 7, 13, 29, ...}", \
            memcmp(a, b, sizeof(a)) == 0);
    return 0;
}

static char * all_tests() {
    /* mu_run_test(test_tk); */
    mu_run_test(test_0);
    mu_run_test(test_13195);

    return 0;
}
