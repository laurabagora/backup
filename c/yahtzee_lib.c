#include "yahtzee_lib.h"

void initializePlayer()
{
	// initalize random number generator
		// functions: srand, time
    srand(time(NULL));
}

char getChoice()
{
	char choice;
	scanf(" %c", &choice);
    // convert choice to lower case
    	// function: tolower
    choice = tolower(choice);
    while (choice != 'y' && choice != 'n')
        {
            printf("Invalid option. Please type 'y' to play"
                " or 'n' to exit: ");
            scanf(" %c", &choice);
            choice = tolower(choice);
        }
    return choice;
}

int rollDice()
{
	// generate the random number and constraint within range (1-6)
        // function: rand
	return rand() % NUM_SIDES + 1;
}

int countNumber(
	int number, int dice1, int dice2, int dice3, int dice4, int dice5)
{
	int count = 0;
	if (dice1 == number)
	{
        count++;
	}
	if (dice2 == number)
	{
		count++;
	}
	if (dice3 == number)
	{
		count++;
	}
	if (dice4 == number)
	{
		count++;
	}
	if (dice5 == number)
	{
		count++;
	}
	return count;
}

bool isYahtzee(int dice1, int dice2, int dice3, int dice4, int dice5)
{
	if (dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5)
	{
		return true;
	}
	return false;
}

bool isFourOfAKind(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	if (count1 == 4 || count2 == 4 || count3 == 4 ||
                count4 == 4 || count5 == 4 || count6 == 4)
    {
    	// found a four of a kind
    	return true;
    }
	return false;
}

bool hasTwoEqual(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	if (count1 == 2 || count2 == 2 || count3 == 2 ||
                count4 == 2 || count5 == 2 || count6 == 2)
    {
    	return true;
    }
    return false;

}
bool hasThreeEqual(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	if (count1 == 3 || count2 == 3 || count3 == 3 ||
                count4 == 3 || count5 == 3 || count6 == 3)
    {
    	return true;
    }
    return false;
}

bool isThreeOfAKind(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	bool threeEqual = hasThreeEqual(
		count1, count2, count3, count4, count5, count6);

	bool twoEqual = hasTwoEqual(
		count1, count2, count3, count4, count5, count6);

	if (threeEqual == true && twoEqual == false)
	{
		return true;
	}
	return false;
}

bool isFullHouse(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	bool threeEqual = hasThreeEqual(
		count1, count2, count3, count4, count5, count6);

	bool twoEqual = hasTwoEqual(
		count1, count2, count3, count4, count5, count6);

	if ( threeEqual == true && twoEqual == true)
	{
		return true;
	}
	return false;
}

bool isLargeStraight(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	if ((count1 != 0 && count2 != 0 && count3 != 0 &&
         count4 != 0 && count5 != 0) || // 1-5
        (count2 != 0 && count3 != 0 && count4 != 0 &&
         count5 != 0 && count6 != 0)) // 2-6
	{
		return true;
	}
	return false;

}

bool isSmallStraight(
	int count1, int count2, int count3, int count4, int count5, int count6)
{
	if ((count1 != 0 && count2 != 0 && count3 != 0 && count4 != 0) ||
    	(count2 != 0 && count3 != 0 && count4 != 0 && count5 != 0) ||
    	(count3 != 0 && count4 != 0 && count5 != 0 && count6 != 0))
	{
		return true;
	}
	return false;
}

int decidePlay(int dice1, int dice2, int dice3, int dice4, int dice5) {
	// Check for Yahtzee (all dice showing the same value)
    	// function: isYahtzee
	if(isYahtzee(dice1, dice2, dice3, dice4, dice5) == true)
	{
		return YAHTZEE;
	}
    else
    {
    	// count ones
        int count1 = countNumber(1, dice1, dice2, dice3, dice4, dice5);
        // count twos
        int count2 = countNumber(2, dice1, dice2, dice3, dice4, dice5);
        // count threes
        int count3 = countNumber(3, dice1, dice2, dice3, dice4, dice5);
        // count fours
        int count4 = countNumber(4, dice1, dice2, dice3, dice4, dice5);
        // count fives
        int count5 = countNumber(5, dice1, dice2, dice3, dice4, dice5);
        // count sixes
        int count6 = countNumber(6, dice1, dice2, dice3, dice4, dice5);
	    
	    if (isFourOfAKind(
	    	count1, count2, count3, count4, count5, count6) == true)
	    {
	        return FOUR_OF_A_KIND;
	    }
	    else if (isThreeOfAKind(
	    	count1, count2, count3, count4, count5, count6) == true)
	    {
	        return THREE_OF_A_KIND;
	    }
	    else if (isFullHouse(
	    	count1, count2, count3, count4, count5, count6) == true)
	    {
	        return FULL_HOUSE;
	    }
	    else if (isLargeStraight(
	    	count1, count2, count3, count4, count5, count6) == true)
	    {
	        return L_STRAIGHT;
	    }
	    else if (isSmallStraight(
	    	count1, count2, count3, count4, count5, count6) == true)
	    {
	        return S_STRAIGHT;
	    }
	    else
	    {
	        return NO_PLAY;
	    }
	}
	return NO_PLAY;
}