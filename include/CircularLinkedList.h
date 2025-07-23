#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

class CircularLinkedList {
private:
    struct Nodo {
        char dato;
        Nodo* siguiente;
    };

    Nodo* head;
    int count;

public:
    CircularLinkedList();
    
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