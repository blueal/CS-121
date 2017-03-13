#include "stdafx.h"
#include "bank.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

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
	
	//outTheDoorQueue->printList();

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

void bank::printQueuesPretty() {

	cout << setw(15) << "outTheDoorQueue:" << setw(15) << "Queue1:" << setw(15) << "Queue2:" << setw(15) << "Queue3:" << endl;

	for (int i = 0;
		i < outTheDoorQueue->countList() ||
		i < expressQueue1->countList() ||
		i < queue2->countList() ||
		i < queue3->countList();
		i++) {

		//Out The Door
		if (i < outTheDoorQueue->countList()) {
			cout << setw(15) << "(" + to_string(outTheDoorQueue->getData(i).getEntryTime()) + ") " + outTheDoorQueue->getData(i).getName();
		}
		else {
			cout << setw(15) << "";
		}

		//Queue1
		if (i < expressQueue1->countList()) {
			cout << setw(15) << expressQueue1->getData(i).getName() + "(" + to_string(expressQueue1->getData(i).getWorkLeftToDo()) + ", " + 
				expressQueue1->getData(i).getActivity() + ")";
		}
		else {
			cout << setw(15) << "";
		}

		//Queue2
		if (i < queue2->countList()) {
			cout << setw(15) << queue2->getData(i).getName() + "(" + to_string(queue2->getData(i).getWorkLeftToDo()) + ", " +
				queue2->getData(i).getActivity() + ")";
		}
		else {
			cout << setw(15) << "";
		}

		//Queue3
		if (i < queue3->countList()) {
			cout << setw(15) << queue3->getData(i).getName() + "(" + to_string(queue3->getData(i).getWorkLeftToDo()) + ", " +
				queue3->getData(i).getActivity() + ")";
		}
		else {
			cout << setw(15) << "";
		}

		cout << endl;

	}

	cout << endl;
	
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
		if (shortestLine->countList() >= expressQueue1->countList()) {
			shortestLine = expressQueue1;
		}
	}

	return shortestLine;
}



//Returns the first open line, 123, ignores express if not eligible, prefers express if available
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
	cout << "**********START*OF*SIMULATION**********" << endl;
	for (int ticker = 0;
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

		//A customer may move to another line only if that line is empty, 321
		if (queue3->countList() > 1) {
			if (emptyLine(queue3->peekAtEnd()) != NULL) {
				emptyLine(queue3->peekAtEnd())->addAtEnd(queue3->removeAtEnd());
			}
		}
		if (queue2->countList() > 1) {
			if (emptyLine(queue2->peekAtEnd()) != NULL) {
				emptyLine(queue2->peekAtEnd())->addAtEnd(queue2->removeAtEnd());
			}
		}
		if (expressQueue1->countList() > 1) {
			if (emptyLine(expressQueue1->peekAtEnd()) != NULL) {
				emptyLine(expressQueue1->peekAtEnd())->addAtEnd(expressQueue1->removeAtEnd());
			}
		}

		//Express line transactions take two clock cycles, the other lines process
		//transactions at the rate of one transaction for each four clock cycles.

		if (queue3->countList() > 0) {
			person personBeingHelped = queue3->removeAtBegin();
			if (personBeingHelped.getWorkLeftToDo() == NOT_HELPED_YET) {
				//Calculate work
				personBeingHelped.setWorkLeftToDo(4 * personBeingHelped.getNumTransactions());
			}
			if (personBeingHelped.doWork() > 0) {
				queue3->addAtBegin(personBeingHelped);
			}
		}
		if (queue2->countList() > 0) {
			person personBeingHelped = queue2->removeAtBegin();
			if (personBeingHelped.getWorkLeftToDo() == NOT_HELPED_YET) {
				//Calculate work
				personBeingHelped.setWorkLeftToDo(4 * personBeingHelped.getNumTransactions());
			}
			if (personBeingHelped.doWork() > 0) {
				queue2->addAtBegin(personBeingHelped);
			}
		}
		if (expressQueue1->countList() > 0) {
			person personBeingHelped = expressQueue1->removeAtBegin();
			if (personBeingHelped.getWorkLeftToDo() == NOT_HELPED_YET) {
				//Calculate work
				personBeingHelped.setWorkLeftToDo(2 * personBeingHelped.getNumTransactions());
			}
			if (personBeingHelped.doWork() > 0) {
				expressQueue1->addAtBegin(personBeingHelped);
			}
		}

		cout << "TICK: " << ticker << endl;
		printQueuesPretty();

	}

	cout << "**********END*OF*SIMULATION**********" << endl;
}