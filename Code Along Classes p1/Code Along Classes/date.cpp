#include <iostream>
using namespace std;
#include <fstream>
#include <String>
#include <cstdlib>
// global const
const int NUM_MONTHS = 12;

//date class
class Date
{
public:
	Date();
	Date(int, int, int);
	//setters
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);


	// getters
	void showDate1();
	void showDate2();
	void showDate3();


private:
	int month;
	int day;
	int year;

	//array of to hold the names of the months, 

	string names[NUM_MONTHS];

	// private member function to assign month names to array
	void setNames();


};
//defualt constructor
Date::Date()
{
	setNames();
}
// overloaded constructor
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
	setNames();

}
void Date::setNames()
{
	names[0] = "January";
	names[1] = "February";
	names[2] = "March";
	names[3] = "April";
	names[4] = "May";
	names[5] = "June";
	names[6] = "July";
	names[7] = "August";
	names[8] = "September";
	names[9] = "October";
	names[10] = "November";
	names[11] = "December";

}
void Date::setMonth(int m)
{
	if (m>1 && m<=12)
	{
		month = m;
	}
	else {
		cout << m <<" is not a valid value for the month" << endl;
		exit(EXIT_FAILURE);
	}
}
void Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
	{
		day = d;
	}
	else
	{
		cout << d << " is not a vaild value for day" << endl;
		exit(EXIT_FAILURE);
	}
}
void Date::setYear(int y)
{
	year = y;
}
void Date::showDate1() 
{
	cout << month << "/" << day << "/" << year << endl;
}
void Date::showDate2()
{
	cout << names[month - 1] << " " << day << "" << year << endl;
}
void Date::showDate3()
{
	cout<< day << " " << names[month - 1] << "" << year << endl;
}

int main() {

	// create a date object and init using overloaded constructor
	Date today(12, 25, 2014);

	// show date in form 1
	today.showDate1();


}