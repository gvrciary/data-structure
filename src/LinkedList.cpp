#include "../include/LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList() : head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
}

void LinkedList::addElement(char dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;

    if (head == nullptr) {
        head = nuevoNodo;
    } else {
        Nodo* actual = head;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
    count++;
}

void LinkedList::printLists() {
    Nodo* actual = head;
    string lines = "";
    cout << "Lista Lineal : Visualizacion grafica \n";
    for (int i = 0; i < count; i++) {
        cout << "┌───┐    ";
    }
    cout << endl;
    while (actual != nullptr) {
        lines += "│ ";
        lines += actual->dato;
        lines += " │ -->";
        actual = actual->siguiente;
    }
    cout << lines << "Null" << endl;
    for (int i = 0; i < count; i++) {
        cout << "└───┘    ";
    }
    cout << endl;
}

void LinkedList::traverseList() {
    Nodo* p = head;

    if (p == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    cout << "Lista recorrida [Elementos]:\n";
    while (p != nullptr) {
        cout << p->dato << ", ";
        p = p->siguiente;
    }
    cout << endl;
}

void LinkedList::insertToStart(char dato){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = head;
    head = nuevoNodo;
    count++;
}

void LinkedList::insertAtPosition(char dato, int position) {
    if (position < 1 || position > count + 1) {
        cout << "Posición no válida. La posición debe estar entre 1 y " << count + 1 << ".\n";
        return;
    }

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;

    if (position == 1) {
        nuevoNodo->siguiente = head;
        head = nuevoNodo;
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

void LinkedList::deleteLast() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* nuevoNodo = head;

    if (head->siguiente == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Nodo* p = head;
        Nodo* anterior = nullptr;

        while (p->siguiente != nullptr) {
            anterior = p;
            p = p->siguiente;
        }

        delete p;
        anterior->siguiente = nullptr;
    }

    count--;
    cout << "Eliminada con exito" << endl;
}

void LinkedList::deleteAtPosition(int position) {
    if (position < 1 || position > count) {
        cout << "Posición no válida. La posición debe estar entre 1 y " << count << ".\n";
        return;
    }

    Nodo* temp;
    if (position == 1) {
        temp = head;
        head = head->siguiente;
    } else {
        Nodo* anterior = head;
        for (int i = 1; i < position - 1; i++) {
            anterior = anterior->siguiente;
        }

        temp = anterior->siguiente;
        anterior->siguiente = temp->siguiente;
    }

    delete temp;
    count--;
}

void LinkedList::deleteFirst() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }

    Nodo* temp = head;
    head = head->siguiente;
    delete temp;
    count--;
    cout << "Eliminada con exito" << endl;
}