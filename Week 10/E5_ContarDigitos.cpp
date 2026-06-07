// Programa que usando recursividad me ayuda a contar los digitos que tiene un codigo numerico

#include <iostream>
using namespace std;


// Estructura de la Funcion Recursiva para contar los digitos de un numero
int contarDigitos(int numero) {

    // Caso BASE: La recursividad se detiene
    if (numero < 10) {
        return 1;
    }

    // Caso RECURSIVO
    return (1 + contarDigitos(numero / 10));
}

// Estructura de la Funcion MAIN
int main() {

    int numero;

    cout << "Ingresa un numero/codigo para contar sus digitos. No puede ser negativo: ";
    cin >> numero;

    if (numero <= 0) {
        cout << "El numero no puede ser negativo." << endl;
    }
    else {
        cout << "El Numero ingresado tiene " << contarDigitos(numero) << " digitos." << endl;
    }

    system("pause");
    return 0;

}