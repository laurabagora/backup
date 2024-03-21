# Imports
from random import *

# Main function
def main():
    max = 100
    # Print Haiku at beginning of game
    print('Welcome to this task')
    print('Guessing numbers one by one')
    print('Let the game begin\n')

    # Variables for while loops, including guesses, total guesses, and best game
    game_count = 0
    total_count = 0
    best = 696969
    again = 'y'
    
    # Runs and reruns through game when called
    # All variations of yes will be shown with the start of 'Y' whether uppercase or lowercase
    while again[0].upper() == 'Y':
        count = game(max)
        again = input("Do you want to play again? ")
        game_count += 1
        total_count += count
        print()
        
        # Goes to results when needed and calculates best game
        if count < best:
            best = count
    results(best, total_count, game_count)
    
# Playing the actual game

def game(max):
    max = 100
    # Counting the number of guesses 
    count = 0

    # Start of game
    print("I'm thinking of a number between 1 and " +  str(max) + "...")

    # Random numbers and setting up guesses
    rando = randint(1,max)
    guess = int(input('Your guess? '))
    count += 1
    
    # Midst of game, whether user needs to guess higher or lower
    while rando != guess:
        
        if rando < guess:
            print("It's lower")
            guess = int(input('Your guess? '))
            count += 1

        else:
            print("It's higher.")
            guess = int(input('Your guess? '))
            count += 1
            
    # When user guesses the right number
    print("You got it right in " + str(count) + " guesses!")

    # Return to either results or to new game
    return count

# Results of Game
def results(best, total_count, game_count):
    print("Overall results:")
    print("Total games   = " + str(game_count))
    print("Total guesses = " + str(total_count))
    
    # Finding the guesses to game ratio and printing best game
    guess_game = round(total_count/game_count, 1)
    print("Guesses/game  = " + str(guess_game))
    print('Best game     = ' + str(best))


# Calling main back
main()
