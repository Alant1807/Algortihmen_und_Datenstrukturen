/*************************************************
 * ADS Praktikum 3
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
	std::cout << "ID: " << this->getNodeChronologicalID() << ", Name :" << this->getName() << ", Age : " << this->getAge() << ", Income : "
		<< this->getIncome() << ", PostCode : " << this->getPostCode() << ", OrderID : " << this->getNodeOrderID() << std::endl;
}

void TreeNode::allprint() {
	std::cout << this->getNodeChronologicalID() << std::setw(15) << this->getName() << std::setw(7) << this->getAge() << std::setw(9)
		<< this->getIncome() << std::setw(10) << this->getPostCode() << std::setw(13) << this->getNodeOrderID() << std::endl;
}

//
////////////////////////////////////
