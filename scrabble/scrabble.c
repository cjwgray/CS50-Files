#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // This will print the winner
    if (score1 < score2)
    {
        printf("%s\n", "Player 2 wins!");
    }
    else if (score1 > score2)
    {
        printf("%s\n", "Player 1 wins!");
    }
    else
    {
        printf("%s\n", "Tie!");
    }
}

int compute_score(string word)
{
    // TODO: This will pull from the "POINTS" array and each character will be match with its score. After that, the score will return for string.
    int b = 0;

  for(int i = 0, x = strlen(word);i < x; i++)

  {
       if (isupper(word[i]))
       {
        b = b + POINTS[word[i] - 'A'];
       }
       else if (islower(word[i]))
       {
        b = b + POINTS[word[i] - 'a'];
       }

}
return b;
printf("\n");

}