#include <iostream>
#include<string>
using namespace std;
#include "Die.h" // for rand and srand
#include <cstdlib> //for the time function
#include <ctime>

int main() 
{
	const int NUM_SIDES = 6;
	const int WINNING_TOTAL = 21;

	int computerTotal = 0;
	int userTotal = 0;
	string input;

	// create two die objects to represent the dice.
	Die die1(NUM_SIDES);
	Die die2(NUM_SIDES);

	cout << "Lets play a game of 21!\n" << endl;

	do
	{
		cout << "Would you like to roll the dice?" << endl;
		cout << "Enter a Y for yes or a N for no:";
		getline(cin, input);

		if (input == "y" || input == "Y")
		{
			// roll for the computer
			die1.roll();
			die2.roll();

			// increment the Computers total points
			computerTotal += die1.getValue() + die2.getValue();

			// roll for the player
			die1.roll();
			die2.roll();

			//increment for the player
			userTotal += die1.getValue() + die2.getValue();

			// display the users total points

			cout << "\nYou have " << userTotal << " points." << endl;


		}
	} while ((userTotal < WINNING_TOTAL) && (input == "y" || input == "Y"));
	if (userTotal > 0)
	{
		//display the totals
		cout << "\nThe computer had " << computerTotal << " points\n";
		cout << "You had " << userTotal << " points.\n";
		//determine the winner
		if (userTotal<= WINNING_TOTAL)
		{
			if (WINNING_TOTAL > computerTotal || computerTotal > WINNING_TOTAL)
			{
				//congrats to the user
				cout << endl << "Congrats You Won\n";

			}
			else
			{
				cout << "Beter luck next time." << endl;
			}
		}
		else
		{
			cout << "Better luck next timem." << endl;
		}
	}
	cout << "Game Over" << endl;
}