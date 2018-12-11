/* A program to find the nth prime. Works for the 67th through 10,000th
 * prime.
 *
 * Uses a hard coded array of the first 66 primes as factors for use in
 * modulo division checking. Could make creating this array procedural
 * in future version, to extend the program's functionality.
 *
 * Runtime: O(n log n)
 * Since checking prime factors is hard-coded, that runs in constant
 * O(66) time, so O(1). Further, we increment and check potential primes
 * by adding two and primes grow by n*ln(n). */

# include <stdio.h>
# include <stdlib.h>

long long nth_prime(int n) {
    /* The nth prime is approximately n*ln(n).
     * For the 10,000 prime that's 92103.
     * Largest possible prime factor is the sqrt(n ln n).
     * For the 10,000th prime that's approximately 303.
     * For good measure, we'll add a few more prime factors beyond the
     * 303 threshold. */
    int primes_less_than_sqrt[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, \
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, \
        103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, \
        167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, \
        233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, \
        307, 311, 313, 317};

    int arr_size = sizeof(primes_less_than_sqrt)/sizeof(int);

    /* How many primes have we already found? Start with size of above
     * integer array. */
    int counter = arr_size;

    int i, j;
    int answer;

    /* First loop increments through numbers, starting with the last
     * number in the above list, plus 2.
     *
     * Since primes can only be odd, the loop increments by 2 until it
     * reaches the nth prime (10,000th in this case).*/
    for (i = primes_less_than_sqrt[arr_size-1] + 2; counter < n; i += 2) {

        /* Second loop iterates through above array to check modulo
         * division of previous prime factors. */
        for (j = 0; j < arr_size; j++) {
            
            /* When we've checked the whole array and none of them came
             * up modulo == 0, then we've found a prime! Increment the
             * counter. */
            if (j == arr_size - 1 && i % primes_less_than_sqrt[j] != 0) {
                counter++;
                answer = i;
            }
            else if (i % primes_less_than_sqrt[j] == 0) {
                break;
            }
        }
    }

    return answer;
}

int main () {
    printf("%lli\n", nth_prime(10000));

    return 0;
}

