#include <stdio.h>

char board[6][7];

void printBoard(void);
void initBoard(void);
int addPiece(char piece, int column); // Returns 1 if successful
int findAvailable(int column);        // Returns available row

// int didSomeoneWin(void);           // Returns the winner
// int checkHorizontal(char winner_piece, int i, int j);
// int checkVertical(char winner_piece, int i, int j);
// int checkDiagonal(char winner_piece, int i, int j);

int checkWin(int i, int j); 

int main() 
{
    initBoard();
    int winner = 0;
    int key;

    while (!winner)
    {
        printBoard();

        printf("Player 1's turn: ");
        scanf("%d", &key);
        addPiece('X', key - 1);
        if (winner)
        {
            printf("Player 1 won!\n");
        }

        printBoard();

        printf("Player 2's turn: ");
        scanf("%d", &key);
        addPiece('O', key - 1);
        if (winner)
        {
            printf("Player 1 won!\n");
        }
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
        checkWin(row, column);
        return 1;
    }
}

int findAvailable(int column)
{
    int i;
    for (i = 5; i >= 0; i--)
    {
        if (board[i][column] == '-')
        {
            break;
        }
    }
    return i;
}

// Now it only works horizontally
int checkWin(int i, int j)
{
    char winner_piece = board[i][j];
    // int count = 1;
    int x = j;

    // if 4 in a row horizontally
    // move backwards until it finds the last character, then move forward and start counting
    while (board[i][x - 1] == winner_piece)
    {
        x--; // Move backwards
    }
    // printf("x value: %d\n", x);

    for (int k = x + 1; k < x + 4; k++)
    {
        if (board[i][k] != winner_piece)
        {
            return 0; // Only checks horizontal
            // break;
        }
    }
    printf("FOUR IN A ROW!!!!\n");
    return 1;

    // if 4 in a row vertically

    // if 4 in a row diagonally
}

// int didSomeoneWin()
// {
//     char winner_piece = 'f';
//     int win = 0;

//     // If 4 in a row horizontally
//     for (int i = 0; i < 6 && !win; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if (board[i][j] != '-')
//             {
//                 printf("Checking horizontal: piece: %c i: %d j: %d\n", board[i][j], i, j);
//                 win = checkHorizontal(board[i][j], i, j);
//                 printf("Win value: %d", win);
//                 if (win)
//                 {
//                     winner_piece = board[i][j];
//                     break;
//                 }
                
//             }
//         }
//     }
    
//     // If 4 in a row vertically CHANGE CONDITIONS
//     for (int i = 0; i < 4 && !win; i++)
//     {
//         for (int j = 0; j < 7; j++)
//         {
//             if (board[i][j] != '-')
//             {
//                 win = checkHorizontal(board[i][j], i, j);
//                 if (win)
//                 {
//                     break;
//                 }
                
//             }
//         }
//     }

//     // If 4 in a row diagonally CHANGE CONDITIONS
//     for (int i = 0; i < 6 && !win; i++)
//     {
//         for (int j = 0; j < 7; j++)
//         {
//             if (board[i][j] != '-')
//             {
//                 win = checkHorizontal(board[i][j], i, j);
//                 if (win)
//                 {
//                     break;
//                 }
                
//             }
//         }
//     }

//     if (win)
//     {
//         if (winner_piece == 'X')
//         {
//             return 1;
//         }
//         else if (winner_piece == 'O')
//         {
//             return 2;
//         }
//     }
    
    
//     return 3;
// }

// int checkHorizontal(char winner_piece, int i, int j)
// {
//     printf("In checkHorizontal: piece: %c i: %d j: %d\n", winner_piece, i, j);
//     for (int k = j; k < j + 4; k++)
//     {
//         printf("In checkHorizontal k loop\n");
//         printf("Board[%d][%d] is: %c\n", i, k, board[i][k]);
//         if (board[i][k] != winner_piece)
//         {
//             printf("Returning 0\n");
//             return 0;
//         }
//     }
//     printf("Returning 1\n");
//     return 1;
// }

// // int checkVertical(char winner_piece, int i, int j)
// // {

// // }

// // int checkDiagonal(char winner_piece, int i, int j)
// // {

// // }
