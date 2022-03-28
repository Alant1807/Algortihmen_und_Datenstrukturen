#pragma once
#include "Node.h"

class Linkedlist {
private:
	Node* head;	// Pointer auf den Anfang der Liste
public:
	Linkedlist();			// Konstruktor
	~Linkedlist();			// Destruktor
	void insert(int key);		// Einfügen von Elementen in die Liste
	bool remove(int key);		// Löschen von Elementen aus der Liste
	bool search(int key) const;	// Suche nach Listenelement
	void print() const;			// Ausgeben der Liste
	void SelectionSort();
};
