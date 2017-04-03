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

tree::tree() {
	root = NULL;
}

void tree::displayInOrder(TreeEntry *entry){
	if (entry != NULL)
	{
		displayInOrder(entry->left);

		//cout << entry->data << endl;

		displayInOrder(entry->right);
	}
}



void tree::displayAll() {
	displayInOrder(root);
}