/*************************************************
 * ADS Praktikum 2.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>
#include <fstream>
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
int main()
{
    int result = Catch::Session().run();

   /* int eingabe = 0;
    string Name = "";
    int Alter = 0;
    double Einkommen = 0;
    int PLZ = 0;
    bool gefunden = false;
    int x = 0;

    Tree* test = new Tree;

    while (eingabe != 8) {

        cout << endl << "-----------------------------------" << endl;
        cout << "------Red/Black Tree von Baran-----" << endl;
        cout << "-----------------------------------" << endl
             <<  "1) Datensatz einfuegen, manuell" << endl <<
                 "2) Daten einfuegen, CSV Import" << endl <<
                 "3) Datensatz suchen" << endl <<
                 "4) Ausgabe in Preorder" << endl <<
                 "5) Ausgabe in LevelOrder" << endl <<
                 "6) Ausgabe in LevelOrder (mit Niveau auswahl)" << endl << 
                 "7) Anzahl der Höhe und Kriterium" << endl <<
                 "8) Beenden" << endl;
        cin >> eingabe;
        switch (eingabe) {

        case 1:
            cout << "Bitte geben Sie die den Datensatz ein" << endl <<
                "Name ?";
            cin >> Name;
            cout << endl << "Alter ?";
            cin >> Alter;
            cout << endl << "Einkommen ?";
            cin >> Einkommen;
            cout << endl << "PLZ ?";
            cin >> PLZ;
            test->addNode(Name, Alter, Einkommen, PLZ);
            break;
        case 2:
            mainscreen_addTreeCSV(test);
            break;
        case 3:
            cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
            cout << "Name ?" << endl;
            cin >> Name;
            test->searchNode(Name);
            break;
        case 4:
            test->preorder();
            break;
        case 5:
            test->printLevelOrder();
            break;
        case 6:
            cout << "Bitte geben die das Niveau an : ";
            cin >> x;
            test->printLevelOrderNiv(x);
            break;
        case 7:
            test->StartRBCriterion();
            break;
        }
    }*/
    //
    ///////////////////////////////////////
    system("PAUSE");
    return 0;
}