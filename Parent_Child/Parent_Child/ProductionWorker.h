#pragma once
#include"Employee.h"
#include<string>
using namespace std;

class ProductionWorker : public Employee
{
public:
	ProductionWorker():Employee()
	{
		shift = 0;payRate = 0;
	}
	ProductionWorker(string aName, string aNumber, string aDate, int aShift, double aPayRate) :Employee(aName, aNumber, aDate)
	{
		shift = aShift; payRate = aPayRate;
	}
	void setShift(int s)
	{
		shift = s;
	}
	void setPayRate(double p)
	{
		payRate = p;
	}
	int getShiftNumber()const
	{
		return shift;
	}
	string getShiftName()const 
	{
		if (shift == 1)
		{
			return "Day";
		}
		else if (shift  ==2)
		{
			return "Night";
		}
		else {
			return "Invalid";
		}
	}
	double getPayRate()const
	{
		return payRate;
	}
	

private:
	int shift;
	double payRate;
};



