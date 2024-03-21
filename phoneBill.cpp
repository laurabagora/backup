#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// inititalize constants
const double MONTH = 10.0;
const double CALL = 0.50;
const double PREM_MONTH = 20.0;
const double PREM_CALL = 0.05;
const double MINUTES = 0.10;
const int AVERAGE_VALUE = 10;
const int CALL_MAX = 100;
const int CALL_MIN = 10;
const int MINUTE_MAX = 8;
const int MINUTE_MIN = 2;

// create the customer class (base class)
class Customer 
{
	protected:
		// initialize variables
		string name;
		int calls;

	public:

		// constructor with arguments
		Customer(string customer_name, int customer_calls):
		
			name(customer_name), calls(customer_calls)
		{}

		// set the virtual customer
		virtual ~Customer() {}

		// set the accessors
		string getName()
		{
			return name;
		}
		int getCalls()
		{
			return calls;
		}

		// computations
		virtual double computeBill();

};

// set the premium customer class
class Premium_Customer: public Customer
{
private:
	double minutes_call;

	public:

		// constructor with arguments
		Premium_Customer(string customer_name, int customer_calls, 
												double customer_minutes):
		
			Customer(customer_name, customer_calls),
											 minutes_call(customer_minutes)
		{}

		double getMinutes()
		{
			return minutes_call;
		}

		// set the virtual customer
		virtual  ~Premium_Customer() {}

		// computations
		virtual double computeBill();
};

// declarations
int randomValueCall();
int randomValueMin();

int main()
{
	// initalize variables
	double total_prem = 0, total_reg = 0, tot, ranCall, ranMin;
	string plan;

	// initialize rand
	srand(time(NULL));

	// set precision
	cout << fixed << setprecision(1);

	// create the customers
	Customer* customer_list[6];
	customer_list[0] = new Customer("Chris Hemsworth", 20);
	customer_list[1] = new Customer("John Kransinki", 50);
	customer_list[2] = new Customer("Andrew Garfield", 100);
	customer_list[3] = new Premium_Customer("Chris Pratt", 30, 3);
	customer_list[4] = new Premium_Customer("Tom Cruise", 60, 3);
	customer_list[5] = new Premium_Customer("Zach Bryan", 100, 3);

	// output for the specific customers
	for(int i = 0; i < 6; i++)
	{
		cout << "Customer " << customer_list[i]->getName() << " owes "
		<< customer_list[i]->computeBill() << " dollars."
		<< endl;
	}

    // create the loop and output for the customer count
	for (int i = 1; i < 11; i++)
	{
		ranCall = randomValueCall();
		tot = i * ranCall;
    	Customer *reg = new Customer("Customer", tot);
    	cout << "Customer " << i << " owes " << int(reg->computeBill()) 
    													<< " dollars.\n";

    	// calculate the average
    	total_reg = total_reg + reg->computeBill();
	}

	// create the loop and output for the premium customer count
	for (int i = 1; i < 11; i++)
	{
		// get the random number of calls and minutes
		ranMin = randomValueMin();
		ranCall = randomValueCall();
		tot = i * ranMin * PREM_CALL;

		// calculate the numbers
    	Premium_Customer *prem = new Premium_Customer("Customer", 
    								i * ranCall, tot);
    	cout << "Premium Customer " << i << " owes " << 
    								prem->computeBill() << " dollars.\n";

    	// calculate the average
    	total_prem = total_prem + prem->computeBill();
	}

	// create the average for the basic, premium, and  calculatae total savings
	double average_reg = total_reg / AVERAGE_VALUE;
	double average_prem = total_prem / AVERAGE_VALUE;
	double savings = average_prem - average_reg;

	// check if the premium is better than the regular and print results
	if (average_reg > average_prem)
	{
		cout << "premium plan seems better for the most customers\n";	
		plan = "premium";
	}
	else
	{
		cout << "basic plan seems better for the most customers\n";	
		plan = "basic";
	}
	cout << "average for basic = $" << average_reg;
	cout << "\naverage for premium = $" << average_prem;
	cout << "\naverage savings for " << plan << " plan = $" << abs(savings);


	// delete all the customers
	return 1;
}

// supporting functions
double Premium_Customer::computeBill()
{
	double charges = 0;
	charges = PREM_MONTH + (PREM_CALL * calls) + (MINUTES * minutes_call);
	return charges;
}

double Customer::computeBill()
{
	double charges = 0;
	charges = MONTH + (CALL * calls);
	return charges;
}

int randomValueCall()
{
	int time;
	// keep in mind the groups of 10
	int ten = (CALL_MAX - CALL_MIN) / 10;
	time = CALL_MIN + rand() % (ten + 1);
	return time;
}

int randomValueMin()
{
	int time;
	time = MINUTE_MIN + rand() % (MINUTE_MAX - MINUTE_MIN + 1);
	return time;
}

