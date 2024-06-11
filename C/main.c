#include <stdio.h>

char board[6][7];
void printBoard(void);
void initBoard(void);
int addPiece(char piece, int column); // Returns 1 if successful
int findAvailable(int column);        // Returns available row
int DidSomeoneWin(void);              // Returns the winner

int main() 
{
    initBoard();
    printBoard();
    printf("Now let's start!!\n");
    int winner = 0;
    int key;

    while (!winner)
    {
        printf("Player 1's turn: ");
        scanf("%d", &key);
        addPiece('X', key - 1);

        printBoard();

        printf("Player 2's turn: ");
        scanf("%d", &key);
        addPiece('O', key - 1);

        printBoard();
    }

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

// Board orientation: the first row to be printed is zero index
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
   printf("\n"); 
}

int addPiece(char piece, int column)
{
    int row = findAvailable(column);
    if (row == -1)
    {
        printf("Column is already full.\n");
        return 0;
    }
    else
    {
        board[row][column] = piece;
        return 1;
    }
}

int findAvailable(int column)
{
    int i;
    for (i = 6; i >= 0; i--)
    {
        if (board[i][column] == '-')
        {
            break;
        }
    }
    return i;
}

int DidSomeoneWin()
{
    // If 4 in a row horizontally
    // If 4 in a row vertically
    // If 4 in a row diagonally
}