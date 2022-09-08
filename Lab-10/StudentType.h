#pragma once

#include <string>

class StudentType
{
private:

	std::string studentFName;

	std::string studentLName;

	int testScore; //test score must be between 0 and 100

	char grade;

public:

	void setFirstName(std::string firstName);

	void setLastName(std::string lastName);

	void setTestScore(int score);

	void setGrade(char gr);

	std::string getFirstName() const;

	std::string getLastName() const;

	int getTestScore() const;

	char getGrade() const;
};