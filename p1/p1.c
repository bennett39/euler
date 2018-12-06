# include <stdio.h>
# include <stdlib.h>

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

    printf("%d\nFloor: %d\nRemainder: %d\n", x, floor, remainder);
    
    return 0;
}
