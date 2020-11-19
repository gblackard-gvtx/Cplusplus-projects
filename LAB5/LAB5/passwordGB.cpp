// Geoffery Blackard
#include <iostream>
using namespace std;
#include <cstring>
#include <cctype>
// This function counts the characters in the c-string
 int characterCount(char passArray[]) {
	 int lenght = strlen(passArray);
	 return lenght;
}
 // This function counts the number of uppercase letters in the c-string
 int uppercaseCount(char passArray[]) {
	 int count = 0;
	 int len = strlen(passArray);
	 for (int i = 0; i < len; i++)
	 {
		 if (isupper(passArray[i]))
		 {
			 count++;
		 }
	 }
	 return count;
 }
 // This function counts the number of letters that are lowercase in the c-string
 int lowercaseCount(char passArray[]) {
	 int count = 0;
	 int len = strlen(passArray);
	 for (int i = 0; i < len; i++)
	 {
		 if (islower(passArray[i]))
		 {
			 count++;
		 }
	 }
	 return count;
 
 }
// This function couts the number of digits in a c string
 int containsDigit(char passArray[]) {
	 int count = 0;
	 int len = strlen(passArray);
	 for (int i = 0; i < len; i++)
	 {
		 if (isdigit(passArray[i]))
		 {
			 count++;
		 }
	 }
	 return count;
 }

 // This fucntion check the rule for lowercase and prints a statement
 void checkLowercase(char passArray[]) {
	 if (lowercaseCount(passArray) == 0) {

		 cout << "Your Password does not contain at least one lowercase character." << endl;
	 }
 }
 // this function checks the rule for uppercase and prints a statement
 void checkUppercase(char passArray[]) {

	 if (uppercaseCount(passArray) == 0) {
		 cout << "Your Password does not contain at least one uppercase character." << endl;
	 }
 }
 // This function check the rules for digits and prints a statement
 void checkDigit(char passArray[]) {
	 if (containsDigit(passArray) == 0) {
		 cout << "Your Password does not contain at least one digit." << endl;
	 }
 }
 // This function checks the rules for character count and prints a statement
 void checkCharacterCount(char passArray[]) {
	 if (characterCount(passArray) <=9) {
		 cout << "Your Password does not contain the minimum number characters." << endl;
	 }
 }


 int main() {
	 const int PASS_SIZE = 20;
	 char password[PASS_SIZE];
	 bool exitState = true;

	 // inital statment and input from the user.
	 cout << "Please enter your password" << endl;
	 cout << "The password should be at least 10 characters long." << endl;
	 cout << "The password should contain at least one uppercase and at least one lowercase letter." << endl;
	 cout << "The password should have at least one digit." << endl;

	 cin.getline(password, PASS_SIZE);
	 // loop through the fuctions till all criteria are met
	 do
	 {
		 checkCharacterCount(password);
		 checkLowercase(password);
		 checkUppercase(password);
		 checkDigit(password);
		 cout << "Please re-enter your password making the above corrections." << endl;
		 cin.getline(password, PASS_SIZE);
		 if (containsDigit(password) > 0 && uppercaseCount(password) > 0 && lowercaseCount(password) > 0 && characterCount(password) > 9) {
			 cout << "Your password meets all the criteria !" << endl;
			 exitState = false;
		 }
	 } while (exitState);

 }