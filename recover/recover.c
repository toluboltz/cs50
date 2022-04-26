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
    char *infile = argv[1];

    // Open image file
    FILE *raw_file = fopen(infile, "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    const int BLOCK_SIZE = 512;

    typedef uint8_t BYTE;

    BYTE *jpg = malloc(sizeof(BYTE) * BLOCK_SIZE);

    char *output_format = "###.jpg";

    char *output_filename = malloc(sizeof(BYTE) * strlen(output_format) + 1);

    sprintf(out_filename, "%03i.jpg", 0);

    fread(jpg, sizeof(BLOCK_SIZE), 1, raw_file);

    FILE *outfile = fopen(output_filename, "w");
    if (outfile == NULL)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    fwrite(jpg, sizeof(BLOCK_SIZE), 1)
}