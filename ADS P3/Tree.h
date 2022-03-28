#pragma once
/*************************************************
 * ADS Praktikum 2.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"

class Tree{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int currentNodeChronologicalID;
    TreeNode* anker; 

    //
    ////////////////////////////////////
public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree() : currentNodeChronologicalID{ 0 }, anker{ nullptr } {}
    ~Tree() {}
    bool addNode(std::string Name, int Age, double Income, int PostCode);
    void printAll(void);
    void balance(TreeNode* ptr);
    bool split4Node(TreeNode* node);
    int proofRBCriterion(TreeNode* x);
    bool rotateTreeRight(TreeNode* ptr, TreeNode* ptr2);
    bool rotateTreeLeft(TreeNode* ptr, TreeNode* ptr2);
    void printLevelOrder(void);
    void printLevelOrder(int niveau);
    void printpreorder(TreeNode* ptr);
    bool searchNode(std::string Name);
    void getNames(TreeNode* ptr, std::string Name, bool& found);
    void getOrder(TreeNode* ptr, int NodeOrderID, bool& found);
    bool searchOrder(int NodeOrderID);
    TreeNode* Searchminimum(TreeNode* ptr);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
