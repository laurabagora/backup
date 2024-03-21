// header files
#include "hangman_lib.h"

// main function
int main()
{

    // initialize program
        // print out a title for the program
            // function: puts
    puts("***************************");
    puts("Welcome to the Hangman Game");
    puts("***************************");

        // initialize the random number generator
            // function: initializeRandom
    initializeRandom();

        // declare a variable for the new round
    char newRound = 'y';
        // declare a variable to store the round result
    bool roundResult;
        // declare a pointer variable to store the giveup
    bool giveup = false;

    // gameplay
        // begin loop to control the round
    do
    {
        // call the play function
            // function: play
        roundResult = play(&giveup);
        
        // if the user give up
        if (giveup == true)
        {
            // inform the user
                // function: puts
            puts("You gave up!");
            // set the variable that ends the program
            newRound = 'n';
        }
        // otherwise
        else
        {
            // check if the play function returned true
            if (roundResult == true)
            {
                // inform the user
                    // function: puts
                puts("You won the round! Well done!");
            }
            // otherwise
            else
            {
                // inform the user
                    // function: puts
                puts("You lost the round!");
            }
        
            // ask if the user wants to play another round
                // function: puts
            puts("\nDo you want to play a new round? [y|n]");
            // read the user's choice
                // function: scanf
            scanf(" %c", &newRound);
            // convert the option to lowercase letter
                // function: tolower
            newRound = tolower(newRound);
        // validate the user's option
            // while it is not y or n
            while ((newRound != 'y') && (newRound != 'n'))
            {
                // inform the user
                    // function: puts
                puts("I didn't get that. Please use y to yes and n to no.");
                // prompt again
                    // function: puts
                puts("Do you want to play a new round? [y|n]");
                // read the user option
                    // function: scanf
                scanf(" %c", &newRound);
                // convert to lowercase letter
                    // function: tolower
                newRound = tolower(newRound);
            }
        }
    }
    // repeat while the user wants to play a new round
    while (newRound == 'y');
    // end program
        // print an ending message
            // function: puts
    puts("Come back another time!");
        // return success
    return 0;
}