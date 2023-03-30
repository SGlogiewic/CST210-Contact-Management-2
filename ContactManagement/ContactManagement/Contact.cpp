#include "Address.h"
#include "Contact.h"
#include "Name.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//initializes totalCt 
int Contact::totalCt = 0;

//setter for id
void Contact::setID()
{
	totalCt++;
	id = totalCt;
}

//deafault constructor
Contact::Contact()
{
	this->name = Name();
	this->address = Address();
	this->phone = " xxx-xxx-xxxx";
	this->id = -1;
}

//parameterized constructor
Contact::Contact(string fName, string lName, string street, string state, string zip)
{
	this->name = Name(fName, lName);
	this->address = Address(street, state, zip);
}

//copy construtor
Contact::Contact(const Contact& c)
{
	this->name = c.name;
	this->address = c.address;
	this->phone = c.phone;
	this->id = c.id;
}

//getter for the full name
string Contact::getName()
{
	return name.getLastName() + ", " + name.getFirstName();
}

//getter for last name
string Contact::getLName()
{
	return name.getLastName();
}

//setter for phone
void Contact::setPhone(string phone)
{
	this->phone = phone;
}

//getter for phone
string Contact::getPhone()
{
	return phone;
}

//getter for id
int Contact::getID()
{
	return id;
}

//setter for name
void Contact::setName(string fName, string lName)
{
	name.setFirstName(fName);
	name.setLastName(lName);
}

//getter for address
string Contact::getAddress()
{
	return address.getStreet() + "\n" + address.getState() + "\n" + address.getZip();
}

//setter for address
void Contact::setAddress(string street, string state, string zip)
{
	address.setStreet(street);
	address.setState(state);
	address.setZip(zip);
}

//function that overloads << operator to output info
ostream& operator<<(ostream& out, const Contact& rhs)
{
	out << rhs.name.getFirstName() << "\n" << rhs.name.getLastName() << "\n" <<
		rhs.address.getStreet() << "\n" << rhs.address.getState()
		<< "\n" << rhs.address.getZip() << "\n" << rhs.phone;
	return out;
}

//function that overloads >> operator to take in info
istream& operator>>(istream& in, Contact& rhs)
{
	in >> rhs.name;
	in >> rhs.address;
	getline(in, rhs.phone);
	rhs.setID();
	return in;
}
