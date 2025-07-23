#include "../include/DoublyCircularLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

DoublyCircularLinkedList::DoublyCircularLinkedList() : head(nullptr), count(0) {}

DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    while (head != nullptr) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
}

void DoublyCircularLinkedList::addElement(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
        head->anterior = head;
    } else {
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = head->anterior;
        head->anterior->siguiente = nuevoNodo;
        head->anterior = nuevoNodo;
    }
    count++;
}

void DoublyCircularLinkedList::printLists() {
    Nodo* actual = head;
    string lines = " ";

    cout << "Lista Doble Circular: Visualización gráfica \n";

    for (int i = 0; i < count; i++) {
        cout << " ┌───┐  ";
    }
    cout << endl;

    if (head != nullptr) {
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

void DoublyCircularLinkedList::traverseList() {
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

void DoublyCircularLinkedList::insertToStart(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
        head->anterior = head;
    } else {
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = head->anterior;
        head->anterior->siguiente = nuevoNodo;
        head->anterior = nuevoNodo;
        head = nuevoNodo;
    }

    count++;
}

void DoublyCircularLinkedList::insertAtPosition(char dato, int position) {
    if (position < 1 || position > count + 1) {
        cout << "Posición no válida. La posición debe estar entre 1 y " << count + 1 << ".\n";
        return;
    }

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (position == 1) {
        nuevoNodo->siguiente = head;
        nuevoNodo->anterior = head->anterior;
        head->anterior->siguiente = nuevoNodo;
        head->anterior = nuevoNodo;
        head = nuevoNodo;
    } else {
        Nodo* anterior = head;
        for (int i = 1; i < position - 1; i++) {
            anterior = anterior->siguiente;
        }
        nuevoNodo->siguiente = anterior->siguiente;
        nuevoNodo->anterior = anterior;
        anterior->siguiente->anterior = nuevoNodo;
        anterior->siguiente = nuevoNodo;
    }

    count++;
}

void DoublyCircularLinkedList::deleteFirst() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head;

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

void DoublyCircularLinkedList::deleteAtPosition(int position) {
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

        if (head->siguiente != head) {
            head->anterior->siguiente = head->siguiente;
            head->siguiente->anterior = head->anterior;
            head = head->siguiente;
        } else {
            head = nullptr;
        }
    } else {
        Nodo* actual = head;
        for (int i = 1; i < position; i++) {
            actual = actual->siguiente;
        }

        temp = actual;

        if (actual->anterior != nullptr) {
            actual->anterior->siguiente = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = actual->anterior;
        }
    }

    delete temp;
    count--;
    cout << "Eliminado con éxito" << endl;
}

void DoublyCircularLinkedList::deleteLast() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head->anterior;

    if (head->siguiente != head) {
        head->anterior = temp->anterior;
        temp->anterior->siguiente = head;
    } else {
        head = nullptr;
    }

    delete temp;
    count--;

    cout << "Eliminado con éxito" << endl;
}