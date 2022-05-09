# Program that determines whether a provided credit card number is valid according to Luhn’s algorithm

from cs50 import get_string


def main():

    # Get card number as a string
    card_number = get_string("Number: ")

    # Compute the checksum on the reversed card number
    sum = check_sum(card_number[::-1])

    
    card_type = verify(sum, card_number)


def check_sum(card_number):
    """Compute checksum on the card number. Return chekcsum value"""

    # Multiply every other digit by 2 starting with the
    # second-to-last digit and store the digits
    prod_digits = []
    for i in range(1, len(card_number), 2):
        prod_digits += [int(digit) for digit in str(int(card_number[i]) * 2)]

    # Add the products' digits sum to the sum of the digits
    # that were not multiplied by 2
    digits_sum = sum(prod_digits)
    for i in range(0, len(card_number), 2):
        digits_sum += int(card_number[i])

    return digits_sum




def verify(sum, card_number):
    pass


if __name__ == "__main__":
    main()