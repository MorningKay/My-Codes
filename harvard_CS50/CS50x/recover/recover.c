#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data left to read from the memory card
    FILE *recover_file = NULL;
    int counter = 0;

    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (recover_file != NULL)
            {
                fclose(recover_file);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", counter);
            recover_file = fopen(filename, "w");
            counter++;
        }

        if (recover_file != NULL)
        {
            fwrite(buffer, 1, 512, recover_file);
        }
    }

    if (recover_file != NULL)
    {
        fclose(recover_file);
    }
    fclose(card);
}
