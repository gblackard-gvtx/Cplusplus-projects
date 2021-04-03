#pragma once
//Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include<cstdlib>
#include<iomanip>
#include"ProductionWorker.h"
class TeamLeader: public	ProductionWorker
{
private:
	int minTrainingHours;
	int trainingHoursAttened;
	double bonusAmount;
public:
	TeamLeader() :ProductionWorker()
	{
		minTrainingHours = 0;trainingHoursAttened = 0; bonusAmount = 0;
	}
	TeamLeader(string aName, string aNumber, string aDate, int aShift, double aPayRate, int aTH, int aTHA, double bA) :ProductionWorker(aName,aNumber,aDate,aShift,aPayRate)
	{
		minTrainingHours = aTH; trainingHoursAttened = aTHA; bonusAmount = bA;
	}
	//setter
	void setMinTraingHours(int n)
	{
		minTrainingHours = n;
	}
	void setTrainingHoursAttended(int n)
	{
		trainingHoursAttened = n;
	}
	void setBonusAmount(double bA)
	{
		bonusAmount = bA;
	}
	//getter
	int getMinTraingHours()
	{
		return minTrainingHours;
	}
	int getTrainingHoursAttended()
	{
		return trainingHoursAttened;
	}
	double getBonusAmount()
	{
		return bonusAmount;
	}
};

