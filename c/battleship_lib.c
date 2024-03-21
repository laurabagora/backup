#include "battleship_lib.h"

// Function to print a 2D matrix
void printMatrix(const char matrix[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to build a 10x10 board filled with a character 'c'
void buildBoard(char board[SIZE][SIZE], char c)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            board[i][j] = c;
        }
    }
}

// Function to check if a position contains water in the board
bool isWater(const char board[SIZE][SIZE], int row, int col)
{
    // Check if the position row, col is out of bounds
    if (row < 0 || row >= 10 || row < 0 || row >= 10)
    {
        return false;
    }

    // Check if the character at position row, col is '0' (water)
    if (board[row][col] == '0')
    {
        return true;
    }

    return false;
}

// function to seed the random number generator
void initializeRandom()
{
    srand(time(NULL));
}

// Function to generate a random horizontal position for a ship of given length
void placeShipHorizontal(
    char board[SIZE][SIZE], int shipLength)
{
    // Flag to check if a valid position is found
    bool valid = false;
    int row, col, i = 0;

    while (!valid)
    {
        // Generate a random row
        row = rand() % SIZE;
        // Generate a random column within valid range
        col = rand() % (SIZE - shipLength + 1);

        // Check if there's enough space horizontally to place the ship
        valid = 1;
        i = 0;
        while (i < shipLength && valid)
        {
            if (board[row][col + i] != '0')
            {
                valid = false;
            }
            i++;
        }

        // If the position is valid, update position and continue the loop
        if (valid)
        {
            // place the ship
            for (i = 0; i < shipLength; i++)
            {
                // Cast ship length to char and add to the board
                board[row][col + i] = (char)(shipLength + '0');
            }
        }
    }
}

// Function to generate a random vertical position for a ship of given length
void placeShipVertical(char board[SIZE][SIZE], int shipLength)
{
    // Flag to check if a valid position is found
    bool valid = false;
    int row, col, i = 0;

    while (!valid)
    {
        // Generate a random row within valid range
        row = rand() % (SIZE - shipLength + 1);
        // Generate a random column
        col = rand() % SIZE;

        // Check if there's enough space vertically to place the ship
        valid = true;
        i = 0;
        while (i < shipLength && valid)
        {
            if (board[row + i][col] != '0')
            {
                valid = false;
            }
            i++;
        }

        // If the position is valid, update position and continue the loop
        if (valid)
        {
            for (int i = 0; i < shipLength; i++)
            {
                // Cast ship length to char and add to the board
                board[row + i][col] = (char)(shipLength + '0');
            }
        }
    }
}

void fillBoard(char board[SIZE][SIZE])
{
    int shipLengths[] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2};
    int shipLength, orientation;

    for (int i = 0; i < 10; i++)
    {
        shipLength = shipLengths[i];

        orientation = rand() % 2; // 0 for horizontal, 1 for vertical

        if (orientation == 0)
        {
            placeShipHorizontal(board, shipLength);
        }
        else
        {
            placeShipVertical(board, shipLength);
        }
    }
}

void shoot(
    const char solution[SIZE][SIZE], char game[SIZE][SIZE], int row, int col)
{
    if (solution[row][col] == '0')
    {
        // Water hit
        game[row][col] = 'W';
    }
    else if (solution[row][col] >= '2' && solution[row][col] <= '5')
    {
        // Ship hit
        game[row][col] = 'S';
    }
}

bool checkVictory(const char solution[SIZE][SIZE], const char game[SIZE][SIZE])
{
    int row, col;

    // Iterate through the board
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            // If a ship is present in the solution but not hit in the game board, return 0 (false)
            if (solution[row][col] >= '2' && 
                solution[row][col] <= '5' &&
                game[row][col] != 'S')
            {
                return false; // Not all ships are hit
            }
        }
    }

    // If all ships are hit, return Victory!
    return true;
}