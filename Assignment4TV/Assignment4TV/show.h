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

	void setName(string name);
	void setStartYear(int startYear);
	void setEndYear(int endYear);
	void setCategory(string category);

	string getName(string name);
	int getStartYear(int startYear);
	int getEndYear(int endYear);
	string getCategory(string category);

	//ADD OTHER FUNCTIONS HERE;
};
