//Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
int main() {
	const int USERINPUT_SIZE = 5;
	int userInput [USERINPUT_SIZE];
	string userName = "";
	int max = 0;
	cout << "Please enter a Username." << endl;
	cin >> userName;
	for (size_t i = 0; i < USERINPUT_SIZE ; i++)
	{
		cout << "Please enter and integer" << endl;
		cin >> userInput[i];
	
		if (userInput[i] > max)
		{
			max = userInput[i];

		}
	}
	cout << "Hello " << userName << "!" << endl;
	cout << "The largest value entered is: " << max << endl;


}