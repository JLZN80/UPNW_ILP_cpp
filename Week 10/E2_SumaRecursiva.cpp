#include <iostream>
using namespace std;


//Funcion Recursiva para calcular la suma de los numeros del 1 al N
double SumaRecursiva(int n) {

    // Caso Base: Cuando la invocacion debe PARAR
    if (n == 1) {
        return 1; // Detiene la recursividad
    }

    // Caso Recursivo: Cuando la invocacion debe CONTINUAR
    else {
        return (n + SumaRecursiva(n - 1));
    }
}


// Funcion Principal de la Suma Recursiva
int main (){

    int n;

    cout << "Ingrese un numero para calcular su suma recursiva. Debe ser Posito y Mayor de 0: ";
    cin >> n;

    if (n <= 0) {
        cout << "El numero debe ser positivo y mayor a 0." << endl;
    }
    else {
        // Usar una funcion recursiva para calcular la suma de los numeros del 1 al N
        cout << "La Suma desde 1 hasta " << n << " es: " << SumaRecursiva(n) << endl; 
    }

    system("pause");
    return 0;
}