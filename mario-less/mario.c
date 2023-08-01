#include <cs50.h>
#include <stdio.h>

int main(void)

{
    // Get size of grid
    int n;
    // User's input height between 1 and 8
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Print grid of bricks

    for(int i = 0; i < n; i++)

    {
        for(int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}