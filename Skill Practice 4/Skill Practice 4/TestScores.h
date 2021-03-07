#include <iostream>
using namespace std;
#include <fstream>
#include <String>
#include <cstdlib>



//Geoffery Balckard
//global vars
const int NUM_SCORES = 3;

class TestScores
{
public:
	TestScores();
	TestScores(int, int, int);
	// setter
	void setTestScores();

	// getter
	void getTestScores();
	void getAVG();

private:
	int scores[NUM_SCORES];

};

TestScores::TestScores()
{
}

TestScores::TestScores(int s1, int s2, int s3)
{
	scores[1] = s1;
	scores[2]= s2;
	scores[3] = s3;
}

void TestScores::setTestScores()
{
	for (int i = 0; i < NUM_SCORES; i++)
	{
		cout << "Enter test score " << (i + 1) << "." << endl;
		cin >> scores[i];
	}
}
void TestScores::getTestScores()
{
	for (int i = 0; i < NUM_SCORES; i++)
	{
		cout << "Test score " << (i + 1) << ". " << scores[i] << endl;
	}
}
void TestScores::getAVG()
{
	int avg = 0;
	
	for (int i = 0; i < NUM_SCORES; i++)
	{
		avg += scores[i];
	}
	cout << "Average: " << (avg / NUM_SCORES) << endl;
}