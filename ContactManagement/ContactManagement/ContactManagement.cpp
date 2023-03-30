//Created by: Stephen Glogiewicz
#include "Contact.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//nameSearch function that searches vector of Contacts for the last name
void nameSearch(vector<Contact>& contVect)
{
	//creates string last for the user's input
	string last = "";
	//creates bool out to check if an output was found
	bool out = false;
	//prompts the user to enter in a last name to searcg
	cout << "\nEnter a last name to search: ";
	getline(cin, last);
	//for loop that runs trough every element in the vector to compare last names
	for (int i = 0; i < contVect.size(); i++)
	{
		//if the last name equals the last name of the currect element, prints out
		//element's info
		if (last == contVect[i].getLName())
		{
			cout << contVect[i] << endl;
			//sets out to true 
			out = true;
		}
	}
	//if out if false, prints out contact not found
	if (!out)
	{
		cout << "\nContact not found." << endl;
	}
}

//idSearch function that searches vector of Contacts for an id
void idSearch(vector<Contact>& contVect)
{
	//creates string idIn for the user's input
	string idIn = "";
	//creates bool out to check if an output was found
	bool out = false;
	cout << "\nEnter an id to search: ";
	getline(cin, idIn);
	//for loop that compares input to string version of the position of an element in
	//the vector and prints out info of that element
	for (int i = 0; i < contVect.size(); i++)
	{
		if (idIn == to_string(contVect[i].getID()))
		{
			cout << contVect[i] << endl;
			//sets out to true
			out = true;
		}
	}
	//if out if false, prints out contact not found
	if (!out)
	{
		cout << "\nConatct not found." << endl;
	}

}

//main function
int main()
{
	//opens contact.txt and address.txt file
	ifstream addressIn("contact.txt");
	ofstream addressOut("address.txt");
	//creates new vector of Contacts
	vector<Contact> contacts;
	//creates new Contact input
	Contact input;
	//creates strings needed for each input value
	string fName, lName;
	string street, state, zip;
	string phone;
	//checks to see if file is working
	if (!addressIn)
	{
		cout << "File not found" << endl;
		exit(50);
	}
	//puts every existing contact into the contacts array
	while (addressIn >> input)
	{
		contacts.push_back(input);
	}
	//creates string num to regulate for loop
	string num = "";
	//runs loop until user enters -1
	while (num != "-1")
	{
		//prompts user to enter in first and last name and stores them
		cout << "Enter first name: ";
		getline(cin, fName);
		cout << "\nEnter last name: ";
		getline(cin, lName);
		//sets name using setName function
		input.setName(fName, lName);
		//prompts user to enter street address, state, and zip
		cout << "\nEnter street address: ";
		getline(cin, street);
		cout << "\nEnter state: ";
		getline(cin, state);
		cout << "\nEnter zip: ";
		getline(cin, zip);
		//sets address using setAddress function
		input.setAddress(street, state, zip);
		//prompts user to enter phone number
		cout << "\nEnter phone number: ";
		getline(cin, phone);
		//sets phone using setPhone function
		input.setPhone(phone);
		//makes most recent input last element in vector
		contacts.push_back(input);
		//asks user if they want to stop entering daat
		cout << "\nEnter -1 to end: ";
		getline(cin, num);
		cout << "" << endl;
		//if the user enters number -1, stops while loop
		if (num == "-1")
		{
			break;
		}
	}
	//prints out all elements in contacts to the file
	for (int i = 0; i < contacts.size(); i++)
	{
		addressOut << contacts[i] << endl;
	}
	//creates string cont to control while loop
	string cont = "yes";
	//creates string sInput for user's input
	string sInput = "";
	//runs until user enters no
	while (cont != "no")
	{
		//asks user if they want to search for a contact
		cout << "\nDo you want to seach for a specific contact: ";
		getline(cin, cont);
		//sets input to lowercase
		for (int i = 0; i < cont.length(); i++)
		{
			cont[i] = tolower(cont[i]);
		}
		//if user enters yes, will search for a contact of the user's choice
		if (cont == "yes")
		{
			//prompts user to enter id or last name of contact depending on input
			cout << "\nTo search by id, enter 1. To search by last name enter 2: ";
			getline(cin, sInput);
			//if user enters 1, runs idSearch, and if 2 then nameSearch
			if (sInput == "1")
			{
				idSearch(contacts);
			}
			else if (sInput == "2")
			{
				nameSearch(contacts);
			}
		}
		//if user enters no, stops while loop
		else if (cont == "no")
		{
			break;
		}
	}
	//closes files
	addressIn.close();
	addressOut.close();
	return 0;
}