/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp

/*
Bearbeitet durch Alan Tofeq
*/

#include "Ring.h"
#include <iostream>

// Ihr Code hier:
void Ring::addNewNode(std::string description, std::string symbolicData) {
	RingNode* neuer_eintrag = new RingNode(0, description, symbolicData);
	if (anker == nullptr) {                                                      // leere Liste
		anker = neuer_eintrag;
		anker->setNext(neuer_eintrag);
		countNodes++;
	}
	else {
		RingNode* ptr = anker;
		for (int i = 0; i < countNodes; i++) {                                 // Knoten altern
			ptr->setAge(ptr->getAge() + 1);
			ptr = ptr->getNext();
		};
		if (anker->getNext()->getAge() == 6) {                                // volle Liste
			RingNode* todelete = anker->getNext();
			neuer_eintrag->setNext(todelete->getNext());
			delete todelete;
		}
		else {                                                               // nicht-volle Liste
			neuer_eintrag->setNext(anker->getNext());
			countNodes++;
		}
		anker->setNext(neuer_eintrag);
		anker = neuer_eintrag;
	}
}

bool Ring::search(std::string symbolicData) {
	RingNode* ptr = anker;
	bool gefunden = false;
	for (int i = 0; i < countNodes; i++) {
		if (ptr->getData() == symbolicData) {
			std::cout << "++ Gefunden in Backup: Alter: " << ptr->getAge() << ", Beschreibung: " << ptr->getDescription() << ", Daten: " << ptr->getData() << std::endl;
			gefunden = true;
		}
		ptr = ptr->getNext();
	}
	if (!(gefunden))
		std::cout << "++ Datensatz konnte nicht gefunden werden.\n";
	return gefunden;
}

void Ring::print() {
	RingNode* ptr = anker->getNext();
	std::string agecounter[6];
	int x = countNodes;
	while (x > 0) {
		agecounter[x - 1] = "Alter: " + std::to_string(ptr->getAge()) + ", Beschreibung: " + ptr->getDescription() + ", Daten: " + ptr->getData() + "\n";
		ptr = ptr->getNext();
		x--;
	}
	for (int i = 0; i < countNodes; i++) {
		if (i < countNodes - 1) {
			std::cout << agecounter[i] + "--------------------------" + "\n";
		}
		else {
			std::cout << agecounter[i];
		}
	}
}
//
////////////////////////////////////
