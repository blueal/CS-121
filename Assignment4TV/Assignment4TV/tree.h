#pragma once
#include "show.h"
using namespace std;
#define TREE_DATA_TYPE show

class tree
{
private:
	typedef struct TreeEntry{

		TreeEntry *left;
		TREE_DATA_TYPE data;
		TreeEntry *right;

	} TreeEntry;

	TreeEntry *root;
	void displayInOrder(TreeEntry *entry);

public:

	tree();
	void displayAll();
	void displayActorsByShow(string show);
	void displayShowsByActor(string actor);
	void displayShowsByDate(int year);

	//ADD OTHER FUNCTIONS HERE;
};
