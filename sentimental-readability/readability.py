# Program that computes the approximate grade level needed to comprehend some text

import re


def main():

    # Get text from user
    text = input("Text: ").upper()

    # Count number of letters in text
    letter_count = count_letters(text)

    # Count number of words in text
    word_count = count_words(text)

    # Count number of sentences in text
    sentence_count = count_sentences(text)


def count(text):
    """Count letters in text. Return number of letters."""
    letter = re.compile(r'[A-Z]')
    words = re.compile(r'[ ]')
    sentences = re.compile(r'[.!?]')

    letter_count = 0
    word_count = 1
    sentence_count = 1


def count_letters(text):
    """Count letters in text. Return number of letters."""
    p = re.compile(r'[A-Z]')

    count = 0
    for l in text:
        if (p.match(l)):
            count += 1

    return count


def count_words(text):
    """Count words in text. Return number of words."""
    p = re.comile(r'[ ]')

    count = 1
    for


def count_sentences(text):
    """Count sentences in text. Return number of sentences."""
    pass


if __name__ == "__main__":
    main()