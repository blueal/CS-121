#pragma once
using namespace std;
#include <string>

class show
{
private:
	string name;
	int yearStart;
	int yearEnd;
	string category;
	
	/*TODO: Figure out what to do with multiple actors*/
	string actor;


public:

	show();
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
