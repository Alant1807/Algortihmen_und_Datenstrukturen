#include "Linkedlist.h"

Linkedlist::Linkedlist() {
	head = new Node;
}

Linkedlist::~Linkedlist() {
	while (head != nullptr) {
		auto delNode = head;
		head = head->next;
		delete delNode;
	}
	delete head;
}

void Linkedlist::insert(int key) {
	Node* neuer_eintrag = new Node(key, nullptr);
	if (head->next == nullptr) {
		head->next = neuer_eintrag;
	}
	else {
		Node* ptr = head->next;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = neuer_eintrag;
	}
}

bool Linkedlist::remove(int key) {
	if (head->next != nullptr) {
		Node* node = head;
		while (node->next != nullptr && node->next->key != key) {
			node = node->next;
		}
		if (node->next != nullptr && node->next->key == key) {
			Node* delnode = node->next;
			node->next = node->next->next;
			delete delnode;
			return true;
		}
	}
	return false;
}

bool Linkedlist::search(int key) const {
	if (head->next != nullptr) {
		Node* find = head->next;
		while (find != nullptr && find->key != key) {
			find = find->next;
		}
		if (find != nullptr && find->key == key) {
			std::cout << "Die gefundene Zahl lautet " << find->key << std::endl;
			return true;
		}
	}
	return false;
}

void Linkedlist::print() const {
	if (head->next != nullptr) {
		std::cout << "List( ";
		Node* out = head->next;
		while (out != nullptr) {
			std::cout << out->key;
			if (out->next != nullptr) {
				std::cout << ", ";
			}
			out = out->next;
		}
		std::cout << " )" << std::endl;
	}
}

void Linkedlist::SelectionSort() {
	Node* i = head;
	for (; i != nullptr; i = i->next) {
		Node* min = i;
		Node* j = i->next;
		for (; j != nullptr; j = j->next) {
			if (min->key > j->key) {
				min = j;
			}
		}
		std::swap(i, min);
	}
}

