//Planets.ccp -- Calculates the weight of a person on a different planet after the user inputs their weight in a string 
//and selects the valid planet in which they wish to calculate for
//CSIS 111 - 002

//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
enum planets { MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};

//Function prototypes
bool validPlanet(string userInput, planets& planetChoice);
float calcWeight(planets& planetChoice, float& userWeight, float& planetWeight);
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- 7" << endl << endl;

	//Variable declarations
	float userWeight, planetWeight;
	planets planetChoice;
	string userInput;

	//Program logic
	//Get the user's Earth weight
	cout << "Enter your weight on Earth: ";
	cin >> userWeight;
	cout << endl;

	//Get the user's planet choice and verify input validity through validPlanet
	do {
		cout << "Enter planet name (use proper capitalization): ";
		cin >> userInput;
		cout << endl;
	} while (!validPlanet(userInput, planetChoice));

	//call the calcWeight function to find weight on users desired planet
	calcWeight(planetChoice, userWeight, planetWeight);

	//output calculated weight on other planet
	cout << "Your weight on " << userInput << " is " << planetWeight << endl << endl;

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
bool validPlanet(string userInput, planets& planetChoice)
{
	//based on user string input set enum variable and return true
	if (userInput == "Mercury")
	{
		planetChoice = MERCURY;
		return true;
	}
	else if (userInput == "Venus")
	{
		planetChoice = VENUS;
		return true;
	}
	else if (userInput == "Earth")
	{
		planetChoice = EARTH;
		return true;
	}
	else if (userInput == "Moon")
	{
		planetChoice = MOON;
		return true;
	}
	else if (userInput == "Mars")
	{
		planetChoice = MARS;
		return true;
	}
	else if (userInput == "Jupiter")
	{
		planetChoice = JUPITER;
		return true;
	}
	else if (userInput == "Saturn")
	{
		planetChoice = SATURN;
		return true;
	}
	else if (userInput == "Uranus")
	{
		planetChoice = URANUS;
		return true;
	}
	else if (userInput == "Neptune")
	{
		planetChoice = NEPTUNE;
		return true;
	}
	else if (userInput == "Pluto")
	{
		planetChoice = PLUTO;
		return true;
	}
	else //user enetred improper input and so error clearly defines how input should be
	{
		cout << "INVALID INPUT" << endl;
		cout << "PLEASE MAKE SURE FIRST LETTER IS CAPITALIZED" << endl;
		cout << "ALL SUBSEQUENT LETTERS SHOULD BE LOWER CASE" << endl << endl;
		return false;
	}
}
float calcWeight(planets& planetChoice, float& userWeight, float& planetWeight)
{
	switch (planetChoice) //use switch statement from enum to calc weight and return value
	{
	case MERCURY:
		planetWeight = userWeight * 0.4155;
		return planetWeight;
		break;
	case VENUS:
		planetWeight = userWeight * 0.8975;
		return planetWeight;
		break;
	case EARTH:
		planetWeight = userWeight * 1.0;
		return planetWeight;
		break;
	case MOON:
		planetWeight = userWeight * 0.166;
		return planetWeight;
		break;
	case MARS:
		planetWeight = userWeight * 0.3507;
		return planetWeight;
		break;
	case JUPITER:
		planetWeight = userWeight * 2.5374;
		return planetWeight;
		break;
	case SATURN:
		planetWeight = userWeight * 1.0677;
		return planetWeight;
		break;
	case URANUS:
		planetWeight = userWeight * 0.8947;
		return planetWeight;
		break;
	case NEPTUNE:
		planetWeight = userWeight * 1.1794;
		return planetWeight;
		break;
	case PLUTO:
		planetWeight = userWeight * 0.0899;
		return planetWeight;
		break;
	}
}