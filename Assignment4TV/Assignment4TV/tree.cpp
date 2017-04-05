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

void tree::displayInOrder(TreeEntry *entry) {
	if (entry != NULL)
	{
		displayInOrder(entry->left);

		entry->data->printShow();
		cout << endl;

		displayInOrder(entry->right);
	}
}

void tree::displayAllTitles(TreeEntry *entry) {
	if (entry != NULL)
	{
		displayAllTitles(entry->left);

		cout << entry->data->getName() << endl;

		displayAllTitles(entry->right);
	}
}

void tree::displayAll() {
	displayInOrder(root);
}

void tree::displayAllTitles() {
	displayAllTitles(root);
}

void tree::addToTree(TREE_DATA_TYPE *newData)
{
	TreeEntry *newPtr = new TreeEntry;

	// Add new data in the new node's data field
	newPtr->data = newData;
	newPtr->left = NULL;
	newPtr->right = NULL;

	//  If the BST is empty, insert the new data in root
	if (root == NULL)
	{
		root = newPtr;
	}
	else   //  Look for the insertion location
	{
		TreeEntry   *treePtr = root;
		TreeEntry   *targetNodePtr;

		while (treePtr != NULL)
		{
			targetNodePtr = treePtr;
			if(newData->isSameShow(treePtr->data))
				// Found same data; ignore it. 
				return;
			else if (newData->getStartYear() < treePtr->data->getStartYear())
				// Search left subtree for insertion location
				treePtr = treePtr->left;
			else   //  newData > treePtr->data 
				   // Search right subtree for insertion location
				treePtr = treePtr->right;
		}

		//  "targetNodePtr" is the pointer to the
		//  parent of the new node.  Decide where 
		//  it will be inserted.
		if (newData->getStartYear() < targetNodePtr->data->getStartYear())
			targetNodePtr->left = newPtr;
		else  // insert it as its right child
			targetNodePtr->right = newPtr;
	}
}

void tree::displayActorsByShowName(string showName) {
	cout << "DISPLAYING ACTORS BY SHOW NAME: " << showName << endl;
	displayActorsByShowName(root, showName);
	cout << endl;
}

void tree::displayActorsByShowName(TreeEntry *entry, string showName) {
	//PRIVATE
	if (entry != NULL)
	{		
		if (entry->data->getName().compare(showName) == 0) {
			entry->data->printActors();
		}

		displayActorsByShowName(entry->left, showName);
		displayActorsByShowName(entry->right, showName);
	}
}

void tree::displayShowsByActorName(string actorName) {
	cout << "DISPLAY ALL SHOWS BY ACTOR NAME: " << actorName << endl;
	displayShowsByActorName(root, actorName);
	cout << endl;
}

void tree::displayShowsByActorName(TreeEntry *entry, string actorName) {
	//PRIVATE
	if (entry != NULL)
	{
		if (entry->data->containsActorName(actorName)) {
			entry->data->printShow();
		}

		displayShowsByActorName(entry->left, actorName);
		displayShowsByActorName(entry->right, actorName);
	}
}

void tree::displayShowsByDateRange(int yearRangeStart, int yearRangeEnd){
	//Assumes rubric means that the show started within the date range given
	cout << "DISPLAY ALL SHOWS REALEASED BETWEEN: " << yearRangeStart << " and " << yearRangeEnd << "." << endl;
	displayShowsByDateRange(root, yearRangeStart, yearRangeEnd);
	cout << endl;
}

void tree::displayShowsByDateRange(TreeEntry *entry, int yearRangeStart, int yearRangeEnd) {
	//PRIVATE
	if (entry != NULL)
	{
		if (entry->data->getStartYear() >= yearRangeStart && entry->data->getStartYear() <= yearRangeEnd) {
			entry->data->printShow();
		}

		displayShowsByDateRange(entry->left, yearRangeStart, yearRangeEnd);
		displayShowsByDateRange(entry->right, yearRangeStart, yearRangeEnd);
	}
}