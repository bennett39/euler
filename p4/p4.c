/* A program to find the largest palindrome that's the product of two
 * three-digit numbers.
 *
 * Implemented as a double for-loop with an additional function that
 * checks if an int is a palindrome using base-10 addition.
 *
 * Runtime: Worst case O(n^2) - quadratic. But the for loop includes a 
 * break statement to ensure on average it doesn't run quadratic. */

# include <stdio.h>
# include <stdlib.h>

# include <math.h>
# include <string.h>

# include "../minunit.h"

/* Program functions */
int largest_palindrome_product();

int main() {
    printf("%d\n", largest_palindrome_product());
    return 0;
}

/* PROGRAM */
int is_palindrome(int x) {
    int original = x;
    int reverse = 0;

    /* Uses modulo and base-10 division/multiplication to reverse an 
     * int */
    while (original > 0) {
        reverse *= 10;
        
        int r = original % 10;
        reverse += r;
        original /= 10;
    }

    /* Does the reversed int match the input int? */
    if (reverse == x) {
        return 1;
    }

    return 0;
}

int largest_palindrome_product() {
    int a, b;
    int max = 0;

    /* Use double for loop to check all values of a and b. Worst case
     * runs in quadratic O(n^2) time, but includes a break statement to
     * avoid that once a palindrome is found. 
     *
     * Easily extendable to larger values of a and b, but need to make
     * `product` a long long data type. */
    for (a = 999; a > 100; a--) {
        for (b = 999; b > 100; b--) {
            int product = a * b;
            
            /* The product won't get any bigger in this loop, so break
             * to outer loop */
            if (product < max) {
                break;
            }

            /* The loop would have broken if the product was smaller
             * than the max, so product must be the new max. */
            if (is_palindrome(product) == 1) {
                max = product;
            }
        }
    }

    return max;
}
