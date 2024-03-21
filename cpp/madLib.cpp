#include <iostream>
using namespace std;

int main()
{
	// initialize variabes
	string teach, name, food, adj, color, animal;
	int num;

	// get input for instructor and store into teach 
	cout << "Enter your instructor's first or last name: ";
	cin >> teach;

	// get your input for name and store into name 
	cout << "Enter your name: ";
	cin >> name;

	// get input for food item and store into food 
	cout << "Enter a food item: ";
	cin >> food;

	// get input for a number and store into num 
	cout << "Enter a number between 100 and 120: ";
	cin >> num;

	// get input for adjective and store into adj 
	cout << "Enter an adjective: ";
	cin >> adj;

	// get input for color and store into color 
	cout << "Enter a color: ";
	cin >> color;

	// get input for animal and store into animal 
	cout << "Enter an animal: ";
	cin >> animal;

	// insert input for the professor followed by strings
	cout << "Dear Professor " << teach << ", \n\n";
	cout << "I am sorry that I am unable to turn ";
	cout << "my homework at this time.\n";

	// insert input for the food followed by strings
	cout << "First, I ate a rotten " << food << " which made";

	// insert input for the color followed by strings
	cout << " me turn " << color << " and\n";

	// insert input for the number followed by strings
	cout << "extremely ill. I came down with a fever of " << num << ".\n";

	// insert input for the adjective followed by strings
	cout << "Next, my " << adj << " pet ";

	// insert input for the animal followed by strings
	cout << animal << " must have ";
	cout << "smelled the remains\n";

	// insert input for the food followed by strings
	cout << "of the " << food << " on my ";
	cout << "homework, because he ate it. I am currently\n";
	cout << "rewriting my homework and I hope you will accept it late.\n\n";

	// insert input for the name followed by strings
	cout << "Sincerly,\n" << name << endl;

	return 0;
}

