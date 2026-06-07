// Cargar un arreglo con 6 valores enteros, luego mostrar el mayor valor del arreglo usando recursividad

#include <iostream>
using namespace std;


// Funcion Recursiva
int MayorValor (int ANumeros[], int size) {

    // Caso Base: Cuando el arreglo tiene un solo elemento, ese es el mayor
    if (size == 1) {
        return ANumeros[0];
    }

    // Caso Recursivo: Comparar el ultimo elemento con el mayor del resto del arreglo
    int mayorDelResto = MayorValor(ANumeros, size - 1);
    
    if (ANumeros[size - 1] > mayorDelResto) {
        return ANumeros[size - 1];
    }
    else {
        return mayorDelResto;
    }

}


// Funcion Main o principal del codigo, quien se encargara de cargar el arreglo y mostrar el resultado
int main() {

    int ANumeros[6];

    cout << "Ingresse 6 Numeros Enteros: " << endl;
    
    for (int i = 0; i < 6; i++) {
        cout << "Numero " << i + 1 << " : ";
        cin >> ANumeros[i];
    }

    cout << "El Mayor Valor del Arreglo es: " << MayorValor(ANumeros, 6) << endl;

    system("pause");
    return 0;
}