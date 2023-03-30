#pragma once
#include <iostream>
#include <fstream>
#include "Address.h"
#include "Name.h"

using namespace std;

class Contact
{
private:
	//creates data members for name, address, phone, and id
	Name name;
	Address address;
	string phone;
	int id;

	//private setID function to update ID
	void setID();
public:
	//creates public int to monitor count of elements
	static int totalCt;

	//default constructor
	Contact();
	//parameterized constructor
	Contact(string fName, string lName, string street, string state, string zip);
	//copy constructor
	Contact(const Contact& c);
	//getters and setters for data members
	string getName();
	void setPhone(string phone);
	string getPhone();
	int getID();
	void setName(string fName, string lName);
	string getLName();
	string getAddress();
	void setAddress(string street, string state, string zip);
	//friend overloaded functions to control outputs and inputs
	friend ostream& operator<<(ostream& out, const Contact& rhs);
	friend istream& operator>>(istream& in, Contact& rhs);
};
