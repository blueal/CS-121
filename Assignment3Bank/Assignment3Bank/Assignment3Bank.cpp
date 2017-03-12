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

using namespace std;
linklist *parseFile(string fileName);
void parseFromInput();

int main() {
	cout << "Hello, World" << endl;

	bool parseFromFile = true;

	if (parseFromFile) {

		// string inputFile = "animals1.dat";
		string inputFile;

		cout << "What is the name of the file you would like to read? :" << endl;
		cin >> inputFile;

		parseFile(inputFile);



	}
	else {

		//parseFromInput();

		linklist *list = new linklist;

		list->addAtBegin("BEGIN-TEST1");
		list->printList();
		list->addAtBegin("BEGIN-TEST2");
		list->printList();
		list->addAtEnd("END-TEST3");
		list->printList();

		cout << "RETURN: " << list->removeAtBegin() << endl;
		list->printList();
		cout << "RETURN: " << list->removeAtEnd() << endl;
		list->printList();
		cout << "RETURN: " << list->removeAtBegin() << endl;
		list->printList();
		cout << "RETURN: " << list->removeAtBegin() << endl;
		list->printList();

	}

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
*/
linklist *parseFile(string fileName) {
	cout << "OPENING FILE: " << fileName << endl;
	linklist *list = new linklist;

	ifstream fin;

	//File Opened
	fin.open(fileName.c_str());
	//cout << "OPENED FILE: " << fileName << endl;
	string commandLine;

	
	//Read the rest of the file until EOF
	while (getline(fin, commandLine)) {
		//person *person = new person;
		cout << commandLine << endl;
		//list->processCommand(commandLine);
		//list->printList();
	}

	fin.close();

	return list;
}

/*END OF FILE*/


