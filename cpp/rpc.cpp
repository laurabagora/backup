#include <iostream>
using namespace std;

int main()
{
	// initialize variabes
	string play1, play2, again;
	int sum1 = 0, sum2 = 0;
	bool play = true;

	// loop through until player does not want to play anymore
	while(play)
	{
		// get input for player 1 and store into play1 
		cout << "Player 1: Please enter either (R)ock,";
		cout << " (P)aper, or (S)cissors: ";
		cin >> play1;

		// get input for player 2 and store into play2
		cout << "Player 2: Please enter either (R)ock,";
		cout << " (P)aper, or (S)cissors: ";
		cin >> play2;

		// change all uppercase letters to lowercase letters
			// first do the paper and set big P to small p
		if (play1 == "P" || play2 == "P")
		{
			play1 = "p";
		}
		// then do the rock and set big R to small r
		else if (play1 == "R" || play2 == "R")
		{
			play1 = "r";
		}
		// last do the scissors and set big S to small s
		else if (play1 == "S" || play2 == "S")
		{
			play1 = "s";
		}

		// check if player 1 beats player 2 through rps rules
		if ((play1 == "s" && play2 == "p") 
			|| (play1 == "p" && play2 == "r")
				|| (play1 == "r" && play2 == "s"))
		{
			// print statement and increment win
			cout << "\nPlayer 1 wins.\n\n";
			sum1 = sum1 + 1;
		}

		// check if player 2 beats player 1 through rps rules
		else if ((play2 == "s" && play1 == "p") 
				|| (play2 == "p" && play1 == "r")
					|| (play2 == "r" && play1 == "s"))
		{
			// print statement and increment win
			cout << "\nPlayer 2 wins.\n\n";
			sum2 = sum2 + 1;
		}

		// print out scores
		cout << "Scores after this play:\n";
		cout << "     Player 1: " << sum1;
		cout << "\n     Player 2: " << sum2;

		// print thanks and check if player wants to continue to play
		cout << "\n\nThanks!!\n\n";
		cout << "Play again? Y/y continues, other quits: ";
		cin >> again;

		// if player says yes then continue through loop
		if (again != "y" || again != "Y")
		{
			play = true;
		}
	}
	// done with loop so ends program
	return 0;
}
