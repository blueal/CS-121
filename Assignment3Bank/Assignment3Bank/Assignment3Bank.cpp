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
void parseFile(string fileName);
void parseFromInput();

int main() {
	cout << "Hello, World" << endl;

	bool parseFromFile = false;

	if (parseFromFile) {

		// string inputFile = "animals1.dat";
		string inputFile;

		cout << "What is the name of the file you would like to read? :" << endl;
		cin >> inputFile;



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

void parseFile(string fileName) {
linklist *list = new linklist;

ifstream fin;

//File Opened
fin.open(fileName.c_str());

string commandLine;
string word;

//Grab each line
getline(fin, commandLine);

//convert the first line from string to a stream
stringstream commandLineStream;
commandLineStream.str(commandLine);

//output first line
cout << commandLine << endl;

while (commandLineStream >> word) {
//    cout << word << '\n';
//The first line contians the intial list items,
//take each item and add it to the list.

list->addNameAtEnd(word);
}
cout << "INITIAL LIST: ";
list->printList();
list->printCountList();

//Read the rest of the file until EOF
while (getline(fin, commandLine)) {

cout << commandLine << endl;
list->processCommand(commandLine);
list->printList();
}

cout << "FINAL LIST: ";
list->printList();
list->printList();
list->printCountList();

//Read the rest of the file until EOF
while (getline(fin, commandLine)) {

cout << commandLine << endl;
list->processCommand(commandLine);
list->printList();
}

cout << "FINAL LIST: ";
list->printList();

list->printCountList();

fin.close();
}
*/

/*END OF FILE*/


