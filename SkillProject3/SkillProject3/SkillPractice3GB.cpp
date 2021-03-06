//GeofferyBlackard

#include <iostream>
using namespace std;
#include <fstream>
#include <String>
#include <cstdlib>



int main() {
	string name;
	string inputLine;
	int lines = 0;

	ifstream file; // filestream object for our file

	// get name of the file

	cout << "Enter the name of the file" << endl;
	getline(cin, name);

	// open the file
	file.open(name);

	// test for error to see if the file exist
	if (!file)
	{
		cout << "ERROR opening " << name << endl;
		exit(EXIT_FAILURE);
	}
	// display the first ten lines of the file
	while (!file.eof()&& lines<10)
	{
		//get a line
		getline(file, inputLine,'\n');

		//increment a line counter
		lines ++;
		// display a line
		if (lines % 2 == 0)
		{
			cout << inputLine << endl;
		}
		
	}
	// if the file has less then 10 lines, indicate the entire file has been displayed
	if (lines < 10)
	{
		cout << endl << "The entire file has been displayed." << endl;
	}



}