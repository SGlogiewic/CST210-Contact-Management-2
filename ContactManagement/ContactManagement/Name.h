#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Name
{
private:
	//creates data members for firstName and lastName
	string firstName, lastName;
public:
	//default constructor
	Name();
	//parameterized constructor
	Name(string firstName, string lastName);
	//getters and setters
	string getFirstName() const;
	void setFirstName(string firstName);
	string getLastName() const;
	void setLastName(string lastName);
	string getFullName() const;
	//friend overloaded functions to control outputs and inputs
	friend ostream& operator<< (ostream& out, const Name& rhs);
	friend istream& operator >> (istream& in, Name& rhs);
};
