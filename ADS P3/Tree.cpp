/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>

void Tree::balance(TreeNode* ptr) {

	if (ptr != anker || ptr->getParent() != anker) {
		TreeNode* parent = ptr->getParent();
		TreeNode* grandparent = parent->getParent();
		if (grandparent->getRight() == parent && parent->getRed()) {
			if (parent->getLeft() == ptr && ptr->getRed()) {
				rotateTreeRight(ptr, parent);
				rotateTreeLeft(grandparent, ptr);
			}
			else if (parent->getRight() == ptr && ptr->getRed()) {
				rotateTreeLeft(grandparent, parent);
			}
		}
		else if (grandparent->getLeft() == parent && parent->getRed()) {
			if (parent->getRight() == ptr && ptr->getRed()) {
				rotateTreeLeft(parent, ptr);
				rotateTreeRight(ptr, grandparent);
			}
			else if (parent->getLeft() == ptr && ptr->getRed()) {
				rotateTreeRight(parent, grandparent);
			}
		}
		else {
			balance(ptr->getParent());
			return;
		}
	}
	else return;
}

bool Tree::split4Node(TreeNode* ptr) {
	/*if (x->getParent() != nullptr && x->getParent()->getParent() != nullptr) {
		TreeNode* Vater = x->getParent();
		TreeNode* Opa = Vater->getParent();
		if (Opa->getLeft() != nullptr && Opa->getRight() == Vater) {
			TreeNode* Onkel = Opa->getLeft();
			if (Vater->getRed() && Onkel->getRed()) {
				Opa->setRed(1);
				Onkel->setRed(0);
				Vater->setRed(0);
				if (anker->getRed()) {
					anker->setRed(0);
				}
				return true;
			}
		}
		else if (Opa->getRight() != nullptr && Opa->getLeft() == Vater) {
			TreeNode* Onkel = Opa->getRight();
			if (Vater->getRed() && Onkel->getRed()) {
				Opa->setRed(1);
				Onkel->setRed(0);
				Vater->setRed(0);
				if (anker->getRed()) {
					anker->setRed(0);
				}
				return true;
			}
		}
	}
	if (anker->getRed()) {
		anker->setRed(0);
	}
	return false;*/

	if (ptr->getRed() == false) {
		if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) {
			if (ptr->getLeft()->getRed() == true && ptr->getRight()->getRed() == true) {
				ptr->setRed(true);
				ptr->getLeft()->setRed(false);
				ptr->getRight()->setRed(false);
				return true;
			}
		}
	}
	return false;
}

int Tree::proofRBCriterion(TreeNode* knoten) {

	//int wertlinks = 0;
	//int wertrechts = 0;
	//if (knoten->getLeft() != nullptr) {
	//	wertlinks = proofRBCriterion(knoten->getLeft());
	//}
	//if (knoten->getRight() != nullptr) {
	//	wertrechts = proofRBCriterion(knoten->getRight());
	//}
	//if (knoten->getLeft() != nullptr && knoten->getRight() != nullptr) {
	//	if (knoten->getLeft()->getRed() || knoten->getRight()->getRed()) {
	//		if (knoten->getLeft()->getRed() && knoten->getRight()->getRed()) {
	//			return (wertlinks == wertrechts) ? wertlinks : -1;	//2
	//		}
	//		else if (knoten->getLeft()->getRed()) {
	//			return (wertlinks + 1 == wertrechts || wertlinks - 1 == wertrechts) ? wertlinks : -1;
	//		}													//3
	//		else {
	//			return (wertrechts + 1 == wertlinks || wertrechts - 1 == wertlinks) ? wertrechts : -1;
	//		}
	//	}
	//	else {
	//		return (wertrechts == wertlinks) ? wertlinks + 1 : -1;		//4
	//	}
	//}
	//else if (knoten->getLeft() != nullptr || knoten->getRight() != nullptr) {
	//	if (knoten->getLeft() != nullptr) {
	//		return (knoten->getLeft()->getRed()) ? wertlinks : wertlinks + 1;
	//	}
	//	else {
	//		return (knoten->getRight()->getRed()) ? wertrechts : wertrechts + 1;
	//	}
	//}
	//else {
	//	return 0;		//1
	//}
	return 0;
}

bool Tree::rotateTreeRight(TreeNode* ptr, TreeNode* ptr2) {

	TreeNode* pp = ptr2->getParent();
	if (ptr2 == anker) {
		anker = ptr;
		ptr->setParent(nullptr);
	}
	else {
		if (pp->getLeft() == ptr2) {
			pp->setLeft(ptr);
		}
		else {
			pp->setRight(ptr);
		}
		ptr->setParent(pp);
	}
	ptr2->setLeft(ptr->getRight());
	ptr->setRight(ptr2);
	ptr2->setParent(ptr);

	bool save = ptr2->getRed();
	ptr2->setRed(ptr->getRed());
	ptr->setRed(save);
	return true;
}

bool Tree::rotateTreeLeft(TreeNode* ptr, TreeNode* ptr2) {

	TreeNode* pp = ptr->getParent();

	if (ptr == anker) {
		anker = ptr2;
		ptr2->setParent(nullptr);
	}
	else {
		if (pp->getRight() == ptr) {
			pp->setRight(ptr2);
		}
		else {
			pp->setLeft(ptr2);
		}
		ptr2->setParent(pp);
	}
	ptr->setRight(ptr2->getLeft());
	ptr2->setLeft(ptr);
	ptr->setParent(ptr2);

	bool save = ptr->getRed();
	ptr->setRed(ptr2->getRed());
	ptr2->setRed(save);
	return true;
}

bool Tree::addNode(std::string Name, int Age, double Income, int  PostCode) {
	//int NodeOrderID = Age + PostCode + (int)Income; // NoderOrderID errechnet sich aus den Attributen
	//TreeNode* newNode = new TreeNode(NodeOrderID, currentNodeChronologicalID, Name, Age, Income, PostCode);
	//TreeNode* ptr;
	//if (anker == nullptr) { // liste leer
	//	anker = newNode;
	//	newNode->setRed(false);
	//}
	//else {
	//	ptr = anker;
	//	while (true) {
	//		if (NodeOrderID < ptr->getNodeOrderID()) {
	//			if (ptr->getLeft() == nullptr) {
	//				ptr->setLeft(newNode);
	//				break;
	//			}
	//			else {
	//				ptr = ptr->getLeft();
	//			}
	//		}
	//		else if (NodeOrderID > ptr->getNodeOrderID()) {
	//			if (ptr->getRight() == nullptr) {
	//				ptr->setRight(newNode);
	//				break;
	//			}
	//			else {
	//				ptr = ptr->getRight();
	//			}
	//		}
	//	}
	//}
	//if (anker == newNode) {
	//	newNode->setParent(nullptr);
	//}
	//else {
	//	newNode->setParent(newNode->findParent(anker));
	//}
	//split4Node(newNode);
	//balance(newNode);
	//++currentNodeChronologicalID;
	//return true;

	int NodeOrderID = Age + (int)Income + PostCode;
	TreeNode* neuer_eintrag = new TreeNode(NodeOrderID, currentNodeChronologicalID, Name, Age, Income, PostCode);
	neuer_eintrag->setRed(true);
	TreeNode* parent = nullptr;
	TreeNode* ptr = anker;
	if (anker == nullptr) {
		anker = neuer_eintrag;
		neuer_eintrag->setRed(false);
		neuer_eintrag->setParent(nullptr);
	}
	else {
		while (ptr != nullptr) {
			parent = ptr;
			split4Node(ptr);
			if (neuer_eintrag->getNodeOrderID() < ptr->getNodeOrderID()) ptr = ptr->getLeft();
			else ptr = ptr->getRight();
		}
		if (neuer_eintrag->getNodeOrderID() < parent->getNodeOrderID()) {
			parent->setLeft(neuer_eintrag);
			neuer_eintrag->setParent(parent);

		}
		else {
			parent->setRight(neuer_eintrag);
			neuer_eintrag->setParent(parent);
		}
	}
	this->currentNodeChronologicalID++;
	anker->setRed(false);
	balance(neuer_eintrag);
	return true;
}

TreeNode* Tree::Searchminimum(TreeNode* ptr) {                          // suche Minimum 
	while (ptr->getLeft() != nullptr) {
		ptr = ptr->getLeft();
	}
	return ptr;
}

void Tree::getOrder(TreeNode* ptr, int NodeOrderID, bool& found) {         // suche die OrderID und gebe (true) wenn sie existiert und (false) falls nicht
	if (ptr != nullptr) {
		if (ptr->getNodeOrderID() == NodeOrderID) { found = true; }
		if (ptr->getLeft() != nullptr) { getOrder(ptr->getLeft(), NodeOrderID, found); }
		if (ptr->getRight() != nullptr) { getOrder(ptr->getRight(), NodeOrderID, found); }
	}
}

bool Tree::searchOrder(int NodeOrderID) {
	TreeNode* ptr = anker;
	bool found = false;
	if (anker == nullptr) { return found; }
	getOrder(ptr, NodeOrderID, found);
	return found;
}

void Tree::getNames(TreeNode* ptr, std::string Name, bool& found) {            // Iteriere mit Preorder durch den Baum und suche den Namen der übergeben wird
	if (ptr != nullptr) {
		if (ptr->getName() == Name) {
			found = true;
			std::cout << "\n+ Fundstellen:\n";
			std::cout << "ID: " << ptr->getNodeChronologicalID() << ", Name: " << Name << ", Age: " << ptr->getAge() << ", Income: "
				<< ptr->getIncome() << ", PostCode: " << ptr->getPostCode() << ", OrderID: " << ptr->getNodeOrderID() << std::endl;
		}
		if (ptr->getLeft() != nullptr) { getNames(ptr->getLeft(), Name, found); }
		if (ptr->getRight() != nullptr) { getNames(ptr->getRight(), Name, found); }
	}
}

bool Tree::searchNode(std::string Name) {
	TreeNode* ptr = anker;
	bool found = false;
	if (anker == nullptr) { return found; }
	getNames(ptr, Name, found);
	return found;
}

void Tree::printpreorder(TreeNode* ptr) {
	if (ptr == nullptr) { return; }
	ptr->allprint();
	printpreorder(ptr->getLeft());
	printpreorder(ptr->getRight());
}

void Tree::printAll(void) {
	printpreorder(anker);
}