#pragma once

#include "linklist.h"
#include <string>
using namespace std;

class bank
{
private:
	string fileName;

	linklist *outTheDoorQueue;

	linklist *expressQueue1;
	linklist *queue2;
	linklist *queue3;

public:
	bank();
	void bank::initializeBank(string fileName);
	void bank::printQueues();

	void printQueuesPretty();

	~bank();
	linklist * shortestLine(person person);
	linklist * emptyLine(person person);
	void bank::runSimulation();
};

