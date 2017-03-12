// Assignment3Bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

#include "linklist.h"
#include "person.h"
#include "bank.h"

using namespace std;

//void parseFromInput();

int main() {
	cout << "Hello, World" << endl;
	bool parseFromFile = true;

	//linklist* outTheDoorQueue;

	string inputFile;

	cout << "What is the name of the file you would like to read? :" << endl;
	cin >> inputFile;

	bank *myBank = new bank;
	
	myBank->initializeBank(inputFile);
	
	myBank->printQueues();

	myBank->runSimulation();
	

	return 0;
}



/*
void parseFromInput(){
linklist *list = new linklist;

bool takingInput = true;
while(takingInput){
string commandLine;
cout << "Type your command (type q to quit): " << endl;
getline(cin, commandLine);

if(commandLine.compare("q") == 0){
takingInput = false;
}else{
list->processCommand(commandLine);
}

list->printList();
list->printCountList();
}
}

linklist *parseFile(string fileName) {
	
	linklist *list = new linklist;

	ifstream fin(fileName);
	if (fin) {
		cout << "FILE OPENED" << endl;
	}
	else {
		cout << "FILE NOT FOUND" << endl;
	}
	
	string commandLine;

	
	//Read the rest of the file until EOF
	while (getline(fin, commandLine)) {
		person person;

		person.parsePerson(commandLine);
		//person.printPerson();

		list->addAtEnd(person);
	}

	fin.close();

	//list->printList();
	return list;
}
*/
/*END OF FILE*/


