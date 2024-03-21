// inclusion guards
#ifndef HANGMAN_LIB_H
#define HANGMAN_LIB_H

// header files
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// global constants
#define FRUITS_LEN 104
#define ATTEMPTS 6
#define MAX_FRUIT_SIZE 25
extern const char* FRUITS[104];

// function prototypes

void initializeRandom();


/**
 * Function: getSecretWord()
 * Process: randomly generates an index between zero and the length of the 
 *      array of FRUITS. Then, selects the appropriate secret word (based on
 *      the index) and attribute the fruit name to the output parameter
 * Input data (parameter): none
 * Output data (return): size – indicates the length of the selected secret
 *      word. For example, if the selected word is yuzu, the function returns
 *      4; if the selected word is grapefruit, the function returns 10.
 * Output data (parameter): secret_word
 * Dependencies: srand, rand, strlen
 **/

int getSecretWord(char secretWord[]);
    
/*
   Function: buildOutputArray()
   Process: creates an output array with blank spaces that are
  shown to the user as the first tip. The output array 
  must be the same size as the secret word and contain 
  one underscore character for each position. For 
  example, if the secret word is “yuzu”, the output 
  array will be = {‘_’, ‘_’, ‘_’, ‘_’}.
   Input data (parameter): size – the length of the secret_word
   Output data (return): void
   Output data (parameter): output_array – contains the array 
  filled with the correct number of underscores.
   Dependencies: none
*/
void buildOutputArray(int size, char outputArray[]);

/*
   Function: buildAttemptArray()
   Process: creates an array with 6 positions to store the 
  user’s incorrect guesses.
   Input data (parameter): none
   Output data (return): void
   Output data (parameter): attempts – array of characters of 
  length 6, filled with a star (‘*’)character in each
  position. The star represents that the no guesses 
  were made yet.
   Dependencies: none
*/
void buildAttemptArray(char attempts[]);

/*
   Function: checkGuess()
   Process: given a letter and a secret word, returns TRUE (1) if the letter is in the secret word and FALSE (0) otherwise.
   Input data (parameter): guess – a character guessed by the 
user
secret_word – string literal that represent the secret word
   Output data (return): TRUE/FALSE depending on whether the 
letter is in the secret word
   Output data (parameter): none
   Dependencies: strlen
*/
bool checkGuess(char guess, const char* secretWord);

/*
   Function: fillOutputArray()
   Process: for each letter in the secret word, verifies whether 
  the letter is the user guess. If it is, replace the 
  underscore `_` in the output array with the letter. 
  For example, if the user guesses ‘u’ and the secret 
  word is `yuzu`, then the output array should become
  {‘_’,’u’,’_’,’u’}.
   Input data (parameter): guess – the user’s correct guess
          secret_word – string literal with the secret word
  output_array – array with the underscores.
   Output data (return): TRUE (1) if any underscore is replaced 
  with the guessed letter. FALSE (0) if the guessed 
  letter was already filled (repeated guess).
   Output data (parameter): output_array – array with underscores replaced with the guessed letter in the correct indexes.
   Dependencies: strlen
*/
bool fillOutputArray(char guess, const char* secretWord, char outputArray[]);

/*
   Function: fillAttemptsArray()
   Process: replaces the next star (*) in the attempt array with 
  a letter that represents a wrong guess from the 
  user. For example, if the secret word is “yuzu” and 
  the first user guess ia ‘a’, the attempts array 
  should become {‘a’, ‘*’, ‘*’, ‘*’}.
   Input data (parameter): guess – the user’s incorrect guess
   Output data (return): TRUE (1) if a * is replaced with the 
  guessed letter. FALSE (0) if the guessed letter is 
  already in the attempt array (repeated guess).
   Output data (parameter): attempts – attempt array with a star 
  replaced with the guessed letter.
   Dependencies: none
*/
bool fillAttemptsArray(char guess, char* attempts);

/*
   Function: checkVictory()
   Process: check whether the output array is completely filled 
  with letters (no underscores).
   Input data (parameter): output_array – the array filled with 
  underscores or the correct guesses
  size – the length of the output_array
   Output data (return): TRUE (1) if the output array is 
  completely filled with letters (no underscore).
  FALSE (0) if there is at least one underscore in the
  output array.
   Output data (parameter): none
   Dependencies: none
*/
bool checkVictory(char outputArray[], int size);

/*
   Function: checkDefeat()
   Process: check whether the attempts array is completely 
  filled with letters (no stars).
   Input data (parameter): attempts – the array filled with 
  stars (‘*’) or the incorrect guesses
   Output data (return): TRUE (1) if the attempts array is 
  completely filled with letters (no stars).
  FALSE (0) if there is at least one star (‘*’) in the
  attempts array.
   Output data (parameter): none
   Dependencies: none
*/
bool checkDefeat(const char* attempts);

/*
   Function: play()
   Process: controls the game. Generates a secret word, creates 
  the array of attempts, creates the output array, and 
  asks for the user guesses. For each guess, the
  function decides whether the letter is in the secret
  word or not. If the letter is in the secret word, it
  fills the output array, print it out, and check if
  the user won. If the letter is an incorrect guess, 
  it fills the attempts array, prints it out and check
  if the user lost. If the user lost, print out the 
  secret word. The user must be notified in case 
  of repeated guesses (correct or incorrect) and
  prompted for another guess.
   Input data (parameter): none
   Output data (return): TRUE (1) if the user wins. FALSE (0) if 
  the user looses.
   Output data (parameter): none
   Dependencies: getSecretWord, buildOutputArray, 
  buildAttemptsArray, checkGuess, fillOutputArray, 
  fillAttemptsArray, checkVictory, checkDefeat, 
  printf, scanf
*/
bool play(bool *giveup);

#endif