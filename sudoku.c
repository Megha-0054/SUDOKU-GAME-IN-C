
#include <stdio.h>

#define SIZE 9


int board[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int original[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void displayBoard()
{
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 3 == 0)
            printf("+-------+-------+-------+\n");

        for (int j = 0; j < SIZE; j++)
        {
            if (j % 3 == 0)
                printf("| ");

            if (board[i][j] == 0)
                printf(". ");
            else
                printf("%d ", board[i][j]);
        }

        printf("|\n");
    }

    printf("+-------+-------+-------+\n");
}

int checkMove(int row, int col, int num)
{
    // for rows
    for (int j = 0; j < SIZE; j++)
    {
        if (board[row][j] == num)
            return 0;
    }

    // for columns
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][col] == num)
            return 0;
    }

    // Check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == num)
                return 0;
        }
    }

    return 1;
}


int isComplete()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }

    return 1;
}

// The Main function
int main()
{
    int row, col, num;

    printf("================================\n");
    printf("       WELCOME TO SUDOKU\n");
    printf("================================\n");

    while (!isComplete())
    {
        displayBoard();

        printf("\nEnter row, column and number (1-9): ");
        printf("\nEnter 0 0 0 to exit: ");

        if (scanf("%d %d %d", &row, &col, &num) != 3)
        {
            printf("Invalid input!\n");
            return 1;
        }

        if (row == 0 && col == 0 && num == 0)
        {
            printf("Game exited!\n");
            return 0;
        }

        // Check input range
        if (row < 1 || row > 9 ||
            col < 1 || col > 9 ||
            num < 1 || num > 9)
        {
            printf("Invalid input! Enter values from 1 to 9.\n");
            continue;
        }

        // Convert to array index
        row--;
        col--;

        // Check fixed cells
        if (original[row][col] != 0)
        {
            printf("You cannot change a fixed number!\n");
            continue;
        }

        // Check Sudoku rules
        if (checkMove(row, col, num))
        {
            board[row][col] = num;
            printf("Correct move!\n");
        }
        else
        {
            printf("Invalid move! Try again.\n");
        }
    }

    displayBoard();

    printf("\nCONGRATULATIONS!\n");
    printf("You have successfully completed Sudoku!\n");

    return 0;
}
