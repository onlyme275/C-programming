#include <stdio.h>

char board[3][3];

void initizerBoard()
{
    char ch = '1';
    for (int i =0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
            printf("%d", board[i][j]);
        }
    }
}

void printBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c %c %c", board[i][0], board[i][1], board[i][2]);
        if(i != 2)
        {
            printf("\n--|--|--\n");
        }
    }
    printf("\n\n");
}

int main()
{
    int choice;
    int player = 1;
    int moves = 0;
    char mark;
    initizerBoard();
    while(1)
    {
        printBoard();
    }
}

