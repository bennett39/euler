# include <stdio.h>
# include <stdlib.h>
# include "../minunit.h"

int sum_of_multiples(int floor, int remainder);

int main(int argc, char *argv[]) {
    /* argv[1] exists */
    if (argc != 2) {
        fprintf(stderr, "No or too many command line arguments\n");
        return 1;
    }
    
    /* atoi will return 0 for any non-integer */
    int x = atoi(argv[1]);
    
    if (x <= 0) {
        fprintf(stderr, "Enter a non-negative integer\n");
        return 1;
    }
    
    int floor = x / 15;
    int remainder = x % 15;
    int total = sum_of_multiples(floor, remainder);

    printf("NUMBER: %d\nFloor: %d\nRemainder: %d\nTotal: %d\n", \
            x, floor, remainder, total);
    
    return 0;
}

int sum_of_multiples(int floor, int remainder) {
    return 0;
}
