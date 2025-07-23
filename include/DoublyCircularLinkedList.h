#ifndef DOUBLYCIRCULARLINKEDLIST_H
#define DOUBLYCIRCULARLINKEDLIST_H

class DoublyCircularLinkedList {
private:
    struct Nodo {
        char dato;
        Nodo* siguiente;
        Nodo* anterior;
    };

    Nodo* head;
    int count;

public:
    DoublyCircularLinkedList();
    ~DoublyCircularLinkedList();
    
    void addElement(char dato);
    void printLists();
    void traverseList();
    void insertToStart(char dato);
    void insertAtPosition(char dato, int position);
    void deleteFirst();
    void deleteAtPosition(int position);
    void deleteLast();
};

#endif