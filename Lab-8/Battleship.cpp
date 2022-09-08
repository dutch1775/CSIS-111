/*
	Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a ‘~’ character entry in the array represents ocean (i.e., not a ship), a ‘#’ character represents a place in the ocean where part of a ship is present, and a ‘H’ character represents a place in the ocean where part of a ship is present and has been hit by a torpedo. Thus, a ship with all ‘H’ characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents the entire ocean and an If statement that prints “HIT” if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game board with 25 lines where each line has 25 characters corresponding to the description above.

	You should write a function called Fire that will take an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed. If a ship is HIT you should update the array with an ‘H’ character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print “HIT AGAIN”. You should write a second function called FleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at which point the program should display “The fleet was destroyed!”.

	Your game loop logic (the main logic of a game) should like like the following:

	do {
		Fire(x, y, gameBoard);
	} while(!FleetSunk(gameBoard));
*/
//CSIS 111-002
//Malik, CH.8, Section 8-6f; 

//Include statements
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const int ROWS = 25;
const int COLS = 25;

//Function prototypes
void wait();
void fire(char gameboard[ROWS][COLS], int xCor, int yCor);
bool fleetSunk(char gameboard[ROWS][COLS]);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Michael Dutchin -- Lab 8" << endl << endl;

	//Variable declarations
	char gameboard[ROWS][COLS] = { };
	ifstream gameboardFile;
	int xCor = 0, yCor = 0;

	//Program logic
	//open the file for the gameboard and initialize an array with the file data
	gameboardFile.open("game.DAT");
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			gameboardFile >> gameboard[i][j];

	//run the loop to have user input coorindates and sink ships
	do {
	
		//call function 
		fire(gameboard, xCor, yCor);

	} while (!fleetSunk(gameboard));//continue function while false

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
	cout << endl;
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
void fire(char gameboard[ROWS][COLS], int xCor, int yCor)
{
	//prompt user or coordinates
	cout << "Enter the coordinates you wish to fire upon (1- 25 inclusive)" << endl;
	cout << "Enter x-coordinate: ";
	cin >> xCor;
	cout << "Enter y-coordinate: ";
	cin >> yCor;

	//if statements for coordinates
	if (gameboard[yCor - 1][xCor - 1] == '~')//if ~ then miss
	{
		cout << "MISS";
	}
	else if (gameboard[yCor - 1][xCor - 1] == '#')// if # then hit and replace with H
	{
		cout << "HIT";
		gameboard[yCor - 1][xCor - 1] = 'H';
	}
	else if (gameboard[yCor - 1][xCor - 1] == 'H')//if H then hit again
	{
		cout << "HIT AGAIN";
	}
	cout << endl;
}
bool fleetSunk(char gameboard[ROWS][COLS])
{
	//loop through gameboard array
	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++)
		{
			gameboard[i][j];
				if (gameboard[i][j] == '#')//if # is anywhere in array return false or continue loop
				{
					return false;
				}
		}
	}
	//if no # found then game is over print statement and return true
	cout << "The fleet was destroyed!" << endl;

	//print gameboard
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << gameboard[i][j] << ' ';
		cout << endl << endl;
	}

	return true;
}