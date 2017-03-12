
#include "stdafx.h"
#include <iostream>
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




}