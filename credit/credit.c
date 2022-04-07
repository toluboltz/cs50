#include <cs50.h>
#include <stdio.h>

int check_sum(long int);

int main(void)
{
    // prompt user for card number
    long int card_number = get_long("Number: ");

    // compute the checksum
    int value = check_sum(card_number);

    printf("Answer: %i\n", value);
}

int check_sum(long int card_number)
{
    // sum of the products digits and the other digits not
    // multiplied by 2
    int product_sum = 0;
    int other_sum = 0;

    // variable to count the digits
    int i = 0;

    while (true)
    {
        // operation to retrieve the last digit
        int modulus = card_number % 10;

        // check for every other digit starting from
        // second-to-last
        if (i % 2 != 0)
        {
            // multiply each digit by 2
            int product = modulus * 2;
            while (true)
            {
                // separate the products into its digits
                // and add them together
                int remainder = product % 10;
                product_sum += remainder;

                product = (product - remainder) / 10;
                
                if (product == 0)
                {
                    break;
                }
            }

        }
        // check for other digits
        else
        {
            // and sum them up
            other_sum += modulus;
        }

        card_number = (card_number - modulus) / 10;

        if (card_number == 0)
        {
            break;
        }

        i++;
    }

    return product_sum + other_sum;
}