
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "person.h"

using namespace std;

//Constructor
person::person() {
	this->entryTime = 0;
	this->name = "";
	/*
	C = Cash
	D = Deposit
	N = New Account
	R = Reconcile Account
	? = UNKNOWN
	*/
	this->activity = '?';
	this->numTransactions = 0;
}

/*SETTERS*/
void person::setEntryTime(int newEntryTime) {
	this->entryTime = newEntryTime;
}

void person::setName(string newName) {
	this->name = newName;
}

void person::setActivity(char newActivity) {
	this->activity = newActivity;
}

void person::setNumTransactions(int newNumTransactions) {
	this->numTransactions = newNumTransactions;
}


/*GETTERS*/
int person::getEntryTime() {
	return this->entryTime;
}

string person::getName() {
	return this->name;
}

char person::getActivity() {
	return this->activity;
}

int person::getNumTransactions() {
	return this->numTransactions;
}

/*PARSER*/

void person::parsePerson(string commandLine) {
	stringstream commandLineStream;
	commandLineStream.str(commandLine);

	commandLineStream >> this->entryTime;
	commandLineStream >> this->name;
	commandLineStream >> this->activity;
	commandLineStream >> this->numTransactions;
}

void person::printPerson() {
	cout << "TIME: " << setw(3) << getEntryTime();
	cout << "\tNAME: " << setw(10) << getName();
	cout << "\tACTIVITY: " << setw(3) << getActivity();
	cout << "\tTRANSACTIONS: " << setw(3) << getNumTransactions();
	cout << endl;
}

bool person::isExpressEligible() {
	return (this->getActivity() == 'C' || this->getActivity() == 'D');
}