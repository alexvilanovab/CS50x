#include <stdio.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    // remember card filename
    char *card_filename = argv[1];
    
    // open card file
    FILE *card = fopen(card_filename, "r");
    if (card == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", card_filename);
        return 2;
    }
    
    // init needed variables
    uint8_t buffer[512];
    FILE *jpeg = NULL;
    char jpeg_filename[3];
    int jpeg_count = 0;
    
    // repeat until end of card (read 512 bytes into a buffer each loop)
    while (fread(buffer, 512, 1, card))
    {
        // start off a new JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // close JPEG if already found
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }
            
            // create new JPEG
            sprintf(jpeg_filename, "%03i.jpg", jpeg_count);
            jpeg = fopen(jpeg_filename, "w");
            jpeg_count++;
        }
        
        // already found a JPEG
        if (jpeg != NULL)
        {
            // write data to JPEG
            fwrite(buffer, 512, 1, jpeg);
        }
    }
    
    // close any remaining files
    if (jpeg != NULL)
    {
        fclose(jpeg);
    }
    fclose(card);
    
    // done
    return 0;
}