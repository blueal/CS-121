#pragma once
using namespace std;
#include <string>
#include "linklist.h"

class show
{
private:
	string name;
	string url;
	int yearStart;
	int yearEnd;
	string category;
	
	linklist *actors;


public:

	show();
	void parseNameAndDates(string firstLine);

	void parseCategory(string line);

	void parseURL(string line);

	void parseActor(string line);

	void printShow();
	void printActors();

	bool isSameShow(show * otherShow);
	bool containsActorName(string actorToFind);
	void setName(string name);
	void setStartYear(int startYear);
	void setEndYear(int endYear);
	void setCategory(string category);

	string getName();
	int getStartYear();
	int getEndYear();
	string getCategory(string category);

	//ADD OTHER FUNCTIONS HERE;
};
