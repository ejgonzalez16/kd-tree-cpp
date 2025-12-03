#include <iostream>
#include "ArbolKD.h"
#include "NodoKD.h"

using namespace std;

void insertarNodo(ArbolKD<string>& arbolBinario);

int main() {
    int opc;
    ArbolKD<string> arbolKD;
    /*if (!arbolGeneral.esVacio()) {
        cout << "\nEl arbol no esta vacio\n";
    }*/
    do {
        std::cout << "Digite:\n1. insertar nodo\n2. eliminar nodo\n3. salir\n";
        cin >> opc;
        switch (opc) {
        case 1: insertarNodo(arbolKD); break;
        }
        system("pause");
        system("cls");
    } while (opc != 3);
}

void insertarNodo(ArbolKD<string>& arbolBinario) {
    float x,y;
    string texto;
    if (arbolBinario.esVacio()) {
        cout << "Digite x de la raiz del arbol: ";
        cin >> x;
        cout << "Digite y de la raiz del arbol: ";
        cin >> y;
        cout << "Digite el texto a insertar: ";
        cin >> texto;
    }
    else {
        cout << "Digite x a insertar: ";
        cin >> x;
        cout << "Digite y a insertar: ";
        cin >> y;
        cout << "Digite el texto a insertar: ";
        cin >> texto;
    }
    if (arbolBinario.insertar(x,y,texto)) {
        cout << "\nSe inserto el nodo\n";
    }
    else {
        cout << "\nNo se inserto el nodo\n";
    }
    cout << "digite el x, y a buscar: ";
    cin >> x >> y;
    NodoKD<string>* nodo = arbolBinario.buscar(x, y);
    cout << "Se encontró la fruta: " << nodo->getDato() << " con coordenadas: " << nodo->getX() << ", " << nodo->getY() << endl;
    cout << "\nPre-orden: ";
    arbolBinario.preOrden();
    cout << "\nIn-orden: ";
    arbolBinario.inOrden();
    cout << "\nPos-Orden: ";
    arbolBinario.posOrden();
    cout << "\nPor niveles: ";
    arbolBinario.nivelOrden();
    cout << "\n";
}