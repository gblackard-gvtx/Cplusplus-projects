//Geoffery Blackard

#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <cstring>



int main()
{
	double avg = 0;
	double fAvg;
	int nArrSize = 0;
	string studentName;
	char welcomeMenu;
	bool welcomeExit = true;
	int* gradeArr = nullptr;
	string* assignName = nullptr;
	

	// do while run a switch untill the user enters q
	do
	{
		cout << "Welcome to CPP Gradebook!" << endl;

		cout << "To enter grades press a, press b to print grade report, to quit press q." << endl;
		cin >> welcomeMenu;
		cin.ignore();

		switch (welcomeMenu)
		{
		case 'A':
		case 'a':
			cout << "Enter student first and last name: \n" << endl;
			getline(cin, studentName);
		
			cout << "Enter in the number of grades you would like to add" << endl;
			cin >> nArrSize;
			cin.ignore();
			//array of pointers created
			gradeArr = new int[nArrSize];
			assignName = new string[nArrSize];
			for (int i = 0; i < nArrSize; i++)
			{
				cout << "Enter the assignment Name," << endl;
				getline(cin, *(assignName + i));
			}

			for (int j = 0; j < nArrSize; j++)
			{
				cout << "Enter the grade for " << *(assignName + j) << endl;
				cin >> *(gradeArr + j);
			}
			cout << endl;
			break;
		case 'b':
		case 'B':

			cout << endl;

			for (size_t k = 0; k < nArrSize; k++)
			{
				avg += *(gradeArr + k);
			}

			fAvg = avg / nArrSize;

			cout << "The average for " + studentName + " is " << setprecision(3) << fAvg << endl;
			cout << "Here are your grades:" << endl;

			for (size_t l = 0; l < nArrSize; l++)
			{
				cout << setw(23) << *(assignName + l) << ":" << setw(3) << *(gradeArr + l) << endl;;

			}

			cout << "Thank you for playing\n" << endl;
			break;
		case 'Q':
		case 'q': welcomeExit = false;
			break;
		default: cout << "Please enter the letter a or q" << endl;
			cout << endl;
			break;
		}

	} while (welcomeExit);
	delete[] assignName, gradeArr;
	assignName = nullptr;
	gradeArr = nullptr;


}