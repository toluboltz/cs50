# Program that determines whether a provided credit card number is valid according to Luhn’s algorithm

from cs50 import get_string


def main():

    # Get card number as a string and reverse it
    card_number = get_string("Number: ")[::-1]

    sum = check_sum(card_number)

    card_type = verify(sum, card_number)


def check_sum(card_number):
    """Compute and return a checksum on the card number."""
    for i in range(0, len(card_number), 2):
        


def verify(sum, card_number):
    pass


if __name__ == "__main__":
    main()