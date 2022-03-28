#include "List.h"

List::List()
{
    // Konstruktor für eine leere Liste
    head_tail       = new Node;
    list_size       = 0;
    temp            = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

List::List(const List& _List)
{
    // Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen.
    list_form       = _List.list_form;
    head_tail       = new Node;
    list_size       = 0;
    temp            = _List.temp;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
    Node* tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail)
    {
        head_tail->prev =
            new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
    if (_List.temp)
        delete &_List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
}

List::~List()
{
    // Dekonstruktor
    // Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht
    // wird.
    Node* tmp = head_tail->next;
    while (tmp != head_tail)
    {
        tmp = tmp->next;
        delete tmp->prev;
    }
    delete head_tail;
}

void List::insertFront(int key)
{
	// Einfuegen eines neuen Knotens am Anfang der Liste
/*
	Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einfügen
*/
    if (head_tail->next == head_tail) {
        
        Node* neuer_eintrag = new Node(key);
       
        neuer_eintrag->prev = head_tail;
        neuer_eintrag->next = head_tail;
        head_tail->next = neuer_eintrag;
        head_tail->prev = neuer_eintrag;
        
        list_size = list_size + 1;
    }
    else {
        Node* ptr = head_tail->next;
        Node* neuer_eintrag = new Node(key, NULL, NULL);
        
        head_tail->next = neuer_eintrag;
        neuer_eintrag->prev = head_tail;
        neuer_eintrag->next = ptr;
        ptr->prev = neuer_eintrag;

        list_size = list_size + 1;
    }
  
}

void List::insertFront(List& _List)
{
	// Einfuegen der Liste _List am Anfang an einer vorhandenen Liste 
	/*	
	Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
	Die einzufuegende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden. 
	*/
	if (head_tail == _List.head_tail) return;			// gleiches Objekt -> keine Aktion
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	Die Liste _List ist danach leer, aber vorhanden.
*/
    if (head_tail->next == head_tail) {
        _List.head_tail->next->prev = head_tail;
        head_tail->next = _List.head_tail->next;
        _List.head_tail->prev->next = head_tail;
        head_tail->prev = _List.head_tail->prev;

        _List.head_tail->next = _List.head_tail;
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;
        _List.list_size = 0;
    }
    else {
        _List.head_tail->prev->next = head_tail->next;
        head_tail->next->prev = _List.head_tail->prev;
        _List.head_tail->next->prev = head_tail;
        head_tail->next = _List.head_tail->next;

        _List.head_tail->next = _List.head_tail;
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;
        _List.list_size = 0;
    }
}

void List::insertBack(int key)
{
	// Einfuegen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Wert value wird am Ende der Liste einfügen
*/
    if (head_tail->next == head_tail) {
        Node* neuer_eintrag = new Node(key);
        neuer_eintrag->next = head_tail;
        neuer_eintrag->prev = head_tail;
        head_tail->next = neuer_eintrag;
        head_tail->prev = neuer_eintrag;
        
        list_size = list_size + 1;
    }
    else {
        Node* ptr = head_tail->prev;
        Node* neuer_eintrag = new Node(key, NULL, NULL);
        head_tail->prev = neuer_eintrag;
        neuer_eintrag->next = head_tail;
        neuer_eintrag->prev = ptr;
        ptr->next = neuer_eintrag;

        list_size = list_size + 1;
    }
}

void List::insertBack(List& _List)
{
	// Einfuegen der Liste _List am Ende einer vorhandenen Liste
	/*
	Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
	Die einzufuegende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden. 
	*/
	if (head_tail == _List.head_tail) return;			// gleiches Objekt -> keine Aktion
/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Ende der Liste (this) übertragen ohne sie zu kopieren!
	Die Liste _List ist danach leer, aber vorhanden.
*/
    if (head_tail->next == head_tail) {
        _List.head_tail->next->prev = head_tail;
        head_tail->next = _List.head_tail->next;
        _List.head_tail->prev->next = head_tail;
        head_tail->prev = _List.head_tail->prev;

        _List.head_tail->next = _List.head_tail;
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;
        _List.list_size = 0;
    }
    else {
        head_tail->prev->next = _List.head_tail->next;
        _List.head_tail->next->prev = head_tail->prev;
        head_tail->prev = _List.head_tail->prev;
        _List.head_tail->prev->next = head_tail;
       
        _List.head_tail->next = _List.head_tail;
        _List.head_tail->prev = _List.head_tail;

        list_size += _List.list_size;
        _List.list_size = 0;
    }
}

bool List::getFront(int& key)
{
	// entnehmen des Knotens am Anfang der Liste
	// der Wert wird als Parameter zurueckgegeben
	// der Knoten wird entnommen
	// im Fehlerfall wird false zurückgegeben
	if (!list_size) return false;	// leere Liste -> kein Wert
	/*
		Der Wert des vorderen Knotens wird rückgegeben und der Knoten gelöscht.
		Die Methode del(key) darf nicht zum löschen benutzt werden.
	*/
    key = head_tail->next->key;    // key ist der wert vom ersten knoten, der gelöscht wird
   
    if (head_tail->next == head_tail->prev) {
        delete head_tail->next;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
        list_size = list_size - 1;
    }
    else {
        Node* ptr = head_tail->next->next;
        delete head_tail->next;
        head_tail->next = ptr;
        ptr->prev = head_tail;
        
        list_size = list_size - 1;
    }
    return true;
}

bool List::getBack(int& key)
{ // entnehmen des Knotens am Ende der Liste
	// der Wert wird als Parameter zurueckgegeben
	// der Knoten wird entnommen
	// im Fehlerfall wird false zurückgegeben
	if (!list_size) return false;	// leere Liste -> kein Wert
	/*
		Der Wert des letzten Knotens wird rückgegeben und der Knoten gelöscht.
		Die Methode del(key) darf nicht zum löschen benutzt werden.
	*/
    key = head_tail->prev->key;
    if (head_tail->next == head_tail->prev) {
        delete head_tail->prev;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
       
        list_size = list_size - 1;
    }
    else {
        Node* ptr = head_tail->prev->prev;
        delete head_tail->prev;
        head_tail->prev = ptr;
        ptr->next = head_tail;

        list_size = list_size - 1;
    }
    return true;
}

bool List::del(int key)
{
	// Loeschen eines gegebenen Knotens
	// im Fehlerfall wird false zurückgegeben
	if (!list_size) return false; // leere Liste -> keine Aktion
/*
	Löschen des Knotens mit dem Wert value 
*/
    else {
        Node* delNode = head_tail->next;
        while (delNode != NULL && delNode != head_tail) {
            if (delNode->key == key) {
                delNode->prev->next = delNode->next;
                delNode->next->prev = delNode->prev;
                delete delNode;
                
                list_size = list_size - 1;
                return true;
            }
            delNode = delNode->next;
        }
    }
    return false;
}

bool List::search(int key)
{
	// suchen eines Knotens
	// nicht gefunden -> Rueckgabe: false
	if (!list_size) return false; // leere Liste -> keine Aktion
/*
	suchen ob ein Knoten mit dem Wert value existiert.
*/
    else {
        int i = 0;
        Node* search = head_tail;
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

bool List::swap(int key1, int key2)
{
	// Vertauschen von zwei Knoten
	// Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.
	// im Fehlerfall wird false zurueckgegeben
	if (list_size < 2) return false; // leere oder einer Liste -> keine Aktion
/*
	Vertauschen von zwei Knoten mit dem Wert value1 und dem Wert value2.
	Es duerfen nicht nur einfach die Werte in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhaengen.
*/
    Node* pointer = head_tail->next;
    Node* pointer2 = head_tail->next;

    while (pointer->key != key1 && pointer != head_tail) {
        pointer = pointer->next;
    }
    while (pointer2->key != key2 && pointer2 != head_tail) {
        pointer2 = pointer2->next;
    }

    if (pointer != head_tail && pointer2 != head_tail) {
        Node* temp1 = new Node;
        temp1->next = pointer->next;
        temp1->prev = pointer->prev;

        Node* temp2 = new Node;
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

int List::size(void)
{
	// Rueckgabe der Anzahl der Knoten in der Liste mit O(1)
/*
	Anzahl der Knoten in der Liste zurückgeben.
*/
	return list_size;	// Hier richtiges Ergebnis zurückgeben
}

bool List::test(void)
{
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und
    // zurück Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
    // der Knoten überein liefert die Methode true
    Node* tmp    = head_tail->next;
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

List& List::operator=(const List& _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen. Kopiert wird in das Objekt "this"
    if (this == &_List)
        return *this; //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node* tmp_node;
    if (list_size)
    {
        Node* tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node !=
               head_tail) // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del  = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size       = 0;
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
        delete &_List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
    return *this;
}

List& List::operator+(const List& List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue
    // Ergebnisliste.
    Node* tmp_node;
    List* tmp;
    if (temp)
    { // this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    }
    else
    {
        tmp =
            new List(*this); // this ist keine temporäre Liste -> Kopie erzeugen
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
        delete &List_Append; // wurde eine temporäre Liste übergeben, dann wird
                             // diese gelöscht
    return *tmp;
}

void List::format(const std::string& start,
                  const std::string& zwischen,
                  const std::string& ende)
{
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start    = start;
    list_form.zwischen = zwischen;
    list_form.ende     = ende;
}

std::ostream& operator<<(std::ostream& stream, List const& Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node* tmp = Liste.head_tail->next; tmp != Liste.head_tail;
         tmp       = tmp->next)
        stream << tmp->key
               << (tmp->next == Liste.head_tail ? Liste.list_form.ende :
                                                  Liste.list_form.zwischen);
    if (Liste.temp)
        delete &Liste; // wurde eine temporäre Liste übergeben, dann wird diese
                       // gelöscht
    return stream;
}
