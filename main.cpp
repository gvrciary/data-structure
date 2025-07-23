#include "include/MenuManager.h"
#include <iostream>

using namespace std;

int main() {
    int option;

    while (true) {
        cout << " - - - Menu Principal - - -" << endl << endl;
        cout << "1) Linked List" << endl;
        cout << "2) Circular List" << endl;
        cout << "3) Doubly List" << endl;
        cout << "4) Doubly Circular List" << endl;
        cout << "5) Orthogonal Linked List" << endl;
        cout << "6) Salir" << endl;
        cout << "Respuesta: ";
        cin >> option;

        switch (option) {
            case 1:
                MenuManager::linkedListMenu();
                return 0;
            case 2:
                MenuManager::circularListMenu();
                return 0;
            case 3:
                MenuManager::doublyListMenu();
                return 0;
            case 4:
                MenuManager::doublyCircularLinkedMenu();
                return 0;
            case 5:
                MenuManager::orthogonalLinkedMenu();
                return 0;
            case 6:
                return 0;
            default:
                cout << "Opcion invalida";
        }
    }
}