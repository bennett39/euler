# include <stdio.h>
# include <stdlib.h>

int main() {
    /* Max result could be 20! which is a 19 digit number. Need a long
     * long */
    long long result = 20;
    
    /* i is our denominator in the loop. No need to divide by 20 because
     * we're incrementing the numerator by 20. */
    int i = 19;
    int found = 0;

    while (found == 0) {
        /* Only need to loop until i == 11 because we've seen the
         * factors below 10 already, just in double. e.g. if it's
         * divisible by 18, we know it will be divisible by 9. */
        if (result % i == 0 && i == 11) {
            found = 1;
        }

        /* When the remainder is zero, decrement the divisor */
        else if (result % i == 0 && i > 11) {
            i--;
        }

        /* When the remainder isn't zero, reset divisor and add 20 to
         * our guess. */
        else {
            i = 19;
            result += 20;
        }
    }
    printf("Your result: %lli\n", result);

    return 0;
}
