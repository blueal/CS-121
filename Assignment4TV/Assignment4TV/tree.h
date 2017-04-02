#pragma once
using namespace std;
#define TREE_DATA_TYPE int

class tree
{
private:
	typedef struct TreeEntry
	{

		TreeEntry *left;
		TREE_DATA_TYPE data;
		TreeEntry *right;

	} TreePtr;

	TreePtr *root;
	void displayInOrder(TreePtr entry);

public:

	tree();
	void displayAll();
	void displayActorsByShow(string show);
	void displayShowsByActor(string actor);
	void displayShowsByDate(int year);

	//ADD OTHER FUNCTIONS HERE;
};
