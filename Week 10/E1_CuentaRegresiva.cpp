// COntador Regresivo que empiece en N y termine en 0, usando recursividad

#include <iostream>
using namespace std;

// FUncion Recurisiva que se encargara de imprimir el numero y luego invocar a la siguiente iteracion
void CuentaRegresiva(int n){

    // Caso Base: Cuando La invocacion debe PARAR
    if (n == 0) {
        return; // Detiene la recursividad
    }
    
    // Mostrar el numero actual
    cout << n << " ";

    // Caso Recursivo: Cuando la invocacion debe CONTINUAR
    CuentaRegresiva(n - 1);

}

// Estructura de la Funcion princial (Quien invocara a la Recursividad)
int main () {
    int n;

    cout << "Ingrese un numero para iniciar la cuenta regresiva (Positivo y > 0): ";
    cin >> n;

    if (n <= 0) {
        cout << "El numero debe ser positivo y mayor a 0." << endl;
    }
    else {
        cout << "Cuenta Regresiva: ";
        CuentaRegresiva(n);
        cout << endl; 
    }

    system("pause");
    return 0;

}