//Geoffery Blackard

#include <iostream>
using namespace std;

int main() {
	//established variables
	int segmentFlown;
	int milesFlown;
	//requesting imputs
	cout << "Please enter the number of segments flown: ";
	cin >> segmentFlown;
	cout << "Please enter the number of miles flown: ";
	cin >> milesFlown;
	//begin if statments
	// if negitive it will print statement
	if (segmentFlown < 0 || milesFlown < 0)
	{
		cout << "Please enter a positive number";
	}
	//else it will move to the membership logic
	else
	{
		if (segmentFlown >= 120 || milesFlown >= 75000)
		{
			cout << " Elite Status: Platinum";
		}
		else if (segmentFlown >= 80 && segmentFlown <= 119 || milesFlown >= 50000 && milesFlown <= 74999)
		{
			cout << " Elite Status: Gold";
		}
		else if (segmentFlown >= 40 && segmentFlown <= 79 || milesFlown >= 25000 && milesFlown <= 49999)
		{
			cout << " Elite Status: Silver";
		}

		else if (segmentFlown >= 0 && segmentFlown <= 39 || milesFlown >= 0 && milesFlown <= 24999)
		{
			cout << " Elite Status: Member";
		}
	}
	return 0;
}