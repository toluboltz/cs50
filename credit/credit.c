#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int card_number = 4003600000000014;

    int modulus;

    int i = 0;
    int other_sum = 0;
    int product_sum = 0;

    while (true)
    {
        modulus = card_number % 10;
        // printf("Modulus %i: %i\n", i, modulus);
        card_number = (card_number - modulus) / 10;
        // printf("Card number %i: %li\n", i, card_number);

        if (i % 2 == 0)
        {
            other_sum += modulus;
        }
        else
        {
            int product = modulus * 2;
            while (true)
            {
                int remainder = product % 10;
                
            }


            printf("%i X 2 = %i\n", modulus, modulus * 2);
        }

        // printf("%i", modulus);

        if (card_number == 0)
        {
            break;
        }

        i++;
    }
    printf("\nOther Sum: %i", other_sum);
    printf("\n");
}