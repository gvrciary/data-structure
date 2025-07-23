#include "../include/CircularLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

CircularLinkedList::CircularLinkedList() : head(nullptr), count(0) {}

void CircularLinkedList::addElement(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;

    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
    } else {
        Nodo* actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = head;
    }
    count++;
}

void CircularLinkedList::printLists() {
    Nodo* actual = head;
    string lines = "";
    cout << "Lista Lineal Circular: Visualización gráfica \n";
    for (int i = 0; i < count; i++) {
        cout << "┌───┐    ";
    }
    cout << endl;
    do {
        lines += "│ ";
        lines += actual->dato;
        lines += " │ -->";
        actual = actual->siguiente;
    } while (actual != head);
    cout << lines << "Head" << endl;
    for (int i = 0; i < count; i++) {
        cout << "└───┘    ";
    }
    cout << endl;
}

void CircularLinkedList::traverseList() {
    Nodo* actual = head;

    if (actual == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    cout << "Lista recorrida:\n";
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != head);
    cout << "Head" << endl;
}

void CircularLinkedList::insertToStart(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    
    if (head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
    } else {
        Nodo* actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = head;
        head = nuevoNodo;
    }

    count++;
}

void CircularLinkedList::insertAtPosition(char dato, int position) {
    if (position < 1 || position > count + 1) {
        cout << "Posición no válida. La posición debe estar entre 1 y " << count + 1 << ".\n";
        return;
    }

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (position == 1) {
        nuevoNodo->siguiente = head;
        head = nuevoNodo;
        Nodo* actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        actual->siguiente = head;
    } else {
        Nodo* anterior = head;
        for (int i = 1; i < position - 1; i++) {
            anterior = anterior->siguiente;
        }
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevoNodo;
    }

    count++;
}

void CircularLinkedList::deleteFirst() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head;

    if (head->siguiente == head) {
        delete head;
        head = nullptr;
    } else {
        Nodo* actual = head;
        while (actual->siguiente != head) {
            actual = actual->siguiente;
        }
        actual->siguiente = head->siguiente;
        head = head->siguiente;
        delete temp;
    }

    count--;
    cout << "Eliminado con éxito" << endl;
}

void CircularLinkedList::deleteAtPosition(int position) {
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
        if (head->siguiente == head) {
            delete head;
            head = nullptr;
        } else {
            Nodo* actual = head;
            while (actual->siguiente != head) {
                actual = actual->siguiente;
            }
            actual->siguiente = head->siguiente;
            head = head->siguiente;
            delete temp;
        }
    } else {
        Nodo* anterior = head;
        for (int i = 1; i < position - 1; i++) {
            anterior = anterior->siguiente;
        }

        temp = anterior->siguiente;
        anterior->siguiente = temp->siguiente;
        delete temp;
    }

    count--;
    cout << "Eliminado con éxito" << endl;
}

void CircularLinkedList::deleteLast() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = nullptr;
    Nodo* actual = head;

    while (actual->siguiente != head) {
        temp = actual;
        actual = actual->siguiente;
    }

    if (temp == nullptr) {
        delete head;
        head = nullptr;
    } else {
        temp->siguiente = head;
        delete actual;
    }

    count--;

    cout << "Eliminado con éxito" << endl;
}