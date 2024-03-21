#include "battleship_lib.h"


int main()
{

    char solution[SIZE][SIZE];
    char game[SIZE][SIZE];

    initializeRandom();

    // Part I - Setup
    buildBoard(solution, '0');
    buildBoard(game, '_');
    fillBoard(solution);

    printf("\nBattleship Game\n");
    printf("===============\n\n");

    printf("Game board:\n");
    printMatrix(game);

    // Part II - the game
    bool giveUp = false, win = false;
    int row, col;

    win = checkVictory(solution, game);
    while (!win && !giveUp)
    {
        printf(
            "Enter the ROW (0-9) where you want to shoot or -1 to give up: ");
        scanf("%d", &row);

        if (row == -1)
        {
            // User gave up
            giveUp = 1;
        }
        else if (row < 0 || row >= SIZE)
        {
            printf("Invalid input. Please enter a number between 0 and 9.\n");
        }
        else
        {
            printf(
                "Enter the COLUMN (0-9) where you want to shoot "
                "or -1 to give up: ");
            scanf("%d", &col);

            if (col == -1)
            {
                // User gave up
                giveUp = 1;
            }
            else if (col < 0 || col >= SIZE)
            {
                printf("Invalid input. Please enter a number between 0 and 9.\n");
            }
            else
            {
                shoot(solution, game, row, col);
                if (game[row][col] == 'S')
                {
                    printf("Ship!\n");
                }
                else
                {
                    printf("Miss!\n");
                }

                printf("Current game board:\n");
                printMatrix(game);

                win = checkVictory(solution, game);
                if (win)
                {
                    printf("Congratulations! You won!\n");
                }
            }
        }
    }

    if (giveUp)
    {
        printf("You gave up. Here is the solution board:\n");
        printMatrix(solution);
    }

    return 0;
}