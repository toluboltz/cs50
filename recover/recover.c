#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Track file name
    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        
    }
}