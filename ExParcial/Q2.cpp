#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    // float notas[5] = {12.5f, 17.0f, 10.0f, 15.5f, 8.5f};
    float notas[5] = {12.5, 17.0, 10.0, 15.5, 8.5};
    float suma = 0.0f;
    float menor = notas[0];
    int aprobados = 0;

    for (int i = 0; i < 5; i++) {
        suma += notas[i];

        if (notas[i] < menor) {
            menor = notas[i];
        }

        if (notas[i] >= 11.0f) {
            aprobados++;
        }
    }

    float promedio = suma / 5;

    cout << fixed << setprecision(2);
    cout << "Promedio: " << promedio << endl;
    cout << "Nota menor: " << menor << endl;
    cout << "Aprobados: " << aprobados << endl;

    system("pause"); // Pausa de Windows
    return 0;
}
