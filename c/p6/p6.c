# include <stdio.h>
# include <stdlib.h>

int sum_squares(int m) {
    int i;
    int squares = 0;

    for (i = 0; i <= m; i++) {
        squares += i*i;
    }

    return squares;
}

/* Could reach the billions because it's quadratic, so best to use a
 * long long. */
long long square_sums(int n) {
    int j;
    int sum;

    for (j = 0; j <= n; j++) {
        sum += j;
    }
    
    return sum*sum;
}

int main() {
    int n = 100;
    long long difference = square_sums(n) - sum_squares(n);

    printf("%lli\n", difference);

    return 0;
}

