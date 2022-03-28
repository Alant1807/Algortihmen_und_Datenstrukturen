#include "Tree.h"

using namespace std;

int main() {
	Tree tree;
	tree.addnode(4);
	tree.addnode(3);
	tree.addnode(1);
	tree.addnode(2);
	tree.addnode(5);
	tree.addnode(8);
	tree.addnode(9);
	tree.addnode(11);
	tree.addnode(7);
	tree.addnode(6);
	tree.printpostorder();
	cout << endl;
	tree.setHeight();
    
	cout << "\n";
	system("pause");
	return 0;
}