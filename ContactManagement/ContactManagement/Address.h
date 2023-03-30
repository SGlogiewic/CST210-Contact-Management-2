#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Address
{
private:
	//creates data members for street, state, and zip
	string street, state, zip;
public:
	//default constructor
	Address();
	//parameterized constructor
	Address(string street, string state, string zip);
	//getters and setters for data members
	string getStreet() const;
	void setStreet(string street);
	string getState() const;
	void setState(string state);
	string getZip() const;
	void setZip(string zip);
	//friend overloaded functions to control outputs and inputs
	friend ostream& operator<< (ostream& out, const Address& rhs);
	friend istream& operator>>(istream& in, Address& rhs);


};
