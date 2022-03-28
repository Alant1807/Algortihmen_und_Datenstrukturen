/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
 /*
 Bearbeitet durch Alan Tofeq
 */

#include "TreeNode.h"
#include <iomanip>

 ////////////////////////////////////
 // Ihr Code hier:

void TreeNode::print() {
	cout << "ID: " << this->getNodeChronologicalID() << ", Name :" << this->getName() << ", Age : " << this->getAge() << ", Income : "
		<< this->getIncome() << ", PostCode : " << this->getPostCode() << ", OrderID : " << this->getNodeOrderID() << endl;
}

void TreeNode::allprint() {
	cout << this->getNodeChronologicalID() << setw(15) << this->getName() << setw(7) << this->getAge() << setw(9) 
		<< this->getIncome() << setw(10) << this->getPostCode() << setw(13) << this->getNodeOrderID() << endl;
}

//
////////////////////////////////////
