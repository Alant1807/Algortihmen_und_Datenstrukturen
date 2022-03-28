#pragma once
#include <iostream>
class Treenode {
private: 
	int key;
	Treenode* left = nullptr;
	Treenode* right = nullptr;
public:
	Treenode() : key{ -1 }, left{ nullptr }, right{ nullptr } {}
	Treenode(int _key, Treenode* _left = nullptr, Treenode* _right = nullptr) : key{ _key }, left{ _left }, right{ _right } {}
	int getKey() const { return this->key; }
	void setKey(int key) { this->key = key; }
	Treenode* getLeft() { return this->left; }
	void setLeft(Treenode* left) { this->left = left; }
	Treenode* getRight() { return this->right; }
	void setRight(Treenode* right) { this->right = right; }
	void allprint() { std::cout << this->key << " "; }
};