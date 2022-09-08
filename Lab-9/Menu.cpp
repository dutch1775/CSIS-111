/*
	Write a program to help a local restaurant automate its breakfast billing system. The program should do the following:

	1. Show the customer the different breakfast items offered by the restaurant.

	2. Allow the customer to select more than one item from the menu.

	3. Calculate and print the bill.

	Use an array menuList of type MenuItemType. MenuItemType consists of three components:
		menuItem of type string,
		menuPrice of type double, and
		isOrdered of type bool.

	Your program must contain at least the following functions:

	1. Function getData: This function loads the data into the array menuList from the file menu.txt.

	2. Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.

	3. Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.)

	Format your output with two decimal places. The name of each item in the output must be left justified. You may assume that the user
	selects only one item of a particular type.

	Algorithm:

		main
		{
			GetData
			do {
				showMenu
			} while not done
			printCheck
		}
*/
//CSIS 111-002

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
struct MenuItemType {
	string menuItem;
	double menuPrice;
	bool isOrdered = false;
};

//Function prototypes
void wait();
void getData(ifstream &input, MenuItemType menuList[]);
void showMenu(MenuItemType menuList[], int customerOrder[], int foodChoice, int &counter);
void printCheck(MenuItemType menuList[], int customerOrder[], int &counter);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 9" << endl << endl;

	//Variable declarations
	MenuItemType menuList[8] = { };
	ifstream input;
	int customerOrder[8] = { };
	int foodChoice = 1, counter = 0;


	//Program logic
	//open menu file and call getData function
	input.open("menu.txt");
	getData(input, menuList);

	//in do-while loop show customer menu, have them order, and after print check
	do {
		showMenu(menuList, customerOrder, foodChoice, counter); //call showMenu to show customer menu and have them order
	} while (menuList->isOrdered != false); //order loop maintains while isOrderded is false
	printCheck(menuList, customerOrder, counter);//calculate and print check after customer orders

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
void getData(ifstream& input, MenuItemType menuList[])
{
	for (int i = 0; i < 8; i++)
	{
		getline(input, menuList[i].menuItem);//get string of item name and store in struct array using getline
		input >> menuList[i].menuPrice;//store item price in sturct array
		input.ignore(1);//use to ignore newline
	}
	
}
void showMenu(MenuItemType menuList[], int customerOrder[], int foodChoice, int &counter)
{
	cout << "Welcome to Johnny's Restaurant" << endl;
	cout << setprecision(2) << fixed;//format menu

	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << ". " << setw(15)//display numbers for items so customers can order while formatted properly
			 << left << menuList[i].menuItem
			 << right << setw(10) << '$'
			 << menuList[i].menuPrice << endl;
	}

	while (foodChoice != 0)
	{
		cout << "Enter the number of the item you wish to order" << endl;
		cout << "To confirm and end order enter '0'" << endl;
		cin >> foodChoice;
		cout << endl;

		//customer input palces order number in order array
		if (foodChoice == 1) {
			customerOrder[counter] = 0;
			counter++;
		}
		if (foodChoice == 2) {
			customerOrder[counter] = 1;
			counter++;
		}
		if (foodChoice == 3) {
			customerOrder[counter] = 2;
			counter++;
		}
		if (foodChoice == 4) {
			customerOrder[counter] = 3;
			counter++;
		}
		if (foodChoice == 5) {
			customerOrder[counter] = 4;
			counter++;
		}
		if (foodChoice == 6) {
			customerOrder[counter] = 5;
			counter++;
		}
		if (foodChoice == 7) {
			customerOrder[counter] = 6;
			counter++;
		}
		if (foodChoice == 8) {
			customerOrder[counter] = 7;
			counter++;
		}
		if (foodChoice == 0) {
			break;//when zero break out of if
		}
	}
	menuList->isOrdered == true;//when if broken set to true to break out of order loop
}
void printCheck(MenuItemType menuList[], int customerOrder[], int &counter) 
{
	double price = 0.0, tax = 0.0, total; //variables to calc order

	cout << "Welcome to Johnny's Restaurant" << endl;
	cout << showpoint << setprecision(2) << fixed;

	for (int i = 0; i < counter; i++) //only loop through actual space used by customer
	{
		cout << setw(15) << left << menuList[customerOrder[i]].menuItem 
			 << right << setw(10) << '$' << menuList[customerOrder[i]].menuPrice << endl;//order array number to find menu names and prices and output what customer ordered
		price = price + menuList[customerOrder[i]].menuPrice;//repeat calc for every iteration
	}

	tax = 0.05 * price;//calc tax
	total = tax + price;//calc total

	//output check in proper format
	cout << setw(15) << left << "Tax" << right << setw(10) << '$' << tax << endl;
	cout << setw(15) << left << "Amount Due" << right << setw(10) << '$' << total << endl;
}