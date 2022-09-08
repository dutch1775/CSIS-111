//HelloWorld.ccp -- Prints out "Hello World!" to the monitor
//CSIS 111-002
//Public Domain


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
	cout << "Michael Dutchin -- Lab 1" << endl << endl;
	//I have read and understand the Lab Sumbittal Instruction

	//Variable declarations
	
	//Program logic
	cout << "Hello World!" << endl << endl;

	cout << 9 % 3 << endl;

	cout << static_cast<char>("a");

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