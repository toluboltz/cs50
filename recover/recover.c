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
    FILE *raw_file = fopen(filename, "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    const int BLOCK_SIZE = 512;

    typedef uint8_t BYTE;

    BYTE *jpg = malloc(sizeof(BYTE) * BLOCK_SIZE);

    char *format = "###.jpg";

    char *outfile = malloc(sizeof(BYTE) * strlen(out_format) + 1);

    sprintf(outfile, "%03i.jpg", 0);

    fread(jpg, sizeof(BLOCK_SIZE), 1, raw_file);

    FILE *out_file = fopen(out_buffer, "w");
    if (out_file == NULL)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    fwrite(jpg)
}