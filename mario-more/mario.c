#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        int height = get_int("Height: ");
    }
    while(height > 0 && height < 9);
}