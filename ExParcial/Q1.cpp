#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Libro {
    char titulo[40];
    int paginas;
    float precio;
    bool tieneDescuento;
    char codigo[15];
    int stock;
} Libro;

int main() {
    // a) C se considera principalmente imperativo/procedimental.
    // El programa se organiza como una secuencia de instrucciones, decisiones y ciclos.

    // b) Variables individuales para cada campo
    char titulo[40] = "Programacion Basica";
    int paginas = 250;
    float precio = 85.50f;       // decimal porque el precio puede tener centimos
    bool tieneDescuento = true;  // lógico: 1 = sí, 0 = no
    char codigo[15] = "LIB-2026-A1"; // texto porque contiene letras, guiones y números
    int stock = 18;

    // c) Struct inicializado
    Libro libro1 = {"Algoritmos en C++", 320, 92.90f, false, "ISBN-UPNW01", 12};

    cout << "Libro: " << libro1.titulo << endl;
    cout << "Precio: S/ " << libro1.precio << endl;
    cout << "Stock: " << libro1.stock << endl;
    
    system("pause"); // Pausa de Windows
    return 0;
    
}

