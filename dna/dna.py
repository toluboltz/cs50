import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit('Usage: python dna.py data.csv sequence.txt')

    # Initialize dictionary to store DNA sequences and STR values
    STR = {}
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        header = next(reader)
        for i in range(1, len(header)):
            STR[header[i]] = 0

    # Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    dna_sequence = ''
    with open(sys.argv[2]) as file:
        dna_sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    for subsequence in STR:
        STR[subsequence] = longest_match(dna_sequence, subsequence)

    print(STR)

    # TODO: Check database for matching profiles
    for person in database:
        print(person)
        name = person.pop('name')
        print(person)
        if person == STR:
            print(name)
    print('No match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
