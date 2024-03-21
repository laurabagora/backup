#include <iostream>
using namespace std;

// inititalize constants

// create the rational class
class rational 
{
	private:
		// initialize variables
		int num, den, wholeNum;

		// reduce the fractions using recursion
		int reduce(int numer, int denom)
		{
			// see if the fraction is divided evenly is 0
			if (denom % numer == 0)
			{
				// if it is then return numerator
				return numer;
			}
			// we need to see if it can be simplified again
			return reduce(denom % numer, numer);
		}

	public:
		// default constructor
		rational()
		{
			num = 0;
			den = 1;
			wholeNum = 0;
		}
		// constructor that sets the member variables
		rational(int num1, int num2)
		{
			num = num1;
			den = num2;
			wholeNum = 0;
		}
		// constructor that sets the whole number
		rational(int numb)
		{
			wholeNum = numb;
			den = 1;
		}

		// overload the input and output operator
		friend ostream& operator << (ostream& output, rational& rat)
		{
			// get the numerator
			output << rat.num;

			// get the slash
			output << '/';

			// get the denominator
			output << rat.den;

			// return the output
			return output;
		}
		friend istream& operator >> (istream& input, rational& rat)
		{
			// slash does not work so we have to create a char
			char slash = '/';

			// get the numerator
			input >> rat.num;

			// get the slash
			input >> slash;

			// get the denominator
			input >> rat.den;

			// return the input
			return input;
		}

		// overload ==, <, <=, >, >=, +, -, *, and /
		bool operator == (const rational& rat)
		{
			// this makes sure that even if they are not simplified
			// it is true
			if (num * rat.den == rat.num * den)
			{
				return true;
			}
			return false;
		}		
		bool operator < (const rational& rat)
		{
			// this makes sure that even if they are not simplified
			// it is true
			if (num *rat.den < rat.num * den)
			{
				return true;
			}
			return false;
		}
		bool operator > (const rational& rat)
		{
			// this makes sure that even if they are not simplified
			// it is true
			if (num *rat.den > rat.num * den)
			{
				return true;
			}
			return false;
		}
		bool operator >= (const rational& rat)
		{
			// this makes sure that even if they are not simplified
			// it is true
			if (num *rat.den >= rat.num * den)
			{
				return true;
			}
			return false;
		}
		bool operator <= (const rational& rat)
		{
			// this makes sure that even if they are not simplified
			// it is true
			if (num *rat.den <= rat.num * den)
			{
				return true;
			}
			return false;
		}
		rational operator + (const rational &rat)
		{
			// init variables
			int numSum, denSum;

			// get the sums
			numSum = (num * rat.den) + (rat.num * den);

			// the denominator has to stay the same
			denSum = den * rat.den;

			// set back into the values
			return rational(numSum, denSum);
		}
		rational operator - (const rational &rat)
		{
			// init variables
			int numMinus, denMinus;
			
			// get the minuses
			numMinus = (num * rat.den) - (rat.num * den);

			// the denominator has to stay the same
			denMinus = den * rat.den;

			// set back into the values
			return rational(numMinus, denMinus);
		}
		rational operator * (const rational &rat)
		{
			// init variables
			int numMult, denMult;

			// get the mulitplications
			numMult = num * rat.num;

			// the denominator has to stay the same
			denMult = den * rat.den;

			// set back into the values
			return rational(numMult, denMult);
		}

		rational operator / (const rational &rat)
		{
			// init variables
			int numDiv, denDiv;

			// multipy across
			numDiv = num * rat.den;
			denDiv = rat.num * den;

			// set back into the values
			return rational(numDiv, denDiv);
		}	

		// make sure the fractions are as small as possible
		// also that the fraction symbol is in the right place
		void normalization(const rational &rat)
		{
			// init cariables
			int first, second;

			// check if first fraction needs to be reduced
			first = reduce(num, den);
			num = num / first;
			den = den / first;

			// check if second fraction needs to be reduced
			second = reduce(rat.num, rat.den);
			num = num / second;
			den = den / second;
		}	
};
int main()
{	
	// init vairables 
	int denom, numer, numer2, denom2;
	rational values1, values2, sum, minus, multiply, divide;
	bool equal;
	string final;

	// print introdcution
	cout << "Please enter any real number\n";
	cout << "Denominator can NOT be 0\n";

	// get user input for the first fraction
	cout << "What would you like your first numerator to be: ";
	cin >> numer;
	cout << "What would you like your first denomerator to be: ";
	cin >>denom;

	// put these values into the class and check for simplification
	values1 = rational(numer, denom);
	values1.normalization(values2);

	// get user input for the second fraction
	cout << "\nWhat would you like your second numerator to be: ";
	cin >> numer2;
	cout << "What would you like your second denomerator to be: ";
	cin >> denom2;

	// put these values into the class and check for simplifcation
	values2 = rational(numer2, denom2);
	values2.normalization(values1);

	// print out the two numbers
	cout << "\nYour first number is: " << numer << "/" << denom << "\n";
	cout << "Your second number is: " << numer2 << "/" << denom2 << "\n";

	// test functions and print out answers
	
	// equal
	equal = (values1 == values2);
	if (equal == true)
	{
		final = "true";
	}
	else
	{
		final = "false";
	}
	cout << "\n" << values1 << " == " << values2 << ": ";
	cout << final << "\n";

	// less than
	equal = (values1 < values2);
	if (equal == true)
	{
		final = "true";
	}
	else
	{
		final = "false";
	}
	cout << values1 << " < " << values2 << ": ";	cout << final << "\n";

	// greater than
	equal = (values1 > values2);
	if (equal == true)
	{
		final = "true";
	}
	else
	{
		final = "false";
	}
	cout << values1 << " > " << values2 << ": ";
	cout << final << "\n";

	// less than or equal
	equal = (values1 <= values2);
	if (equal == true)
	{
		final = "true";
	}
	else
	{
		final = "false";
	}
	cout << values1 << " <= " << values2 << ": ";
	cout << final << "\n";

	// greater than or equal
	equal = (values1 >= values2);
	if (equal == true)
	{
		final = "true";
	}
	else
	{
		final = "false";
	}
	cout << values1 << " >= " << values2 << ": ";
	cout << final << "\n";

	// sum
	sum = values1 + values2;
	cout << values1 << " + " << values2 << "= ";
	cout << sum << "\n";

	// minus
	minus = values1 - values2;
	cout << values1 << " - " << values2 << "= ";
	cout << minus << "\n";

	// multiply
	multiply = values1 * values2;
	cout << values1 << " * " << values2 << "= ";
	cout << multiply << "\n";

	// divide
	divide = values1 / values2;
	cout << values1 << " / " << values2 << "= ";
	cout << divide << "\n";

	// end program
	return 0;
}