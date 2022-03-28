/*************************************************
 * ADS Praktikum 3
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
 /*
 Bearbeitet durch Alan Tofeq
 */

#pragma once
#include <string>
#include <iostream>
#include <vector>

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int NodeOrderID = 0;
    int NodeChronologicalID = 0;
    std::string Name = "";
    int Age = 0;
    double Income = 0;
    int PostCode = 0;
    bool red;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode* parent = nullptr;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode) :
        NodeOrderID{ NodeOrderID }, NodeChronologicalID{ NodeChronologicalID }, Name{ Name }, Age{ Age }, Income{ Income }, PostCode{ PostCode }, red{ red } {}
    int getNodeOrderID() const { return this->NodeOrderID; }
    void setNodeOrderID(int NodeOrderID) { this->NodeOrderID = NodeOrderID; }
    int getNodeChronologicalID() const { return this->NodeChronologicalID; }
    void setNodeChronologicalID(int NodeChronologicalID) { this->NodeChronologicalID = NodeChronologicalID; }
    std::string getName() const { return this->Name; }
    void setName(std::string Name) { this->Name = Name; }
    int getAge() const { return this->Age; }
    void setAge(int Age) { this->Age = Age; }
    double getIncome() const { return this->Income; }
    void setIncome(double Income) { this->Income = Income; }
    int getPostCode() const { return this->PostCode; }
    void setPostCode(int PostCode) { this->PostCode = PostCode; }
    TreeNode* getLeft() { return this->left; }
    void setLeft(TreeNode* left) { this->left = left; }
    TreeNode* getRight() { return this->right; }
    void setParent(TreeNode* parent) { this->parent = parent; }
    TreeNode* getParent() { return this->parent; }
    void setRight(TreeNode* right) { this->right = right; }
    void setRed(bool red) { this->red = red; }
    bool getRed() const { return this->red; }
    void print();
    void allprint();
    //
    ////////////////////////////////////
};
