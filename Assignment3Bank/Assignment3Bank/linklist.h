#pragma once



#include <string>
#define DATATYPE string
using namespace std;

class linklist
{
private:
	typedef struct LinkListEntry
	{

		LinkListEntry *next;
		DATATYPE data;
	} LinkListEntry;

	LinkListEntry *head;

public:

	linklist();
	void removeData(DATATYPE data);
	DATATYPE removeAtEnd();
	DATATYPE removeAtBegin();
	void addAtEnd(DATATYPE data);
	void addAtBegin(DATATYPE data);
	void printList();
	//ADD OTHER FUNCTIONS HERE;
};
