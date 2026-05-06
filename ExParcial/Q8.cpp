#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Equipo {
    char nombre[30];
    char tema[30];
    int puntaje;
} Equipo;

int main() {
    Equipo equipos[3] = {
        {"Equipo Alfa", "Aplicacion Web", 0},
        {"Equipo Beta", "Base de Datos", 0},
        {"Equipo Gamma", "IoT Basico", 0}
    };

    int indiceGanador = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Ingrese puntaje de " << equipos[i].nombre << " (0 a 100): ";
        cin >> equipos[i].puntaje;

        while (equipos[i].puntaje < 0 || equipos[i].puntaje > 100) {
            cout << "Error. Ingrese puntaje entre 0 y 100: ";
            cin >> equipos[i].puntaje;
        }

        if (equipos[i].puntaje > equipos[indiceGanador].puntaje) {
            indiceGanador = i;
        }
    }

    cout << "=== RESULTADO FERIA DE PROYECTOS ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << equipos[i].nombre
             << " - " << equipos[i].tema
             << " : " << equipos[i].puntaje << " puntos" << endl;
    }

    cout << "GANADOR: " << equipos[indiceGanador].nombre
         << " con " << equipos[indiceGanador].puntaje << " puntos" << endl;

    system("pause"); // Pausa de Windows
    return 0;
}

