#pragma once
#include "Treenode.h"

class Tree {
private:
	Treenode* anker;
	void printinorder(Treenode* ptr);
	void printpreorder(Treenode* ptr);
	void printpostorder(Treenode* ptr);
public:
	Tree();
	~Tree();
	void addnode(int key);
	bool deletenode(int key);
	bool searchnode(int key);
	Treenode* rsuch(Treenode* node, int key);
	void deletetree(Treenode* anker);
	void printinorder();
	void printpostorder();
	void printpreorder();
	void printlevelorder();
	void printNiveau(int niveau);
	Treenode* maximumsearch(Treenode* ptr);
	Treenode* minimumsearch(Treenode* ptr);
	void maxi();
	void mini();
	int max(int i, int j);
	int compHeight(Treenode* node);
	void setHeight();
	int setHeightRecursive(Treenode* pointer);
};
