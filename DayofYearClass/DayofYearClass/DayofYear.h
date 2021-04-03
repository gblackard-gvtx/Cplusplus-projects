//GeofferyBlackard
#pragma once
#include <iostream>
#include <string>
using namespace std;

class DayofYear
{
private:
	int day;
	string month;

public:
	static int dayAtEndOfMonth[];
	static string monthName[];

	void print();
	void setDay(int day) {this->day = day;}
	void setMonth(string month) { this->month = month; }
	void validDay(int day, string month);



};


