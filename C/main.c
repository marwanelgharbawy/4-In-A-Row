#include <stdio.h>

char board[6][7];
void printBoard(void);
void initBoard(void);
int addPiece(char piece, int column); // Returns 1 if successful
int findAvailable(int column);        // Returns available row
int didSomeoneWin(void);              // Returns the winner
int checkHorizontal(char winner_piece, int i, int j);
int checkVertical(char winner_piece, int i, int j);
int checkDiagonal(char winner_piece, int i, int j);

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

int didSomeoneWin()
{
    char winner_piece;
    int win = 0;

    // If 4 in a row horizontally
    for (int i = 0; i < 4 && !win; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] != '-')
            {
                win = checkHorizontal(board[i][j], i, j);
                if (win)
                {
                    break;
                }
                
            }
        }
    }
    
    // If 4 in a row vertically CHANGE CONDITIONS
    for (int i = 0; i < 4 && !win; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] != '-')
            {
                win = checkHorizontal(board[i][j], i, j);
                if (win)
                {
                    break;
                }
                
            }
        }
    }

    // If 4 in a row diagonally CHANGE CONDITIONS
    for (int i = 0; i < 4 && !win; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] != '-')
            {
                win = checkHorizontal(board[i][j], i, j);
                if (win)
                {
                    break;
                }
                
            }
        }
    }

    if (win)
    {
        if (winner_piece == 'X')
        {
            return 1;
        }
        else if (winner_piece == 'O')
        {
            return 2;
        }
    }
    
    
    return 3;
}

int checkHorizontal(char winner_piece, int i, int j)
{
    for (int k = i; k < i + 4; k++)
    {
        if (board[k][j] != winner_piece)
        {
            return 0;
        }
    }
    return 1;
}

int checkVertical(char winner_piece, int i, int j)
{

}

int checkDiagonal(char winner_piece, int i, int j)
{

}
