/* NAME: ALEX FRIEDBERG
DATE : 4 / 25 / 17
ASSIGNMENT : 5

HASH TABLE PROGRAM
MAIN PROGRAM

*/

#include "stdafx.h"
using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "hash.h"

int main()
{
	cout << "Hello, World!" << endl;
	
	string inputFile;

	cout << "What is the name of the file you would like to read? :" << endl;
	cin >> inputFile;

	cout << inputFile << endl;

	ifstream fin(inputFile);
	if (fin) {
		cout << "FILE OPENED: " << inputFile << endl;
	}
	else {
		cout << "FILE NOT FOUND: " << inputFile << endl;
	}
	
	string line;

	while (getline(fin, line))
	{
		if (line.compare("") == 0) continue;

		//cout << line << endl;
		
		Insert(line);
		
	}

	PrintHashTableBuckets();
	PrintHashTableBucketsMinMax();
	LookupPrintCount("aardvark");
	LookupPrintCount("bucolic");
	LookupPrintCount("catastrophic");
	LookupPrintCount("humdrum");
	LookupPrintCount("euphoria");
	LookupPrintCount("ferocious");
	LookupPrintCount("precarious");
	LookupPrintCount("talkative");
	LookupPrintCount("stupendous");
	LookupPrintCount("bias");

	return 0;
}