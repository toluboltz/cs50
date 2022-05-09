# Program that asks user for their name and prints out "hello, <name>"

def main():
    """Request user's name and print out hello, <name>."""
    name = input("What is your name?\n")
    print(f"hello, {name}")


if __name__ == "__main__":
    main()