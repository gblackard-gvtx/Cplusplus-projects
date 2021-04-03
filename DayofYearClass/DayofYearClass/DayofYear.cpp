//GeofferyBlackard
#include "DayofYear.h"
#include<string>

// define the statics before anything else

int DayofYear::dayAtEndOfMonth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 272, 304, 334, 365 };

string DayofYear::monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

// dayof year print - convert and print day of year

void DayofYear::print()
{
	int month = 0;

	while (dayAtEndOfMonth[month] < day)
	month = (month + 1) % 12;

		if (month == 0)
		{
			cout << "\nJanuary " << day << endl << endl;

		}
		else
		{
			cout << endl << monthName[month] << " " << day - dayAtEndOfMonth[month - 1] << endl << endl;
		}
	
}
void DayofYear::validDay(int day, string month){
	int invalid = 0;
	for (int i = 0; i < 12; i++)
	{
		if (month.compare(monthName[i]) ==0)
		{
			if (month.compare("january") == 0|| month.compare("January") == 0)
			{
				cout << "The date entered is vaild, " << month << " has " << day << " days in it" << endl;
			}
			else
			{
				int daysCurrentMonth = dayAtEndOfMonth[i] - dayAtEndOfMonth[i - 1];
				if (day > daysCurrentMonth)
				{
					cout << "I am sorry " << day << " is not a valid date in " << month << endl;
				}
				else {
					cout << day << " is within the month of " << month << endl;
				}

			}

		}
		else
		{
			invalid++;
		}
		
	}
	if (invalid == 12)
	{
		cout << "Im sorry the month entered was not vaild!" << endl;
	}
	

}
