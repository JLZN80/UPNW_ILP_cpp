#include <iostream>
using namespace std;

double factorial_recursive(double n) {
    
    // Case 1: Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Case 2: Recursive case
    else {
        return (n * factorial_recursive(n - 1));
    }
}

int main() {
    double n = 5; // Ejemplo de número para calcular su factorial
    double result = factorial_recursive(n);

    cout << "El factorial de " << n << " (USANDO RECURSIVIDAD) es: " << result << endl;

    system("pause");

    return 0;
}
