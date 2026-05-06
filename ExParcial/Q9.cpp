#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    float asistencia[5] = {80.0f, 72.5f, 95.0f, 60.0f, 88.5f};
    float *p = asistencia;
    float suma = 0.0f;
    int cumplen = 0;

    for (int i = 0; i < 5; i++) {
        suma += *(p + i);

        if (*(p + i) >= 70.0f) {
            cumplen++;
        }
    }

    float promedio = suma / 5;

    cout << fixed << setprecision(2);
    cout << "Promedio de asistencia: " << promedio << "%" << endl;
    cout << "Alumnos que cumplen asistencia minima: " << cumplen << endl;

    system("pause"); // Pausa de Windows
    return 0;
}
