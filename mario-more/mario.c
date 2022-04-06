#include <cs50.h>
#include <stdio.h>

void pyramid(int, int);

int main(void)
{
    int height;
    int space_length = 2;

    // Get the height of the pyramids.
    // Height must be between 1 and 8 inclusive.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    pyramid(height, space_length);
}

void pyramid(int height, int space_length)
{
    for (int i = 1; i <= height; i++)
    {
        // Print preceding spaces
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        // print left #'s
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // print "gap" spaces
        for (int s = 0; s < space_length; s++)
        {
            printf(" ");
        }
        // print right #'s
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // go to the next row
        printf("\n");
    }
}