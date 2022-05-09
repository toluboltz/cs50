# Program that determines whether a provided credit card number is valid according to Luhn’s algorithm

from cs50 import get_int


def main():

    # Get card number
    card_number = get_int("Number: ")

    sum = check_sum(card_number)

    card_type = verify(sum, card_number)


def check_sum(card_number):
    pass


def verify(sum, card_number):
    pass


if __name__ == "__main__":
    main()