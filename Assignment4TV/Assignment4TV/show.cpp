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
}
