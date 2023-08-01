#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Ask user to input message
    string message = get_string("Message: ");

    // Each character of the string will be interated
    for (int i = 0, x = strlen(message); i < x; i++)
    {

        int arrayNumbers[] = {0,0,0,0,0,0,0,0};

        int Num = message[i];

        int y = 0;


        {
            while (Num > 0)
            arrayNumbers[y] = Num % 2;
            Num = Num / 2;
            y++;
        }

         // Print arrayNumbers in reverse
        for (int a = BITS_IN_BYTE - 1; a >= 0; a--)
        {
            print_bulb(arrayNumbers[a]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
