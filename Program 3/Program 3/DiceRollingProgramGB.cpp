//Geoffery Blackard
#include <iostream>
#include<string>
using namespace std;
#include "Die.h" // for rand and srand
#include <cstdlib> //for the time function
#include <ctime>
// this function creates the die object then calls the roll function as many times as the user request
void diceRoll(int numSides, int numRolls, int userTotal)
{
	int rolls = 0;
	
	Die die(numSides);
	for (int i = 0; i < numRolls; i++)
	{
		die.roll();
		userTotal += die.getValue();
	}
	cout << "Your total dice roll was:" << userTotal << endl;


}

int main()
{
	int numSides = 0;
	int numDiceRolls = 0;
	char input = 'y';
	bool exit = true;
	int userTotal = 0;

	

	cout << "Lets Roll Some Dice!" << endl;
	do
	{
		// we get the user input for the size of the dice and the number of rolls
		cout << "Would you like to roll the dice?" << endl;
		cout << "Enter a Y for yes or a N for no:";
		cin >> input;

		switch (input)
		{
		case 'Y':
		case 'y':
			cout << "Enter the number of sides for the dice you would like to roll" << endl;
			cin >> numSides;
			cout << "Enter the number of dice you would like to roll" << endl;
			cin >> numDiceRolls;
			diceRoll(numSides, numDiceRolls, userTotal);
			userTotal = 0;
			break;
		case 'n':
		case 'N':
			exit = false;
		}

	} while (exit);

	return 0;
}