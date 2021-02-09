//Geoffery Blackard

#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <cstring>

//Global Array size
const int ARR_SIZE = 3;

//Prints put grades, assignment and username
void print(string assignment[ARR_SIZE], int grade[ARR_SIZE], string userName) {
	
	double avg = 0;
	double fAvg;
	
	for (size_t j = 0; j < ARR_SIZE; j++)
	{
		avg += grade[j];
	}

	fAvg = avg / ARR_SIZE;

	cout << "The average for " + userName + " is " << std::setprecision(3) << fAvg << endl;
	cout << "Here are your grades:" << endl;

	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << setw(23) << assignment[i] << ":" << setw(3) << grade[i] << endl;;

	}

	cout << "Thank you for playing\n" << endl;

}
//Adds assignment names to array
void addAssignment(string assignARR[ARR_SIZE]) {
	int j = 1;
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << "Enter the name of the assignment " << j << " :" << endl;
		std::getline(std::cin, assignARR[i]);
		j++;
	}
	cout << endl;

}
//Adds grades to array
void addGrades(int grade[ARR_SIZE], string assignment[ARR_SIZE]) {
	for (size_t i = 0; i < ARR_SIZE; i++)
	{
		cout << "Enter the grade for " << assignment[i] << " :" << endl;
		cin >> grade[i];

	}
	cout << endl;

}

int main()
{
	std::string studentName, assignmentName;
	int grade[ARR_SIZE];
	string assignArry[ARR_SIZE]{};
	char welcomeMenu;
	bool welcomeExit = true;
	// do while run a switch untill the user enters q
	do
	{
		cout << "Welcome to CPP Gradebook!" << endl;

		cout << "To enter grades press a, to quit press q." << endl;
			cin >> welcomeMenu;
			cin.ignore();

		switch (welcomeMenu)
		{
		case 'A':
		case 'a':
			cout << "Enter student first and last name: \n" << endl;
			std::getline(std::cin, studentName);
			addAssignment(assignArry);
			addGrades(grade, assignArry);
			print(assignArry, grade, studentName);
			break;
		case 'Q':
		case 'q': welcomeExit = false;
			break;
		default: cout << "Please enter the letter a or q" << endl;
			cout << endl;
			break;
		}
		
		;

	} while (welcomeExit);


	
}