#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Check the height of photo
    for(int i = 0; i < height; i++)
    {
        //Check the width of photo
        for(int j = 0; j < width; j++)
        {
            //change interger to float
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            //Get the average value
            int x = round((red + green + blue)/3);
            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtBlue = x;


        }


    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //check the height
 for(int i = 0; i < height; i++)
    {
        //check the width
        for(int j = 0; j < width; j++)
        {
            //change interger to float
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            //Get the average value
            int sepiaRed = round((.393 * red) + (.769 * green) + (.189 * blue));
            int sepiaGreen = round((.349 * red) + (.686 * green) + (.168 * blue));
            int sepiaBlue = round((.272 * red) + (.534 * green) + (.131 * blue));



            //Update the value if colors exceeds 255
            if(sepiaRed > 255)
            {
                  sepiaRed = 255;
            }

            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }


    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Check for the height
    for(int i = 0; i < height; i++)
    {
        //Check for the width
        for(int j = 0; j < width / 2; j++)
        {
            //Code to reflect image
           RGBTRIPLE x = image[i][j];
           image[i][j] = image[i][width - (j + 1)];
           image[i][width - (j + 1)] = x;
        }


    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //This code will copy the image
    RGBTRIPLE blurPic [height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            blurPic[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int blurRed;
            int blurGreen;
            int blurBlue;
            float counter = 0.00;


            blurRed = 0;
            blurGreen = 0;
            blurBlue = 0;

            //Get value
            for(int a = -1; a < 2; a++)
            {
                for(int b = -1; b < 2; b++)
                {
                    int blurA, blurB;
                    blurA = i + a;
                    blurB = j + b;


                    //Check if value is correct
                    if (blurA < 0 ||blurA > (height - 1))
                    {
                        continue;
                    }
                    if (blurB < 0 || blurB > (width - 1))
                    {
                        continue;
                    }

                    blurRed += image[blurA][blurB].rgbtRed;
                    blurGreen += image[blurA][blurB].rgbtGreen;
                    blurBlue += image[blurA][blurB].rgbtBlue;
                    counter++;


                    //Calculate the average
                    blurPic[i][j].rgbtRed = round(blurRed / counter);
                    blurPic[i][j].rgbtGreen = round(blurGreen / counter);
                    blurPic[i][j].rgbtBlue = round(blurBlue / counter);
                }
            }

        }
    }
    //Copy new image into the original image
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blurPic[i][j].rgbtRed;
            image[i][j].rgbtGreen = blurPic[i][j].rgbtGreen;
            image[i][j].rgbtBlue = blurPic[i][j].rgbtBlue;
        }
    }
    return;
}
