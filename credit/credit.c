#include <cs50.h>
#include <stdio.h>

int check_sum(int);

int main(void)
{
    long int card_number = 4003600000000014;

    int modulus;

    int other_sum = 0;
    int product_sum = 0;

    while (true)
    {
        modulus = card_number % 10;
        // printf("Modulus %i: %i\n", i, modulus);

        // printf("Card number %i: %li\n", i, card_number);

        if (i % 2 == 0)
        {
            other_sum += modulus;
        }
        else
        {
            int product = modulus * 2;
            int remainder;
            while (true)
            {
                remainder = product % 10;
                product_sum += remainder;

                product = (product - remainder) / 10;

                if (product == 0)
                {
                    break;
                }
            }


            // printf("%i X 2 = %i\n", modulus, modulus * 2);
        }

        // printf("%i", modulus);

        card_number = (card_number - modulus) / 10;

        if (card_number == 0)
        {
            break;
        }

        i++;
    }
    printf("\nOther Sum: %i", other_sum);
    printf("\nProduct Sum: %i", product_sum);
    printf("\n");
}

int check_sum(int card_number)
{

}