// Geoffery Blackard
#include <iostream>
using namespace std;
#include<string>
#include <fstream>
#include <iomanip> 
// This function calulates the letter grade based on the final avg
char letterGrade(double labAvg, double quizAvg, double examAvg) {
	char letter;
	double finalGrade = labAvg + examAvg + quizAvg;
	if (finalGrade <= 100 && finalGrade >= 90)
	{
		letter = 'A';
	}
	else if(finalGrade < 90 && finalGrade >= 80)
	{
		letter = 'B';
	}
	else if (finalGrade <= 79 && finalGrade >= 70)
	{
		letter = 'C';
	}
	else if (finalGrade <= 69 && finalGrade >= 60)
	{
		letter = 'D';
	}
	else
	{
		letter = 'F';
	}

	return letter;
}
// Calculates the final AVG
double weightAvg(double labAvg, double quizAvg, double examAvg) {
	double avg = labAvg + examAvg + quizAvg;
	return avg;
}
// Calculates Category AVG with out dropping a grade
double Avg(int arry[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arry[i];

	}
	sum = sum / size;
	return sum;

}
// Calulates category average minus the lowes grade
double categoryDropAvg(int arry[],int size) 
{
	int i;
	double sum = 0;
	double dropAvg = 0;
	for (i = 0; i < size; i++)
	{
		sum += arry[i];

	}


	int lowest;
	lowest = arry[0];
	for (i = 1; i < size; i++)
	{
		if (arry[i] < lowest)
			lowest = arry[i];
	}
	dropAvg = (sum - lowest) / ((double)size - 1);

	return dropAvg;
}
// allows the user to set grades for each Category
void setGrades(int arry[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter the grade " << (i + 1) << "\n";
		cout << "Grades must be between 0 and 100\n";
		cin >> arry[i];
		while (arry[i] < 0 || arry[i] > 100)
		{
			cout << "Grades must be between 0 and 100\n";
			cin >> arry[i];
		}
	}
}
// calculates the lowest grade
int lowestGrade(int arry[], int size)
{
	int lowest;
	lowest = arry[0];
	for (int i = 1; i < size; i++)
	{
		if (arry[i] < lowest)
			lowest = arry[i];
	}
	return lowest;
}
// calculates the weighted AVG
double weightedGrade(int arry[], int size, double weight)
{
	double categoryWeight = categoryDropAvg(arry, size) * weight;
	return categoryWeight;
}

int main() {
	ofstream outputFile;
	outputFile.open("GradeReport.txt");
	const int LAB_SIZE = 6;
	const int QUIZ_SIZE = 10;
	const int EXAM_SIZE = 2;
	 double categoryWeightLab = 0.35;
	 double categoryWeightQuiz = 0.35;
	 double categoryWeightExam = 0.30;
	int lab[LAB_SIZE] = { 0 };
	int quiz[QUIZ_SIZE] = { 0 };
	int exam[EXAM_SIZE] = { 0 };
	int menu1;
	int i = 0;
	bool mainMenuQuit = true;
	double labAvg = 0;
	double quizAvg = 0;
	double examAvg = 0;
	int labLowest = 0;
	int quizLowest = 0;
	double catWAvgLab = 0;
	double catWAvgQuiz = 0;
	double catWAvgExam = 0;


	cout << "Welcome to the C Plus Plus Gradebook." << endl;
	// loops into a switch statement prompting users to select a option , option 4 to quit
	while (mainMenuQuit)
	{
		cout << "Please choose which grading category you would like to add an assignment to." << endl;
		cout << "1: Lab" << endl;
		cout << "2: Quiz" << endl;
		cout << "3: Exam" << endl;
		cout << "4: Quit" << endl;

		cin >> menu1;
		switch (menu1)
		{
		case 1: cout << " We will now begin gradeing in the Lab category.\n";
			setGrades(lab, LAB_SIZE);
			labAvg = categoryDropAvg(lab, LAB_SIZE);
			labLowest = lowestGrade(lab, LAB_SIZE);
			catWAvgLab = weightedGrade(lab, LAB_SIZE,categoryWeightLab);
			break;
		case 2: cout << "We will now begin to grade in the Quiz category\n";
			setGrades(quiz,QUIZ_SIZE);
			quizAvg = categoryDropAvg(quiz, QUIZ_SIZE);
			quizLowest = lowestGrade(quiz, QUIZ_SIZE);
			catWAvgQuiz = weightedGrade(lab, LAB_SIZE, categoryWeightQuiz);
			break;
		case 3: cout << "We will now begin to grade in the Exam category\n";
			setGrades(exam,EXAM_SIZE);
			examAvg = Avg(exam, EXAM_SIZE);
			catWAvgExam = weightedGrade(lab, LAB_SIZE, categoryWeightExam);
			break;
		case 4: mainMenuQuit = false;
			break;

		default: cout << "You did not enter a 1, 2, 3, or 4!\n";
			break;
		}
		
	}

	// Hardcoded output of the report. 
	outputFile <<"                Grade Report\n" ;
	outputFile <<"\n" "                Lab     Quizes    Exams\n";//16 spaces, 6spaces, 4spaces 
	outputFile << "1"<< setw(18) << lab[0] << setw(8) << quiz[0] << setw(10) << exam[0] << "\n";
	outputFile << "2"<< setw(18) << lab[1] << setw(8) << quiz[1] << setw(10) << exam[1] << "\n";
	outputFile << "3"<< setw(18) << lab[2] << setw(8) << quiz[2] << "\n";
	outputFile << "4" << setw(18) << lab[3] << setw(8) << quiz[3] << "\n";
	outputFile << "5"<< setw(18) << lab[4] << setw(8) << quiz[4] << "\n";
	outputFile << "6"<< setw(18) << lab[5] << setw(8) << quiz[5] << "\n";
	outputFile << "7"<< setw(26) << quiz[6] << "\n";
	outputFile << "8"<< setw(26) << quiz[7] << "\n";
	outputFile << "9"<< setw(26) << quiz[8] << "\n";
	outputFile << "10"<< setw(25) << quiz[9] << "\n";
	outputFile << "-----------------------------------------\n";
	outputFile << "Lowest:" << setw(12) << setprecision(2) << labLowest << setw(8) << quizLowest << fixed << "\n";
	outputFile << "Average:"<<setw(14) << setprecision(2) << labAvg << setw(8) << quizAvg << setw(10) << examAvg << fixed << "\n";
	outputFile << "Percentage:      0.35    0.35      0.30\n";
	outputFile << "WT.Total:" << setw(13) << setprecision(2) << catWAvgLab <<setw(8) << catWAvgQuiz << setw(10) << catWAvgExam << fixed << "\n";
	outputFile << "Final Grade:" << setw(12) << setprecision(4)<< weightAvg(catWAvgLab,catWAvgQuiz,catWAvgExam) << setw(2) << letterGrade(catWAvgLab, catWAvgQuiz, catWAvgExam) << fixed;
	//Closeing text file
	outputFile.close();
	return 0;
}