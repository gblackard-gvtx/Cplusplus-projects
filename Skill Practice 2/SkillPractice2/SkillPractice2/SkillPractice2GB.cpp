//Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>


int main() {
	int medOne = 0;
	int medTwo = 0;
	double med = 0;
	int* medianArr = nullptr;
// this will be used to determin the size of the array
	int nArrSize = 0;

	cout << "How large wouldyou like your array to be?" << endl;
	cin >> nArrSize;
	//array of pointers created
	medianArr = new int[nArrSize];
	//adding int to the array
	for (size_t i = 0; i < nArrSize; i++)
	{
		cout << "Enter in a integer number " << i + 1 << "." << endl;
		cin >> *(medianArr + i);

	}
	//calulating the median based on even or odd sized arrays
	if (nArrSize%2 == 0)
	{
		medOne = (nArrSize / 2) - 1;
		medTwo = (nArrSize / 2);
		med = double(*(medianArr + medOne) + *(medianArr + medTwo)) / 2;
		cout << "The Median is " << med << endl;

	}
	else
	{
		medOne = (nArrSize / 2);
		med = static_cast<double>(*(medianArr + medOne));
		cout << "The Median is " << med << endl;
	}
	//closing out program
	delete[] medianArr;
	medianArr = nullptr;


}