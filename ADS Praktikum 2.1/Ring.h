/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
/*
Bearbeitet durch Alan Tofeq
*/

// Ring .h

#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"

class Ring {

private:
	RingNode* anker;
	int countNodes;

public:

	Ring() : countNodes{ 0 }, anker{ nullptr } {} 
	void addNewNode(std::string description, std::string symbolicData);
	bool search(std::string symbolicData);
	void print();


	friend RingNode* get_anker(Ring& r);
	friend int get_countNodes(Ring& r);
};
