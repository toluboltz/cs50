# Program that prints out double half-pyramid of a specified height

from cs50 import get_int


def main():

    # Get half-pyramid height, must be betweeen 1 and 8 inclusive
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break

    # Length of space between half-pyramids
    gap_length = 2

    pyramid(height, gap_length)


def pyramid(height, gap_length):
    """Print 2 half-pyramids separated by a gap."""
    for i in range(1, height + 1):
        # Print preceding spaces
        print(" " * height - i, end="")

        # Print left #'s
        print("#" * i, end="")

        # Print gap between half-pyramids
        print(" " * gap_length, end="")

        # Print right #'s
        print("#" * i, end="")


if __name__ == "__main__":
    main()