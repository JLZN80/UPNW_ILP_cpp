
#include <iostream>
#include <cstring>
#include <cstdlib> //system("pause") es parte de la biblioteca cstdlib, que se utiliza para ejecutar comandos del sistema operativo desde el programa. En este caso, se usa para pausar la ejecución del programa hasta que el usuario presione una tecla.
using namespace std;


int main() {

    char nombre[30];
    char apellido[30];
    char nombreCompleto[70];

    // asignar varibles usando funciones de C
    strcpy(nombre, "Maria");
    strcpy(apellido, "Lopez");

    // crear el nombre completo usando strcpy y strcat
    strcpy(nombreCompleto, nombre); // nombreCompleto = nombre
    strcat(nombreCompleto, " "); // nombreCompleto = nombreCompleto + " "
    strcat(nombreCompleto, apellido); // nombreCompleto = nombreCompleto + apellido
  
    cout << "Nombre Completo: " << nombreCompleto << endl;
    cout << "Longitud del Nombre Completo: " << strlen(nombreCompleto) << endl; // strlen(nombreCompleto) devuelve la longitud del string nombreCompleto, es decir, el numero de caracteres que tiene el string sin contar el caracter nulo '\0' que se agrega al final del string para indicar su fin.

    system("pause");
    return 0;

}