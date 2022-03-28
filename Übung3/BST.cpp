#include "BST.h"
#include <iostream>
#include <queue>
#include <algorithm>

void BST::deleteBST(Treenode* p) {
	if (p->right) {
		deleteBST(p->right);
		p->right = nullptr;
	}
	else if (p->left) {
		deleteBST(p->left);
		p->left = nullptr;
	}
	else if (p->left == nullptr && p->right == nullptr) {
		delete p;
	}
}

BST::BST() {
	head = new Treenode();
	head->left = nullptr;
	head->right = nullptr;
}

void BST::insert(int key) {
	if (key < This->item) {
		if (Left != NULL) {
			Left->insert(key);
		}
		else {
			Left = new Treenode(key);
		}
	}
	else {
		if (Right != NULL) {
			Right->insert(key);
		}
		else {
			Right = new Treenode(key);
		}
	}
}

void BST::printBST() {

	// BST wird in Levelorder mit Hilfe einer Queue ausgegeben

	Treenode* root = head->right;

	// 2 Queues instanzieren (1 Punkt)
	std::queue<Treenode*> q;
	std::queue<int> nq;
	if (root == nullptr) {
		std::cout << "BST ist leer" << std::endl;
		return;
	}
	// Wurzelknoten und Startniveau in die Queues pushen (1 Punkt)
	q.push(root);
	nq.push(0);

	// vorheriges Niveau merken bzw. den Niveauwechsel irgendwie mitbekommen (1 Punkt)
	int prev_niveau = -1;
	int niveau;

	// Schleife 6 Punkte
	while (!q.empty()) {
		// Entnahme aus den Queues und löschen (2 Punkte)
		Treenode* curr = q.front();
		q.pop();
		niveau = nq.front(); nq.pop();

		// Ausgabe Niveauwechsel (1 Punkt)
		if (prev_niveau != niveau) {
			std::cout << std::endl << "Niveau " << niveau << ": ";
			prev_niveau = niveau;
		}
		// Ausgabe des Knotens (1 Punkt)
		std::cout << "(" << curr->item << ") ";

		// Linker Nachfolgeknoten in die Queues (1 Punkt)
		if (curr->left != nullptr)
		{
			q.push(curr->left);
			nq.push(niveau + 1);
		}
		// Rechter Nachfolgeknoten in die Queues (1 Punkt)
		if (curr->right != nullptr)
		{
			q.push(curr->right);
			nq.push(niveau + 1);
		}
	}
	return;
}