/*
# Ejercicio 4 — Videojuego: jugador y puntaje

## Contexto
Un videojuego universitario necesita registrar el nickname de un jugador, su nivel y su puntaje acumulado.

## Qué se busca
Crea una clase Jugador con constructor, getters y un método subirNivel() que aumente el nivel en 1. Además, crea un método sumarPuntos(int puntos). Muestra el estado antes y después de actualizar.

## Explicación
Aquí el alumno practica la idea de que el objeto modifica su propio estado mediante métodos. Ya no se cambia el nivel o puntaje desde afuera de forma desordenada.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
    string nickname;
    int nivel;
    int puntaje;

public:
    Jugador(const string& n, int niv, int p) : nickname(n), nivel(niv), puntaje(p) {}

    string getNickname() const { return nickname; }
    int getNivel() const { return nivel; }
    int getPuntaje() const { return puntaje; }

    void subirNivel() { nivel++; }
    void sumarPuntos(int puntosGanados) {
        if (puntosGanados > 0) puntaje += puntosGanados;
    }
};

int main() {
    Jugador j1("NeoPlayer", 3, 1200);
    cout << "Antes:" << endl;
    cout << j1.getNickname() << " | Nivel: " << j1.getNivel() << " | Puntaje: " << j1.getPuntaje() << endl;
    j1.subirNivel();
    j1.sumarPuntos(350);
    cout << "Despues:" << endl;
    cout << j1.getNickname() << " | Nivel: " << j1.getNivel() << " | Puntaje: " << j1.getPuntaje() << endl;
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Métodos que modifican el estado
- Constructores
- Getters
*/

