/// Geoffery Blackard
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip> 
using namespace std;




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
// Add member function add data to the Member structure
void addNewMember() {
	Member person;
	char again;
	const int MIN_VALUE = 100000;
	const int MAX_VALUE = 500000;
	
	fstream people("MemberData.dat", ios::out | ios::binary | ios::app);
	

	do
	{
		cout << "\n\nEnter the following information. " << endl;
		cout << "\nFirst Name: " << endl;
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

		person.accountNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;;

		people.write(reinterpret_cast<char*>(&person), sizeof(person));

		cout << setw(18) << "\n\nThe following member information was added." << endl;
		cout << setw(18) <<"Account Number: " << person.accountNumber << endl;
		cout << setw(18) <<"First Name: " << person.firstName << endl;
		cout << setw(18) <<"Last Name: " << person.lastName << endl;
		cout << setw(18) <<"Email Address: " << person.emailAddress << endl;
		cout << setw(18) <<"Balance: " << person.accountBalance << endl;

		cout << "\nDo you want to enter another record? ";
		cin >> again;
		cin.ignore();

	} while (again == 'Y' || again == 'y');
	people.close();
}

void accountBalance( int n){
	Member info;
	bool flag = false;
	ifstream inFile;
	inFile.open("MemberData.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";

	while (inFile.read(reinterpret_cast<char*> (&info), sizeof(info)))
	{
		if (info.accountNumber == n)
		{
			cout << setw(18) << "Account Number: " << info.accountNumber << endl;
			cout << setw(18) << "First Name: " << info.firstName << endl;
			cout << setw(18) << "Last Name: " << info.lastName << endl;
			cout << setw(18) << "Email Address: " << info.emailAddress << endl;
			cout << setw(18) << "Balance: " << info.accountBalance << endl <<"\n\n";
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist";


}


int main() {

	char welcomeMenu;
	bool welcomMenuQuit = true;
	int num;

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
		case 'b': cout << "Enter Member Account Number.\n";
			cin >> num;
			accountBalance(num);
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