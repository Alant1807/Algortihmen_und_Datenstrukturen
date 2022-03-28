#include "hashtable.h"
#include <iostream>

/*
Bearbeitet von Alan Tofeq
*/

using namespace std;

HashTable::HashTable(int size) {

	//*****************************
	// implement constructor here *
	//*****************************

	hashTable = new vector<int>(size);
	hashTable->assign(size, -1);
	this->collisionCount = 0;
	this->elements = 0;
	this->size = size;
}

HashTable::~HashTable() {
	//****************************
	// implement destructor here *
	//****************************

	delete hashTable;
}

int HashTable::hashValue(int item) {

	int index = -1; //dummy initializtation

	//******************************************
	// implement calculation of hashindex here *
	//******************************************

	int i = 0;
	index = item % this->size;    // hi(x) = (h(x) + i * i) % N)
	while (hashTable->at(index) != -1) {        // Kollision erkannt, while solange durchführen, bis kollision beseitigt ist
		i++;                                    // inkrementiere i
		this->collisionCount++;                       // inkrementiere collisionCount
		index = (item + i * i) % this->size;    // Quadratisches Sondieren 
	}
	return index;
}


int HashTable::insert(int item) {

	//******************************************
	// implement insertion of new element here *
	//******************************************
	
	int index = hashValue(item);
	hashTable->at(index) = item;
	elements++;
	return index; //dummy return
}

bool HashTable::search(int item) {
	int index = -1;
	int i = 0;
	index = (item + i * i) % this->size;
	while (hashTable->at(index) != item) {
		if (hashTable->at(index) == item) {
			break;
		}
		i++;
		this->collisionCount++;
		if (this->getCollisionCount() == 5) {
			cout << "nichts Gefunden\n";
			return false;
		}
	}
	if (hashTable->at(index) == item) {
		cout << "Item: " << item << " gefunden\n";
		return true;
	}
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
