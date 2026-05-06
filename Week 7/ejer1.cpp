
#include <iostream>
#include <cstring>
#include <cstdlib> //system("pause") es parte de la biblioteca cstdlib, que se utiliza para ejecutar comandos del sistema operativo desde el programa. En este caso, se usa para pausar la ejecución del programa hasta que el usuario presione una tecla.
using namespace std;

// Definicion de la Estructura Libro
typedef struct 
{
    char TituloLibro[40];
    int CantPaginas;
    float Precio;
    bool TieneDscto;
    char isbn[15];
    int stock;
} Libro; // similar al INT, FLOAT, DOUBLE, BOOL, etc. es un nuevo tipo de dato definido por el usuario, que se puede usar para declarar variables de tipo Libro.

// Iniciaizar un Libro de Ejemplo
int main() {

    // Informacion del Libro (Ingresada por el Usuario -> cin / Como valores predeterminados -> Asignar valores a las variables)
    char titulo[40] = "El Quijote";
    int paginas = 863;
    float precio = 19.99;
    bool tieneDscto = true;
    char isbn[15] = "978311484100";
    int stock = 50;

    // Debo crear una variable de tipo Libro para almacenar la informacion del libro
    Libro varLibro;

    // Asignar los valores a la variable de tipo Libro
    strcpy(varLibro.TituloLibro, titulo);
    varLibro.CantPaginas = paginas;
    varLibro.Precio = precio;
    varLibro.TieneDscto = tieneDscto;
    strcpy(varLibro.isbn, isbn);
    varLibro.stock = stock;

    // Visualizar la informacion del libro
    cout << "Titulo del Libro: " << varLibro.TituloLibro << endl;
    cout << "Cantidad de Paginas: " << varLibro.CantPaginas << endl; 
    cout << "Precio: $" << varLibro.Precio << endl;
    cout << "Tiene Descuento: " << (varLibro.TieneDscto ? "Si" : "No") << endl;
    cout << "ISBN: " << varLibro.isbn << endl;
    cout << "Stock Disponible: " << varLibro.stock << endl;

    system("pause");
    return 0;

}

