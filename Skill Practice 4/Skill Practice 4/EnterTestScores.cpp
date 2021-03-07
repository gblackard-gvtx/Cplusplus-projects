//Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>
#include <String>
#include <cstdlib>
#include "TestScores.h"
int main() {
	char welcomeMenu;
	bool welcomeExit = true;
	TestScores test;
	// do while run a switch untill the user enters q
	do
	{
		cout << "To enter test scores press A." << endl;
		cout << "To view grades entered press B." << endl;
		cout << "To veiw the average of scores enterd press C." << endl;
		cout << "To quit press Q" << endl;

		cin >> welcomeMenu;
		cin.ignore();

		switch (welcomeMenu)
		{
		case 'A':
		case 'a':test.setTestScores();
			break;
		case 'B':
		case 'b':test.getTestScores();
			break;
		case 'C':
		case 'c':test.getAVG();
			break;
		case 'Q':
		case 'q': welcomeExit = false;
			break;
		default: cout << "Please enter the letter a or q" << endl;
			cout << endl;
			break;
		}

	} while (welcomeExit);
}