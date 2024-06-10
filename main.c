#include <stdio.h>

char board[6][7];
void printBoard(void);
void initBoard(void);

void main () 
{
    initBoard();
    printBoard();

    return 0;
}

void initBoard(void)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = '-';
        }
    }
}

void printBoard(void)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    
}
