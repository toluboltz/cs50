#include <cs50.h>
#include <stdio.h>

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
    string ciphertext = encrypt_text()
}

string encrypt_text(string text, string key)
{

}

int get_index(char character)
{
    // Convert character to uppercase
    toupper(character)
}