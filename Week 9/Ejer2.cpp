/*
=======================================================================================================
EJERCICIO A2 — Registro de Alumnos IS6041 UPNW
Universidad · Lista de alumnos · busqueda · estado aprobado
=======================================================================================================
El sistema de Canvas UPNW necesita una lista enlazada para gestionar los alumnos del curso IS6041. 
Cada alumno tiene: codigo, nombre y promedio. Implementar: agregar alumnos al final, imprimir la lista
mostrando si estan APROBADOS (promedio>=11) o DESAPROBADOS, y buscar un alumno por codigo.

*/

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

struct Alumno {
    int    codigo;
    string nombre;
    float  promedio;

    Alumno* NextNodo;
};

Alumno* agregar(Alumno* h, int cod, string nom, float prom) {
    Alumno* n = new Alumno;

    n->codigo = cod; 
    n->nombre = nom; 
    n->promedio = prom;
    n->NextNodo = nullptr;

    if (!h) return n;
    Alumno* t=h;
    while(t->NextNodo) t=t->NextNodo;
    t->NextNodo = n;
    return h;
}

Alumno* buscar(Alumno* h, int cod) {
    while (h != nullptr) {
        if (h->codigo == cod) return h;
        h = h->NextNodo;
    }
    return nullptr;
}

void imprimirLista(Alumno* h) {
    cout << "=== ALUMNOS IS6041 ===" << endl;
    while (h != nullptr) {
        string estado = (h->promedio >= 11) ? "APROBADO" : "DESAPROBADO";
        cout << "[" << h->codigo << "] "
             << h->nombre << " - Prom: "
             << h->promedio << " - " << estado << endl;
        h = h->NextNodo;
    }
}

void liberarLista(Alumno* h) {
    while (h != nullptr) {
        Alumno* temp = h;
        h = h->NextNodo;
        delete temp;
    }
}   

int main() {
    Alumno* lista = nullptr;
    lista = agregar(lista, 20231001, "Carlos Quispe", 15.5);
    lista = agregar(lista, 20231002, "Maria Garcia", 17.2);
    lista = agregar(lista, 20231003, "Luis Torres", 9.8);
    lista = agregar(lista, 20231004, "Ana Flores", 13.0);

    imprimirLista(lista);

    int cod;

    cout << "\nBuscar por codigo: "; cin >> cod;
    Alumno* enc = buscar(lista, cod);
    if (enc) cout << "Encontrado: " << enc->nombre << " - Prom: " << enc->promedio << endl;
    else     cout << "Alumno no encontrado." << endl;
    
    cin.get();

    //liberarLista(lista);
    
    cin.get();
    
    return 0;
}
