#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Initialize the score
    int score = 0;
    // get the length of the word
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        // Convert each letter to uppercase
        char letter = toupper(word[i]);

        // Get the value of the letter
        int letter_value = (int) letter;

        // Check if letter is A-Z
        if (letter_value >= 65 && letter_value <= 90)
        {
            // Get the score of the letter
            score += POINTS[letter_value - 65];
        }
    }

    // Return the scoree
    return score;
}
