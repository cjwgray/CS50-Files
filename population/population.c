#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //Prompt for start size
    do
    {
        n = get_int("Start size of population: ");
    }
    while (n < 9);


    //Prompt for end size
    int j;
    do
    {
        j = get_int("End size of population: ");
    }
    while (j <= n);


    //Calculate number of years until we reach threshold
    int year = 0;
    do

    {
        n = n + (n / 3) - (n / 4);
        year++;
    }
    while(n < j);


    //Print number of years
    printf("Years: %i\n", year);

}