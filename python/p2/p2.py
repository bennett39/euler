def even_fibonaccis(last, current, total, upper_bound):
    new = last + current

    if new > upper_bound:
        return total

    if new % 2 == 0:
        total += new

    last = current
    current = new

    return even_fibonaccis(last, current, total, upper_bound)


def main():
    print(even_fibonaccis(1, 2, 2, 4000000))
    return 0

if __name__ == "__main__":
    main()
