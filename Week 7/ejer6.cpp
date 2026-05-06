
#include <iostream>
#include <cstring>
#include <cstdlib> //system("pause") es parte de la biblioteca cstdlib, que se utiliza para ejecutar comandos del sistema operativo desde el programa. En este caso, se usa para pausar la ejecución del programa hasta que el usuario presione una tecla.
using namespace std;

typedef struct {

    char estudiante[30];
    char libro[40];
    int DiasPrestamo;

} Prestamo;

int main() {

    // declaro un arreglo de tipo Prestamo para almacenar la informacion de 3 prestamos de libros
    Prestamo ArrayPrestamo[3] = {
        {"Juan Perez", "El Quijote", 15},
        {"Maria Lopez", "Cien Años de Soledad", 30},
        {"Carlos Sanchez", "La Sombra del Viento", 20}
    };

    // Recorro el arreglo de prestamos para mostrar su contenido

    cout << "REPORTE DE PRESTAMOS DE LIBROS" << endl;

    for (int i=0; i < 3; i++) {
        cout << "Estudiante: " << ArrayPrestamo[i].estudiante << endl;
        cout << "Libro: " << ArrayPrestamo[i].libro << endl;
        cout << "Días de préstamo: " << ArrayPrestamo[i].DiasPrestamo << endl;
        cout << "-----------------------------" << endl;
    }

    system("pause");
    return 0;

}
