/*************************************************
 * ADS Praktikum 3
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
 /*
 Bearbeitet durch Alan Tofeq
 */

#include "Tree.h"
#include "TreeNode.h"

 ////////////////////////////////////
 // Ihr Code hier:

bool Tree::addNode(std::string Name, int Age, double Income, int PostCode) {
	int NodeOrderID = Age + (int)Income + PostCode;
	TreeNode* neuer_eintrag = new TreeNode(NodeOrderID, currentNodeChronologicalID, Name, Age, Income, PostCode);
	neuer_eintrag->setRed(true);                         // neuer Knoten direkt auf rot setzen
	TreeNode* parent = nullptr;
	TreeNode* ptr = anker;
	while (ptr != nullptr) {
		split4Node(ptr);
		parent = ptr;
		if (neuer_eintrag->getNodeOrderID() < ptr->getNodeOrderID()) ptr = ptr->getLeft();      // iteriere nach links
		else ptr = ptr->getRight();                      // iteriere nach rechts
	}
	if (parent == nullptr) {                            // Liste leer 
		anker = neuer_eintrag;
		neuer_eintrag->setRed(false);
		neuer_eintrag->setParent(nullptr);
	}
	else if (neuer_eintrag->getNodeOrderID() < parent->getNodeOrderID()) {         // neuer_knoten kleiner als parent -> neuer knoten nach links einfügen
		parent->setLeft(neuer_eintrag);
		neuer_eintrag->setParent(parent);
	}
	else {                                                     // neuer_knoten kleiner als parent -> neuer knoten nach links einfügen
		parent->setRight(neuer_eintrag);
		neuer_eintrag->setParent(parent);
	}
	TreeNode* searchpointer = neuer_eintrag;
	balance(searchpointer);
	this->currentNodeChronologicalID++;
	return true;
}

void Tree::deletetree(TreeNode* anker) {
	if (anker == nullptr) { return; }
	deletetree(anker->getLeft());
	deletetree(anker->getRight());
	this->currentNodeChronologicalID--;
	delete anker;
}

void Tree::levelorder() {
	if (anker == nullptr) {
		std::cout << "\nDer Baum ist leer.\n";
		return;
	}
	TreeNode* lesepointer = anker;
	std::queue<TreeNode*> node;
	node.push(lesepointer);
	while (!node.empty()) {
		lesepointer = node.front();
		node.pop();
		lesepointer->allprint();
		if (lesepointer->getLeft() != nullptr) node.push(lesepointer->getLeft());
		if (lesepointer->getRight() != nullptr) node.push(lesepointer->getRight());
	}
}

void Tree::printLevelOrder(void) {
	std::queue<TreeNode*> nodeQueue; std::queue<int> niveauQueue;
	TreeNode* lesepointer = anker;
	int niveau = 0; int nivend = -1;
	if (lesepointer == nullptr) {
		std::cout << "\nDer Baum ist leer.\n";
		return;
	}
	else {
		nodeQueue.push(lesepointer);
		niveauQueue.push(niveau);
		while (!nodeQueue.empty()) {
			lesepointer = nodeQueue.front();			// lesepointer zeigt auf den ersten knoten in der queue
			nodeQueue.pop();					        // knoten aus queue löschen
			niveau = niveauQueue.front();			    // niv wird zur ersten zahl in der queue
			niveauQueue.pop();					        // niveau aus queue löschen
			if (nivend != niveau) {
				std::cout << "\n";
				std::cout << "Niveau " << niveau << ":";
				nivend = niveau;
			}
			if (lesepointer->getLeft() != nullptr) {
				if (lesepointer->getLeft()->getRed() == false) {
					niveauQueue.push(niveau + 1);
					nodeQueue.push(lesepointer->getLeft());
					std::cout << " (";
				}
				else {
					if (lesepointer->getLeft()->getLeft() != nullptr) {
						niveauQueue.push(niveau + 1);
						nodeQueue.push(lesepointer->getLeft()->getLeft());
					}
					if (lesepointer->getLeft()->getRight() != nullptr) {
						niveauQueue.push(niveau + 1);
						nodeQueue.push(lesepointer->getLeft()->getRight());
					}
					std::cout << " (" << lesepointer->getLeft()->getNodeOrderID() << ", ";
				}
			}
			else std::cout << " (";
			std::cout << lesepointer->getNodeOrderID();
			if (lesepointer->getRight() != nullptr) {
				if (lesepointer->getRight()->getRed() == false) {
					niveauQueue.push(niveau + 1);
					nodeQueue.push(lesepointer->getRight());
					std::cout << ")";
				}
				else {
					if (lesepointer->getRight()->getLeft() != nullptr) {
						niveauQueue.push(niveau + 1);
						nodeQueue.push(lesepointer->getRight()->getLeft());
					}
					if (lesepointer->getRight()->getRight() != nullptr) {
						niveauQueue.push(niveau + 1);
						nodeQueue.push(lesepointer->getRight()->getRight());
					}
					std::cout << ", " << lesepointer->getRight()->getNodeOrderID() << ")";
				}
			}
			else std::cout << ")";
		}
		std::cout << "\n";
	}
}

void Tree::printLevelOrder(int niveau) {
	std::queue<TreeNode*> nodeQueue; std::queue<int> niveauQueue;
	TreeNode* lesepointer = anker;
	int niv = -1;
	if (lesepointer == nullptr) {
		std::cout << "\nDer Baum ist leer." << std::endl;
		return;
	}
	else {
		nodeQueue.push(lesepointer);
		niveauQueue.push(niv + 1);
		std::cout << std::endl;
		std::cout << "Niveau " << niveau << ":";
		while (!niveauQueue.empty()) {
			lesepointer = nodeQueue.front();	       // lesepointer zeigt auf den ersten knoten in der queue
			nodeQueue.pop();					       // knoten aus queue löschen
			niv = niveauQueue.front();			       // niv wird zur ersten zahl in der queue
			niveauQueue.pop();					       // niveau aus queue löschen
			if (lesepointer->getLeft() != nullptr) {
				if (lesepointer->getLeft()->getRed() == false) {
					niveauQueue.push(niv + 1);
					nodeQueue.push(lesepointer->getLeft());
					if (niveau == niv) std::cout << " (";
				}
				else {
					if (lesepointer->getLeft()->getLeft() != nullptr) {
						niveauQueue.push(niv + 1);
						nodeQueue.push(lesepointer->getLeft()->getLeft());
					}
					if (lesepointer->getLeft()->getRight() != nullptr) {
						niveauQueue.push(niv + 1);
						nodeQueue.push(lesepointer->getLeft()->getRight());
					}
					if (niveau == niv) std::cout << " (" << lesepointer->getLeft()->getNodeOrderID() << ", ";
				}
			}
			else {
				if (niveau == niv) std::cout << " (";
			}
			if (niveau == niv) std::cout << lesepointer->getNodeOrderID();
			if (lesepointer->getRight() != nullptr) {
				if (lesepointer->getRight()->getRed() == false) {
					niveauQueue.push(niv + 1);
					nodeQueue.push(lesepointer->getRight());
					if (niveau == niv) std::cout << ")";
				}
				else {
					if (lesepointer->getRight()->getLeft() != nullptr) {
						niveauQueue.push(niv + 1);
						nodeQueue.push(lesepointer->getRight()->getLeft());
					}
					if (lesepointer->getRight()->getRight() != nullptr) {
						niveauQueue.push(niv + 1);
						nodeQueue.push(lesepointer->getRight()->getRight());
					}
					if (niveau == niv) std::cout << ", " << lesepointer->getRight()->getNodeOrderID() << ")";
				}
			}
			else {
				if (niveau == niv) std::cout << ")";
			}
			if (niveau < niv) break;
		}
		std::cout << std::endl;
	}
}

bool Tree::split4Node(TreeNode* ptr) {
	if (ptr->getRed() == false) {
		if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) {
			if (ptr->getLeft()->getRed() == true && ptr->getRight()->getRed() == true) {
				ptr->getLeft()->setRed(false);
				ptr->getRight()->setRed(false);
				if (anker != ptr) ptr->setRed(true);
				return true;
			}
		}
	}
	return false;
}

void Tree::startproofRBCriterion() {
	int hoehe = proofRBCriterion(anker);
	if (hoehe != -1) std::cout << "\nDer Rot-Schwarz-Baum erfuellt das Kriterium der Schwarzausgeglichenheit und hat die Hoehe: " << hoehe << std::endl;
	else std::cout << "\nDer Rot-Schwarz-Baum erfüllt das Kriterium der Schwarzausgeglichenheit nicht !!!\n";
}

int Tree::proofRBCriterion(TreeNode* ptr) {
	int heightleft = 0;
	int heightright = 0;
	if (ptr == nullptr) return -1;
	else {
		if (ptr->getLeft() != nullptr) heightleft = proofRBCriterion(ptr->getLeft());
		if (ptr->getRight() != nullptr) heightright = proofRBCriterion(ptr->getRight());
		if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) {
			if (ptr->getLeft()->getRed() == true && ptr->getRight()->getRed() == true) {  // beide Nachfolgerknoten rot -> höhen müssen gleich sein und return roten Knoten
				if (heightleft == heightright) return heightleft;
				else return -1;
			}
			else if (ptr->getLeft()->getRed() == true && ptr->getRight()->getRed() == false) {	   // einer der Nachfolger ist rot -> höhe des roten Nachfolger + 1 -> return roten Knoten 
				if (heightleft == heightright + 1) return heightleft;
				else return -1;
			}
			else if (ptr->getLeft()->getRed() == false && ptr->getRight()->getRed() == true) {	   // Analog wie oben aber rechter Nachfolger ist rot
				if (heightright == heightleft + 1) return heightright;
				else return -1;
			}
			else if (ptr->getLeft()->getRed() == false && ptr->getRight()->getRed() == false) {	   // beide Nachfolger sind schwarz -> höhen müssen übeinstimmen und return schwarze Nachfolgerknoten + 1
				if (heightleft == heightright) return heightleft + 1;
				else return -1;
			}
		}
		else if (ptr->getLeft() != nullptr && ptr->getRight() == nullptr) {		// der rechte Nachfolger existiert nicht -> höhe des roten Nachfolgerknoten und schwarzer Nachfolgeknoten + 1
			if (ptr->getLeft()->getRed() == true) return heightleft;
			else return heightleft + 1;
		}
		else if (ptr->getLeft() == nullptr && ptr->getRight() != nullptr) {		// der linke Nachfolger existiert nicht -> höhe des roten Nachfolgerknoten und schwarzer Nachfolgeknoten + 1
			if (ptr->getRight()->getRed() == true) return heightright;
			else return heightright + 1;
		}
		if (ptr->getLeft() == nullptr && ptr->getRight() == nullptr) return 0;    // beide Nachfolger existieren nicht	
	}
}

void Tree::balance(TreeNode* ptr) {
	int rote_knoten = 0;
	while (ptr != nullptr) {
		if (ptr->getRed() == false) rote_knoten = 0;
		else rote_knoten++;
		if (rote_knoten == 2) balancehelper(ptr);
		ptr = ptr->getParent();
	}
}

void Tree::balancehelper(TreeNode* ptr) {
	if (ptr->getParent() != nullptr && ptr->getRight() != nullptr) {
		if (ptr->getParent()->getNodeOrderID() < ptr->getNodeOrderID() && ptr->getRight()->getRed()) {        // Linksrotation
			TreeNode* parent = ptr->getParent();
			rotateTreeLeft(parent, ptr);
			ptr->setRed(false);                                                                               // Umfärben
			ptr->getLeft()->setRed(true);
			return;
		}
		if (ptr->getParent()->getNodeOrderID() > ptr->getNodeOrderID() && ptr->getRight()->getRed()) {        // Links-rechts Rotation
			rotateTreeLeft(ptr, ptr->getRight());
			TreeNode* grandparent = ptr->getParent()->getParent();
			TreeNode* parent = ptr->getParent();
			rotateTreeRight(grandparent, parent);
			parent->setRed(false);
			parent->getRight()->setRed(true);                                                                // Umfärben
			return;
		}
	}
	if (ptr->getParent() != nullptr && ptr->getLeft() != nullptr) {
		if (ptr->getParent()->getNodeOrderID() > ptr->getNodeOrderID() && ptr->getLeft()->getRed()) {      // Rechtsrotation
			TreeNode* parent = ptr->getParent();
			rotateTreeRight(parent, ptr);
			ptr->setRed(false);
			ptr->getRight()->setRed(true);                                                                  // Umfärben
			return;
		}
		if (ptr->getParent()->getNodeOrderID() < ptr->getNodeOrderID() && ptr->getLeft()->getRed()) {      // Rechts-links-Rotation
			rotateTreeRight(ptr, ptr->getLeft());
			TreeNode* grandparent = ptr->getParent()->getParent();
			TreeNode* parent = ptr->getParent();
			rotateTreeLeft(grandparent, parent);
			parent->setRed(false);
			parent->getLeft()->setRed(true);                                                              // Umfärben            
			return;
		}
	}
}

bool Tree::rotateTreeRight(TreeNode* ptr, TreeNode* ptr2) {
	std::cout << "RR[" << ptr->getNodeOrderID() << "|" << ptr2->getNodeOrderID() << "]" << std::endl;
	if (anker != ptr) {								               
		TreeNode* pp = ptr->getParent();
		if (pp->getNodeOrderID() > ptr2->getNodeOrderID()) {			
			pp->setLeft(ptr2);
			ptr2->setParent(pp);
		}
		else {															
			pp->setRight(ptr2);
			ptr2->setParent(pp);
		}
	}
	else {											
		anker = ptr2;
		ptr2->setParent(nullptr);
	}
	ptr->setLeft(ptr2->getRight());
	if (ptr->getLeft() != nullptr) {
		ptr->getLeft()->setParent(ptr);
	}
	ptr->setParent(ptr2);
	ptr2->setRight(ptr);
	return true;
}

bool Tree::rotateTreeLeft(TreeNode* ptr, TreeNode* ptr2) {
	std::cout << "LR[" << ptr->getNodeOrderID() << "|" << ptr2->getNodeOrderID() << "]" << std::endl;
	if (ptr != anker) {									           
		TreeNode* pp = ptr->getParent();
		if (pp->getNodeOrderID() > ptr2->getNodeOrderID()) {	
			pp->setLeft(ptr2);
			ptr2->setParent(pp);
		}
		else {														
			pp->setRight(ptr2);
			ptr2->setParent(pp);
		}
	}
	else {												
		anker = ptr2;
		ptr2->setParent(nullptr);
	}                             
	ptr->setRight(ptr2->getLeft());
	if (ptr->getRight() != nullptr) {
		ptr->getRight()->setParent(ptr);
	}
	ptr->setParent(ptr2);
	ptr2->setLeft(ptr);
	return true;

}


TreeNode* Tree::Searchminimum(TreeNode* ptr) {         // suche Minimum 
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

void Tree::printtabelle() {
	std::cout << "\n\nID  | Name       | Age    | Income | PostCode |  OrderID  |    Red\n";
	std::cout << "----+------------+--------+--------+----------+------------------------\n";
}
//
////////////////////////////////////