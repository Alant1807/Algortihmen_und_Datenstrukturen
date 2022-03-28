/*************************************************
 * ADS Praktikum 3
 * main.cpp
 *
 *************************************************/
 /*
 Bearbeitet durch Alan Tofeq
 */

#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:



/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV"

Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/
void mainscreen_addTreeCSV(Tree*& ref)
{
	char j;
	cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
		"importieren(j / n) ? >";
	cin >> j;
	if (j == 'j')
	{
		ifstream csvread;
		csvread.open("ExportZielanalyse.csv", ios::in);
		if (!csvread.is_open())
			cerr << "Fehler beim Lesen!" << endl;
		else
		{
			string name, age, postcode, income;

			while (!csvread.eof())
			{
				getline(csvread, name, ';');
				getline(csvread, age, ';');
				getline(csvread, income, ';');
				getline(csvread, postcode, '\n');
				ref->addNode(name, stoi(age), stod(income), stoi(postcode));
			}
			csvread.close();
		}
		cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
	}
}
//
///////////////////////////////////////
int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	//Ihr Code hier:
	Tree* data = new Tree();
	int eingabe = 0;
	int niveau = 0;
	bool found = false;

	cout << "=================================\n";
	cout << "ADS-ELK-Stack v1.8, by Alan Tofeq\n";
	cout << "=================================\n";
	do {
		cout << "\n1) Datensatz einfuegen, manuell\n";
		cout << "2) Datensatz einfuegen, CSV Import\n";
		cout << "3) Datensatz suchen\n";
		cout << "4) Ausgabe in Preorder\n";
		cout << "5) Ausgabe in Levelorder\n";
		cout << "6) Ausgabe in Levelorder (mit Niveauauswahl)\n";
		cout << "7) Ausgabe der Hoehe des Rot-Schwarz-Baum\n";
		cout << "8) Beenden\n" << "?> ";
		
		do {
			while (!(cin >> eingabe)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
			if (eingabe < 1 || eingabe > 8) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
			}
		} while (eingabe < 1 || eingabe > 8);

		string Name = "";
		int Alter = 0;
		double Einkommen = 0.0;
		int PLZ = 0;
		int OrderID = 0;

		if (eingabe == 1) {
			bool finde = false;
			cout << "\n+ Bitte geben Sie die den Datensatz ein\n"
				<< "Name ?> ";
			cin >> Name;
			cout << "Alter ?> ";
			do {
				while (!(cin >> Alter)) {
					cout << "Falsche Eingabe. Bitte erneut eingeben ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (Alter < 1 || Alter > 120) {
					cout << "Falsche Eingabe. Bitte erneut eingeben ";
				}
			} while (Alter < 1 || Alter > 120);
			cout << "Einkommen ?> ";
			while (!(cin >> Einkommen)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "PLZ ?> ";
			while (!(cin >> PLZ)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			finde = data->addNode(Name, Alter, Einkommen, PLZ);
			if (finde == true)
				cout << "\n+ Ihr Datensatz wurde eingefuegt.\n";
			else
				cout << "\n Ihr Datensatz wurde nicht eingefuegt.\n";
		}
		if (eingabe == 2)
			mainscreen_addTreeCSV(data);
		if (eingabe == 3) {
			cout << "\n+ Bitte geben Sie den zu suchenden Datensatz an\n"
				<< "Name ?> ";
			cin >> Name;

			if (data->searchNode(Name)) {
				TreeNode* ptr = nullptr;
				data->getNames(ptr, Name, found);
			}
			else
				cout << "\n+ Datensatz nicht gefunden.\n";
		}
		if (eingabe == 4) {
			data->printtabelle();
			data->printAll();
		}
		if (eingabe == 5) {
			data->printtabelle();
			data->levelorder();
			cout << endl << endl;
			data->printLevelOrder();
		}
		if (eingabe == 6) {
			cout << "\nBitte geben die das Niveau an, dass sie anzeigen wollen: ";
			cin >> niveau;
			data->printLevelOrder(niveau);
		}
		if (eingabe == 7)
			data->startproofRBCriterion();
	} while (eingabe != 8);
	//
	///////////////////////////////////////
	cout << "\n";
	system("PAUSE");

	return 0;
}