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
        printf("Could not open %s.\n", infile);
        return 1;
    }

    const int BLOCK_SIZE = 512;

    typedef uint8_t BYTE;

    BYTE *jpg = malloc(sizeof(BYTE) * BLOCK_SIZE);

    char *output_format = "###.jpg";

    char *output_filename = malloc(sizeof(BYTE) * strlen(output_format) + 1);

    int file_count = 0;
    printf("here\n");
    while (fread(jpg, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        FILE *outfile
        // Check for JPEG file format
        if (jpg[0] == 0xff && jpg[1] == 0xd8 && jpg[2] == 0xff && ((jpg[3] & 0xf0) == 0xe0))
        {
            if (outfile)
            // Create output file name
            sprintf(out_filename, "%03i.jpg", file_count);

            // Open output file
            FILE *outfile = fopen(output_filename, "w");
            if (outfile == NULL)
            {
                printf("Could not open %s.\n", filename);
                return 1;
            }


        }
        // if (jpg[0] == 0xff && jpg[1] == 0xd8 && jpg[2] == 0xff && )
        // {

        // }


        file_count++;
        if (file_count == 5)
        {
            break;
        }
    }



    // fwrite(jpg, sizeof(BLOCK_SIZE), 1)

    free(jpg);

    fclose(raw_file);

    return 0;
}