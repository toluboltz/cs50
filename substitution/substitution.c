#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt_text(string, string);
int get_index(char);

int main(int argc, string argv[])
{
    // Validate the input
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check if input key has 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Get plain text from user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plain text
    string key = argv[1];
    string ciphertext = encrypt_text(plaintext, key);

}

string encrypt_text(string text, string key)
{
    // initialize the cipher text
    string ciphertext = text;

    // Get the length of the plain text
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        // Convert each letter to uppercase
        char letter = toupper(text[i]);

        // Get the value of the letter
        int letter_value = (int) letter;

        // Check if letter is A-Z
        if (letter_value >= 65 && letter_value <= 90)
        {
            // Get the score of the letter
            score += POINTS[letter_value - 65];
        }

        // Compute the index of each letter in the plain text
        // and get the corresponding cipher from the key

        printf("%i\n", get_index(text[i]));

        // Preserve the case of the plain text
    }

    return "";
}

int get_index(char character)
{
    // Convert character to uppercase
    character = toupper(character);

    // Compute the index
    int index = (int) character - 65;

    // return the index
    return index;
}