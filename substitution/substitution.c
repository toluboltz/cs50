#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string encrypt_text(string, string);

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

    // Print the cipher text
    printf("ciphertext: %s\n", ciphertext);

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

        // Get the ASCII value of the letter
        int letter_value = (int) letter;

        // Check if each letter is an alphabet in A-Z (inclusive)
        if (letter_value >= 65 && letter_value <= 90)
        {
            // Compute the letter's index in the key
            int index = letter_value - 65;

            // Preserve the case of the plain text
            if (isupper(text[i]))
            {
                ciphertext[i] = toupper(key[index]);
            }
            else
            {
                ciphertext[i] = tolower(key[index]);
            }
        }
        else
        {
            // Incase of non-alphabet letters
            // leave them as is.
            ciphertext[i] = text[i];
        }

    }

    // Return the cipher text
    return ciphertext;
}