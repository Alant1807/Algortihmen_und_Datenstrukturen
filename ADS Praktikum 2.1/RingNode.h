/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
/*
Bearbeitet durch Alan Tofeq
*/

#pragma once
#include <string>

class RingNode {

private:
	int oldAge = 0;
	RingNode* next;
	std::string description = "";
	std::string symbolicData = "";

public:
	RingNode(): next{nullptr} {}
	RingNode(int oldAge, std::string description, std::string symbolicData): oldAge{oldAge}, description{description}, symbolicData{symbolicData}, next{nullptr} {}
	int getAge() const { return this->oldAge; }
	void setAge(int oldAge) { this->oldAge = oldAge; }
	std::string getDescription() const { return this->description; }
	void setDescription(std::string description) { this->description = description; }
	std::string getData() const { return this->symbolicData; }
	void setData(std::string symbolicData) { this->symbolicData = symbolicData; }
	RingNode* getNext() const { return this->next; }
	void setNext(RingNode* next) { this->next = next; }
};
