#include <iostream>
using namespace std;

// inititalize constants

// create the ship class (base class)
class Ship 
{
	private:
		// initialize variables
		string name;
		int year;

	public:

		// default constructor
		Ship():
			name(""), year(0)
		{}

		// constructor with arguments
		Ship(string ship_name, int ship_year):
		
			name(ship_name), year(ship_year)
		{}

		// set the mutators
		void setName()
		{
			getline(cin, name);
		}
		void setYear()
		{
			cin >> year;
			cin.ignore();
		}

		// set the accessors
		string getName()
		{
			return name;
		}
		int getYear()
		{
			return year;
		}

		// first output
		void outputs(string name, int year);

};

// create the cruise ship class (first derived class)
class CruiseShip: public Ship
{
	private:
		// initialize variables
		int capacity;

	public:
		// default constructor
		CruiseShip():
			capacity(0)
		{}

		// constructor with arguments
		CruiseShip(string ship_name, int ship_year, int ship_capcity):
		
			Ship(ship_name, ship_year), capacity(ship_capcity)
		{}

		// set the mutators
		void setCapacity()
		{
			cin >> capacity;
			cin.ignore();
		}

		// set the accessors
		int getCapacity()
		{
			return capacity;
		}

		// function declarations
		void outputs(string name, int capacity);

};

// create the cargo ship class (second derived class)
class CargoShip: public Ship
{
private:
	// initalize variables
	int capacity;

public:
		// default constructor
		CargoShip():
			capacity(0)
		{}
		
		// constructor with arguments
		CargoShip(string ship_name, int ship_year, int ship_capcity):
		
			Ship(ship_name, ship_year), capacity(ship_capcity)
		{}

		// set the mutators
		void setCapacity()
		{
			cin >> capacity;
			cin.ignore();
		}

		// set the accessors
		int getCapacity()
		{
			return capacity;
		}

		// override output
		void outputs(string name, int capacity);
};

int main()
{
	// initialzie variables
	string arg_cargo_name, arg_name, arg_cruise_name; 
	string name, cruise_name, cargo_name;
	int year, arg_year, cargo_year, cruise_year;
	int cruise_capacity, cargo_capacity;
	int arg_cruise_capacity, arg_cargo_capacity;

	// set the constructors with arguments
	Ship arg_ship("Laura's ship", 2003);
	CruiseShip arg_cruise_ship("Laura's cruise ship", 1946, 896575);
	CargoShip arg_cargo_ship("Laura's Cargo ship", 1753, 657389);

	// set the constructor with mutators and accessors
	Ship ships;
	CruiseShip cruise_ship;
	CargoShip cargo_ship;

	// INPUTS
	// get the input statements for ship name and year

	// put the name into the class
	cout << "INPUT:\nEnter the Name of the Ship: ";
	ships.setName();
	name = ships.getName();

	// put the year into class
	cout << "Enter the year the Ship was built: ";
	ships.setYear();
	year = ships.getYear();



	// get the inputs for cruise ship name, year, and capacity

	// put the name into the class
	cout << "\nEnter the Name of the CruiseShip: ";
	cruise_ship.setName();
	cruise_name = cruise_ship.getName();

	// put the year into class
	cout << "Enter the year the CruiseShip was built: ";
	cruise_ship.setYear();
	cruise_year = cruise_ship.getYear();

	// put the capacity into the class
	cout << "Enter the capacity of the CruiseShip (in persons): ";
	cruise_ship.setCapacity();
	cruise_capacity = cruise_ship.getCapacity();



	// get the inputs for cargo ship name, year, and capacity
	
	// put the name into the class
	cout << "\nEnter the Name of the CargoShip: ";
	cargo_ship.setName();
	cargo_name = cargo_ship.getName();

	// put the year into class
	cout << "Enter the year the CargoShip was built: ";
	cargo_ship.setYear();
	cargo_year = cargo_ship.getYear();

	// put the capacity into the class
	cout << "Enter the capacity of the CargoShip (in tonnage): ";
	cargo_ship.setCapacity();
	cargo_capacity = cargo_ship.getCapacity();


	// OUTPUTS
	cout <<"\nOUTPUT:\nNow printing the objects created using defualt constructor";
	cout << " and mutators: \n\n";

	// print the outputs for the default constructors
	ships.outputs(name, year);
	cruise_ship.outputs(cruise_name,cruise_capacity);
	cargo_ship.outputs(cargo_name, cargo_capacity);

	cout << "Now printing the objects created using constructor ";
	cout << "with arguments: \n\n";

	// get the names and years through the classes
	// print the ship output for the arguments
	arg_name = arg_ship.getName();
	arg_year = arg_ship.getYear();
	arg_ship.outputs(arg_name, arg_year);

	// print the cruise ship output for the arguments
	arg_cruise_name = arg_cruise_ship.getName();
	arg_cruise_capacity = arg_cruise_ship.getCapacity();
	arg_cruise_ship.outputs(arg_cruise_name, arg_cruise_capacity);

	// print the cargo ship output for the arguments
	arg_cargo_name = arg_cargo_ship.getName();
	arg_cargo_capacity = arg_cargo_ship.getCapacity();
	arg_cargo_ship.outputs(arg_cargo_name, arg_cargo_capacity);

	// end of program
	return 0;
}

// supporting functions
void Ship::outputs(string name, int year)
{
	// print out the ship name and year it is built
	cout << "Ship Name: " << name << "\n";
	cout << "Built: " << year << "\n\n";
}
void CruiseShip::outputs(string name, int capacity)
{
	// print out the ship name and capacity
	cout << "CruiseShip Name: " << name << "\n";
	cout << "Capacity of Cruise Ship - Number of Passengers: ";
	cout << capacity << " Persons\n\n";
}
void CargoShip::outputs(string name, int capacity)
{
	// print out the ship name and capacity
	cout << "CargoShip Name: " << name << "\n";
	cout << "Capacity of Cargo Ship - Tonnage: " << capacity;
	cout << " Tons\n\n";
}
