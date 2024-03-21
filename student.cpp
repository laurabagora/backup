#include <iostream>
using namespace std;

// inititalize constants
const int MAX_LIST_SIZE = 50;

// create the student class
class student 
{
	private:
		// initialize variables
		string name;
		int numClasses;
		string classList[MAX_LIST_SIZE];

	public:
		// constructor
		student()
		{
			name = " ";
			numClasses = 0;
		}

		// set the mutators
		void setName()
		{
			getline(cin, name);
		}
		void setNumClasses()
		{
			cin >> numClasses;
			cin.ignore();
		}
		void setClassList()
		{
			// initialize variables
			int index;
        	//classList =  new string[numClasses];
        	for (index = 0; index < numClasses; index++) 
        	{
            	cout << "Enter the name of class " 
            						<< index + 1 << ": ";
            	getline(cin, classList[index]);
            }
         }

		// set the accessors
		string getName()
		{
			return name;
		}
		int getNumClasses() 
		{
			return numClasses;
		}
		const string *getClassList()
		{
			return classList;
		}

		// function declarations
		void inputs();
		void outputs();
		void resets();

};

int main()
{
	// initialize variabes
	string again = "y";
	student students;

	// loop through until user says no
	while (again == "y")
	{
		// ask for the user input
		students.inputs();
		students.outputs();

		// ask to enter again (y/n)
		cout << "Do you want to enter the data again (y/n)? ";
		getline(cin, again);

		// reset data if user wants to go again
		if (again == "y")
		{
			students.resets();
		}
	}

	// end of program
	return 0;
}

// supporting functions
void student::inputs()
{
	// get the input for student name
	cout << "Enter the student's name: ";
	setName();

	// get the input for the number of classes
	cout << "Enter the number of classes: ";
	setNumClasses();

	// get the input for the class list
	setClassList();
}

void student::outputs()
{
	// initiliae variables
	int index; 

	// output the names
	cout << "\nThe student's name is:  " << getName() << "\n";

	// output the number of classes
	cout << "The number of classes are: " 
			<< getNumClasses() << "\n";

	// output the class list
	cout << "The classes are listed below\n";
	for (index = 0; index < numClasses; index++)
	{
		// print out the class list
		cout << "Class " << index + 1 << ": "
					 << getClassList()[index] << "\n";
	}
}

void student::resets()
{
	// reset the name
	name = " ";

	// reset the number of classes
	numClasses = 0;

}
