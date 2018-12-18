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
unsigned int* primes_below_root(unsigned long n) {
    /* Return array size of 300 b/c program designed with 2 million as 
     * upper bound. primes_below_root will go up to sqrt(2mil), so less 
     * than 1,500. Not likely to find more than 300 primes below 1,500. 
     * */
    static unsigned int primes[300] = {2};
    unsigned int root = sqrt(n);

    int i = 3;
    int counter = 1;
    
    while (i <= root) {
        for (int j = 0; j < 300; j++) {
            if (j == counter) {
                primes[counter] = i;
                counter++;
            }
            if (i % primes[j] == 0) {
                break;
            }
        }
        i += 2;
    }

    return primes;
}


/* Dealing with summation of millions. Use long long. */
unsigned long long summation_primes(unsigned long upper_bound) {
    unsigned long long sum = 0;

    if (upper_bound > 3) {
        sum = 2;
        
        unsigned int* factors = primes_below_root(upper_bound);
        unsigned long i = 3;

        while (i < upper_bound) {
            for (int j = 0; j < 300; j++) {
                if (factors[j] == 0 || factors[j] == i) {
                    sum += i;
                    break;
                }
                else if (i % factors[j] == 0) {
                    break;
                }
            }
            i += 2;
        }
    }
    printf("%llu\n", sum); 
    return sum;
}


/* TESTS */
static char * test_0() {
    mu_assert("Failed 0", summation_primes(0) == 0);
    return 0;
}

static char * test_10() {
    mu_assert("Failed 10", summation_primes(10) == 17);
    return 0;
}

static char * test_100() {
    mu_assert("Failed 100", summation_primes(100) == 1060);
    return 0;
}

static char * test_2mil() {
    mu_assert("Failed 2 mil", summation_primes(2000000) == 142913828922);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_0);
    mu_run_test(test_10);
    mu_run_test(test_100);
    mu_run_test(test_2mil);

    return 0;
}
