#include <iostream>
#include <ctime>
using namespace std;

// inititalize constants
const int LIST_SIZE = 5;
const int BOX_SIZE = 3;

// create static
static int totalBoxes();

// create the produce class
class produce 
{
	private:
		// initialize variables
		string product;

	public:

		// constructor
		produce()
		{
			product = " ";
		}

		// set the mutators
		void setProduct(string &news)
		{
			product = news;
		}

		// set the accessors
		string getProduct()
		{
			return product;
		}

		// function declarations
		void outputs(string newList[BOX_SIZE]);

};

int main()
{
	// initialize time
	srand(time(0));

	// initalize variables
	string again = "yes";
	int random, index;
	string choice, sub;
	produce boxes;

	// initalize lists
	string productList[LIST_SIZE] =
			 ["Broccoli", "Tomato", "Kiwi", "Kale", "Tomatillo"];
	string newList[BOX_SIZE];

	// set the loop to go again if the user says yes
	while(again == "yes")
	{
		// output the contents of the box
		cout << "\nThe contents of  box " << totalBoxes()/2 << ":\n";

		// grab three random items from the box
		for(index = 0; index < BOX_SIZE; index++)
		{
			// get the ndom value and grab it from the list
			random = rand() % LIST_SIZE;

			//boxes.setProduct(productList[random]);
			newList[index] = productList[random];
		}
		// print the box
		boxes.outputs( newList);

		// subsitutions
		cout << "\nHere are the following subsitution options:\n";
		cout << "Broccoli, Tomato, Kiwi, Kale, or Tomatillo?\n\n";

		// loop through box
		for(index = 0; index < BOX_SIZE; index++)
			{
			cout << "Would you like to subsitute item " << index+1;
			cout <<" with any of these items (yes/no): "; 
			getline(cin, choice);

			// if user wants to subtitute then do this
			if (choice == "yes")
			{
				// get the subsitution item
				cout << "What would you like to subsitute this item with: ";
				getline(cin, sub);

				// switch out
				newList[index] = sub;
			}
		}

		// print the final contents	
		cout << "\nThe finals contents of  box " << totalBoxes() / 2<< ":\n";
		boxes.outputs(newList);

		// increment the total number of boxes
		totalBoxes();

		// ask if user wants to enter again
		cout << "Do you want another box (yes/no)? ";
		getline(cin, again);
	}

	// end of program
	return 0;
}

// supporting functions
void produce::outputs(string newList[BOX_SIZE])
{
	// loop through box
	for(int index = 0; index < BOX_SIZE; index++)
	{
	// print out the product list
	cout << "Item " << index + 1 << ": "
				              << newList[index] << "\n";
	}
}

int totalBoxes()
{
	// get the static int and increment it
	static int totalBoxesCount = 1;
	return totalBoxesCount++;
}
