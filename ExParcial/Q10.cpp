#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Producto {
    char nombre[30];
    char categoria[20];
    int unidades;
} Producto;

int main() {
    Producto productos[3] = {
        {"Cafe americano", "Bebida", 0},
        {"Sandwich mixto", "Comida", 0},
        {"Jugo natural", "Bebida", 0}
    };

    int total = 0;
    int indiceMayor = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Ingrese unidades vendidas de " << productos[i].nombre << ": ";
        cin >> productos[i].unidades;

        while (productos[i].unidades < 0) {
            cout << "Error. Ingrese unidades mayores o iguales a 0: ";
            cin >> productos[i].unidades;
        }

        total += productos[i].unidades;

        if (productos[i].unidades > productos[indiceMayor].unidades) {
            indiceMayor = i;
        }
    }

    cout << "=== REPORTE DE VENTAS ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << productos[i].nombre
             << " - " << productos[i].categoria
             << " : " << productos[i].unidades << " unidades" << endl;
    }

    cout << "PRODUCTO MAS VENDIDO: " << productos[indiceMayor].nombre
         << " con " << productos[indiceMayor].unidades << " unidades" << endl;
    cout << "Total vendido: " << total << " unidades" << endl;

    system("pause"); // Pausa de Windows
    return 0;
}
