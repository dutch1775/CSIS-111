/*
The cost to become a member of a fitness center is as follows:
	(a) the senior citizens discount is 30%;
	(b) if the membership is bought and paid for 12 or more months, the discount is 15%; and
	(c) if more than five personal training sessions are bought and paid for, the discount on each session is 20%.

Write a menu-driven program that determines the cost of a new membership. Your program must contain
	a function that displays the general information about the fitness center and its charges,
	a function to get all of the necessary information to determine the membership cost, and
	a function to determine the membership cost.

Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

Malik, Ch 6, Programming Exercise 25 (page 463)

*/
//CSIS 111-02
//Tutor: Ryan Peters

//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const float MONTHLY_MEMBERSHIP_RATE = 25.00;
const float PERSONAL_SESSION_RATE = 50.00;

//Function prototypes
void wait();
void discountMenu();
void discountSelection(bool& isSenior, int& personalTrainingSessions, int& monthsPaid);
float membershipCalc(bool& isSenior, int& personalTrainingSessions, int& monthsPaid, float& membershipCost);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 6" << endl << endl;

	//Variable declarations
	bool isSenior = false;
	int personalTrainingSessions = 0, monthsPaid = 0;
	float membershipCost;

	//Program logic
	//call the discountMenu function to display the general information abou the gym and the menu
	discountMenu();

	//call the discountSelection function to give the customer the options and have them select their membership
	discountSelection(isSenior, personalTrainingSessions, monthsPaid);

	//call the memebershipCost function to calculate the memebership cost
	membershipCalc(isSenior, personalTrainingSessions, monthsPaid, membershipCost);
	
	//output final calculated annual membership cost
	cout << "Your annual membership cost is $" << fixed << showpoint << setprecision(2) << membershipCost << endl;

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
void discountMenu()
{
	//function outputting menu and basic gym info
	cout << "*************************************** Super Fitness ***************************************" << endl << endl;
	cout << "Super Fitness is an old school fitness center dedicated to getting you\n";
	cout << "in the best possible shape in a way that is healthy and fun. There are\n";
	cout << "no gimicks here. Just solid training";
	cout << endl << endl;

	cout << "Our monthly rates are $25.00, but we do offer the following discounts:\n";
	cout << "	a) Senior Citizens (65 and older):" << setw(27) << "30%\n";
	cout << "	b) Prepaid Annual Memebership:" << setw(31) << "15%\n";
	cout << "	c) Prepaid personal trainning sessions (5 or more):" << setw(10) << "20%\n";
	cout << endl;
}
void discountSelection(bool& isSenior, int& personalTrainingSessions, int& monthsPaid)
{
	//intialize selection variable and loop menu for customer to select
	int selection = 0;
	while (selection != 4)
	{
		//menu selection options
		cout << "Membership Options Menu:\n";
		cout << "	Enter '1' if you are a Senior Citizen (30% discount)\n";
		cout << "	Enter '2' if you are interested in prepaying for your annual membership (15% discount)\n";
		cout << "	Enter '3' if you are interested in any Personal Training Sessions\n	($50.00 per session -- 5 or more sessions earns you a 20% reduction in Personal Training Rates)\n";
		cout << "	Enter '4' if you are done.\n";
		cout << "Please enter the number of your option above: ";
		cin >> selection;
		cout << endl;
		//after customer chooses give values to variables needed for calculations depending on what discounts customer wants
		if (selection == 1)
		{
			isSenior = true;
			cout << endl;
		}
		else if (selection == 2)
		{
			cout << "How many months would you like to pay for (12 or more): ";
			cin >> monthsPaid;
			cout << endl;
		}
		else if (selection == 3)
		{
			cout << "How many sessions would to like to pay for: ";
			cin >> personalTrainingSessions;
			cout << endl;
		}
	}
}
float membershipCalc(bool& isSenior, int& personalTrainingSessions, int& monthsPaid, float& membershipCost)
{
	//calculate basic annual membership
	membershipCost = (MONTHLY_MEMBERSHIP_RATE * 12);

	//calculate membership with senior citizen discount if applicable
	if (isSenior)
	{
		membershipCost = membershipCost - (MONTHLY_MEMBERSHIP_RATE * .30 * 12);
	}
	//calculate membership with annual payment discount if applicable
	if (monthsPaid >= 12)
	{
		membershipCost = membershipCost - (MONTHLY_MEMBERSHIP_RATE * .15 * 12);
	}
	//calculate membership with training sessions
	membershipCost = membershipCost + (PERSONAL_SESSION_RATE * personalTrainingSessions);
	//calculate membership cost with training discount if applicable
	if (personalTrainingSessions > 5)
	{
		membershipCost = membershipCost - (PERSONAL_SESSION_RATE * .20 * personalTrainingSessions);
	}
	//return calculated annual membership
	return membershipCost;
}