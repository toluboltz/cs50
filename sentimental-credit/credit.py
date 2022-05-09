# Program that determines whether a provided credit card number is valid according to Luhn’s algorithm

import re


def main():

    # Get card number as a string
    card_number = input("Number: ")

    # Compute the checksum on the reversed card number
    sum = check_sum(card_number[::-1])

    # Verify the card_type
    card_type = verify(sum, card_number)

    # Print out card_type
    print(card_type)


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
    """Verify the card type. Return if card type."""

    # Check if checksum ends with 0
    if sum % 10 != 0:
        return "INVALID"

    amex = re.compile(r'[3][47]')
    mastercard = re.compile(r'[5][12345]')
    visa = re.compile(r'[4]')

    if (visa.match(card_number)):
        print("VISA")


if __name__ == "__main__":
    main()