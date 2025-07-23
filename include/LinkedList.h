#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
private:
    struct Nodo {
        char dato;
        Nodo* siguiente;
    };

    Nodo* head;
    int count;

public:
    LinkedList();
    ~LinkedList();
    
    void addElement(char dato);
    void printLists();
    void traverseList();
    void insertToStart(char dato);
    void insertAtPosition(char dato, int position);
    void deleteLast();
    void deleteAtPosition(int position);
    void deleteFirst();
};

#endif