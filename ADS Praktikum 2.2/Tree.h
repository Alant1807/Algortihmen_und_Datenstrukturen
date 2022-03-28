/*************************************************
 * ADS Praktikum 2.2
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
    //vector<TreeNode*> vec;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
   
    Tree() : currentNodeChronologicalID{ 0 }, anker{ nullptr } {}
    ~Tree() { deletetree(anker); delete anker;}
   
    void addNode(std::string Name, int Age, double Income, int PostCode);
    bool deleteNode(int NodeOrderID);
    void printAll(void);
    void getNames(TreeNode* ptr, string Name, bool& found);
    void printpreorder(TreeNode* ptr);
    bool searchNode(std::string Name);
    void getOrder(TreeNode* ptr, int NodeOrderID, bool& found);
    bool searchOrder(int NodeOrderID);
    TreeNode* Searchminimum(TreeNode* ptr);
    TreeNode* deletehelpfunction(TreeNode* ptr, int NodeOrderID, bool& found);
    //bool deleteOrderID(int NodeOrderID);
    void deletetree(TreeNode* anker);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
