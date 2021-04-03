//Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include<cstdlib>
#include<iomanip>
#include"TeamLeader.h"

void displayInfo(TeamLeader t);

int main() {
	char exit = 'n';
	string name, number;
	int shift, minTrain =5, trainAtt;
	double bonus, payRate;
	TeamLeader tl;

	do
	{
		cout << "Welcome to the Teamlead portal." << endl << endl;
		cout << "Please enter your Full Name." << endl;
		getline(cin, name);
		tl.setname(name);
		cout << "Thank you! " << name << "." << endl;
		cout << "Please enter your Employee Number." << endl;
		getline(cin, number);
		tl.setNumber(number);
		cout << "Please enter the shift you worked this week. Enter 1 for Day or 2 for Night" << endl;
		cin >> shift;
		while (!cin || cin.fail() || shift < 1 || shift > 2)
		{
			cout << "\nPlease enter a number." << endl;
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> shift;
		}
		tl.setShift(shift);
		cout << "Enter the number of training hours you atteded this week" << endl;
		cin >> trainAtt;
		while (!cin || cin.fail() || trainAtt< 0)
		{
			cout << "\nPlease enter a number." << endl;
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> trainAtt;
		}
		tl.setTrainingHoursAttended(trainAtt);
		if (trainAtt>=minTrain)
		{
			bonus = 200.50;
			tl.setBonusAmount(bonus);
		}
		else
		{
			bonus = 0;
			tl.setBonusAmount(bonus);
		}

		cout << "\nAre you finished? ";
		cin >> exit;
		cin.ignore();

	} while (exit=='n' || exit=='N');
	displayInfo(tl);
	
}
void displayInfo(TeamLeader t) {
	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: " << t.getName() << endl;
	cout << "Employee Number: " << t.getNumber() << endl;
	cout << "Shift: " << t.getShiftName() << endl;
	cout << "Bonus Amount Earned: " << t.getBonusAmount() << endl;
}
