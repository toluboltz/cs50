# Program that determines whether a provided credit card number is valid according to Luhn’s algorithm

from cs50 import get_string


def main():

    # Get card number as a string and reverse it
    card_number = get_string("Number: ")[::-1]

    sum = check_sum(card_number)

    card_type = verify(sum, card_number)


def check_sum(card_number):
    """


def verify(sum, card_number):
    pass


if __name__ == "__main__":
    main()