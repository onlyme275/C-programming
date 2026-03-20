#include <stdio.h>


char board[3][3];

void intializerBoard()
{
    char ch = '1';
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

void printBoard()
{
    printf("\n");
    for(int i=0; i<3; i++)
    {
        printf("%c %c %c", board[i][0], board[i][1], board[i][2]);
        if(i != 2)
        {
            printf("\n--|--|--\n");
        }
    }
    printf("\n\n");
}

int checkwinner()
{
    for(int i=0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }
    return 0;
}

int main()
{
    int choice;
    int player = 1;
    int moves = 0;
    char mark;

    intializerBoard();
    while(1)
    {
        printBoard();
        if(player == 1)
        {
            mark='X';
        }else{
            mark='O';
        }
        printf("Player %d (%c), enter position (1-9): ", player, mark);
        scanf("%d", &choice);
        int row = (choice - 1)/3;
        int col = (choice - 1)%3;

        if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[row][col] = mark;
        moves++;

        if(checkwinner())
        {
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        }
        if(moves == 9)
        {
            printBoard();
            printf("It's a draw.\n");
            break;
        }
        player = (player == 1) ? 2 : 1;
    }
    return 0;
}

