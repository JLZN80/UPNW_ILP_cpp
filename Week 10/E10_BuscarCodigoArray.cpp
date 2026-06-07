// Codigo que busca un elemento en un Array de una lista de una manera recursiva

#include <iostream>
using namespace std;


// Codigo de la Funcion Recursiva para buscar un elemento en un Array
bool buscarCodigoArray(int ANumeros[], int size, int codigo) {

    // Caso Base 1: Se recorrio todo el arreglo y no se encontro el codigo, retornar false
    if (size == 0) {
        return false;
    }
    
    // Caso Base 2: Si el ultimo elemento del arreglo es igual al codigo buscado, retornar true
    if (ANumeros[size - 1] == codigo) {
        return true;
    }

    // Case ecursivo: Comparar el ultimo elemento con el codigo buscado, si es igual, retornar true, sino, seguir buscando en el resto del arreglo
    return buscarCodigoArray(ANumeros, size - 1, codigo);
}


// Codigo Principal del Programa, quien se encargara de cargar el arreglo y mostrar el resultado
int main() {

    int Catalogo[7];
    int codigo;

    cout << "Ingrese 7 Codigos de Productos (Numeros Enteros): " << endl;

    // Cargando el Catalogo con 7 codigos de productos
    for (int i = 0; i < 7; i++) {
        cout << "Codigo " << i + 1 << " : ";
        cin >> Catalogo[i];
    }

    // El usuario me ingresa el codigo a Buscar:
    cout << "Ingrese el Codigo a Buscar: ";
    cin >> codigo;

    //Informe si el Codigo Ingresado existe o no en el Catalogo usando la funcion recursiva
    if (buscarCodigoArray(Catalogo, 7, codigo)) {
        cout << "El Codigo " << codigo << " existe en el Catalogo." << endl;
    }
    else {
        cout << "El Codigo " << codigo << " NO existe en el Catalogo." << endl;
    }

    system("pause");
    return 0;

}