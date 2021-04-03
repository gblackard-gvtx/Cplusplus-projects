//GeofferyBlackard
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include<cstdlib>
#include "DayofYear.h"

int main() {
	// create a instance of the dayofyear class
	DayofYear doyOBJ;

	int day;
	string month;

	// display the purpose of the program
	cout << "This program will check to see if the day entered for the enterd month is valid." << endl << endl;
	cout << "Enter in the name of the month. Capitalize the first letter of the month to be vaild." << endl;
	getline(cin,month);
	cout << "Enter a whole number between 1 & 31." << endl;
	cin >> day;
	while (!cin || cin.fail() || day > 31 ||day < 1)
	{
		cout << "\nEnter a whole number between 1 & 31." << endl;
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> day;
	}
	doyOBJ.validDay(day,month);
	return 0;
}