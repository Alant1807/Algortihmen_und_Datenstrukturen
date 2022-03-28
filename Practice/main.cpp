#include <iostream>
#include "Linkedlist.h"

using namespace std;

int main() {
	std::locale::global(std::locale("German_germany"));
	Linkedlist list;
	list.insert(9);
	list.insert(5);
	list.insert(6);
	list.insert(4);
	list.insert(8);
	list.insert(1);
	list.print();
	list.SelectionSort();
	list.print();

	system("pause");
	return 0;
}