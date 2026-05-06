#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    float precios[6] = {25.90f, 49.50f, 15.00f, 32.80f, 60.00f, 18.40f};
    float *p = precios;
    float mayor = *p; // primer precio

    cout << fixed << setprecision(2);

    for (int i = 0; i < 6; i++) {
        cout << "Precio[" << i << "]: S/ " << *(p + i) << endl;

        if (*(p + i) > mayor) {
            mayor = *(p + i);
        }
    }

    cout << "Precio mayor: S/ " << mayor << endl;

    system("pause"); // Pausa de Windows
    return 0;
}

