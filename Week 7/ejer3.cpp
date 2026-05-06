
#include <iostream>
#include <cstring>
#include <cstdlib> //system("pause") es parte de la biblioteca cstdlib, que se utiliza para ejecutar comandos del sistema operativo desde el programa. En este caso, se usa para pausar la ejecución del programa hasta que el usuario presione una tecla.
using namespace std;

int main() {

    float precios[6] = {25.90, 49.50, 15.0, 32.80, 60.0, 18.40};

    // Definir una variabe de tipo puntero para almacenar la direccion de la nota menor
    float *p = precios; // p apunta al primer elemento del arreglo precios, es decir, p = &precios[0]
    float mayor = *(p + 0); // mayor se inicializa con el valor del primer elemento del arreglo precios, es decir, mayor = precios[0]
    
    // Recorro el vector usando PUNTEROS y NO VALOR
    for (int i=0; i <6; i++) {
        cout << "Precio [" << i << "]: " << *(p + i) << endl; // *(p + i) es lo mismo que precios[i], pero usando aritmetica de punteros
    
    // Hallemos el MAXIMO VALOR del arreglo usando punteros
        if (*(p + i) > mayor) {
            mayor = *(p + i); // si el precio actual es mayor que el precio mayor registrado, entonces actualizo el precio mayor con el precio actual
        }
    }

    cout << "Precio Mayor: " << mayor << endl;

    system("pause");
    return 0;

}