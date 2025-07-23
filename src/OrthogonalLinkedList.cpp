#include "../include/OrthogonalLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

OrthogonalLinkedList::OrthogonalLinkedList() : head(nullptr), count(0) {}

OrthogonalLinkedList::~OrthogonalLinkedList() {
    while (head != nullptr) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
}

void OrthogonalLinkedList::addElement(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->abajo = nullptr;
    nuevoNodo->arriba = nullptr;

    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
        head->anterior = head;
        head->abajo = head;
        head->arriba = head;
    } else {
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = head->anterior;
        nuevoNodo->abajo = head;
        nuevoNodo->arriba = head->arriba;
        head->anterior->siguiente = nuevoNodo;
        head->anterior = nuevoNodo;
        head->arriba->abajo = nuevoNodo;
        head->arriba = nuevoNodo;
    }
    count++;
}

void OrthogonalLinkedList::printLists() {
    Nodo* actual = head;
    string lines = " ";

    cout << "Lista Ortogonal Lineal: Visualización gráfica \n";

    for (int i = 0; i < count; i++) {
        cout << " ┌───┐  ";
    }
    cout << endl;

    if (head != nullptr) {
        Nodo* temp = actual;
        do {
            string charString(1, actual->dato);

            lines += "│ " + charString + " │ ⇄ ";
            actual = actual->siguiente;
        } while (actual != nullptr && actual != head);
    }

    cout << lines << "Head" << endl;
    for (int i = 0; i < count; i++) {
        cout << " └───┘  ";
    }
    cout << endl;
}

void OrthogonalLinkedList::traverseList() {
    Nodo* actual = head;

    if (actual == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    cout << "Lista recorrida:\n";
    do {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    } while (actual != head);
    cout << "Head" << endl;
}

void OrthogonalLinkedList::insertRowAtStart(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
        head->anterior = head;
        head->abajo = head;
        head->arriba = head;
    } else {
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = head->anterior;
        nuevoNodo->abajo = head;
        nuevoNodo->arriba = head->arriba;
        head->anterior->siguiente = nuevoNodo;
        head->anterior = nuevoNodo;
        head->arriba->abajo = nuevoNodo;
        head->arriba = nuevoNodo;
        head = nuevoNodo;
    }

    count++;
}

void OrthogonalLinkedList::insertColumnAtEnd(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
        head->anterior = head;
        head->abajo = head;
        head->arriba = head;
    } else {
        Nodo* actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = actual;
        nuevoNodo->abajo = nuevoNodo;
        nuevoNodo->arriba = nuevoNodo;
        actual->siguiente = nuevoNodo;
        head->anterior = nuevoNodo;
    }

    count++;
}

void OrthogonalLinkedList::deleteLastRow() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head->arriba;

    if (head->abajo != nullptr) {
        head->arriba->abajo = head->abajo;
        head->abajo->arriba = head->arriba;
        head = head->abajo;
    } else {
        head = nullptr;
    }

    delete temp;
    count--;

    cout << "Eliminado con éxito" << endl;
}

void OrthogonalLinkedList::deleteFirstColumn() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head->siguiente;

    if (head->siguiente != head) {
        head->anterior->siguiente = head->siguiente;
        head->siguiente->anterior = head->anterior;
        head = head->siguiente;
    } else {
        head = nullptr;
    }

    delete temp;
    count--;

    cout << "Eliminado con éxito" << endl;
}