#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int length;
    do
    {
        int length = get_int("Length: ");
    }
    while(length < 1);

    int x[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = 2 * x[i-1];
        printf("%i\n", x[i]);
    }

}