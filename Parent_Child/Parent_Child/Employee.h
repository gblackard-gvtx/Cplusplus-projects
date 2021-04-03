#pragma once
#include<string>
using namespace std;

class Employee
{
private:
	string name;
	string number;
	string hireDate;
public:
	Employee()
	{
		name = ""; number = ""; hireDate = "";
	}
	Employee(string aName, string aNumber, string aHireDate)
	{
		name = aName; number = aNumber;hireDate = aHireDate;
	}
	void setname(string n)
	{
		name = n;
	}
	void setNumber(string num)
	{
		number = num;
	}
	void setHireDate(string date)
	{
		hireDate = date;
	}
	//getters
	string getName() const 
	{
		return name;
	}
	string getNumber() const
	{
		return number;
	}
	string getHireDate() const
	{
		return hireDate;
	}
};

