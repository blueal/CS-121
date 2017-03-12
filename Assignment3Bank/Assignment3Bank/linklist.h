#pragma once



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
	string removeAtEnd();
	string removeAtBegin();
	void addNameAtEnd(string name);
	void addNameAtBegin(string name);
	void printList();
	//ADD OTHER FUNCTIONS HERE;
};
