#pragma once
class Die
{
public:
	Die(int);
	void roll();
	int getSides();
	int getValue();
private:
	int sides;
	int value;
	
};



