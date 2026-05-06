#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Prestamo {
    char estudiante[30];
    char libro[40];
    int dias;
} Prestamo;

int main() {
    Prestamo prestamos[3] = {
        {"Juan Perez", "Fundamentos de C++", 5},
        {"Ana Torres", "Algoritmos Basicos", 7},
        {"Luis Ramos", "Logica de Programacion", 3}
    };

    cout << "=== REPORTE DE PRESTAMOS ===" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << prestamos[i].estudiante
             << " - " << prestamos[i].libro
             << " : " << prestamos[i].dias << " dias" << endl;
    }

    system("pause"); // Pausa de Windows
    return 0;
}


