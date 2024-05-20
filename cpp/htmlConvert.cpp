#include <iostream>
#include <fstream>
using namespace std;

// constants

// supporting function declarations
void converts(istream &inFile, ostream &outFile);
bool openInputFile(ifstream &file, const string &name);
bool openOutputFile(ofstream &file, const string &name);

int main()
{
	// initalize variables
	ifstream inDataFile;
	ofstream outDataFile;

	// get the input and output stream
	if (!openInputFile(inDataFile, "input.cpp"))
	{
		cout << "File open error!\n";
	}
	else if (!openOutputFile(outDataFile, "output.html"))
	{
		cout << "Output file open error!\n";
	}
	else
	{
		converts(inDataFile, outDataFile);
		cout << "File convsersion succesful\n";
	}		
	// close files and end program
	inDataFile.close();
	outDataFile.close();
	return 0;
}

// supporting functions
void converts(istream &inFile, ostream &outFile)
{
	// initalize variables
	char chars;

	// first output pre at the beginning
	outFile << "<PRE>\n";

	// then go through the entire file
	while(inFile.get(chars))
	{
		// change the characters if needed
		if( chars == '<')
		{
			outFile << "&lt";
		}
		else if( chars == '>')
		{
			outFile << "&gt";
		}
		else
		{
			outFile << chars;
		}
	}

	// add the pre at the end
	outFile << "\n<PRE>";
}
bool openInputFile(ifstream &file, const string &name)
{
	// open the file
	file.open(name, ios::in);

	// check if the file opened
	if (file.fail())
	{
		return false;
	}
	return true;
}
bool openOutputFile(ofstream &file, const string &name)
{
	// open the file 
	file.open(name, ios::out);

	// check if the file opened
	if (file.fail())
	{
		return false;
	}
	return true;
}