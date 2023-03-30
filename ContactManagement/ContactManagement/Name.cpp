#include "Name.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
Name::Name()
{
	firstName = "";
	lastName = "";
}

//parameterized constructor
Name::Name(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

//getter for firstName
string Name::getFirstName() const
{
	return firstName;
}

//setter for firstName
void Name::setFirstName(string firstName)
{
	this->firstName = firstName;
}

//getter for lastName
string Name::getLastName() const
{
	return lastName;
}

//setter for lastName
void Name::setLastName(string lastName)
{
	this->lastName = lastName;
}

//getter for the full name
string Name::getFullName() const
{
	return getLastName() + ", " + getFirstName();
}

//function that overloads << operator to output info
ostream& operator<<(ostream& out, const Name& rhs)
{
	out << rhs.lastName << ", " << rhs.firstName;
	return out;
}

//function that overloads >> operator to take in info
istream& operator>>(istream& in, Name& rhs)
{
	getline(in, rhs.lastName);
	getline(in, rhs.firstName);
	return in;
}
