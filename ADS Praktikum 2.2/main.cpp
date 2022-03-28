/*************************************************
 * ADS Praktikum 2.2
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
	// Ihr Code hier:
	Tree* data = new Tree();
	int eingabe = 0;
	bool found = false;

	cout << "=================================\n";
	cout << "ADS-ELK-Stack v1.8, by Alan Tofeq\n";
	cout << "=================================\n";
	do {
		cout << "\n1) Datensatz einfuegen, manuell\n";
		cout << "2) Datensatz einfuegen, CSV Import\n";
		cout << "3) Datensatz loeschen\n";
		cout << "4) Datensatz suchen\n";
		cout << "5) Gesamte Datenstruktur anzeigen\n";
		cout << "6) Beenden\n" << "?> ";
		
		do {
			while (!(cin >> eingabe)) {
				cout << "Falsche Eingabe. ? ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
		} while (eingabe < 0 && eingabe > 6);

		string Name = "";
		int Alter = 0;
		double Einkommen = 0.0;
		int PLZ = 0;
		int OrderID = 0;

		if (eingabe == 1) {
			cout << "\n+ Bitte geben Sie die den Datensatz ein\n"
				<< "Name ?> ";
			cin >> Name;
			cout << "Alter ?> ";
			do {
				while (!(cin >> Alter)) {
					cout << "Falsche Eingabe. ? ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (Alter < 0 && Alter > 120);
			cout << "Einkommen ?> ";
			while (!(cin >> Einkommen)) {
				cout << "Falsche Eingabe. ? ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "PLZ ?> ";
			while (!(cin >> PLZ)) {
				cout << "Falsche Eingabe. ? ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			data->addNode(Name, Alter, Einkommen, PLZ);
			cout << "\n+ Ihr Datensatz wurde eingefuegt.\n";
		}
		if (eingabe == 2)
			mainscreen_addTreeCSV(data);
		if (eingabe == 3) {
			cout << "\n+ Bitte geben Sie den zu loeschenden Datensatz an\n"
				<< "OrderID ?> ";
			while (!(cin >> OrderID)) {
				cout << "Falsche Eingabe. ? ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (data->searchOrder(OrderID)) {
				data->deleteNode(OrderID);
				cout << "\n+ Datensatz wurde geloescht\n";
			}
			else {
				cout << "\n+ Datensatz konnte nicht geloescht werden.\n";
			}
		}
		if (eingabe == 4) {
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
		if (eingabe == 5) {
			cout << "\n\nID  | Name       | Age    | Income | PostCode | OrderID \n";
			cout << "----+------------+--------+--------+----------+---------\n";
			data->printAll();
		}
	} while (eingabe != 6);
	//
	///////////////////////////////////////
	cout << "\n";
	system("PAUSE");

	return 0;
}