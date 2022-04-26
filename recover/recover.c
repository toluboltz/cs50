#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

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
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // Store the block size
    const int BLOCK_SIZE = 512;

    // Define a byte data type
    typedef uint8_t BYTE;

    // Define output format
    char *output_format = "###.jpg";

    // Allocate memory for JPEG buffer
    BYTE *jpg = malloc(sizeof(BYTE) * BLOCK_SIZE);

    // Allocate memory for output filename buffer (used in sprintf)
    char *output_filename = malloc(sizeof(BYTE) * strlen(output_format) + 1);

    // File object
    FILE *outfile;

    // Variable to keep track of first JPEG image
    bool write = false;

    // Variable to keep track of output file number
    int file_count = 0;

    while (fread(jpg, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // Check for JPEG file format
        if (jpg[0] == 0xff && jpg[1] == 0xd8 && jpg[2] == 0xff && ((jpg[3] & 0xf0) == 0xe0))
        {
            // Create output file name
            sprintf(output_filename, "%03i.jpg", file_count);

            // Open output file
            outfile = fopen(output_filename, "w");
            if (outfile == NULL)
            {
                printf("Could not open %s.\n", output_filename);
                return 1;
            }
            // Set write flag to true
            write = true;

            // Increment file count variable
            file_count++;
        }

        // Check if to write to output file
        if (write)
        {
            fwrite(jpg, sizeof(BYTE), BLOCK_SIZE, outfile);
        }
    }

    free(jpg);
    free(output_filename);

    fclose(raw_file);
    fclose(outfile);

    return 0;
}