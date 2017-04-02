/* NAME: ALEX FRIEDBERG
DATE: 2/11/17
ASSIGNMENT: 2

MAIN PROGRAM

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "linklist.h"

using namespace std;
void parseFile(string fileName);
void parseFromInput();

int main() {
	cout << "Hello, World" << endl;

	// string inputFile = "animals1.dat";
	string inputFile;

	//  cout << "What is the name of the file you would like to read? 'animals1.dat' or  'animals2.dat' " << endl;
	// cin >> inputFile;

	inputFile = "animals1.dat";
	parseFile(inputFile);
	inputFile = "animals2.dat";
	parseFile(inputFile);

	// parseFromInput();



	return 0;
}

void parseFromInput() {
	linklist *list = new linklist;

	bool takingInput = true;
	while (takingInput) {
		string commandLine;
		cout << "Type your command (type q to quit): " << endl;
		getline(cin, commandLine);

		if (commandLine.compare("q") == 0) {
			takingInput = false;
		}
		else {
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
		/*
		* Command is processed in linklist class
		*/
	}

	cout << "FINAL LIST: ";
	list->printList();

	list->printCountList();

	fin.close();
}





