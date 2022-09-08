//car_range.cpp -- Write a program that prompts the capacity, in gallons, of an automobile fuel tank 
//	and the miles per gallon the automobile can be driven. The program outputs the number of miles `
//	the automobile can be driven without refueling.
//CSIS 111-002
// Malik, Ch.2, Section 2-8f


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 2" << endl << endl;

	//Variable declarations
	int tankCapacity;
	int milesPerGallon;
	int range;

	//Program logic
	//	Prompt user for tank capacity and miles per gallon
	cout << "Enter the gas tank capacity and the miles per gallon of your automobile separated by one or two spaces: ";
	cin >> tankCapacity >> milesPerGallon;
	cout << endl;
	//	Calculate the car's range and assign it to the variable range
	range = tankCapacity * milesPerGallon;
	//	Output the cars range as well as what the user entered.
	cout << "Your car has a gas tank capacity of " << tankCapacity << " gallons." << endl;
	cout << "Your car gets " << milesPerGallon << " miles per gallon." << endl;
	cout << "Your car can be driven " << range << " miles without refueling." << endl;

	//Closing program statements
	wait();
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