#include <iostream>
using namespace std;

int factorial(int n) {
    // Caso base: 0! y 1! valen 1
    if (n <= 1) {
        return 1;
    }

    // Caso recursivo: n! = n * (n - 1)!
    return n * factorial(n - 1);
}

int main() {
    int n;

    cout << "Ingrese un numero entero no negativo: ";
    cin >> n;

    if (n < 0) {
        cout << "No se puede calcular factorial de un numero negativo." << endl;
    } else {
        cout << n << "! = " << factorial(n) << endl;
    }

    system("pause");
    return 0;
}