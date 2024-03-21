#include <iostream>
using namespace std;

// initalize constants
const char NULL_VALUE = '\0';
const int MAX = 100;

int main()
{
	// initialize variabes
	char original[MAX], *head, *tail, temp;
	int length = 0;

	// get input for the string
	cout << "Enter a string to be reversed: ";
	cin >> original;

	// print the beginning of the output string
	cout << "\nThe reverse of " << original << " is: ";

	// loop through the array to get the length of the array
	while(original[length] != NULL_VALUE)
	{
		// incrememnert the length for each iteration
		length = length + 1;
	}

	// the head is pointed to the first character of the string
	head = original;

	// the tail is pointed to the last character of the string
	tail = original + length - 1;

	// loop through until the head and tail are swapped
	while (head < tail)
	{
		// swap the values
		temp = *head;
		*head = *tail;
		*tail = temp;

		// incremement the head, deincrement the tail
		head = head + 1;
		tail = tail - 1;
	}

	// finish the output string
	cout << original << "\n";

	return 0;
}

