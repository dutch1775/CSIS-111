/******************************************************************************
(Apartment problem) A real estate office handles, say, 50 apartment units.
When the rent is, say, $600 per month, all the units are occupied. However,
for each, say, $40 increase in rent, one unit becomes vacant. Moreover, each
occupied unit requires an average of $27 per month for maintenance. How many
units should be rented to maximize the profit?

Write a program that reads the following from an input file (provided)

	The total number of units.

	The rent to occupy all the units.

	The Amount to maintain a rented unit (maintenance fee).

And prompts the user to enter the following:

	The increase in rent that results in a vacant unit.

The program then outputs the number of units to be rented to maximize the profit.
Algorithm:
	while (profit goes up)
	{
		increase the monthly rent
		decrease number of units rented by one
		calculate the profit which is (rent - maintenance fee) * number of units rented
	}
	output the results (remember to back out the last changes made to monthly rent,
	number of units, and profit above -- why do you need to back out the last changes)
		number of units rented
		monthly rent
		total profit

Malik, Ch 5, Programming Exercise 28 (page 345)
******************************************************************************/
//CSIS 111-002
//Tutor: Ryan Peters

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//include any missing standard libraries required to complete the program

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 5" << endl << endl;

	//Variable declarations
	double rent, rentIncrement, maintenanceCost, maxProfit = 0, profit;
	int rentedUnits;
	ifstream inData;

	//Program logic
	//Open input file and store data from file to variables
	inData.open("input.dat");
	inData >> rentedUnits >> rent >> maintenanceCost;
	inData.close();

	//prompt user to enter increment value and store value in variable
	cout << "Enter the rent increase increment (for example 40): ";
	cin >> rentIncrement;

	//initialize profit variable
	profit = rentedUnits * (rent - maintenanceCost);

	//use while loop to calculate maxProfit
	while (maxProfit < profit)
	{
		maxProfit = profit;
		rent += rentIncrement;
		rentedUnits--;
		profit = rentedUnits * (rent - maintenanceCost);
	}
	//add back a unit and take back one increment to account for loop
	rentedUnits++;
	rent -= rentIncrement;
	
	//output results of the calculations
	cout << "Number of units rented: " << rentedUnits << endl;
	cout << "Monthly rent: $" << fixed << showpoint << setprecision(2) << rent << endl;
	cout << "Total Profit: $" << fixed << showpoint << setprecision(2) << maxProfit << endl;

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