#include <iostream>
using namespace std;

int main() {
	double THR;
	double age;
	double restingHeartRate;
	// sending request statement, getting user inputs
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your resting heart rate: ";
	cin >> restingHeartRate;
	// using inputs to calculate THR
	THR = .7 * (220 - age)+ .3 * restingHeartRate;

	//printing THR statement
	cout << "Your THR is " << static_cast<int> (THR) << " beats per minute\n";

	return 0;

}