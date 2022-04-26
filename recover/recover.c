#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Remember image filename
    char *filename = argv[1];

    // Open image file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    const int BLOCK_SIZE = 512;

    typedef uint8_t BYTE;

    BYTE *jpg_buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);

    
}