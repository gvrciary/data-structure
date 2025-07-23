#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList {
private:
    struct Nodo {
        char dato;
        Nodo* siguiente;
        Nodo* anterior;
    };

    Nodo* head;
    Nodo* tail;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
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