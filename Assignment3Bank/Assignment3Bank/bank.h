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

	~bank();
	void bank::runSimulation();
};

