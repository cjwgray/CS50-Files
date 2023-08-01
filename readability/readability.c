#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int  main(void)
{
    // Ask for text
    string word = get_string("Text: ");

       // Count number of letters
    float num = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if ((word[i] >= 97 && word[i] <= 122) ||
            (word[i] >= 65 && word[i] <= 90))
        {
            num++;
        }
    }

     // Count number of words
    float numTwo = 1;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == 32)
        {
           numTwo++;
        }
    }

     // Count number of sentences
    float numThree = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == 46 || word[i] == 33 || word[i] == 63)
        {
            numThree++;
        }
    }

      // Calculate average number of letters & sentences
    float letter = 100 * (num / numTwo);
    float sentence = 100 * (numThree / numTwo);

    int index = round(0.0588 * letter - 0.296 * sentence - 15.8);

       // Return result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}