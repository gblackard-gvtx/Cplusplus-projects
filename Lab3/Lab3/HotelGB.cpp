// Geoffery Blackard
#include <iostream>
using namespace std;
#include <fstream>

int main() {
	int hotelFloors, hotelRooms, roomsPerFloor, occupied, unoccupied;
	int totalFloors ;
	int totalOccupied = 0;
	int	totalUnoccuiped = 0;
	int occupiedPercentage;
	//writing to txt file
	ofstream outputFile;
	outputFile.open("HotelReport.txt");
	// request number of floors for this hotel
	cout << "Please enter the number of floors the hotel has.\n";
	cin >> hotelFloors;
	// loop to validate hotel floors
	while (hotelFloors < 1 || hotelFloors > 999)
	{
		cout << "Please enter a floor number between 1 & 999.\n";
		cin >> hotelFloors;
	}
	// writing to files the number of floors
	outputFile << "Number of hotel Floors: "<< hotelFloors << endl;

	// for loop to iterate through the number of floors. Requesting number or occupied and unoccupied rooms
	//while loops used to validate the input
			for (totalFloors = 1; totalFloors <= hotelFloors; totalFloors++)
			{

				cout << "Please enter the number of rooms for the current floor\n";
				cout << "Current floor:  " << totalFloors << endl;
				cout << " Enter rooms that are unoccupied: \n";
				cin >> unoccupied;
				outputFile << "Floor number: " << totalFloors << endl;
				while (unoccupied < 1 || unoccupied > 999)
				{
					cout << "Please enter a number between 1 & 999.\n";
					cin >> unoccupied;
				
				}
				totalUnoccuiped = totalUnoccuiped + unoccupied;
				cout << "Please enter the occupied rooms: \n";
				cin >> occupied;
				while (occupied < 1 || occupied > 999)
				{
					cout << "Please enter a number between 1 & 999.\n";
					cin >> occupied;
				}
				totalOccupied = totalOccupied + occupied;
				roomsPerFloor = totalOccupied + totalUnoccuiped;
			}
			//calculated feilds after the for loop is finished 
			outputFile << "Unoccupied rooms: " << unoccupied << endl;
			outputFile << "Occupied rooms: " << occupied << endl;
			hotelRooms = totalOccupied + totalUnoccuiped;
			outputFile << "Total hotel rooms: "<< roomsPerFloor << endl ; 
			outputFile << "Total Occupied Rooms: " << totalOccupied << endl;
			outputFile << "Total Unoccupied: " << totalUnoccuiped << endl;
			occupiedPercentage = ((double)totalOccupied / hotelRooms) * 100;

			cout << "Number of hotel rooms: " << hotelRooms << endl;
			cout << "Percentage occupied: " << occupiedPercentage << " %";
			outputFile << "Percentage of occupied rooms: " << occupiedPercentage << " %" << endl;

			//Closeing text file
			outputFile.close();
	return 0;
}