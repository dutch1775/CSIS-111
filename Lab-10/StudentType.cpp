#include "StudentType.h"
#include <string>
#include <iostream>

using namespace std;

//Your class implementation functions go below

void StudentType::setFirstName(std::string firstName)
{
	studentFName = firstName;
}

void StudentType::setLastName(std::string lastName)
{
	studentLName = lastName;
}

void StudentType::setTestScore(int score)
{
	if (score < 0 || score > 100) //if test score not 1-100 then sets 0
		testScore = 0;
	else                          //if test score is 1-100 then set user input
		testScore = score;
}

void StudentType::setGrade(char gr)
{
	grade = gr;
}

std::string StudentType::getFirstName() const
{
	return studentFName;
}

std::string StudentType::getLastName() const
{
	return studentLName;
}

int StudentType::getTestScore() const
{
	return testScore;
}

char StudentType::getGrade() const
{
	return grade;
}