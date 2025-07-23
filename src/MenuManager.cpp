#include "../include/MenuManager.h"
#include "../include/LinkedList.h"
#include "../include/CircularLinkedList.h"
#include "../include/DoublyLinkedList.h"
#include "../include/DoublyCircularLinkedList.h"
#include "../include/OrthogonalLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

void MenuManager::linkedListMenu() {
    string OPTIONS_MENU[] = {"Añadir al final", "Recorrer una lista", "Insertar al inicio", "Insertar en una posicion expecifica", "Eliminar el primero", "Eliminar cualquier nodo" , "Eliminar el ultimo", "Salir"};
    LinkedList myList;
    int option;

    cout << "Primero necesitas crear la lista" << endl;
    do {
        char dato;
        cout << "Ingrese un dato: ";
        cin >> dato;
        myList.addElement(dato);

        cout << "¿Desea agregar otro elemento?\n- (1: SI)\n- (Con cualquier otro numero sales)\nRespuesta: ";
        cin >> option;

    } while (option == 1);

    cout << "\n-----------\nLista creada con exito\n-----------\n\n" << endl;
    
    while(true){
        myList.printLists();
        cout << " - - - Menu Listas - - -" << endl;
        for (int i = 0; i < sizeof(OPTIONS_MENU) / sizeof(OPTIONS_MENU[0]); ++i) {
            cout << i + 1 << ") " << OPTIONS_MENU[i] << endl;
        }
        cout << "Respuesta: ";
        cin >> option;
        char temp;
        int position;
        switch(option){
            case 1:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myList.addElement(temp);
            break;
            case 2:
                myList.traverseList();
            break;
            case 3:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myList.insertToStart(temp);
            break;
            case 4:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                cout << "En que posicion desea añadirlo\nRespuesta: ";
                cin >> position;
                myList.insertAtPosition(temp, position);
            break;
            case 5:
                myList.deleteFirst();
            break;
            case 6:
                cout << "En que posicion desea eliminar\nRespuesta: ";
                cin >> position;
                myList.deleteAtPosition(position);
            break;
            case 7:
                myList.deleteLast();
            break;
            case 8:
                return;
            default:
            cout << "Opcion invalida";
        }
    }
    return;
}

void MenuManager::circularListMenu(){
    string OPTIONS_MENU[] = {"Añadir al final", "Recorrer una lista", "Insertar al inicio", "Insertar en una posicion expecifica", "Eliminar el primero", "Eliminar cualquier nodo" , "Eliminar el ultimo", "Salir"};

    CircularLinkedList myCircularList;
    int option;

    cout << "Primero necesitas crear la lista circular" << endl;
    do {
    char dato;
    cout << "Ingrese un dato: ";
    cin >> dato;
    myCircularList.addElement(dato);

    cout << "¿Desea agregar otro elemento?\n- (1: SI)\n- (Con cualquier otro número sales)\nRespuesta: ";
    cin >> option;

    } while (option == 1);

    cout << "\n-----------\nLista circular creada con éxito\n-----------\n\n" << endl;

    while (true) {
        myCircularList.printLists();
        cout << " - - - Menu Listas - - -" << endl;
        for (int i = 0; i < sizeof(OPTIONS_MENU) / sizeof(OPTIONS_MENU[0]); ++i) {
            cout << i + 1 << ") " << OPTIONS_MENU[i] << endl;
        }
        
        cout << "Respuesta: ";
        cin >> option;
        char temp;
        int position;
        switch(option){
            case 1:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myCircularList.addElement(temp);
            break;
            case 2:
                myCircularList.traverseList();
            break;
            case 3:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myCircularList.insertToStart(temp);
            break;
            case 4:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                cout << "En que posicion desea añadirlo\nRespuesta: ";
                cin >> position;
                myCircularList.insertAtPosition(temp, position);
            break;
            case 5:
                myCircularList.deleteFirst();
            break;
            case 6:
                cout << "En que posicion desea eliminar\nRespuesta: ";
                cin >> position;
                myCircularList.deleteAtPosition(position);
            break;
            case 7:
                myCircularList.deleteLast();
            break;
            case 8:
                return;
            default:
            cout << "Opcion invalida";
        }
    }
}

void MenuManager::doublyListMenu(){
    string OPTIONS_MENU[] = {"Añadir al final", "Recorrer una lista", "Insertar al inicio", "Insertar en una posicion expecifica", "Eliminar el primero", "Eliminar cualquier nodo" , "Eliminar el ultimo", "Salir"};
    DoublyLinkedList myDoublyList;
    int option;

    cout << "Primero necesitas crear la lista doblemente enlazada" << endl;
    do {
        char dato;
        cout << "Ingrese un dato: ";
        cin >> dato;
        myDoublyList.addElement(dato);

        cout << "¿Desea agregar otro elemento?\n- (1: SI)\n- (Con cualquier otro número sales)\nRespuesta: ";
        cin >> option;

    } while (option == 1);

    cout << "\n-----------\nLista doblemente enlazada creada con éxito\n-----------\n\n" << endl;

    while (true) {
        myDoublyList.printLists();
        cout << " - - - Menu Listas - - -" << endl;
        for (int i = 0; i < sizeof(OPTIONS_MENU) / sizeof(OPTIONS_MENU[0]); ++i) {
            cout << i + 1 << ") " << OPTIONS_MENU[i] << endl;
        }

        cout << "Respuesta: ";
        cin >> option;
        char temp;
        int position;
        switch(option){
            case 1:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myDoublyList.addElement(temp);
                break;
            case 2:
                myDoublyList.traverseList();
                break;
            case 3:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myDoublyList.insertToStart(temp);
                break;
            case 4:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                cout << "En que posicion desea añadirlo\nRespuesta: ";
                cin >> position;
                myDoublyList.insertAtPosition(temp, position);
                break;
            case 5:
                myDoublyList.deleteFirst();
                break;
            case 6:
                cout << "En que posicion desea eliminar\nRespuesta: ";
                cin >> position;
                myDoublyList.deleteAtPosition(position);
                break;
            case 7:
                myDoublyList.deleteLast();
                break;
            case 8:
                return;
            default:
                cout << "Opcion invalida";
        }
    }
}

void MenuManager::doublyCircularLinkedMenu(){
    string OPTIONS_MENU[] = {"Añadir al final", "Recorrer una lista", "Insertar al inicio", "Insertar en una posicion expecifica", "Eliminar el primero", "Eliminar cualquier nodo" , "Eliminar el ultimo", "Salir"};
    DoublyCircularLinkedList myDoublyCircularList;
    int option;

    cout << "Primero necesitas crear la lista doblemente circular" << endl;
    do {
        char dato;
        cout << "Ingrese un dato: ";
        cin >> dato;
        myDoublyCircularList.addElement(dato);

        cout << "¿Desea agregar otro elemento?\n- (1: SI)\n- (Con cualquier otro número sales)\nRespuesta: ";
        cin >> option;

    } while (option == 1);

    cout << "\n-----------\nLista doblemente circular creada con éxito\n-----------\n\n" << endl;

    while (true) {
        myDoublyCircularList.printLists();
        cout << " - - - Menu Listas - - -" << endl;
        for (int i = 0; i < sizeof(OPTIONS_MENU) / sizeof(OPTIONS_MENU[0]); ++i) {
            cout << i + 1 << ") " << OPTIONS_MENU[i] << endl;
        }

        cout << "Respuesta: ";
        cin >> option;
        char temp;
        int position;
        switch(option){
            case 1:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myDoublyCircularList.addElement(temp);
                break;
            case 2:
                myDoublyCircularList.traverseList();
                break;
            case 3:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myDoublyCircularList.insertToStart(temp);
                break;
            case 4:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                cout << "En que posicion desea añadirlo\nRespuesta: ";
                cin >> position;
                myDoublyCircularList.insertAtPosition(temp, position);
                break;
            case 5:
                myDoublyCircularList.deleteFirst();
                break;
            case 6:
                cout << "En que posicion desea eliminar\nRespuesta: ";
                cin >> position;
                myDoublyCircularList.deleteAtPosition(position);
                break;
            case 7:
                myDoublyCircularList.deleteLast();
                break;
            case 8:
                return;
            default:
                cout << "Opcion invalida";
        }
    }
}

void MenuManager::orthogonalLinkedMenu(){
    string OPTIONS_MENU[] = {"Insertar renglon al principio", "Recorrer lista", "Insertar columna al final", "Eliminar ultimo renglon", "Eliminar primera columna", "Salir"};
    OrthogonalLinkedList myOrthogonalList;
    int option;

    cout << "Primero necesitas crear la lista ortogonal lineal" << endl;
    do {
        char dato;
        cout << "Ingrese un dato: ";
        cin >> dato;
        myOrthogonalList.addElement(dato);

        cout << "¿Desea agregar otro elemento?\n- (1: SI)\n- (Con cualquier otro número sales)\nRespuesta: ";
        cin >> option;

    } while (option == 1);

    cout << "\n-----------\nLista ortogonal lineal creada con éxito\n-----------\n\n" << endl;

    while (true) {
        myOrthogonalList.printLists();
        cout << " - - - Menu Listas Ortogonales Lineales - - -" << endl;
        for (int i = 0; i < sizeof(OPTIONS_MENU) / sizeof(OPTIONS_MENU[0]); ++i) {
            cout << i + 1 << ") " << OPTIONS_MENU[i] << endl;
        }

        cout << "Respuesta: ";
        cin >> option;
        char temp;
        switch (option) {
            case 1:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myOrthogonalList.insertRowAtStart(temp);
                break;
            case 2:
                myOrthogonalList.traverseList();
                break;
            case 3:
                cout << "Que elemento desea añadir(char)\nRespuesta: ";
                cin >> temp;
                myOrthogonalList.insertColumnAtEnd(temp);
                break;
            case 4:
                myOrthogonalList.deleteLastRow();
                break;
            case 5:
                myOrthogonalList.deleteFirstColumn();
                break;
            case 6:
                return;
            default:
                cout << "Opcion invalida";
        }
    }
}