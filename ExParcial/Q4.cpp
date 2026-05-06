#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    char nombre[30];
    char apellido[30];
    char completo[70];

    strcpy(nombre, "Maria");
    strcpy(apellido, "Lopez");

    strcpy(completo, nombre);
    strcat(completo, " ");
    strcat(completo, apellido);

    cout << "Nombre completo: " << completo << endl;
    cout << "Longitud: " << strlen(completo) << " caracteres" << endl;

    system("pause"); // Pausa de Windows
    return 0;
}
