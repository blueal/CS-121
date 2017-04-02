/*
ALEX FRIEDBERG

tree .cpp
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "tree.h"

using namespace std;

void tree::displayInOrder(TreePtr entry){
	if (treePtr != NULL)
	{
		displayInOrder(treePtr->leftPtr);

		cout << treePtr->data << endl;

		displayInOrder(treePtr->rightPtr);
	}
}

tree::tree() {
	root = NULL;
}

void tree::displayAll() {
	displayInOrder(root);
}