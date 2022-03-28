#pragma once
#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <iostream>
#include <string>

// Bearbeitet durch Alan Tofeq

template <typename T>
class List
{
    /*
    Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse
    List kann ein Stapel oder Warteschlange realisiert werden.
    */
private:
    struct form
    {
        std::string start = "<< ";
        std::string zwischen = ", ";
        std::string ende = " >>\n";
    } list_form;

    Node<T>* head_tail; // Zeiger auf Kopf- und End-Element -> next der 1. Knoten;
                     // -> prev der letzte Knoten
    int list_size;  // Länge der Kette
    bool temp; // normalerweise false; ist true, wenn es sich um eine temor�re
               // Liste handelt die innerhalb der überladenen Operatoren
               // angelegt wird
public:
    List();
    List(const List<T>& _List); // Kopie Konstruktor
    ~List();
    void insertFront(T key);     // Einfügen eines Knotens am Anfang
    void insertFront(List<T>& _List); // Einfügen einer vorhandenen Liste am Anfang
    void insertBack(T key);      // Einfügen eines Knotesn am Ende
    void insertBack(List<T>& _List);  // Einfügen einer vorhandenen Liste am Ende
    bool getFront(T& key);       // Entnehmen eines Knoten am Anfang
    bool getBack(T& key);        // Entnehmen eines Knoten am Ende
    bool del(T key);             // löschen eines Knotens [key]
    bool search(T key);          // Suchen eines Knoten
    bool swap(T key1, T key2); // Knoten in der Liste vertauschen
    int  size(void);               // Größe der Lise (Anzahl der Knoten)
    bool test(void);               // Überprüfen der Zeigerstruktur der Liste
    void format(const std::string& start,
        const std::string& zwischen,
        const std::string& ende);
    // Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
    // start: stirng vor der Ausgabe der Liste
    // zwischen: string zwischen Listenknoten
    // ende: string am Ende der Liste
    List<T>& operator=(const List<T>& _List); // Zuweisungsoperator definieren

    List<T>& operator+(const List<T>& List_Append); // Listen zusammenführen zu einer Liste

    template <typename Tf>

    friend std::ostream& operator<<(std::ostream& stream, const List<Tf>& Liste); // Ausgabeoperator überladen

    friend Node<T>* get_anker(List<T>& l);

    friend int get_AnzahlNodes(List<T>& l);
};

#endif

template <typename T>
List<T>::List()
{
    // Konstruktor für eine leere Liste
    head_tail = new Node<T>;
    list_size = 0;
    temp = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

template <typename T>
List<T>::List(const List<T>& _List)
{
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen.
    list_form = _List.list_form;
    head_tail = new Node<T>;
    list_size = 0;
    temp = _List.temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node<T>* tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail)
    {
        head_tail->prev =
            new Node<T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List.temp)
        delete& _List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
}

template <typename T>
List<T>::~List()
{
    // Dekonstruktor
    // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht
    // wird.
    Node<T>* tmp = head_tail->next;
    while (tmp != head_tail)
    {
        tmp = tmp->next;
        delete tmp->prev;
    }
    delete head_tail;
}

template <typename T>
void List<T>::insertFront(T key)
{

    // Einfuegen eines neuen Knotens am Anfang der Liste
    /*
    Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einfügen
    */

    // Wenn die Liste leer ist
    if (head_tail->next == head_tail) {

        Node<T>* neuer_eintrag = new Node<T>(key);   // neuer Knoten wird erstellt

        neuer_eintrag->prev = head_tail;
        neuer_eintrag->next = head_tail;
        head_tail->next = neuer_eintrag;
        head_tail->prev = neuer_eintrag;

        list_size++;
    }
    // Neuer Knoten am Anfang der Liste
    else {
        Node<T>* ptr = head_tail->next;
        Node<T>* neuer_eintrag = new Node<T>(key, NULL, NULL);    // neuer Knoten wird erstellt

        head_tail->next = neuer_eintrag;
        neuer_eintrag->prev = head_tail;
        neuer_eintrag->next = ptr;
        ptr->prev = neuer_eintrag;

        list_size++;
    }



}

template <typename T>
void List<T>::insertFront(List<T>& _List)
{
    // Einfuegen der Liste _List am Anfang an einer vorhandenen Liste 
    /*
    *
    Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
    Die einzufuegende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */

    if (head_tail == _List.head_tail) return;			// gleiches Objekt -> keine Aktion

    //wenn liste A leer ist
    if (head_tail->next == head_tail) {
        _List.head_tail->next->prev = head_tail;
        head_tail->next = _List.head_tail->next;
        _List.head_tail->prev->next = head_tail;
        head_tail->prev = _List.head_tail->prev;

        _List.head_tail->next = _List.head_tail;       //_list wird geschlossen
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;                 // Liste A wird um die größe von _List vergrößert
        _List.list_size = 0;
    }
    else {
        _List.head_tail->prev->next = head_tail->next;
        head_tail->next->prev = _List.head_tail->prev;
        _List.head_tail->next->prev = head_tail;
        head_tail->next = _List.head_tail->next;

        _List.head_tail->next = _List.head_tail;     //_list wird geschlossen
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;               // Liste A wird um die größe von _List vergrößert
        _List.list_size = 0;
    }

    /*
        Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
        Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
        Die Liste _List ist danach leer, aber vorhanden.
    */

}

template <typename T>
void List<T>::insertBack(T key)
{
    // Einfuegen eines neuen Knotens am Ende der Liste
/*
    Einen neuen Knoten mit dem Wert value wird am Ende der Liste einfügen
*/

// Wenn die Liste leer ist
    if (head_tail->next == head_tail) {
        Node<T>* neuer_eintrag = new Node<T>(key);    // neuer Knoten wird erstellt
        neuer_eintrag->next = head_tail;
        neuer_eintrag->prev = head_tail;
        head_tail->next = neuer_eintrag;
        head_tail->prev = neuer_eintrag;

        list_size++;
    }
    // Neuer Knoten am Ende der Liste
    else {
        Node<T>* ptr = head_tail->prev;
        Node<T>* neuer_eintrag = new Node<T>(key, NULL, NULL);   // neuer Knoten wird erstellt
        head_tail->prev = neuer_eintrag;
        neuer_eintrag->next = head_tail;
        neuer_eintrag->prev = ptr;
        ptr->next = neuer_eintrag;

        list_size++;
    }
}

template <typename T>
void List<T>::insertBack(List<T>& _List)
{
    // Einfuegen der Liste _List am Ende einer vorhandenen Liste
    /*
    Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
    Die einzufuegende Liste _List ist anschließend leer.
    Es darf keine Schleife und kein new benutzt werden.
    */

    if (head_tail == _List.head_tail) return;			// gleiches Objekt -> keine Aktion

    //wenn liste A leer ist
    if (head_tail->next == head_tail) {
        _List.head_tail->next->prev = head_tail;
        head_tail->next = _List.head_tail->next;
        _List.head_tail->prev->next = head_tail;
        head_tail->prev = _List.head_tail->prev;

        _List.head_tail->next = _List.head_tail;       // Liste wird geschlossen
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;                 // Liste A wird um die größe von _List vergrößert
        _List.list_size = 0;
    }
    else {
        head_tail->prev->next = _List.head_tail->next;
        _List.head_tail->next->prev = head_tail->prev;
        head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = head_tail;

        _List.head_tail->next = _List.head_tail;       // Liste wird geschlossen
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;                // Liste A wird um die größe von _List vergrößert
        _List.list_size = 0;
    }

    /*
        Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
        Diese Knoten (koplette Kette) werden an den Ende der Liste (this) übertragen ohne sie zu kopieren!
        Die Liste _List ist danach leer, aber vorhanden.
    */


}

template <typename T>
bool List<T>::getFront(T& key)
{
    // entnehmen des Knotens am Anfang der Liste
    // der Wert wird als Parameter zurueckgegeben
    // der Knoten wird entnommen
    // im Fehlerfall wird false zurückgegeben
    if (!list_size) return false;	// leere Liste -> kein Wert

    key = head_tail->next->key;     //key ist der wert des knotens, der gelöscht wird

    // Wenn Liste um ein Knoten lang ist außer head_tail
    if (head_tail->next == head_tail->prev) {
        delete head_tail->next;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
        list_size--;
    }
    // Wenn Liste mehrere Knoten enthält
    else {
        Node<T>* ptr = head_tail->next->next;
        delete head_tail->next;
        head_tail->next = ptr;
        ptr->prev = head_tail;

        list_size--;
    }
    return true;

    /*
        Der Wert des vorderen Knotens wird rückgegeben und der Knoten gelöscht.
        Die Methode del(key) darf nicht zum löschen benutzt werden.
    */
}

template <typename T>
bool List<T>::getBack(T& key)
{ // entnehmen des Knotens am Ende der Liste
    // der Wert wird als Parameter zurueckgegeben
    // der Knoten wird entnommen
    // im Fehlerfall wird false zurückgegeben
    if (!list_size) return false;	// leere Liste -> kein Wert

    key = head_tail->prev->key;     //key ist der wert des knotens, der gelöscht wird

    // Wenn Liste um ein Knoten lang ist außer head_tail
    if (head_tail->next == head_tail->prev) {
        delete head_tail->prev;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;

        list_size--;
    }
    // Wenn Liste mehrere Knoten enthält
    else {
        Node<T>* ptr = head_tail->prev->prev;
        delete head_tail->prev;
        head_tail->prev = ptr;
        ptr->next = head_tail;

        list_size--;
    }
    return true;


    /*
        Der Wert des letzten Knotens wird rückgegeben und der Knoten gelöscht.
        Die Methode del(key) darf nicht zum löschen benutzt werden.
    */
}

template <typename T>
bool List<T>::del(T key)
{
    // Loeschen eines gegebenen Knotens
     // im Fehlerfall wird false zurückgegeben
    if (!list_size) return false; // leere Liste -> keine Aktion
/*
    Löschen des Knotens mit dem Wert value
*/
    else {
        Node<T>* delNode = head_tail->next;
        while (delNode != NULL && delNode != head_tail) {     // Liste wird durchlaufen solange delNode != NULL und head_tail ist
            if (delNode->key == key) {
                delNode->prev->next = delNode->next;
                delNode->next->prev = delNode->prev;
                delete delNode;

                list_size--;
                return true;
            }
            delNode = delNode->next;
        }
    }
    return false;



}

template <typename T>
bool List<T>::search(T key)
{
    // suchen eines Knotens
    // nicht gefunden -> Rueckgabe: false
    if (!list_size) return false; // leere Liste -> keine Aktion
/*
    suchen ob ein Knoten mit dem Wert value existiert.
*/
    else {
        int i = 0;
        Node<T>* search = head_tail;
        while (i < list_size + 1) {
            if (search->key == key && search != head_tail) {
                return true;
            }
            search = search->next;
            i++;
        }
    }
    return false;

}

template <typename T>
bool List<T>::swap(T key1, T key2)
{
    // Vertauschen von zwei Knoten
    // Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.
    // im Fehlerfall wird false zurueckgegeben

    if (list_size < 2) return false; // leere oder einer Liste -> keine Aktion

    Node<T>* pointer = head_tail->next;
    Node<T>* pointer2 = head_tail->next;

    while (pointer->key != key1 && pointer != head_tail) {      // Liste wird durchlaufen bis der pointer auf den Knoten mit key zeigt
        pointer = pointer->next;
    }
    while (pointer2->key != key2 && pointer2 != head_tail) {    // Liste wird durchlaufen bis der pointer2 auf den Knoten mit key zeigt
        pointer2 = pointer2->next;
    }

    if (pointer != head_tail && pointer2 != head_tail) {
        Node<T>* temp1 = new Node<T>;
        temp1->next = pointer->next;
        temp1->prev = pointer->prev;

        Node<int>* temp2 = new Node<int>;
        temp2->next = pointer2->next;
        temp2->prev = pointer2->prev;

        // ersten Temp Knoten verketten
        pointer->next->prev = temp1;
        pointer->prev->next = temp1;
        temp1->next = pointer->next;
        temp1->prev = pointer->prev;

        // Zweiten Knoten verketten
        pointer2->prev->next = temp2;
        pointer2->next->prev = temp2;
        temp2->next = pointer2->next;
        temp2->prev = pointer2->prev;


        // Knoten Reihenfolge verändern
        pointer->next = temp2->next;
        pointer->prev = temp2->prev;
        temp2->prev->next = pointer;
        temp2->next->prev = pointer;

        pointer2->next = temp1->next;
        pointer2->prev = temp1->prev;
        temp1->next->prev = pointer2;
        temp1->prev->next = pointer2;

        // temp Knoten löschen
        delete temp1, temp2;
        return true;
    }
    return false;

}

template <typename T>
int List<T>::size(void)
{
    // Rueckgabe der Anzahl der Knoten in der Liste mit O(1)
/*
    Anzahl der Knoten in der Liste zurückgeben.
*/
    return list_size;	// Hier richtiges Ergebnis zurückgeben
}

template <typename T>
bool List<T>::test(void)
{
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und
    // zurück Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
    // der Knoten überein liefert die Methode true
    Node<T>* tmp = head_tail->next;
    int   i_next = 0, i_prev = 0;
    while (tmp != head_tail)
    {
        tmp = tmp->next;
        if (i_next > list_size)
            return false;
        i_next++;
    }
    if (i_next != list_size)
        return false;
    tmp = head_tail->prev;
    while (tmp != head_tail)
    {
        tmp = tmp->prev;
        if (i_prev > list_size)
            return false;
        i_prev++;
    }
    return i_prev == i_next;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen. Kopiert wird in das Objekt "this"
    if (this == &_List)
        return *this; //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node<T>* tmp_node;
    if (list_size)
    {
        Node<T>* tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node !=
            head_tail) // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size = 0;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    tmp_node = _List.head_tail->next; // Die Listen-Knotenwerte werden kopiert
    while (tmp_node != _List.head_tail)
    {
        insertBack(tmp_node->key);
        tmp_node = tmp_node->next;
    }
    if (_List.temp)
        delete& _List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
    return *this;
}

template <typename T>
List<T>& List<T>::operator+(const List<T>& List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue
    // Ergebnisliste.
    Node<T>* tmp_node;
    List<T>* tmp;
    if (temp)
    { // this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    }
    else
    {
        tmp =
            new List<T>(*this); // this ist keine temporäre Liste -> Kopie erzeugen
        tmp->temp = true;    // Merker setzten, dass es sich um eine temporäre
                             // Liste handelt
    }
    if (List_Append.list_size)
    { // anhängen der übergebenen Liste an tmp
        tmp_node = List_Append.head_tail->next;
        while (tmp_node != List_Append.head_tail)
        {
            tmp->insertBack(tmp_node->key);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append.temp)
        delete& List_Append; // wurde eine temporäre Liste übergeben, dann wird
                             // diese gelöscht
    return *tmp;
}

template <typename T>
void List<T>::format(const std::string& start,
    const std::string& zwischen,
    const std::string& ende)
{
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start = start;
    list_form.zwischen = zwischen;
    list_form.ende = ende;
}

template <typename Tf>
std::ostream& operator<<(std::ostream& stream, List<Tf> const& Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node<Tf>* tmp = Liste.head_tail->next; tmp != Liste.head_tail;
        tmp = tmp->next)
        stream << tmp->key
        << (tmp->next == Liste.head_tail ? Liste.list_form.ende :
            Liste.list_form.zwischen);
    if (Liste.temp)
        delete& Liste; // wurde eine temporäre Liste übergeben, dann wird diese
                       // gelöscht
    return stream;
}

template class List<int>;