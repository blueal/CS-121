#pragma once
/*
ALEX FRIEDBERG
ASSIGNMENT 3

PERSON CLASS.h
*/


#include <string>
using namespace std;

#define NOT_HELPED_YET -1

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
	int workLeftToDo;


public:

	person();
	void setEntryTime(int newEntryTime);
	void person::setName(string newName);
	void person::setActivity(char newActivity);
	void person::setNumTransactions(int newNumTransactions);
	void setWorkLeftToDo(int newTime);
	
	int doWork();

	int person::getEntryTime();
	string person::getName();
	char person::getActivity();
	int person::getNumTransactions();
	int getWorkLeftToDo();


	void person::printPerson();
	bool isExpressEligible();
	void person::parsePerson(string commandLine);
	//ADD OTHER FUNCTIONS HERE;
};
