// Assignment4TV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

/* NAME: ALEX FRIEDBERG
DATE : 2 / 11 / 17
ASSIGNMENT : 3

BANK PROGRAM
MAIN PROGRAM

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
	cout << "Hello, World" << endl;
	bool parseFromFile = true;

	//linklist* outTheDoorQueue;

	string inputFile;

	cout << "What is the name of the file you would like to read? :" << endl;
	cin >> inputFile;

	bank *myBank = new bank;

	myBank->initializeBank(inputFile);

	//myBank->printQueues();

	myBank->runSimulation();


	return 0;
	return 0;
}

