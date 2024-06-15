#include <stdio.h>

char board[6][7];
int win = 0;

void printBoard(void);
void initBoard(void);
int addPiece(char piece, int column); // Returns 1 if successful
int findAvailable(int column);        // Returns available row

// int didSomeoneWin(void);           // Returns the winner
// int checkHorizontal(char winner_piece, int i, int j);
// int checkVertical(char winner_piece, int i, int j);
// int checkDiagonal(char winner_piece, int i, int j);

int checkWin(int i, int j); // Changes win flag to 1

int main() 
{
    initBoard();
    printBoard();
    // int winner = 0;
    int key;

    while (!win)
    {
        printf("Player 1's turn: ");
        scanf("%d", &key);
        addPiece('X', key - 1);
        printBoard();
        if (win)
        {
            printf("Player 1 won!\n");
            break;
        }

        printf("Player 2's turn: ");
        scanf("%d", &key);
        addPiece('O', key - 1);
        printBoard();
        if (win)
        {
            printf("Player 2 won!\n");
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

int checkWin(int i, int j)
{
    char winner_piece = board[i][j];
    int count;

    // Check horizontally

    count = 1;
    for (int y = j - 1; y >= 0 && board[i][y] == winner_piece; y--) count++;
    for (int y = j + 1; y < 7 && board[i][y] == winner_piece; y++) count++;
    if (count >= 4) 
    {
        win = 1;
        printf("FOUR IN A ROW HORIZONTALLY!!!!\n");
        return 1;
    }

    // Check vertically

    count = 1;
    for (int x = i - 1; x >= 0 && board[x][j] == winner_piece; x--) count++;
    for (int x = i + 1; x < 6 && board[x][j] == winner_piece; x++) count++;
    if (count >= 4) 
    {
        win = 1;
        printf("FOUR IN A ROW VERTICALLY!!!!\n");
        return 1;
    }

    // Check diagonal \

    count = 1;
    for (int x = i - 1, y = j - 1; x >= 0 && y >= 0 && board[x][y] == winner_piece; x--, y--) count++;
    for (int x = i + 1, y = j + 1; x < 6 && y < 7 && board[x][y] == winner_piece; x++, y++) count++;
    if (count >= 4) 
    {
        win = 1;
        printf("FOUR IN A ROW DIAGONALLY!!!!\n");
        return 1;
    }

    // Check diagonal /

    count = 1;
    for (int x = i - 1, y = j + 1; x >= 0 && y < 7 && board[x][y] == winner_piece; x--, y++) count++;
    for (int x = i + 1, y = j - 1; x < 6 && y >= 0 && board[x][y] == winner_piece; x++, y--) count++;
    if (count >= 4) 
    {
        win = 1;
        printf("FOUR IN A ROW DIAGONALLY!!!!\n");
        return 1;
    }

    return 0;
}

// // Now it only works horizontally
// int checkWin(int i, int j)
// {
//     char winner_piece = board[i][j];
//     int x = i;
//     int y = j;

//     // if 4 in a row horizontally
//     // Move backwards until it finds the last character, then move forward and start counting
//     while (board[i][y - 1] == winner_piece)
//     {
//         y--; // Move backwards
//     }
//     for (int k = y + 1; k < y + 4; k++)
//     {
//         win = 1;
//         if (board[i][k] != winner_piece)
//         {
//             win = 0;
//             break;
//         }
//     }
//     if (win)
//     {
//         printf("FOUR IN A ROW!!!!\n");
//         return 1;
//     }

//     // if 4 in a row vertically
//     if (i < 3) // First row to be printed is zero index, last one is 6
//     {
//         for (int k = i; k < i + 3; k++)
//         {
//             win = 1;
//             if (board[k][j] != winner_piece)
//             {
//                 win = 0;
//                 break;
//             }
//         }
//         if (win)
//         {
//             printf("FOUR IN A ROW!!!!\n");
//             return 1;
//         }
//     }

//     // if 4 in a row diagonally
//     // Diagonals only have 2 cases
//     // First case: diagonal moving up then right /
//     // Row is x, column is y
//     while (board[x + 1][y - 1] == winner_piece)
//     {
//         x++; // Go down
//         y--; // Go left
//     }
//     for (int k = x, l = y; k > x - 3 && l < y + 3; k--, l++)
//     {
//         win = 1;
//         if (board[k][l] != winner_piece)
//         {
//             win = 0;
//             break;
//         }
//     }
//     if (win)
//     {
//         printf("FOUR IN A ROW VERTICALLY!!!!\n");
//         return 1;
//     }

//     return 0;

// }

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
