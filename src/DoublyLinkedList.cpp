#include "../include/DoublyLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
}

void DoublyLinkedList::addElement(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (head == nullptr) {
        head = nuevoNodo;
        tail = nuevoNodo;
    } else {
        tail->siguiente = nuevoNodo;
        nuevoNodo->anterior = tail;
        tail = nuevoNodo;
    }
    count++;
}

void DoublyLinkedList::printLists() {
    Nodo* actual = head;
    cout << "Lista Doble Lineal: Visualización gráfica \n";
    
    for (int i = 0; i < count; i++) {
        cout << "┌───┐   ";
    }
    cout << endl;
    while (actual != nullptr) {
        cout << "│ " << actual->dato << " │ ⇄ ";
        actual = actual->siguiente;
    }
    cout << "Null" << endl;
    for (int i = 0; i < count; i++) {
        cout << "└───┘   ";
    }
    cout << endl;
}

void DoublyLinkedList::traverseList() {
    Nodo* actual = head;

    if (actual == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    cout << "Lista recorrida:\n";
    while (actual != nullptr) {
        cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    cout << "Null" << endl;
}

void DoublyLinkedList::insertToStart(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = head;
    nuevoNodo->anterior = nullptr;

    if (head != nullptr) {
        head->anterior = nuevoNodo;
    } else {
        tail = nuevoNodo;
    }

    head = nuevoNodo;
    count++;
}

void DoublyLinkedList::insertAtPosition(char dato, int position) {
    if (position < 1 || position > count + 1) {
        cout << "Posición no válida. La posición debe estar entre 1 y " << count + 1 << ".\n";
        return;
    }

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (position == 1) {
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = nullptr;
        if (head != nullptr) {
            head->anterior = nuevoNodo;
        } else {
            tail = nuevoNodo;
        }
        head = nuevoNodo;
    } else {
        Nodo* anterior = head;
        for (int i = 1; i < position - 1; i++) {
            anterior = anterior->siguiente;
        }
        nuevoNodo->siguiente = anterior->siguiente;
        nuevoNodo->anterior = anterior;
        if (anterior->siguiente != nullptr) {
            anterior->siguiente->anterior = nuevoNodo;
        } else {
            tail = nuevoNodo;
        }
        anterior->siguiente = nuevoNodo;
    }

    count++;
}

void DoublyLinkedList::deleteFirst() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head;

    if (head->siguiente != nullptr) {
        head->siguiente->anterior = nullptr;
        head = head->siguiente;
    } else {
        head = nullptr;
        tail = nullptr;
    }

    delete temp;
    count--;
    cout << "Eliminado con éxito" << endl;
}

void DoublyLinkedList::deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    if (position < 1 || position > count) {
        cout << "Posición no válida. La posición debe estar entre 1 y " << count << ".\n";
        return;
    }

    Nodo* temp;
    if (position == 1) {
        temp = head;

        if (head->siguiente != nullptr) {
            head->siguiente->anterior = nullptr;
            head = head->siguiente;
        } else {
            head = nullptr;
            tail = nullptr;
        }
    } else {
        Nodo* actual = head;
        for (int i = 1; i < position; i++) {
            actual = actual->siguiente;
        }

        temp = actual;

        if (actual->anterior != nullptr) {
            actual->anterior->siguiente = actual->siguiente;
        } else {
            head = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = actual->anterior;
        } else {
            tail = actual->anterior;
        }
    }

    delete temp;
    count--;
    cout << "Eliminado con éxito" << endl;
}

void DoublyLinkedList::deleteLast() {
    if (tail == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = tail;

    if (tail->anterior != nullptr) {
        tail->anterior->siguiente = nullptr;
        tail = tail->anterior;
    } else {
        head = nullptr;
        tail = nullptr;
    }

    delete temp;
    count--;

    cout << "Eliminado con éxito" << endl;
}