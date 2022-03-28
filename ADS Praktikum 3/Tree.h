/*************************************************
 * ADS Praktikum 3
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
 /*
 Bearbeitet durch Alan Tofeq
 */

#pragma once
#include "TreeNode.h"
#include "catch.h"

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* anker;
    int currentNodeChronologicalID;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
   
    Tree() : currentNodeChronologicalID{ 0 }, anker{ nullptr } {}
    ~Tree() { deletetree(anker); }
   
    
    //void addNode(std::string Name, int Age, double Income, int PostCode);
    //bool deleteNode(int NodeOrderID);
    bool addNode(std::string Name, int Age, double Income, int PostCode);
    void printAll(void);
    void getNames(TreeNode* ptr, std::string Name, bool& found);
    void printpreorder(TreeNode* ptr);
    bool searchNode(std::string Name);
    void getOrder(TreeNode* ptr, int NodeOrderID, bool& found);
    bool searchOrder(int NodeOrderID);
    TreeNode* Searchminimum(TreeNode* ptr);
    //TreeNode* deletehelpfunction(TreeNode* ptr, int NodeOrderID, bool& found);
    //bool deleteOrderID(int NodeOrderID);
    void deletetree(TreeNode* anker);
    void levelorder();
    void printLevelOrder(void);
    void printLevelOrder(int niveau);
    void printtabelle();
    void balance(TreeNode* ptr);
    void balancehelper(TreeNode* ptr);
    bool split4Node(TreeNode* ptr);
    int proofRBCriterion(TreeNode* ptr);
    void startproofRBCriterion();
    bool rotateTreeRight(TreeNode* ptr, TreeNode* ptr2);
    bool rotateTreeLeft(TreeNode* ptr, TreeNode* ptr2);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
