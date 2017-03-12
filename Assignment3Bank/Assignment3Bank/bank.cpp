#include "stdafx.h"
#include "bank.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bank::bank() {
	outTheDoorQueue = new linklist;
	expressQueue1 = new linklist;
	queue2 = new linklist;
	queue3 = new linklist;

}

void bank::initializeBank(string fileName)
{

	ifstream fin(fileName);
	if (fin) {
		cout << "FILE OPENED" << endl;
	}
	else {
		cout << "FILE NOT FOUND" << endl;
	}

	string commandLine;
	this->fileName = fileName;

	//Read the rest of the file until EOF
	while (getline(fin, commandLine)) {
		person person;

		person.parsePerson(commandLine);
		//person.printPerson();

		outTheDoorQueue->addAtEnd(person);
	}
	
	outTheDoorQueue->printList();

	fin.close();

}

void bank::printQueues() {

	cout << "outTheDoorQueue:" << endl;
	outTheDoorQueue->printList();
	cout << endl;
	cout << "expressQueue1: " << endl;
	expressQueue1->printList();
	cout << endl;
	cout << "queue2: " << endl;
	queue2->printList();
	cout << endl;
	cout << "queue3: " << endl;
	queue3->printList();
}

bank::~bank()
{
}

linklist *bank::shortestLine(person person) {
	linklist *shortestLine = NULL;

	if (queue3->countList() > queue2->countList()) {
		shortestLine = queue2;
	}
	else
	{
		shortestLine = queue3;
	}

	if (person.getActivity() == 'C' ||
		person.getActivity() == 'D') {
		//Express Eligible
		if (shortestLine->countList() > expressQueue1->countList()) {
			shortestLine = expressQueue1;
		}
	}

	return shortestLine;
}



//Returns the first open line, 321, ignores express if not eligible, prefers express if available
linklist *bank::emptyLine(person person) {
	if (person.isExpressEligible() && expressQueue1->countList() == 0) {
		return expressQueue1;
	}
	else if (queue2->countList() == 0) {
		return queue2;
	}
	else if(queue3->countList() == 0) {
		return queue3;
	}
	else {
		return NULL;
	}


}

void bank::runSimulation() {
	for (int ticker = 1;
		outTheDoorQueue->countList() > 0 ||
		expressQueue1->countList() > 0 ||
		queue2->countList() > 0 ||
		queue3->countList() > 0;
		ticker++) {

		//While people are waiting, out the door, if it's their time, let them in, put them in the shortest line

		while(outTheDoorQueue->countList() > 0 && outTheDoorQueue->peekAtBegin().getEntryTime() == ticker) {
			//Time to come inside
			//Find the shortest line and put them in it
			person nextPerson = outTheDoorQueue->removeAtBegin();
			shortestLine(nextPerson)->addAtEnd(nextPerson);
				
		}

		//A customer may move to another line only if that line is empty
		
		
		printQueues();
	}
}