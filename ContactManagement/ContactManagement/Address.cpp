#include "Address.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
Address::Address()
{
	street = "";
	state = "";
	zip = "";
}

//parameterized constructor
Address::Address(string street, string state, string zip)
{
	this->street = street;
	this->state = state;
	this->zip = zip;
}

//getter for street
string Address::getStreet() const
{
	return street;
}

//setter for street
void Address::setStreet(string street)
{
	this->street = street;
}

//getter for state
string Address::getState() const
{
	return state;
}

//setter for state
void Address::setState(string state)
{
	this->state = state;
}

//getter for zip
string Address::getZip() const
{
	return zip;
}

//setter for zip
void Address::setZip(string zip)
{
	this->zip = zip;
}

//function that overloads << operator to print out info
ostream& operator<<(ostream& out, const Address& rhs)
{
	out << rhs.street << endl;
	out << rhs.state << endl;
	out << rhs.zip << endl;
	return out;
}

//function that overloads >> operator to take in info
istream& operator>>(istream& in, Address& rhs)
{
	getline(in, rhs.street);
	getline(in, rhs.state);
	getline(in, rhs.zip);
	return in;
}
