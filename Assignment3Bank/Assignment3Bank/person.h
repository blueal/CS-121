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
	int transactions;


public:

	person();
	void printPerson();
	//ADD OTHER FUNCTIONS HERE;
};
