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

		//newShow->printShow();

		showDataBase->addToTree(newShow);
	}

	//showDataBase->displayAll();
	cout << "Display all shows in the tree (only the titles!)" << endl;
	showDataBase->displayAllTitles();
	cout << endl;

	cout << "Display all actors of a given show in the tree: The Saint, Benson, Dexter’s Laboratory, Matlock, Futurama" << endl;
	showDataBase->displayActorsByShowName("The Saint");
	showDataBase->displayActorsByShowName("Benson");
	showDataBase->displayActorsByShowName("Dexter's Laboratory");
	showDataBase->displayActorsByShowName("Matlock");
	showDataBase->displayActorsByShowName("Futurama");
	cout << endl;

	cout << "Display all shows of a given actor : Nancy Cartwright, Marcia Wallace, Bill Daily, Joe Penny, John DiMaggio, Ron Howard." << endl;
	showDataBase->displayShowsByActorName("Nancy Cartwright");
	showDataBase->displayShowsByActorName("Marcia Wallace");
	showDataBase->displayShowsByActorName("Bill Daily");
	showDataBase->displayShowsByActorName("Joe Penny");
	showDataBase->displayShowsByActorName("John DiMaggio");
	showDataBase->displayShowsByActorName("Ron Howard");
	cout << endl;

	cout << "Display all shows released between 1965 and 1975, 2000 and 2010." << endl;
	showDataBase->displayShowsByDateRange(1965, 1975);
	showDataBase->displayShowsByDateRange(2000, 2010);
	cout << endl;


	fin.close();
	return 0;
}

