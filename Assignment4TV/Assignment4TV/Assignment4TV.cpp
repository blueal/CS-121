// Assignment4TV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

/* NAME: ALEX FRIEDBERG
DATE : 4 / 2 / 17
ASSIGNMENT : 4

TV SHOW PROGRAM
MAIN PROGRAM

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tree.h"

int main()
{
	cout << "Hello, World" << endl;
	bool parseFromFile = true;

	//linklist* outTheDoorQueue;

	string inputFile;

	cout << "What is the name of the file you would like to read? :" << endl;
	cin >> inputFile;

	cout << inputFile << endl;

	ifstream fin(inputFile);
	if (fin) {
		cout << "FILE OPENED" << endl;
	}
	else {
		cout << "FILE NOT FOUND" << endl;
	}

	tree *showDataBase = new tree;
	
	while (true)
	{
		string line;
		show *newShow = new show; 

		if (!getline(fin, line)) break;
		if (line.compare("") == 0) continue;
			
		newShow->parseNameAndDates(line);

		if (!getline(fin, line)) break;
		newShow->parseCategory(line);

		if (!getline(fin, line)) break;
		newShow->parseURL(line);

		while (getline(fin, line))
		{
			if (line.compare("") == 0) break;
			newShow->parseActor(line);
		}

		newShow->printShow();
	}

	
	return 0;
}

