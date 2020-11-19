/// Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>
#include <cstring>
#include <cctype>





void welcome() {
	cout << "Welcome to C Plus Plus Bank" << endl;

	cout << "\nPlease choose from the following menu items." << endl;
	cout << "\nA: Add New Member" << endl;
	cout << "B: View Account Balance" << endl;
	cout << "C: Make a Withdraw" << endl;
	cout << "D: Quit" << endl;
}
const int EMAIL_SIZE = 100, NAME_SIZE = 30;
struct Member
{

	int accountNumber;
	char emailAddress[EMAIL_SIZE];
	char firstName[NAME_SIZE];
	char lastName[NAME_SIZE];
	double accountBalance;


};
int containsOther(char nameArray[]) {
	int count = 0;
	int len = strlen(nameArray);
	for (int i = 0; i < len; i++)
	{
		if (isalpha(nameArray[i]))
		{
			
		}
		else
		{
			count++;
		}
	}
	return count;
}
void addNewMember() {
	Member person;
	char again;
	
	fstream people("MemberData.dat", ios::out | ios::binary);

	do
	{
		cout << "Enter the following information. " << endl;
		cout << "First Name: " << endl;
		cin.ignore();
		cin.getline(person.firstName, NAME_SIZE);
			
		while (islower(person.firstName[0]) > 0)
		{
			
			cout << "Please make sure the first letter of First Name is capitalized" << endl;
			cin.getline(person.firstName, NAME_SIZE);
		}
		
		while (containsOther(person.firstName) > 0)
		{
			cout << "Please make sure first name input does not contain any special characters or numbers" << endl;
			cin.getline(person.firstName, NAME_SIZE);
		}
	
		cout << "Last Name: " << endl;
		cin.getline(person.lastName, NAME_SIZE);
	
		while (islower(person.lastName[0]) > 0)
		{
			
			cout << "Please make sure the first letter of Last Name is capitalized" << endl;
			cin.getline(person.lastName, NAME_SIZE);
		}


		while (containsOther(person.lastName) > 0)
		{
			cout << "Please make sure last name input does not contain any special characters or numbers" << endl;
			cin.getline(person.lastName, NAME_SIZE);
		}
		
		cout << "Email address." << endl;
		cin.getline(person.emailAddress, EMAIL_SIZE);
		

		cout << "Enter Members starting balance. Balance must be greater then $100" << endl;
		cin >> person.accountBalance;
		while (person.accountBalance < 100)
		{
			cout << "Enter Members starting balance. Balance must be greater then $100" << endl;
			cin >> person.accountBalance;
		}
		cin.ignore();

		people.write(reinterpret_cast<char*>(&person), sizeof(person));

		cout << "Do you want to enter another record? ";
		cin >> again;
		cin.ignore();

	} while (again == 'Y' || again == 'y');
	people.close();
}




int main() {

	char welcomeMenu;
	bool welcomMenuQuit = true;

	do
	{
		welcome();

		cin >> welcomeMenu;
		switch (welcomeMenu)
		{

		case 'A':
		case 'a': addNewMember();

			break;
		case 'B':
		case 'b': cout << "We will now begin to grade in the Quiz category\n";
			break;
		case 'C':
		case 'c': cout << "We will now begin to grade in the Exam category\n";
			break;
		case 'D':
		case 'd': welcomMenuQuit = false;
			break;

		default: cout << "You did not enter an A, B, C, or D!\n";
			break;
		}
	} while (welcomMenuQuit);



}