// header files
#include "hangman_lib.h"

// constant FRUITS
const char* FRUITS[104] = {"abiu",  "açaí", "acerola", "akebi", "ackee", 
    "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry",
    "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel",
    "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut",
    "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian",
    "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin",
    "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia",
    "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit",
    "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo",
    "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe",
    "galia", "melon", "honeydew", "watermelon", "mulberry", "nance",
    "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya",
    "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum", 
    "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate",
    "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant",
    "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry",
    "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};


void initializeRandom()
{
    // Initialization, should only be called once
        // function: srand, time
    srand(time(NULL));
}


int getSecretWord(char secretWord[])
{
    //generates the numbers [0-103]
        // function: rand
    int index = rand() % FRUITS_LEN;
    // copy the fruit into the secretword
        // function: strcpy
    strcpy(secretWord, FRUITS[index]);
    // get the size of the secretword
        // function: strlen
    int size = strlen(secretWord);
    // return the size
    return size;
}


void buildOutputArray(int size, char outputArray[])
{
    // for each character, except the last one
    for (int i = 0; i < size-1; i++)
    {
        // fill in with underscore
        outputArray[i] = '_';
    }
    // set the last space with \0
    outputArray[size-1] = '\0';
}


void buildAttemptArray(char* attempts)
{
    // for each position in the array
    for (int i = 0; i < ATTEMPTS; i++)
    {
        // set the array to *
        attempts[i] = '*';
    }
    // set the last position to \0
    attempts[ATTEMPTS] = '\0';
}


bool checkGuess(char guess, const char* secretWord)
{
    // for each letter in the secret word
        // function: strlen
    for (int i = 0; i < strlen(secretWord); i++)
    {
        //if letter is in the secret word
        if (secretWord[i] == guess)
        {
            // return true
            return true;
        }
    }
    // otherwise, return false
    return false;
}


bool fillOutputArray(char guess, const char* secretWord, char outputArray[])
{
    // assume that the guess is duplicated
    int newGuess = false;
    // for each letter in the secret word
        // function: strlen
    for (int i = 0; i < strlen(secretWord); i++)
    {
        //if letter is the guess
        if (secretWord[i] == guess)
        {
            // if the corresponding position is empty in the output array
            if (outputArray[i] == '_')
            {
                // it is a new guess
                newGuess = true;
                // set the position in the output array to guess
                outputArray[i] = guess;
            }
        }
    }
    // return the newguess
    return newGuess;
}


bool fillAttemptsArray(char guess, char* attempts)
{
    // declare variables
    int i = 0;
    // while it is not the end of the array
        // function: strlen
    while(i < strlen(attempts))
    {
        // if the position in the attempts array is the guess
        if (attempts[i] == guess)
        {
            // repeated guess
            return false;
        }
        // if the position in the attempts array is a star
        if (attempts[i] == '*')
        {
            // fill in the position with the guess
            attempts[i] = guess;
            // array successfully filled
            return true;
        }
        // otherwise, move to the next position
        i++;
    }
    // something went wrong
    return false;
}


bool checkVictory(char outputArray[], int size)
{
    // for each position of the output array
    for (int i = 0; i < size; i++)
    {
        // if the position is empty
        if (outputArray[i] == '_')
        {
            // the user didn't win
            return false;
        }
    }
    // otherwise, the user won
    return true;
}


bool checkDefeat(const char* attempts)
{
    // for each position in the attempts array
        // function: strlen
    for (int i = 0; i < strlen(attempts); i++)
    {
        // if the position is a star
        if (attempts[i] == '*')
        {
            // the user didn't lose
            return false;
        }
    }
    // the user lost
    return true;
}


bool play(bool *giveup)
{
    // delcare the variable for the secretWord
    char secretWord[MAX_FRUIT_SIZE];
    // get a new secret word
        // function: getSecretWord
    int sizeSecretWord = getSecretWord(secretWord);
    // declare the attempts array
    char attempts[ATTEMPTS+1];
    // build the attempts array
        // function: buildAttemptArray
    buildAttemptArray(attempts);
    // declare the output array
    char outputArray[sizeSecretWord];
    // build the output array with an extra position
        // function: buildOutputArray
    buildOutputArray(sizeSecretWord + 1, outputArray);
    // declare supporting variables
    char guess;
    bool found, newLetter = true, won, lost;
    // begin the round
    do
    {
        //take the user's guess
            // function: puts
        puts("\nWhich letter? (0 to exit the game): ");
        // read the guess
            // function: scanf
        scanf(" %c", &guess);
        // set the guess to lower case
            // function: tolower
        guess = tolower(guess);
        // if the user types zero
        if (guess == '0')
        {
            // the user gave up
            *giveup = true;
            // set lost to true
            lost = true;
        }
        // otherwise, it is a non-zero value
        else
        {
            // the user did not give up
            *giveup = false;
            // check if the guess is in the secret word
                // function: checkGuess
            found = checkGuess(guess, secretWord);

            // If the letter is in the secret word
            if (found)
            {
                //it fills the output array
                    // function: fillOutputArray
                newLetter = fillOutputArray(guess, secretWord, outputArray);

                // if it is not a new guess
                if (newLetter == false)
                {
                    // inform the user
                        // function: puts
                    puts("Repeated guess. Try another letter!");
                }
                // otherwise
                else
                {
                    // print it out
                        // function: puts
                    puts(outputArray);
                    // and check if the user won
                        // function: checkVictory
                    if (checkVictory(outputArray, sizeSecretWord))
                    {
                        // end the function if the user won
                        won = true;
                    }
                }
            }
            // the letter is not in the secret word
            else
            {
                // inform the user
                    // function: puts
                puts("The letter doesn't exist in the word.");
                // it fills the attempts array
                    // function: fillAttemptsArray
                newLetter = fillAttemptsArray(guess, attempts);
                // if it's a repeated guess
                if (newLetter == false)
                {
                    // inform the user
                        // function: puts
                    puts("Repeated guess. Try another letter!");
                }
                // otherwise
                else
                {
                    // start the message for printing the array
                        // function: printf
                    printf("Mistakes: ");
                    // print the array
                        // function: puts
                    puts(attempts);
                    // and check if the user lost
                        // function: checkDefeat
                    if (checkDefeat(attempts))
                    {
                        //If the user lost, print out the secret word.
                            // function: printf
                        printf("The secret word was: ");
                        // print the secret word array
                            // function: puts
                        puts(secretWord);
                        // end the function because the user lost
                        lost = true;
                    }
                }
            }
        }
    }
    // repeat while the exit is false
    while(!won && !lost);

    // if the user won
    if (won)
    {
        // return true
        return true;
    }
    // if the user gave up or lost
    else
    {
        // return false
        return false;
    }
}