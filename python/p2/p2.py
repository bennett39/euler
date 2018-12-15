def even_fibonaccis(upper_bound, last=1, current=2, total=2):
    """
    A function to calculate the sum of even fibonacci numbers below an
    upper bound.

    Recursively finds a new Fibonacci number and adds it to the total if
    it's even.

    Runtime: O(upper_bound) - linear
    """
    new = last + current

    if new > upper_bound:
        return total

    if new % 2 == 0:
        total += new

    last = current
    current = new

    return even_fibonaccis(upper_bound, last, current, total)


def main():
    print(even_fibonaccis(4000000))
    return 0


if __name__ == "__main__":
    main()
