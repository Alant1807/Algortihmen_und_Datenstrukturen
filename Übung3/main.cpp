#include "BST.h"
#include <iostream>

using namespace std;

int main() {
	BST* mytree = new BST();
	Treenode* Insert;
	mytree->printBST();

	// BST aufbauen 
	mytree->insert(5, Insert);
	mytree->insert(3, Insert);
	mytree->insert(7, Insert);
	mytree->insert(1, Insert);
	mytree->insert(4, Insert);
	mytree->insert(2, Insert);
	mytree->insert(6, Insert);
	mytree->insert(10, Insert);
	mytree->insert(8, Insert);
	mytree->insert(11, Insert);
	mytree->insert(9, Insert);

	// BST in Levelorder ausgeben 
	mytree->printBST();

	system("pause");
	return 0;
}