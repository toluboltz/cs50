#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Compute the number of letters in the text
    int number_of_letters = count_letters(text);

    // Compute the number of words in the text
    int number_of_words = count_words(text);

    // Compute the number of sentences in the text
    int number_of_sentences = count_sentences(text);

    printf("%d letters\n", number_of_letters);
    printf("%d words\n", number_of_words);
    printf("%d sentences\n", number_of_sentences);

    // Compute the readability grade
    // Using Coleman-Liau Index: index = 0.0588 * L - 0.296 * S - 15.8
    // Where: L is the average number of letters per 100 words, and
    //        S is the average number of sentences per 100 words
    float L = (float) number_of_letters / number_of_words * 100;
    float S = (float) number_of_sentences / number_of_words * 100;
    int index = 0.0588 * L - 0.296 * S - 15.8;

    printf("L: %f, S: %f, Index: %d\n", L, S, index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string text)
{
    // Initialize the length of the text
    int text_length = strlen(text);

    // Initialize the number of letters
    int count = 0;

    // Loop through each character in the text
    for (int i = 0; i < text_length; i++)
    {
        // Convert character to uppercase
        char uppercase = toupper(text[i]);

        // If character is in A-Z, increment letter count
        // Otherwise ignore the character
        if ((int) uppercase >= 65 && (int) uppercase <= 90)
        {
            count += 1;
        }
        else
        {
            continue;
        }
    }
    // Return the number of letters
    return count;
}

int count_words(string text)
{
    // Initialize the length of the text
    int text_length = strlen(text);

    // Initialize the number of letters to 1
    // to account for the last word
    int count = 1;

    // Loop through each character in the text
    for (int i = 0; i < text_length; i++)
    {
        // If we find a space, increment count by 1
        if (text[i] == ' ')
        {
            count += 1;
        }
        else
        {
            continue;
        }
    }

    // Return the number of words
    return count;
}

int count_sentences(string text)
{
    // Initialize the length of the text
    int text_length = strlen(text);

    // Initialize the number of letters to 1
    // to account for the last word
    int count = 0;

    // Loop through each character in the text
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
        else
        {
            continue;
        }
    }

    // Return the number of sentences
    return count;
}