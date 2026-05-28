/*
=======================================================================================================
EJERCICIO A4 — Registro de Detenidos DIVINCRI
Policia · Agregar detenido · Liberar por DNI · Imprimir registro
=======================================================================================================
La DIVINCRI (Division de Investigacion Criminal de la Policia del Peru) mantiene un registro de detenidos 
en una lista enlazada. Cada detenido tiene: dni, nombre, cargo y numero de celda. Implementar:
agregarDetenido() al final, liberarDetenido() por DNI (elimina el nodo), e imprimirRegistro().

*/

#include <iostream>
#include <string>
using namespace std;

struct Detenido {
    int    dni;
    string nombre;
    string cargo;
    int    celda;
    Detenido* siguiente;
};

Detenido* agregar(Detenido* h, int dni, string nom,
                  string cargo, int celda) {
    Detenido* n = new Detenido;
    n -> dni = dni; 
    n -> nombre = nom; 
    n -> cargo = cargo;
    n -> celda = celda; 
    n -> siguiente = nullptr;
    if (!h) return n;
    Detenido* t=h;
    while(t->siguiente) t = t -> siguiente;
    t -> siguiente = n;
    return h;
}

// Libera (elimina) un detenido por su DNI
Detenido* liberar(Detenido* h, int dni) {
    if (!h) return nullptr;
    // Caso: es el primer nodo

    if (h->dni == dni) {
        cout << "LIBERADO: " << h->nombre << endl;
        Detenido* nuevo_head = h->siguiente;
        delete h;
        return nuevo_head;
    }
    // Buscar en el resto de la lista
    Detenido* cur = h;

    while (cur->siguiente && cur->siguiente->dni != dni)
        cur = cur->siguiente;

    if (cur->siguiente) {
        cout << "LIBERADO: " << cur->siguiente->nombre << endl;
        Detenido* temp = cur->siguiente->siguiente;
        delete cur->siguiente;
        cur->siguiente = temp;
    } else {
        cout << "DNI " << dni << " no encontrado." << endl;
    }
    return h;
}

void imprimirRegistro(Detenido* h) {
    cout << "=== REGISTRO DIVINCRI ===" << endl;
    while (h != nullptr) {
        cout << "DNI:" << h->dni << " | " << h->nombre
             << " | Cargo: " << h->cargo
             << " | Celda: " << h->celda << endl;
        h = h->siguiente;
    }
}

void liberarLista(Detenido* h) {
    while(h){ 
        Detenido* t = h -> siguiente; 
        delete h; 
        h = t; 
    }
}

int main() {
    Detenido* lista = nullptr;
   
    lista = agregar(lista, 47123456, "Luis Quispe",  "Robo agravado",  101);
    lista = agregar(lista, 87654321, "Ana Torres",   "Estafa bancaria",102);
    lista = agregar(lista, 12345678, "Pedro Gomez",  "Desorden publico",103);
   
    imprimirRegistro(lista);
   
    cout << "\n--- Libertad provisional ---" << endl;
    lista = liberar(lista, 87654321);
   
    imprimirRegistro(lista);
   
    liberarLista(lista);

    cin.get();
    
    return 0;
}
