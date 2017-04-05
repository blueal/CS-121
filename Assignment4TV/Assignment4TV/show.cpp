/*
ALEX FRIEDBERG

tree .cpp
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "show.h"

using namespace std;

show::show() {
	name = "";
	url = "";
	yearStart = 0000;
	yearEnd = 0000;
	category = "";

	actors = new linklist;
}

void show::parseNameAndDates(string line)
{
	int dateIndex = line.find("(");
	this->name = line.substr(0, dateIndex - 1);
	this->yearStart = stoi(line.substr(dateIndex+1, 4));
	this->yearEnd = stoi(line.substr(dateIndex+6, 4));

}

void show::parseCategory(string line)
{
	this->category = line;
}

void show::parseURL(string line)
{
	this->url = line;

}

void show::parseActor(string line) {
	this->actors->addAtEnd(line);
}


void show::printShow()
{
	cout << name << ", " << yearStart << ", " << yearEnd << endl;
	cout << category << endl;
	cout << url << endl;
	actors->printList();
	cout << endl;
}

bool show::isSameShow(show *otherShow) {
	if (this->name.compare(otherShow->name) != 0)
		return false;
	if (this->category.compare(otherShow->category) != 0)
		return false;
	if (this->url.compare(otherShow->url) != 0)
		return false;
	if (this->yearStart != otherShow->yearStart || this->yearEnd != otherShow->yearEnd)
		return false;
	if (this->actors->countList() != otherShow->actors->countList())
		return false;
	for (int i = 0; i < this->actors->countList(); i++) {
		if (this->actors->getData(i).compare(otherShow->actors->getData(i)) != 0)
			return false;
	}


	return true;
}

bool show::containsActorName(string actorToFind)
{
	for (int i = 0; i < this->actors->countList(); i++) {
		if (this->actors->getData(i).compare(actorToFind) == 0)
			return true;
	}
	return false;
}

int show::getStartYear()
{
	return this->yearStart;
}

int show::getEndYear()
{
	return this->yearEnd;
}

string show::getName() {
	return this->name;
}

void show::printActors(){
	this->actors->printList();
}