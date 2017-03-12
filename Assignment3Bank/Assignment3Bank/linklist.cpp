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

/*
void linklist::removeName(string name){

LinkListEntry *curr;
LinkListEntry *prev;
prev = NULL;

for(curr = head; curr != NULL; curr = curr->next){
if(curr->name.compare(name) == 0){
if(prev == NULL){
//First Entry in list
head = curr->next;
delete curr;
}else{
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
*/

string linklist::removeAtEnd() {
	LinkListEntry *prev;
	LinkListEntry *curr;
	string returnString = "";
	prev = NULL;

	for (curr = head; curr != NULL; curr = curr->next) {
		if (curr->next == NULL) {
			//Last Entry
			if (prev == NULL) {
				//First and only entry in list
				head = NULL;
			}
			else {
				prev->next = NULL;
			}
			returnString = curr->name;
			delete curr;
			break;
		}
		prev = curr;
	}

	return returnString;

}

string linklist::removeAtBegin() {
	LinkListEntry *prev;
	LinkListEntry *curr;
	string returnString = "";

	if (head != NULL) {
		curr = head;
		head = head->next;

		returnString = curr->name;
		delete curr;
	}
	return returnString;
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

void linklist::addNameAtBegin(string name) {

	LinkListEntry *n = new LinkListEntry; //NEW NODE

	LinkListEntry *curr;
	LinkListEntry *prev;

	n->name = name;

	n->next = head;
	head = n;

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
/*END OF FILE*/
