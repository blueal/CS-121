#pragma once
/*
ALEX FRIEDBERG
LINK LIST .h FILE
*/

#include <string>
using namespace std;

class linklist
{
private:
	typedef struct LinkListEntry
	{
		LinkListEntry *next;
		string name;
	} LinkListEntry;

	LinkListEntry *head;

public:

	linklist();
	void removeName(string name);
	void addNameAtEnd(string name);
	void printCountList();
	void printList();
	void processCommand(string commandLine);
	//ADD OTHER FUNCTIONS HERE;
};









