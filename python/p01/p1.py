def multiples_3_5(n):
    """
    Function to find all multiples of 3 & 5 below n and adds them.
    Returns the sum.

    Runtime: O(n)
    """

    sum_of_multiples = 0

    for i in range(n):
        if i % 3 == 0 or i % 5 == 0:
            sum_of_multiples += i

    return sum_of_multiples


def main():
    print(multiples_3_5(10))
    print(multiples_3_5(1000))

    return 0


if __name__ == "__main__":
    main()
