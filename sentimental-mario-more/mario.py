# Program that prints out double half-pyramid of a specified height

from cs50 import get_int


def main():

    # Get half-pyramid height, must be betweeen 1 and 8 inclusive
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break

    for i in range(1, height + 1):
        