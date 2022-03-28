#include "Tree.h"
#include <queue>

Tree::Tree() {
	anker = new Treenode();
	anker->setRight(nullptr);
	anker->setLeft(nullptr);
}

Tree::~Tree() {
	deletetree(anker->getRight());
	delete anker;
}

void Tree::addnode(int key) {
	Treenode* neuer_eintrag = new Treenode(key);
	Treenode* current = anker->getRight();
	Treenode* parent = nullptr;
	while (current != nullptr) {
		parent = current;
		if (neuer_eintrag->getKey() < current->getKey()) {
			current = current->getLeft();
		}
		else {
			current = current->getRight();
		}
	}
	if (parent == nullptr) {
		anker->setRight(neuer_eintrag);
	}
	else {
		if (neuer_eintrag->getKey() < parent->getKey()) {
			parent->setLeft(neuer_eintrag);
		}
		else {
			parent->setRight(neuer_eintrag);
		}
	}
}

bool Tree::deletenode(int key) {
	bool found = true;
	while (found) {
		Treenode* delnode = anker->getRight();
		Treenode* parent = nullptr;
		Treenode* x, * y = nullptr;

		while (delnode != nullptr && delnode->getKey() != key) {
			parent = delnode;
			if (key < delnode->getKey()) {
				delnode = delnode->getLeft();
			}
			else {
				delnode = delnode->getRight();
			}
		}
		if (delnode == nullptr) {
			found = false;
			return found;
		}
		if (delnode->getLeft() == nullptr && delnode->getRight() == nullptr) {
			x = nullptr;
		}
		else if (!(delnode->getLeft() != nullptr && delnode->getRight() != nullptr)) {
			if (delnode->getLeft() != nullptr) {
				x = delnode->getLeft();
			}
			else {
				x = delnode->getRight();
			}
		}
		else {
			y = delnode;
			x = delnode->getRight();
			while (x->getLeft() != nullptr) {
				y = x;
				x = x->getLeft();
			}
			x->setLeft(delnode->getLeft());
			if (y != delnode) {
				y->setLeft(x->getRight());
				x->setRight(delnode->getRight());
			}
		}
		if (parent == nullptr) {
			anker->setRight(x);
		}
		else {
			if (parent->getLeft() == delnode) {
				parent->setLeft(x);
			}
			else {
				parent->setRight(x);
			}
		}
		delete delnode;
	}
	return found;
}

Treenode* Tree::rsuch(Treenode* node, int key) {
	if ((node == nullptr) || (node->getKey() == key)) {
		return node;
	}
	if (key < node->getKey()) {
		return rsuch(node->getLeft(), key);
	}
	else {
		return rsuch(node->getRight(), key);
	}
}

bool Tree::searchnode(int key) {
	if (anker->getRight() != nullptr) {
		Treenode* ptr = anker->getRight();
		while (ptr != nullptr && ptr->getKey() != key) {
			if (key < ptr->getKey()) {
				ptr = ptr->getLeft();
			}
			else {
				ptr = ptr->getRight();
			}
		}
		if (ptr != nullptr && ptr->getKey() == key) {
			return true;
		}
	}
	return false;
}

void Tree::deletetree(Treenode* anker) {
	if (anker != nullptr) {
		deletetree(anker->getLeft());
		deletetree(anker->getRight());
		delete anker;
	}
}

void Tree::printinorder(Treenode* ptr) {
	if (ptr != nullptr) {
		printinorder(ptr->getLeft());
		ptr->allprint();
		printinorder(ptr->getRight());
	}
}

void Tree::printpreorder(Treenode* ptr) {
	if (ptr != nullptr) {
		ptr->allprint();
		printpreorder(ptr->getLeft());
		printpreorder(ptr->getRight());
	}
}

void Tree::printpostorder(Treenode* ptr) {
	if (ptr != nullptr) {
		printpostorder(ptr->getLeft());
		printpostorder(ptr->getRight());
		ptr->allprint();
	}
}

void Tree::printinorder() {
	printinorder(anker->getRight());
}

void Tree::printpostorder() {
	printpostorder(anker->getRight());
}

void Tree::printpreorder() {
	printpreorder(anker->getRight());
}

Treenode* Tree::maximumsearch(Treenode* ptr) {
	if (ptr->getRight() != nullptr) {
		maximumsearch(ptr->getRight());
	}
	else {
		return ptr;
	}
}

Treenode* Tree::minimumsearch(Treenode* ptr) {
	if (ptr->getLeft() != nullptr) {
		minimumsearch(ptr->getLeft());
	}
	else {
		return ptr;
	}
}

void Tree::maxi() {
	Treenode* ptr = anker->getRight();
	while (ptr->getRight() != nullptr) {
		ptr = ptr->getRight();
	}
	std::cout << "Der Maximum Knoten lautet " << ptr->getKey() << std::endl;
}

void Tree::mini() {
	Treenode* ptr = anker->getRight();
	while (ptr->getLeft() != nullptr) {
		ptr = ptr->getLeft();
	}
	std::cout << "Der Minimum Knoten lautet " << ptr->getKey() << std::endl;
}

int Tree::max(int i, int j) {
	if (j > i)
		return j;
	else return i;
}

int Tree::compHeight(Treenode* node) {
	if (!node)
		return 0;
	else
		return max(compHeight(node->getLeft()), compHeight(node->getRight())) + 1;
}

void Tree::setHeight() {
	setHeightRecursive(anker->getRight());
}

int Tree::setHeightRecursive(Treenode* pointer) {
	if (pointer == nullptr)
		return -1;
	//Postorder traversierung
	int links = setHeightRecursive(pointer->getLeft());
	int rechts = setHeightRecursive(pointer->getRight());

	int hoehe = max(links, rechts) + 1; //Maximum Path ist die Maximale Hoehe
	std::cout << pointer->getKey() << " hoehe: " << hoehe << std::endl;

	int balance = links - rechts;
	if (1 < balance || -1 > balance) {
		std::cout << "Verletzung bei " << pointer->getKey() << " \n";
	}

	return hoehe;
}

void Tree::printlevelorder(){
	std::queue<Treenode*> q;
	std::queue<int> nq;
	if (anker->getRight() == nullptr) {
		std::cout << "BST ist leer" << std::endl;
		return;
	}
	else {
		q.push(anker->getRight());
		nq.push(0);
	}
	int prev_niveau = -1;
	int niveau;
	while (!q.empty()) {
		Treenode* curr = q.front(); q.pop();
		niveau = nq.front(); nq.pop();
		if (prev_niveau != niveau) {
			std::cout << std::endl << "Niveau " << niveau << ": ";
			prev_niveau = niveau;
		}
		std::cout << "(" << curr->getKey() << ") ";
		if (curr->getLeft() != nullptr) {
			q.push(curr->getLeft());
			nq.push(niveau + 1);
		}
		if (curr->getRight() != nullptr) {
			q.push(curr->getRight());
			nq.push(niveau + 1);
		}
	}
	std::cout << std::endl;
	return;
}

void Tree::printNiveau(int niveau) {
	std::queue<Treenode*> nodeQueue;
	std::queue<int> niveauQueue;
	if (anker->getRight() != nullptr) {
		nodeQueue.push(anker->getRight());
		niveauQueue.push(0);
	}
	else {
		std::cout << "BST ist leer" << std::endl;
		return;
	}
	int prevniv = -1;
	std::cout << "Niveau " << niveau << ": ";
	while (!nodeQueue.empty()) {
		Treenode* currentNode = nodeQueue.front();
		nodeQueue.pop();
		int currentNodeNiveau = niveauQueue.front();
		niveauQueue.pop();
		if (currentNodeNiveau == niveau) {
			std::cout << "(" << currentNode->getKey() << ") ";
			prevniv = niveau;
		}
		if (currentNode->getLeft() != nullptr) {
			nodeQueue.push(currentNode->getLeft());
			niveauQueue.push(currentNodeNiveau + 1);
		}
		if (currentNode->getRight() != nullptr) {
			nodeQueue.push(currentNode->getRight());
			niveauQueue.push(currentNodeNiveau + 1);
		}
	}
	if (prevniv != niveau) {
		std::cout << "gibt es nicht !!!\n";
	}
	return;
}
