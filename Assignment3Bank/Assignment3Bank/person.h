#pragma once
/*
ALEX FRIEDBERG
ASSIGNMENT 3

PERSON CLASS.h
*/


#include <string>
using namespace std;

class person
{
private:
	int entryTime;
	string name;
	/*
	C = Cash
	D = Deposit
	N = New Account
	R = Reconcile Account
	*/
	char activity;
	int numTransactions;


public:

	person();
	void setEntryTime(int newEntryTime);
	void person::setName(string newName);
	void person::setActivity(char newActivity);
	void person::setNumTransactions(int newNumTransactions);

	void printPerson();
	//ADD OTHER FUNCTIONS HERE;
};
