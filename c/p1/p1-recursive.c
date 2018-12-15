# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

/* Program functions */
int sum_of_multiples(int total, int x);

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
    
    int user_entry, error_check;
    printf("Enter a number: ");
    error_check = scanf("%d", &user_entry);

    if (error_check == EOF || error_check == 0) {
        fprintf(stderr, "Invalid entry. Quitting...\n");
    }
    else {
        printf("You entered %d\n", user_entry);
        printf("The sum of 3/5 factors is %d\n", sum_of_multiples(0, user_entry));
    }

    return result != 0;
}

int sum_of_multiples(int total, int x) {
    x -= 1;
    if (x < 3) {
        printf("%d\n", total);
        return total;
    }
    else if (x % 3 == 0 || x % 5 == 0) {
        return sum_of_multiples(total + x, x);
    }
    else {
        return sum_of_multiples(total, x);
    }
}


/* TESTS */

static char * test_2() {
    mu_assert("error 2 !>> 0", sum_of_multiples(0, 2) == 0);
    return 0;
}

static char * test_10() {
    mu_assert("error 10 !>> 23", sum_of_multiples(0, 10) == 23);
    return 0;
}

static char * test_16() {
    mu_assert("error 16 !>> 60", sum_of_multiples(0, 16) == 60);
    return 0;
}

static char * test_19() {
    mu_assert("error 19 !>> 78", sum_of_multiples(0, 19) == 78);
    return 0;
}

static char * test_31 () {
    mu_assert("error 31 !>> 225", sum_of_multiples(0, 31) == 225);
    return 0;
}

static char * test_33() {
    mu_assert("error 33 !>> 225", sum_of_multiples(0, 33) == 225);
    return 0;
}

static char * test_48() {
    mu_assert("error 48 !>> 543", sum_of_multiples(0, 47) == 495);
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

    return 0;
}
