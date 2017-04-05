#pragma once
#include "show.h"
using namespace std;
#define TREE_DATA_TYPE show

class tree
{
private:
	typedef struct TreeEntry{

		TreeEntry *left;
		TREE_DATA_TYPE *data;
		TreeEntry *right;

	} TreeEntry;

	TreeEntry *root;
	void displayInOrder(TreeEntry *entry);
	void displayAllTitles(TreeEntry *entry);
	void displayActorsByShowName(TreeEntry * entry, string showName);
	void displayShowsByActorName(TreeEntry * entry, string showName);
	void displayShowsByDateRange(TreeEntry * entry, int yearRangeStart, int yearRangeEnd);

public:

	tree();
	void displayAll();
	void displayAllTitles();
	void tree::addToTree(TREE_DATA_TYPE *newData);

	void displayActorsByShowName(string showName);
	void displayShowsByActorName(string actorName);

	void displayShowsByDateRange(int yearRangeStart, int yearRangeEnd);

	

	//ADD OTHER FUNCTIONS HERE;
};
