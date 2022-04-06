#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user's name
    string name = get_string("Please enter name: ");

    // Print hello, <name>
    printf("hello, %s\n", name);
}