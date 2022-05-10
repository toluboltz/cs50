# Program that computes the approximate grade level needed to comprehend some text

import re


def main():

    # Get text from user
    text = input("Text: ").upper()

    # Count number of letters, words and sentences
    letters, words, sentences = count(text)

    # Compute letters per 100 words
    L = letters / words * 100

    #  Compute sentences per 100 words
    S = sentences / words * 100

    # Compute readability index
    index = 0.0588 * L - 0.296 * S - 15.8

    

    print(letter, word, sentence)


def count(text):
    """Count letters in text. Return number of letters."""
    letters = re.compile(r'[A-Z]')
    words = re.compile(r'[ ]')
    sentences = re.compile(r'[.!?]')

    letter_count = 0
    word_count = 1
    sentence_count = 0

    for l in text:
        if (letters.match(l)):
            letter_count += 1
        elif (words.match(l)):
            word_count += 1
        elif (sentences.match(l)):
            sentence_count += 1

    return letter_count, word_count, sentence_count


if __name__ == "__main__":
    main()