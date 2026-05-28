/*
=======================================================================================================
EJERCICIO A3 — Cola de Respawn en Videojuego
Videojuego · Cola FIFO · encolar y desencolar jugadores
=======================================================================================================
En un videojuego multijugador tipo 'battle royale', los jugadores que son eliminados se unen a una cola 
de RESPAWN (reaparicion). El primero en entrar es el primero en reaparecer (FIFO). Implementar: 
encolarJugador() al final, desencolarJugador() del inicio (libera el nodo), e imprimirCola().

*/

#include <iostream>
#include <string>
using namespace std;

struct Jugador {
    int    id;
    string nombre;
    int    vidas;
    Jugador* siguiente;
};

// Encolar: el nuevo jugador va al FINAL
Jugador* encolar(Jugador* h, int id, string nom, int vidas) {
    Jugador* n = new Jugador;
    n -> id = id; 
    n -> nombre = nom; 
    n -> vidas = vidas; 
    n -> siguiente = nullptr;
    if (!h) return n;
    Jugador* t=h;
    while(t->siguiente) t = t -> siguiente;
    t -> siguiente = n;
    return h;
}

// Desencolar: saca al primero (FIFO) y lo elimina
Jugador* desencolar(Jugador* h) {
    if (!h) { cout << "Cola vacia." << endl; return nullptr; }
    cout << "[RESPAWN] " << h->nombre << " vuelve al juego!" << endl;
    Jugador* nuevo_head = h->siguiente;
    delete h;
    return nuevo_head;
}

void imprimirCola(Jugador* h) {
    if (!h) { cout << "Cola vacia." << endl; return; }
    cout << "=== COLA RESPAWN ===" << endl;
    int pos=1;
    while (h != nullptr) {
        cout << pos << ". " << h->nombre
             << " (Vidas: " << h->vidas << ")" << endl;
        h=h->siguiente; pos++;
    }
}

void liberarCola(Jugador* h) {
    while(h){ Jugador* t=h->siguiente; delete h; h=t; }
}

int main() {
    Jugador* cola = nullptr;
    cola = encolar(cola, 1, "DragonSlayer99", 3);
    cola = encolar(cola, 2, "NightWolf_Lima", 3);
    cola = encolar(cola, 3, "ShadowFox",      2);

    imprimirCola(cola);

    cout << "\n--- Procesando respawn ---" << endl;

    cola = desencolar(cola);
    cola = desencolar(cola);

    imprimirCola(cola);

    liberarCola(cola);

    cin.get();
    
    return 0;
}
