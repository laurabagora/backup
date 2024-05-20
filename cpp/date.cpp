#include <iostream>
#include <stdexcept>
using namespace std;

// constants
const string monthName[] = 
{"January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December"};
const int MAX_MONTH = 12;
const int MIN = 1;
const int MAX_DAY = 31;

// get the class for the month
class InvalidMonth
{
private:
	string m_error;
 
public:
	InvalidMonth(string error): 
		m_error(error)
	{}
 
	const char* getError() const
	{ 
	 	return m_error.c_str();
	}
};

// get the class for the day
class InvalidDay
{
private:
	string m_error;
 
public:
	InvalidDay(string error): 
		m_error(error)
	{}
 
	const char* getError() const
	{ 
	 	return m_error.c_str();
	}
};

// get the class for the date
class Date
{
	private:
		int month;
		int day;
		int year;

	public:
		// constructor
		Date(int new_month, int new_day, int new_year):
			month(new_month), day(new_day), year(new_year)
		{}

		// accessors
		int getMonth()
		{
			return month;
		}
		int getYear()
		{
			return year;
		}
		int getDay()
		{
			return day;
		}

		// mutators
		void setMonth(int news)
		{
			// check if the month is out of the bounds 1 and 12
			if (news < MIN || news > MAX_MONTH)
			{
				throw InvalidMonth("Invalid Month");
			}
			// if in bounds then set the month
			month = news - 1;
		}
		void setDay(int news)
		{
			// check if the day is out of the bounds 1 and 31
			if (news < MIN || news > MAX_DAY)
			{
				throw InvalidDay("Invalid Day");
			}
			// if in bounds then set the day
			day = news;
		}
		void setYear(int news)
		{
			year = news;
		}

		// supporting function declaration
		void output1();
		void output2();
		void output3();
};

int main()
{
	// initalize variables
	int month, day, year;

	// get the inputs
	cout << "Enter a month (integer between 1 and 12):";
	cin >> month;
	cout << "Enter a day (integer between 1 and 31): ";
	cin >> day;
	cout << "Enter a year: ";
	cin >> year;

	// handle the exceptions
	try 
	{
		// put the values into the date class
		Date dates(month, day, year);

		// make sure the exceptions work
		dates.setMonth(month);
		dates.setDay(day);

		// print the formats
		dates.output1();
		dates.output2();
		dates.output3();
	}
	catch (const InvalidMonth &exception)
	{
		cout << exception.getError() << "\n";
	}

	catch (const InvalidDay &exception)
	{
		cout << exception.getError() << "\n";
	}

	// end program
	return 0;
}

// supporting functions
void Date::output1()
{
	// initalize varaibles
	int newMonth, twoYear;

	// get the last two digits of the year and month needs one added
	twoYear = year % 100;
	newMonth = month + 1;
	cout << newMonth << "/" << day << "/" << twoYear << "\n";
}

void Date::output2()
{
	cout << monthName[month] << " " << day << ", " << year << "\n";
}

void Date::output3()
{
	cout << day << " " << monthName[month] << " " << year << "\n";

}