#include <iostream>
using namespace std;

int sumarArreglo(int notas[], int posicion, int tamano) {
    // Caso base: si la posicion llega al tamaño, ya no hay mas elementos
    if (posicion == tamano) {
        return 0;
    }

    // Caso recursivo: elemento actual + suma del resto del arreglo
    return notas[posicion] + sumarArreglo(notas, posicion + 1, tamano);
}

int main() {
    int notas[5];

    cout << "Ingrese 5 notas enteras:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    cout << "La suma total es: " << sumarArreglo(notas, 0, 5) << endl;

    system("pause");
    return 0;
}