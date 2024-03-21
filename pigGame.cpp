#include <iostream>
#include <cstdlib>
using namespace std;

// constants
const int MAX = 6;
const int MIN = 2;
const int CAP = 100;
const int TURN_CAP = 20;

// function prototypes
int computerTurn(int computerTotalScore);
int humanTurn(int humanTotalScore);
int rollDice();

int main()
{
	// initialize variabes
	srand(time(NULL));
	int humanTotalScore = 0, computerTotalScore = 0;
	bool play = true;


	// go through until cap is met
	while(play)
	{
		// have the human go first
		humanTotalScore = humanTurn(humanTotalScore);

		// check to make sure cap was not met
		if (humanTotalScore > CAP || computerTotalScore > CAP)
		{
			// if it is then end loop
			play = false;
		}
		// if not then go to computer
		else
		{
			computerTotalScore = computerTurn(computerTotalScore);
		}
    }

    // if human won then print statement
    if (humanTotalScore > CAP)
    {
    	cout << "\nYou Win!!";
    }

    // if computer won then print statement
    else
    {
    	cout << "\nComputer Wins :(";
    }

	// done with loop so ends program
	return 0;
}

int computerTurn(int computerTotalScore)
{
	// initialize variables
	string decision;
	int roll, compSum = 0;
	bool hold = true;

	// keep computers turns unless hold 
	while(hold)
	{
		// roll the dice to get the random number
		roll = rollDice();

		cout << "\n\nThe computer rolled a: " << roll;

		// check if roll is not 1, then end turn
		if(roll == 1)
		{
			hold = false;
		}
		else
		{		
			// add the roll to the total
			compSum = compSum + roll;
			computerTotalScore = computerTotalScore + roll;

			// print out what is going on
			cout << "\nThe computers overall total is: "<<computerTotalScore;
		}
		// check if sum is less than 20
		if(compSum >= TURN_CAP)
		{
			// if not then stop rolling
			cout << "\nMax of 20 was hit this roll";
			hold = false;
		}
		// check if sum is less than 100
		if(computerTotalScore >= CAP)
		{
			// if not then stop rolling
			hold = false;
		}
	}
	return computerTotalScore;
}

int humanTurn(int humanTotalScore)
{
	// initialize variables
	string decision;
	int roll, humanSum = 0;
	bool hold = true;

	// keep computers turns unless hold 
	while(hold)
	{
		// roll the dice to get the random number
		roll = rollDice();

		cout << "\n\nYou rolled a: " << roll;

		// check if roll is not 1, then end turn
		if(roll == 1)
		{
			hold = false;
		}
		else
		{		
			// add the roll to the total
			humanSum = humanSum + roll;
			humanTotalScore = humanTotalScore + roll;

			// print out what is going on
			cout << "\nYour overall total is: "<< humanTotalScore;
		}
		// check if sum is less than 100
		if(humanTotalScore >= CAP)
		{
			// if not then stop rolling
			hold = false;
		}
		// check if sum is less than 20
		else if(humanSum >= TURN_CAP)
		{
			// if not then stop rolling
			cout << "\nMax of 20 was hit this roll";
			hold = false;
		}
		else
		{
			// check if player wants to roll again or hold
			cout << "\nInput ‘r’ (or ‘R’) to";
			cout << " roll again or ‘h’ (or ‘H’) to hold: ";
			cin >> decision;

			// if the player holds then end loop and go back to main
			if (decision == "h" || decision == "H")
			{
				hold = false;
			}
		}		
	}
	return humanTotalScore;
}

int rollDice()
{
	// rolls a random side of the dice
	return ((rand() % MAX - MIN + 1) + MIN);
}		