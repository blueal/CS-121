/*
ALEX FRIEDBERG

LINKED LIST .cpp
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "linklist.h"

using namespace std;

linklist::linklist() {
	head = NULL;
}

void linklist::removeName(string name) {

	LinkListEntry *n = new LinkListEntry;

	LinkListEntry *curr;
	LinkListEntry *prev;
	prev = NULL;

	for (curr = head; curr != NULL; curr = curr->next) {
		if (curr->name.compare(name) == 0) {
			if (prev == NULL) {
				//First Entry in list
				head = curr->next;
				delete curr;
			}
			else {
				//more then one entry in list
				prev->next = curr->next;
				delete curr;
			}
			return;
		}
		prev = curr;
	}
	cout << "ERROR: '" << name << "' not found in list" << endl;

}


void linklist::addNameAtEnd(string name) {

	LinkListEntry *n = new LinkListEntry;

	LinkListEntry *curr;
	LinkListEntry *prev;
	prev = NULL;

	for (curr = head; curr != NULL; curr = curr->next) {
		prev = curr;
	}

	//  LinkListEntry *n = new linkListEntry;

	n->name = name;
	n->next = NULL;
	if (head != NULL) {
		prev->next = n;
	}
	else {
		head = n;
	}
}


void linklist::printCountList() {

	//Create another linklist that is similar to the original list, except:
	//The list contains no duplicates
	//An additional value is stored and used, 'count'

	LinkListEntry *curr;
	typedef struct LinkListCountedEntry
	{
		LinkListCountedEntry *next;
		string name;
		int count;
	} LinkListCountedEntry;

	LinkListCountedEntry *countedHead;
	LinkListCountedEntry *countedCurr;
	LinkListCountedEntry *countedPrev;

	countedHead = NULL;
	//linklist *countList = new linklist;
	//linklist *countListCurr;


	for (curr = head; curr != NULL; curr = curr->next) {
		//Walk the array
		bool isInList = false;
		countedPrev = NULL;
		for (countedCurr = countedHead; countedCurr != NULL; countedCurr = countedCurr->next) {
			if (countedCurr->name.compare(curr->name) == 0) {
				//Name is already in list
				isInList = true;
				break;
			}
			countedPrev = countedCurr;
		}
		//first mention in list, make a new entry
		if (isInList) {
			countedCurr->count++;
		}
		else {
			countedCurr = new LinkListCountedEntry;
			countedCurr->name = curr->name;
			countedCurr->count = 1;
			countedCurr->next = NULL;
			if (countedPrev == NULL) {
				//begining of list
				countedHead = countedCurr;
			}
			else {
				countedPrev->next = countedCurr;
			}
		}
	}

	//  cout << "WE GOT TO HERE 1"<<endl;
	for (countedCurr = countedHead; countedCurr != NULL; countedCurr = countedCurr->next) {

		cout << countedCurr->name << " (" << countedCurr->count << ")";
		if (countedCurr->next != NULL) {
			cout << ", ";
		}

	}
	//  cout << "WE GOT TO HERE 2"<< endl;

	cout << endl;
}

void linklist::processCommand(string commandLine) {

	//  cout <<  commandLine <<endl;

	//Convert the line to a stream
	stringstream commandLineStream2;
	string word;
	commandLineStream2.str(commandLine);
	commandLineStream2 >> word;
	//cout << word << endl;

	if (word.compare("delete") == 0 || word.compare("remove") == 0) {
		//delete command received
		string whatToDelete;
		commandLineStream2 >> whatToDelete;
		//        cout << "DELETE COMMAND: " << whatToDelete << endl;
		//list->removeName(whatToDelete);
		removeName(whatToDelete);
	}
	else if (word.compare("add") == 0) {
		//add command received
		string whatToAdd;
		commandLineStream2 >> whatToAdd;
		//      cout << "ADD COMMAND: " << whatToAdd << endl;
		// list->addNameAtEnd(whatToAdd);
		addNameAtEnd(whatToAdd);

	}
	//  cout << "CURRENT LIST: ";
	// printList();


}


void linklist::printList() {
	LinkListEntry *curr;

	for (curr = head; curr != NULL; curr = curr->next) {
		//WALK THE LIST
		cout << curr->name;
		if (curr->next != NULL) {
			cout << ", ";
		}

	}
	cout << endl;


}
