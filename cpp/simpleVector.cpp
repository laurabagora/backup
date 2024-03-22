#include <iostream>
using namespace std;

// create the customer class (base class) and the template
template <class T>
class SimpleVector 
{
	private:
		// initialize variables
		T *ptrs;
		int size;

	public:

		// constructor without arguments
		SimpleVector():
			ptrs(nullptr), size(0)
		{}

		// constructor with only the size argument and creates new array
		SimpleVector(int new_size):
			ptrs(new T[new_size]), size(new_size)
		{}

		// copy constructor to take in new values
		SimpleVector(SimpleVector &news)
		{
			int index = 0;

			// set the size and new array
			size = news.size;
			ptrs = new T[size];

			// deep copy all data
			while (index < size)
			{
				// sets the information to the new index
				ptrs[index] = news.ptrs[index];

				// incremenet
				index++;
			}
		}

		// destructor, deallocates array and sets size to 0
		~SimpleVector()
		{
			delete[] ptrs;
			size = 0;
		}

		// accesor for the size
		int getSize()
		{
			return size;
		}

		// public method to get a certain position in array
		T &getElementAt(int pos)
		{
			return ptrs[pos];
		}

		// gets the overload operator for [] and return the element
		T operator [] (int pos)
		{
			// return the element
			return getElementAt(pos);
		}
};

// declaration
template <class T>
void inputData(SimpleVector<T> &arrays);

template <class T>
void retreiveData(SimpleVector<T> &arrays);

template <class T>
void displayData(SimpleVector<T> &arrays);


int main()
{
	// initialize variables
	int type, inputs;
	char choose = 'y';
	SimpleVector<int> intArray;
	SimpleVector<double> doubleArray;
	SimpleVector<string> stringArray;

	// check to make sure the user wants to enter data
	while(choose == 'y')
	{
		// get the user input for data type
		cout << "What type of data do you want to enter (1 for integer"
								<< ", 2 for double and 3 for strings):\n";
		cin >> type;

		// get the user input for how many inputs
		cout << "how many data inputs do you have?\n";
		cin >> inputs;

		// check which type
		if (type == 1)
		{
			// set the int array by copying data over
			intArray = SimpleVector<int>(inputs);

			// put the data into the array
			inputData(intArray);

			// get the data from a certain input in the array
			retreiveData(intArray);

			// display the entire array
			displayData(intArray);
		}
		else if (type == 2)
		{
			// set the int array and coppying that data over
			doubleArray = SimpleVector<double>(inputs);

			// put the data into the array
			inputData(doubleArray);

			// get the data from a certain input in the array
			retreiveData(doubleArray);

			// display the entire array
			displayData(doubleArray);
		}
		else if (type == 3)
		{
			// set the int array and copying that data over
			stringArray = SimpleVector<string>(inputs);

			// put the data into the array
			inputData(stringArray);

			// get the data from a certain input in the array
			retreiveData(stringArray);

			// display the entire array
			displayData(stringArray);
		}

		// ask if they want to do it again
		cout << "\nDo you want to enter the data again? (y/n): ";
		cin >> choose;
	}

	// they did not choose to do go again so end program
	return 0;
}

// supporting functions
template <class T>
void inputData(SimpleVector<T> &arrays)
{
	// initalize variables
	int index;
	T type;

	// loop through the array
	for (index = 0; index < arrays.getSize(); index++)
	{
		// get the user input
		cout << "Enter data at index " << index << ": ";
		cin >> type;

		// using the getElementAt class to get the value
		arrays.getElementAt(index) = type;
	}
}
template <class T>
void retreiveData(SimpleVector<T> &arrays)
{
	// initalize variables
    int index;
    T data;

    // get the user input for the index
    cout << "Enter an index to retrieve the data from: ";
    cin >> index;

    // Retrieve data at the specified index using getElementAt method
    data = arrays[index];

    // Print the retrieved data
    cout << "Retrieved data from index " << index << " is: " << data;

}

template <class T>
void displayData(SimpleVector<T> &arrays)
{
	// initalize variables
	int index;

	// diaplay the data
	cout << "\nDisplaying data\n";

	// loop trhough array to display data
	for (index = 0; index < arrays.getSize(); index++)
	{
		// using the [] operator
		cout << arrays[index] << " ";
	}
}