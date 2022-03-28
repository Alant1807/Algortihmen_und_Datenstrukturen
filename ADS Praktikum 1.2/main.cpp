#include <iostream>
//#define CATCH_CONFIG_RUNNER
#include "List.h"
//#include "catch.hpp"
using namespace std;

// Bearbeitet durch Alan Tofeq

int main(void)
{
	std::locale::global(std::locale("German_germany"));
    //int  result = Catch::Session().run();
    int  i;
    List<int> MyList;

    for (i = 0; i < 10; i++)
    {
        MyList.insertFront(i + 1);
        MyList.insertBack(i + 100);
    }

    cout << MyList;

    cout << "100: " << (MyList.search(100) ? "gefunden" : "nicht gefunden")
         << endl;
    cout << "99: " << (MyList.search(99) ? "gefunden" : "nicht gefunden")
         << endl
         << endl;

    while (MyList.getBack(i))
        cout << i << " ";
    cout << endl << endl;

    List<int>  MyList1, MyList2, MyList3;
    List<int>* MyList_dyn = new List<int>();

    for (i = 0; i < 10; i++)
    {
        MyList1.insertFront(i + 1);
        MyList2.insertBack(i + 100);
    }

    MyList1.format("MyList1\n<<", ", ", ">>\n\n");
    cout << MyList1;

    MyList_dyn->format("MyList_dyn\n<<", ", ", ">>\n\n");
    MyList_dyn->insertFront(-111);
    cout << *MyList_dyn;

    MyList2.format("MyList2\n<<", ", ", ">>\n\n");
    cout << MyList2;

    MyList3 = MyList1 + (*MyList_dyn) + MyList2;

    delete MyList_dyn;

    cout << "Groesse von MyList3: " << MyList3.size() << endl << endl;

    MyList3.format("MyList3\n<<", ", ", ">>\n\n");
    cout << MyList3 << endl;

    MyList3.swap(8, 103);
    MyList3.swap(100, -111);

    cout << MyList3;

    if (MyList3.test())
        cout << "MyList3: Zeiger OK\n\n";
    else
        cout << "MyList3: Zeiger ******Error\n\n";

	List<int> Liste1, Liste2, Liste3, Liste4, Liste5;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "/////////////////////////////////////////////////////////////" << endl
		<< "----------------------EIGENE TESTCASES-----------------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	cout << "-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "---------------Testcases zu insertback & swap----------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	for (int i = 0; i < 10; i++) {
		Liste1.insertBack(i + 1);
	}
	cout << "Liste " << Liste1 << endl;

	if ((Liste1.swap(2, 3) && Liste1.swap(9, 10)) == true) {
		cout << "Liste " << Liste1 << endl;
	}
	else {
		cout << "Tauschen fehlgeschlagen" << endl << endl;
	}
	if ((Liste1.swap(2, 12) && Liste1.swap(9, 10)) == true) {
		cout << "Liste " << Liste1 << endl;
	}
	else {
		cout << "Tauschen fehlgeschlagen" << endl << endl;
	}
	if (Liste1.test())
		cout << "Liste1: Zeiger OK\n\n";
	else
		cout << "Liste1: Zeiger ******Error\n\n";

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "---------------Testcases zu insertfront & swap---------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	for (int i = 0; i < 10; i++) {
		Liste2.insertFront(i * i + 1);
	}
	cout << "Liste2 " << Liste2 << endl;

	cout << "Tausche 5 und 37" << endl;
	if (Liste2.swap(50, 37) == true) {
		cout << "Liste2 " << Liste2 << endl;
	}
	else {
		cout << "Tauschen fehlgeschlagen" << endl << endl;
	}
	cout << "Tausche 65 und 30" << endl;
	if (Liste2.swap(65, 30) == true) {
		cout << "Liste2 " << Liste2 << endl;
	}
	else {
		cout << "Tauschen fehlgeschlagen" << endl << endl;
	}
	if (Liste2.test())
		cout << "Liste2: Zeiger OK\n\n";
	else
		cout << "Liste2: Zeiger ******Error\n\n";

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "---------------------Testcases zu Delete---------------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	cout << "Fülle die Liste 3-5 mit Werten und Lösche 17, 28 und 45" << endl << endl;

	bool liste3 = false, liste4 = false, liste5 = false;

	for (int i = 0; i < 10; i++) {

		Liste3.insertBack(i * 4 + 1);
		Liste4.insertBack(i * 3 + 1);
		Liste5.insertBack(i * 5 + 1);
	}

	cout << "Liste 3-5 vorher:" << endl << endl;
	cout << "Liste3 " << Liste3 << " und Länge: " << Liste3.size() << endl << endl;
	cout << "Liste4 " << Liste4 << " und Länge: " << Liste4.size() << endl << endl;
	cout << "Liste5 " << Liste5 << " und Länge: " << Liste5.size() << endl << endl;

	if (Liste3.del(17) == true) {
		cout << "Der Wert 17 wurde erfolgreich aus Liste3 entfernt" << endl << endl;
	}
	else {
		cout << "Der Wert 17 existiert nicht und kann nicht gelöscht werden" << endl << endl;
	}
	if (Liste4.del(28) == true) {
		cout << "Der Wert 28 wurde erfolgreich aus Liste4 entfernt" << endl << endl;
	}
	else {
		cout << "Der Wert 28 existiert nicht und kann nicht gelöscht werden" << endl << endl;
	}
	if (Liste5.del(45) == true) {
		cout << "Der Wert 45 wurde erfolgreich aus Liste5 entfernt" << endl << endl;
	}
	else {
		cout << "Der Wert 45 existiert nicht und kann nicht gelöscht werden" << endl << endl;
	}

	cout << "Liste 3-5 danach:" << endl << endl;
	cout << "Liste3 " << Liste3 << " und Länge jetzt: " << Liste3.size() << endl << endl;
	cout << "Liste4 " << Liste4 << " und Länge jetzt: " << Liste4.size() << endl << endl;
	cout << "Liste5 " << Liste5 << " und Länge jetzt: " << Liste5.size() << endl << endl;

	if (Liste3.test())
		cout << "Liste3: Zeiger OK\n\n";
	else
		cout << "Liste3: Zeiger ******Error\n\n";
	if (Liste4.test())
		cout << "Liste4: Zeiger OK\n\n";
	else
		cout << "Liste4: Zeiger ******Error\n\n";
	if (Liste5.test())
		cout << "Liste5: Zeiger OK\n\n";
	else
		cout << "Liste5: Zeiger ******Error\n\n";

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "--------------Testcases zu Insertfront mit Liste-------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	List<int> listfront, listfront2, listback3, listback4;

	for (int i = 0; i < 10; i++) {
		listfront.insertFront((i * i * 2) + 1);
	}
	for (int i = 0; i < 10; i++) {
		listfront2.insertFront((i * i) + 1);
	}

	cout << "Liste vorher " << listfront << " und Länge " << listfront.size() << endl << endl;
	cout << "Zu einfügende Liste vorher " << listfront2 << " und Länge: " << listfront2.size() << endl << endl;

	listfront.insertFront(listfront2);

	cout << "Liste mit eingefügter Liste: " << listfront << " und Länge jetzt: " << listfront.size() << endl << endl;

	if (listfront2.size() == 0) {
		cout << "Länge von Listfront2: " << listfront2.size() << endl << endl;
	}
	else {
		cout << "Es liegt ein Fehler vor" << endl << endl;
	}

	if (listfront.del(17) == true) {
		cout << "Der Wert 17 wurde erfolgreich aus lisfront entfernt" << endl << endl;
	}
	else {
		cout << "Der Wert 17 existiert nicht und kann nicht gelöscht werden" << endl << endl;
	}
	if (listfront.del(28) == true) {
		cout << "Der Wert 28 wurde erfolgreich aus lisfront entfernt" << endl << endl;
	}
	else {
		cout << "Der Wert 28 existiert nicht und kann nicht gelöscht werden" << endl << endl;
	}
	if (listfront.del(45) == true) {
		cout << "Der Wert 45 wurde erfolgreich aus lisfront entfernt" << endl << endl;
	}
	else {
		cout << "Der Wert 45 existiert nicht und kann nicht gelöscht werden" << endl << endl;
	}

	cout << "Tausche 5 und 37" << endl;
	if (listfront.swap(50, 37) == true) {
		cout << "listfront " << listfront << endl;
	}
	else {
		cout << "Tauschen fehlgeschlagen" << endl << endl;
	}
	cout << "Tausche 65 und 30" << endl;
	if (listfront.swap(65, 30) == true) {
		cout << "listfront " << listfront << endl;
	}
	else {
		cout << "Tauschen fehlgeschlagen" << endl << endl;
	}
	if (listfront.test())
		cout << "listfront: Zeiger OK\n\n";
	else
		cout << "listfront: Zeiger ******Error\n\n";

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "--------------Testcases zu InsertBack mit Liste--------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;


	for (int i = 0; i < 10; i++) {
		listback3.insertBack((i * i * 6) + 1);
	}
	for (int i = 0; i < 10; i++) {
		listback4.insertBack((i * i * 3) + 1);
	}

	cout << "Liste vorher " << listback3 << " und Länge " << listback3.size() << endl << endl;
	cout << "Zu einfügende Liste vorher " << listback4 << " und Länge: " << listback4.size() << endl << endl;

	listback3.insertBack(listback4);

	cout << "Liste mit eingefügter Liste: " << listback3 << " und Länge jetzt: " << listback3.size() << endl << endl;

	if (listback4.size() == 0) {
		cout << "Länge von Listfront2: " << listback4.size() << endl << endl;
	}
	else {
		cout << "Es liegt ein Fehler vor" << endl << endl;
	}
	if (listback3.test())
		cout << "listback: Zeiger OK\n\n";
	else
		cout << "listback: Zeiger ******Error\n\n";

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "listfront " << listfront << "und die Länge: " << listfront.size() << endl << endl;
	cout << "listback " << listback3 << "und die Länge: " << listback3.size() << endl << endl;

	//operator +
	listfront = listfront + listback3;
	cout << "Liste jetzt " << listfront << "und die Länge: " << listfront.size() << endl << endl;
	if (listfront.test())
		cout << "listfront: Zeiger OK\n\n";
	else
		cout << "listfront: Zeiger ******Error\n\n";

	//Copy-Konstruktor
	List<int> copyList(listfront);
	cout << "Copy-Liste " << copyList << endl;
	cout << "100: " << (copyList.search(100) ? "gefunden" : "nicht gefunden")
		<< endl;
	cout << "99: " << (copyList.search(99) ? "gefunden" : "nicht gefunden")
		<< endl
		<< endl;
	if (copyList.test())
		cout << "Copy-Liste: Zeiger OK\n\n";
	else
		cout << "Copy-Liste: Zeiger ******Error\n\n";

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "---------------Testcases zu getFront & getback---------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	List<int> L1;
	int var, var2 = 0;

	//Leere Liste
	if ((L1.getFront(var) || L1.getBack(var)) == false) {
		cout << "Leere Liste." << endl << endl;
	}
	else {
		cout << "Error Liste nicht Leer" << endl << endl;
	}

	//mit nur einem Wert
	//für getFront()
	L1.insertFront(12);
	cout << "L1: " << L1 << " Länge: " << L1.size() << endl << endl;
	L1.getFront(var);
	if (var == 12) {
		cout << "Zahl 12 gefunden und entfernt." << endl << endl;
		cout << "L1 danach " << L1 << "Länge: " << L1.size() << endl << endl;
	}
	else {
		cout << "Fehler. Zahl 12 wurde nicht gefunden und gelöscht." << endl << endl;
	}

	//für getBack()
	L1.insertFront(12);
	L1.getBack(var2);
	if (var2 == 12) {
		cout << "Zahl 12 gefunden und entfernt." << endl << endl;
	}
	else {
		cout << "Fehler. Zahl 12 wurde nicht gefunden und gelöscht." << endl << endl;
	}

	//Mit mehreren Werten
	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < 10; i++) {
			L1.insertBack(i);
		}
	}
	L1.getFront(var);
	L1.getBack(var2);
	if (var == 0) {
		cout << "Zahl 0 gefunden und entfernt." << endl << endl;
	}
	else {
		cout << "Fehler. Zahl 0 wurde nicht gefunden und gelöscht." << endl << endl;
	}
	if (var2 == 9) {
		cout << "Zahl 9 gefunden und entfernt." << endl << endl;
	}

	cout << "\n-------------------------------------------------------------" << endl << endl;

	cout << "/////////////////////////////////////////////////////////////" << endl
		<< "----------------------Testcases zu size----------------------" << endl
		<< "/////////////////////////////////////////////////////////////" << endl << endl;

	//leere Liste
	List<int> list;
	if (list.size() == 0) {
		cout << "Liste ist leer." << endl << endl;
	}
	else {
		cout << "Liste ist nicht leer." << endl << endl;
	}
	//nicht leere Listen
	for (int i = 0; i < 10; i++) {
		list.insertBack(i);
	}
	cout << "list " << list << endl;
	if (list.size() == 10) {
		cout << "Die Länge der Liste ist 10 Knoten lang." << endl << endl;
	}
	else {
		cout << "Es ist ein Fehler unterlaufen bzw die Länge existiert nicht." << endl << endl;
	}
	list.del(4);
	cout << "list " << list << endl;
	if (list.size() == 9) {
		cout << "Die Länge der Liste ist 9 Knoten lang." << endl << endl;
	}
	else {
		cout << "Es ist ein Fehler unterlaufen bzw die Länge existiert nicht." << endl << endl;
	}
	int x = 0;
	list.getBack(x);
	list.getFront(x);
	cout << "list " << list << endl;
	if (list.size() == 7) {
		cout << "Die Länge der Liste ist 7 Knoten lang." << endl << endl;
	}
	else {
		cout << "Es ist ein Fehler unterlaufen bzw die Länge existiert nicht." << endl << endl;
	}
	if (list.test())
		cout << "list: Zeiger OK\n\n";
	else
		cout << "list: Zeiger ******Error\n\n";

	cout << "\n------------------------------------------------------------" << endl << endl;

    system("PAUSE");
    return 0;
}
