# include <stdio.h>
# include <stdlib.h>

long long nth_prime(int n) {
    /* The nth prime is approximately n*ln(n).
     * For the 10,000 prime that's 92103.
     * Largest possible prime factor is the sqrt(n ln n).
     * For the 10,000th prime that's approximately 303.
     * So, just check for divisibility by primes less than 303. */

    int primes_less_than[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, \
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, \
        103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, \
        167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, \
        233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

    int counter = sizeof(primes_less_than)/sizeof(int);

    return counter;
}

int main () {
    printf("%lli\n", nth_prime(10000));

    return 0;
}

