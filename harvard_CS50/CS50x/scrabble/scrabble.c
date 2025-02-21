#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int sum_score(string str);
void check_winner(int score1, int score2);

int main(void)
{
    // Prompt the user for two words

    // Compute the score of each word

    // Print the winner

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int score1 = sum_score(player1);
    int score2 = sum_score(player2);
    check_winner(score1, score2);
}

int sum_score(string str)
{
    char c;
    int player_score = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        c = toupper(str[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' ||
            c == 'S' || c == 'T' || c == 'U')
            player_score += 1;
        else if (c == 'D' || c == 'G')
            player_score += 2;
        else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
            player_score += 3;
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
            player_score += 4;
        else if (c == 'K')
            player_score += 5;
        else if (c == 'J' || c == 'X')
            player_score += 8;
        else if (c == 'Q' || c == 'Z')
            player_score += 10;
    }
    return player_score;
}

void check_winner(int score1, int score2)
{
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Ties!\n");
}
