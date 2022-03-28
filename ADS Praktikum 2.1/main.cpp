/*************************************************
* ADS Praktikum 2.1
* main.cpp
*
*************************************************/
/*
Bearbeitet durch Alan Tofeq 
*/

#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:
	int eingabe = 0;
	Ring* backup = new Ring();
	int counter = 0;
	cout << "==============================\n";
	cout << "Backup Organizer by Alan Tofeq\n";
	cout << "==============================\n";
	while (true) {
		cout << "\n1) Backup anlegen\n";
		cout << "2) Backup suchen\n";
		cout << "3) Alle Backups ausgeben\n";
		cout << "4) Anwendung verlassen\n?> ";
		cin >> eingabe;
		if (eingabe == 1) {
			string description, data = "";
			cout << "\n++Backup Anlegen\n";
			cout << "Beschreibung ?> ";
			cin.ignore();
			getline(cin, description);
			cout << "Daten ?> ";
			getline(cin, data);
			backup->addNewNode(description, data);
			cout << "++Ihr Datensatz wurde hinzugefuegt.\n";
		}
		if (eingabe == 2) {
			cin.ignore();
			string search = "";
			cout << "\n++Backup Daten Suchen\n";
			cout << "Nach welchen Daten soll gesucht werden?\n";
			cout << "?> ";
			getline(cin, search);
			backup->search(search);
		}
		if (eingabe == 3) {
			cin.ignore();
			cout << "\n";
			backup->print();
		}
		if (eingabe == 4) {
			cout << "\nDie Anwendung wurde erfolgreich beendet\n";
			break;
		}
	}
	//
	///////////////////////////////////////
	cout << "\n";
	system("Pause");
	return 0;
}
