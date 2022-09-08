//Hotel.cpp -- brief statement as to the file’s purpose -- See assignment below.
/*	Assignment Description
	The cost of renting a room at a hotel is, say $100.00 per night. For special occasions,
	such as a wedding or conference, the hotel offers a special discount as follows: If
	the number of rooms booked is at least 10, the discount is 10%; at least 20, the discount
	is 20%; and at least 30, the discount is 30%. Also if rooms are booked for at least three
	days, then there is an additional 5% discount.

	Write a program that
		- loads the cost of renting one room and the sales tax rate
			from an input file (provided),
		- prompts the user to enter the number of rooms booked, and
		- prompts the user to enter the number of days the rooms are booked.

	The program outputs to an output file named (output.dat)
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.

	Your program must use appropriate named constants to store special values such as various discounts.
*/
//CSIS 111-002
//Tutor: Ryan Peters

//Include statements
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//include the standard library file needed to read and write files

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const double ADDDISCOUNT = .05;

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 4" << endl << endl;

	//Variable declarations
	double roomRate, taxRate, discountRate, salesTax, totalRoomCost;
	int roomsBooked, days;

	//Add an ifstream variable to read the input file "input.dat" and open it.
	ifstream inData;
	inData.open("input.dat");

	//Add an ofstream variable to output the final results to output.dat.
	ofstream outData;
	outData.open("output.dat");

	//Program logic
	
	//Open and read input.dat to get the cost of renting one room
	//and the sales tax rate.
	inData >> roomRate >> taxRate;
	inData.close();
		
	//Prompt the user to provide the following:
	//-the number of rooms booked and
	//-the number of days the rooms are booked.
	cout << "Please enter the number of rooms that are booked and the number of days these rooms are booked" << endl<< "(separate the values by a space): ";
	cin >> roomsBooked >> days;
	cout << endl;
	
	// Complete the appropriate calculations
	//   Calculate the discount rate
	if (roomsBooked < 10)
		discountRate = 0.0;
	else if (roomsBooked < 20)
		discountRate = 0.1;		//10% discount
	else if (roomsBooked < 30)
		discountRate = 0.2;		//20% discount
	else
		discountRate = 0.3;		//30% discount

	if (days >= 3) {
		discountRate = (discountRate + ADDDISCOUNT);
	}

	//Calculate finalRoomRate
	totalRoomCost = ((roomRate * roomsBooked) * (1- discountRate));

	//Caclulate salesTax and totalRoomCost
	salesTax = (taxRate * totalRoomCost);

	/*
		Output to output.dat
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.
		Your output should look nice and neat
	*/

	outData << fixed << showpoint << setprecision(2);

	outData << setw(0) << "The price per room:" << setw(25) << "$" << roomRate << endl;
	outData << setw(0) << "The discount per room:" << setw(26) << (discountRate * 100) << '%' << endl;
	outData << setw(0) << "The number of rooms booked:" << setw(18) << roomsBooked << endl;
	outData << setw(0) << "The number of days each room is booked:" << setw(5) << days << endl;
	outData << setw(0) << "The total cost of the rooms:" << setw(16) << "$" << totalRoomCost << endl;
	outData << setw(0) << "The sales tax:" << setw(30) << "$" << salesTax << endl;
	outData << setw(0) << "The grand total is:" << setw(25) << "$" << (totalRoomCost + salesTax) << endl;

	outData.close();

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}