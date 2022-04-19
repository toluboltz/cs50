#include <cs50.h>
#include <stdio.h>

// function prototypes
int check_sum(long int);
string verify_card(long int, int);

int main(void)
{
    // prompt user for card number
    long int card_number = get_long("Number: ");

    // compute the checksum
    int sum_value = check_sum(card_number);

    // printf("Answer: %i\n", value);

    string card_type = verify_card(card_number, sum_value);

    printf("%s", card_type);
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
                // separate the products into its digits (starting from the last)
                // and add them together
                int remainder = product % 10;
                product_sum += remainder;

                // a little operation to remove the last digit
                // e.g. (231 - 1) / 10 = 23
                product = (product - remainder) / 10;

                // break out of the loop if no digits are left
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

        // a little operation to remove the last digit
        // e.g. (231 - 1) / 10 = 23
        card_number = (card_number - modulus) / 10;

        // break out of the loop if no card numbers are left
        if (card_number == 0)
        {
            break;
        }
        // increase counter by 1
        i++;
    }
    // return the checksum
    return product_sum + other_sum;
}

string verify_card(long int number, int check_sum)
{
    // validate checksum's last digit
    // if not 0, the card is invalid
    if (check_sum % 10 != 0)
    {
        return "INVALID\n";
    }

    // initialize variables to store length of the card
    // and flag for what the number starts with:
    // 0: invalid, 1: amex, 2: mastercard, 3: visa
    int length = 1;
    int starts_with = 0;

    while (true)
    {
        // integer division to get rid of last digit
        number /= 10;

        // check for the starting digits of the card
        if (number == 34 || number == 37)
        {
            starts_with = 1;
        }
        else if (number == 51 || number == 52 || number == 53 || number == 54 || number == 55)
        {
            starts_with = 2;
        }
        else if (number == 4)
        {
            starts_with = 3;
        }

        // if there are no more digits, break out of the loop
        if (number == 0)
        {
            break;
        }

        // increment the card length
        
        length++;
    }

    // conditions to check the card length and starting digit(s)
    if (length == 15 && starts_with == 1)
    {
        return "AMEX\n";
    }
    else if (length == 16 && starts_with == 2)
    {
        return "MASTERCARD\n";
    }
    else if ((length == 13 && starts_with == 3) || (length == 16 && starts_with == 3))
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}