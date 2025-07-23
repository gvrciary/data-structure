#ifndef ORTHOGONALLINKEDLIST_H
#define ORTHOGONALLINKEDLIST_H

class OrthogonalLinkedList {
private:
    struct Nodo {
        char dato;
        Nodo* siguiente;
        Nodo* anterior;
        Nodo* abajo;
        Nodo* arriba;
    };

    Nodo* head;
    int count;

public:
    OrthogonalLinkedList();
    ~OrthogonalLinkedList();
    
    void addElement(char dato);
    void printLists();
    void traverseList();
    void insertRowAtStart(char dato);
    void insertColumnAtEnd(char dato);
    void deleteLastRow();
    void deleteFirstColumn();
};

#endif