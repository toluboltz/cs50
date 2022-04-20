#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string);
int count_words(string);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Compute the number of letters in the text
    int number_of_letters = count_letters(text);

    printf("%d\n", number_of_letters);
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

    // Initialize the number of letters
    int count = 0;

    // Loop through each character in the text
    for (int i = 0; i < text_length; i++)
    {
        //
        if ((int) text[i] == 32)
        {
            count += 1;
        }
        else
        {
            continue;
        }
    }

    return 0;
}