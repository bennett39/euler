def main():
    print(largest_palindrome_product(999, 999))
    
    return 0


def is_palindrome(x):
    original = x
    reverse = 0
    
    while original > 0:
        reverse = reverse * 10 + original % 10
        original //= 10

    if reverse == x:
        return True

    return False


def largest_palindrome_product(max_a, max_b):
    largest_product = 0

    for a in range(max_a, 0, -1):
        for b in range(max_b, 0, -1):
            product = a * b
            if product < largest_product:
                break
            if is_palindrome(product):
                largest_product = product

    return largest_product


if __name__=="__main__":
    main()
