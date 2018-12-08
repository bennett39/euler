# include <stdio.h>
# include <stdlib.h>

# include <math.h>
# include <string.h>

# include "../minunit.h"

/* Program functions */
int largest_palindrome_product(int digits);

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

/* PROGRAM */
int is_palindrome(int x) {
    int original = x;
    int reverse = 0;

    while (original > 0) {
        reverse *= 10;
        
        int r = original % 10;
        reverse += r;
        original /= 10;
    }

    if (reverse == x) {
        return 1;
    }

    return 0;
}


int largest_palindrome_product(int digits) {
    int max = pow(pow(10, digits), 2) - 1;
    
    printf("%d\n", max);
    if (is_palindrome(max) == 1) {
        printf("%d is a palindrome.\n", max);
    }
    return max;
}

/* TESTS */
/*
static char * test_tk() {
    mu_assert("",);
    return 0;
}
*/

static char * test_tk() {
    mu_assert("2 digits should be 9009", \
            largest_palindrome_product(2) == 9009);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_tk);

    return 0;
}