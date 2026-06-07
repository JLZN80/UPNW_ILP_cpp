#include <iostream>
using namespace std;

int potencia(int base, int exponente) {
    // Caso base: cualquier numero elevado a 0 es 1
    if (exponente == 0) {
        return 1;
    }

    // Caso recursivo: base^exponente = base * base^(exponente - 1)
    return base * potencia(base, exponente - 1);
}

int main() {
    int base, exponente;

    cout << "Ingrese la base: ";
    cin >> base;

    cout << "Ingrese el exponente no negativo: ";
    cin >> exponente;

    if (exponente < 0) {
        cout << "Este ejercicio solo acepta exponentes no negativos." << endl;
    } else {
        cout << base << " elevado a " << exponente << " es: ";
        cout << potencia(base, exponente) << endl;
    }

    system("pause");
    return 0;
}