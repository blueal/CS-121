#pragma once



#include <string>
#include "person.h"
#define LINK_LIST_ENTRY_TYPE person
using namespace std;

class linklist
{
private:
	typedef struct LinkListEntry
	{

		LinkListEntry *next;
		LINK_LIST_ENTRY_TYPE data;
	} LinkListEntry;

	LinkListEntry *head;

public:

	linklist();
	//void removeData(LINK_LIST_ENTRY_TYPE data);
	LINK_LIST_ENTRY_TYPE removeAtEnd();
	LINK_LIST_ENTRY_TYPE removeAtBegin();
	void addAtEnd(LINK_LIST_ENTRY_TYPE data);
	void addAtBegin(LINK_LIST_ENTRY_TYPE data);
	void printList();
	LINK_LIST_ENTRY_TYPE peekAtBegin();
	LINK_LIST_ENTRY_TYPE peekAtEnd();
	LINK_LIST_ENTRY_TYPE linklist::getData(int itemInList);
	int linklist::countList();
	//ADD OTHER FUNCTIONS HERE;
};
