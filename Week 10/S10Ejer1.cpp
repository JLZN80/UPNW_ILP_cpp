#include <iostream>

int factorial_iterative(int n) {
    
    int result = 1;

    // Funcion de iteracion con un for desde 1 hasta N...
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

int main() {
    int n = 5; // Ejemplo de número para calcular su factorial
    int result = factorial_iterative(n);

    std::cout << "El factorial de " << n << " (USANDO ITERACION) es: " << result << std::endl;

    system("pause");

    return 0;


}


