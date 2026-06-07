#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Caso base 1
    if (n == 0) {
        return 0;
    }

    // Caso base 2
    if (n == 1) {
        return 1;
    }

    // Caso recursivo: Fibonacci(n) = Fibonacci(n - 1) + Fibonacci(n - 2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Ingrese la posicion Fibonacci que desea calcular: ";
    cin >> n;

    if (n < 0) {
        cout << "La posicion no puede ser negativa." << endl;
    } else {
        cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    }

    system("pause");
    return 0;
}