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

void bank::runSimulation() {
	for (int ticker = 1;
		outTheDoorQueue->countList() > 0 &&
		expressQueue1->countList() > 0 &&
		queue2->countList() > 0 &&
		queue3->countList() > 0;
		ticker++) {

		//Check if someone is waiting, out the door, let them in

		if (outTheDoorQueue->countList() > 0) {
			person person = outTheDoorQueue->removeAtBegin();

			if (person.getActivity() == 'C' || person.getActivity() == 'D') {
				//EXPRESS LANE ELIGIBLE

			}
		}

	}
}