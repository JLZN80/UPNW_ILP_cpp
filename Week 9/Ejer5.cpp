/*
=======================================================================================================
EJERCICIO A5 — Sistema de Prestamos Biblioteca UPNW
Biblioteca · Catalogar libros · Prestar · Devolver
=======================================================================================================
La biblioteca de la UPNW necesita gestionar su catalogo de libros con una lista enlazada. Cada libro tiene: 
isbn, titulo, autor y estado (disponible o prestado con nombre del prestatario). Implementar: agregarLibro(), 
prestarLibro(isbn, usuario) que valida disponibilidad, devolverLibro(isbn) e imprimirCatalogo().

*/

#include <iostream>
#include <string>
using namespace std;

struct Libro {
    int    isbn;
    string titulo;
    string autor;
    bool   prestado;
    string prestatario;
    Libro* siguiente;
};

Libro* agregar(Libro* h, int isbn, string titulo, string autor) {
    Libro* n = new Libro;
    n -> isbn = isbn; 
    n -> titulo = titulo; 
    n -> autor = autor;
    n -> prestado = false; 
    n -> prestatario = ""; 
    n -> siguiente = nullptr;
    if (!h) return n;
    Libro* t = h;
    while (t->siguiente) t = t->siguiente;
    t->siguiente = n;
    return h;
}

bool prestar(Libro* h, int isbn, string usuario) {
    while (h != nullptr) {
        if (h->isbn == isbn) {
            if (h->prestado) {
                cout << "'" << h->titulo << "' ya esta prestado a "
                     << h->prestatario << endl;
                return false;
            }
            h->prestado = true;
            h->prestatario = usuario;
            cout << "Prestamo exitoso: '" << h->titulo
                 << "' a " << usuario << endl;
            return true;
        }
        h = h->siguiente;
    }
    cout << "ISBN " << isbn << " no encontrado." << endl;
    return false;
}

bool devolver(Libro* h, int isbn) {
    while (h != nullptr) {
        if (h->isbn == isbn) {
            if (!h->prestado) {
                cout << "El libro no estaba prestado." << endl;
                return false;
            }
            cout << "Devolucion: '" << h->titulo
                 << "' de " << h->prestatario << endl;
            h->prestado = false;
            h->prestatario = "";
            return true;
        }
        h = h->siguiente;
    }
    return false;
}

void imprimirCatalogo(Libro* h) {
    cout << "=== CATALOGO BIBLIOTECA UPNW ===" << endl;
    while (h != nullptr) {
        cout << "ISBN:" << h->isbn << " | " << h->titulo
             << " de " << h->autor;
        if (h->prestado) cout << " [PRESTADO a " << h->prestatario << "]";
        else             cout << " [DISPONIBLE]";
        cout << endl;
        h = h->siguiente;
    }
}

void liberarLista(Libro* h) {
    while(h){ Libro* t=h->siguiente; delete h; h=t; }
}

int main() {
    Libro* catalogo = nullptr;

    catalogo = agregar(catalogo,9781,"Cien anos de soledad","G. Garcia Marquez");
    catalogo = agregar(catalogo,9782,"El Quijote",          "M. de Cervantes");
    catalogo = agregar(catalogo,9783,"Rayuela",             "J. Cortazar");

    imprimirCatalogo(catalogo);

    cout << "\n--- Prestamos ---" << endl;

    prestar(catalogo, 9781, "Carlos Quispe");
    prestar(catalogo, 9781, "Maria Garcia");  // ya prestado

    imprimirCatalogo(catalogo);

    cout << "\n--- Devolucion ---" << endl;

    devolver(catalogo, 9781);

    imprimirCatalogo(catalogo);

    liberarLista(catalogo);

    cin.get();

    return 0;
}
