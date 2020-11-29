/// Geoffery Blackard
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip> 
using namespace std;



// Prints Welcome menu option information
void welcome() {
	cout << "\nWelcome to C Plus Plus Bank" << endl;

	cout << "\nPlease choose from the following menu items." << endl;
	cout << "\nA: Add New Member" << endl;
	cout << "B: View Account Balance" << endl;
	cout << "C: Make a Withdraw" << endl;
	cout << "D: Quit" << endl;
}
//globle Variables for Structure
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
// Add member function add data to the Member structure Person.
//Then this structure is writen to a .Dat file using a append IOS so new Members are added to the end of the file
void addNewMember() {
	Member person;
	char again;
	
	fstream people("MemberData.dat", ios::out | ios::binary | ios::app);
	

	do
	{
		
		cout << "\n\nEnter the following information. " << endl;

		cout << "\nEnter Member Account Number" << endl;

		cin>>person.accountNumber;
		while (!cin || cin.fail())
		{
			cout << "\nPlease enter a number." << endl;
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> person.accountNumber;
		}
		cin.ignore();
		cout << "\nFirst Name: " << endl;
		cin.getline(person.firstName, NAME_SIZE);
			
		while (islower(person.firstName[0]) > 0)
		{
			
			cout << "\nPlease make sure the first letter of First Name is capitalized" << endl;
			cin.getline(person.firstName, NAME_SIZE);
		}
		
		while (containsOther(person.firstName) > 0)
		{
			cout << "\nPlease make sure first name input does not contain any special characters or numbers" << endl;
			cin.getline(person.firstName, NAME_SIZE);
		}
	
		cout << "\nLast Name: " << endl;
		cin.getline(person.lastName, NAME_SIZE);
	
		while (islower(person.lastName[0]) > 0)
		{
			
			cout << "\nPlease make sure the first letter of Last Name is capitalized" << endl;
			cin.getline(person.lastName, NAME_SIZE);
		}


		while (containsOther(person.lastName) > 0)
		{
			cout << "\nPlease make sure last name input does not contain any special characters or numbers" << endl;
			cin.getline(person.lastName, NAME_SIZE);
		}
		
		cout << "\nEmail address." << endl;
		cin.getline(person.emailAddress, EMAIL_SIZE);
		

		cout << "\nEnter Members starting balance. Balance must be greater then $100" << endl;
		cin >> person.accountBalance;
		while (person.accountBalance < 100)
		{
			cout << "\nEnter Members starting balance. Balance must be greater then $100" << endl;
			cin >> person.accountBalance;
		}


		people.write(reinterpret_cast<char*>(&person), sizeof(person));

		cout << setw(18) << "\n\nThe following member information was added." << endl;
		cout << setw(18) <<"Account Number: " << person.accountNumber << endl;
		cout << setw(18) <<"First Name: " << person.firstName << endl;
		cout << setw(18) <<"Last Name: " << person.lastName << endl;
		cout << setw(18) <<"Email Address: " << person.emailAddress << endl;
		cout << setw(19) << setprecision(2) << fixed <<"Balance: $" << person.accountBalance << endl;

		cout << "\nDo you want to enter another record? ";
		cin >> again;
		cin.ignore();

	} while (again == 'Y' || again == 'y');
	people.close();
}
//This function allow you to search the file based on the account number. If the account number dosent exist it will return a error. 
void accountBalance( int n){
	Member info;
	bool flag = false;
	ifstream inFile;
	inFile.open("MemberData.dat", ios::binary);
	if (!inFile)
	{
		cout << "File not found Press any Key...";
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
			cout << setw(19) << setprecision(2) << fixed << "Balance: $" << info.accountBalance << endl <<"\n\n";
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist\n\n";


}
// This fuction will allow withdraws from member accounts. First it open the Member.DAT . Then  searches the .dat file for the account number. Once it finds the account number is print the Member Structure to the screen.
// You are then prompted to enter a withdraw amount. This function will not let you withdraw more then the available funds. 
void widthdraw(int n) {
	double amt;
	Member info;
	bool flag = false;
	fstream inFile;
	inFile.open("MemberData.dat", ios::binary | ios::in | ios::out);
	if (!inFile)
	{
		cout << "File not found! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";

	while (!inFile.eof() && flag == false)
	{
		inFile.read(reinterpret_cast<char*> (&info), sizeof(info));
		if (info.accountNumber == n)
		{
			cout << setw(18) << "Account Number: " << info.accountNumber << endl;
			cout << setw(18) << "First Name: " << info.firstName << endl;
			cout << setw(18) << "Last Name: " << info.lastName << endl;
			cout << setw(18) << "Email Address: " << info.emailAddress << endl;
			cout << setw(19) << setprecision(2) << fixed << " Current Balance: $" << info.accountBalance << endl << "\n\n";
			cout << "\n\n\tTO WITHDRAW AMOUNT ";
			cout << "\n\nEnter the ammount you would like to withdraw." << endl;
			cin >> amt;
			while (!cin || cin.fail())
			{
				cout << "Please enter a number value.\n" << endl;
				cin.clear(); // reset failbit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> amt;
			}
			double newBalance = static_cast<double>(info.accountBalance) - amt;
			if (newBalance < 0)
			{
				cout << "Insufficience balance!";
			}
			else
			{
				info.accountBalance = newBalance;
			}
			int pos = (-1) * static_cast<int>(sizeof(info));
			inFile.seekp(pos, ios::cur);
			inFile.write(reinterpret_cast<char*> (&info), sizeof(info));
			cout << "\n\n\t Record Updated\n\n";
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist";

}

// Main uses a switch to navigate the menu. User can both lower and upper case letters. Users can only enter numbers for that account numbers.  
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
			while (!cin || cin.fail())
			{
				cout << "Please enter a number." << endl;
				cin.clear(); // reset failbit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> num;
			}
			accountBalance(num);
			break;
		case 'C':
		case 'c': cout << "Enter Member Account Number.\n";
			cin >> num;
			while (!cin || cin.fail())
			{
				cout << "Please enter a number." << endl;
				cin.clear(); // reset failbit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> num;
			}
			widthdraw(num);
			break;
		case 'D':
		case 'd': welcomMenuQuit = false;
			break;

		default: cout << "You did not enter an A, B, C, or D!\n";
			break;
		}
	} while (welcomMenuQuit);


	return 0;
}