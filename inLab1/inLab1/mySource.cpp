#include <iostream>
using namespace std;

int main() {
	double taxAmount, tipAmount, totalMealCost;
	double mealCost = 88.67;
	double taxAmountPercentage = 0.0675;
	double tipPercentage = 0.2;

	taxAmount = (mealCost * taxAmountPercentage);
	tipAmount = (mealCost + taxAmount) * tipPercentage;
	totalMealCost = mealCost + taxAmount + tipAmount;
	
	cout << "Meal Cost: $" << mealCost << "\n";
	cout << "Tax: $" << taxAmount << "\n";
	cout << "Tip: $" << tipAmount << "\n";
	cout << "The total cost of your meal plus tax and tip is $" << totalMealCost <<"\n";

	return 0;
}
