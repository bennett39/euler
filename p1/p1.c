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

int main(int argc, char *argv[]) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run %d\n", tests_run);

    return result != 0;
}

int sum_of_multiples(int x) {
    int floor = x / 15;
    int remainder = x % 15;
    int total = 0;

    printf("NUMBER: %d\tFloor: %d\tRemainder: %d\tTotal: %d\n", \
            x, floor, remainder, total);

    return total;
}

static char * test_2() {
    mu_assert("error 2 !>> 0", sum_of_multiples(2) == 0);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_2);
    return 0;
}
