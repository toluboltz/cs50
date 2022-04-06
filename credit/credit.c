#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int card_number = 4003600000000014;

    int modulus;

    int i = 1;
    while (true)
    {
        modulus = card_number % 10;
        printf("Modulus %i: %i\n", i, modulus);
        card_number -= card_number - modulus;
        printf("Card number %i: %li\n", i, card_number);

        if (card_number == 0)
        {
            break;
        }

        i++;
    }
    printf("Done\n");
}