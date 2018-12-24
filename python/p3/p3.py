# A program to find the greatest prime factor of a number.
# Worst case, runs in linear time (worst case = given a prime).
# Otherwise subpromlems, get divided, so on average it's log n

from math import sqrt

def main():
    print(greatest_prime_factor(13195))
    print(greatest_prime_factor(600851475143))
    return 0


def greatest_prime_factor(x):
    """
    Finds the smallest factor and divides by it until only the largest
    factor remains.
    """
    if x < 2:
        return 0
    else:
        i = 2
        max = 2
        root = sqrt(x)

        while i <= root:
            if x % i == 0:
                max = i
                x = x / i
                i = 2
            else:
                i += 1

        return max


if __name__=="__main__":
    main()
