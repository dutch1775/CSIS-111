//StudentTypeTest.cpp -- driver used to test StudentType implementation.
//CSIS 111-002

//Include statements
#include <iostream>
#include <string>
#include "StudentType.h"

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 10" << endl << endl;

	//Variable declarations
	StudentType st;	//declare your StudentType variable
	string fName, lName;
	int stuScore;
	char stuGrade;

	//Program logic -- set your StudentType instance variables using your set functions
	// then display your student data using you StudentType get functions.

	//prompt user for student info for function parameters
	cout << "Enter student firstname: ";
	cin >> fName;
	cout << "Enter student lastname: ";
	cin >> lName;
	cout << "Enter student test score (1-100): ";
	cin >> stuScore;
	cout << "Enter student grade: ";
	cin >> stuGrade;

	//call set fucntions using set variables as paramters
	st.setFirstName(fName); 
	st.setLastName(lName);
	st.setTestScore(stuScore);
	st.setGrade(stuGrade);

	cout << endl << "Printing Student Information ... " << endl << endl;

	//print out student info using the functions
	cout << "Student firstname: " << st.getFirstName() << endl;
	cout << "Student lastname: " << st.getLastName() << endl;
	cout << "Student test score: " << st.getTestScore() << endl;
	cout << "Student grade: " << st.getGrade() << endl;

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