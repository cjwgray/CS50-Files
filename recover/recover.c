#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = NULL;
    char *filename = malloc(8 * sizeof(char));
    unsigned char bufferImage[512];
    int count = 0;
    int setNum = 512;

    //If the file isn't recovered
    if (argc != 2)
    {
       printf("Usage: ./recover IMAGE\n");
       return 1;
    }


    //Read the blocks
    while(fread(bufferImage, sizeof(char), setNum, inputFile))
    {
        //check if JPEG is ready
        if ((bufferImage[0] == 0xff) && (bufferImage[1] == 0xd8) && (bufferImage[2] == 0xff) && ((bufferImage[3] & 0xf0) == 0xe0))
        {
            sprintf(filename, "%03i.jpg", count);
            outputFile = fopen(filename, "w");
            count++;
        }

        if(outputFile != NULL)
        {
            fwrite(bufferImage, sizeof(char), setNum, outputFile);
        }
    }
    //Close files
    free(filename);
    
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}