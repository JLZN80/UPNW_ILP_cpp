#include <iostream>
#include <string>
using namespace std;

// Una ESTRUCTURA
struct Producto {
    string nombre;
    double precio;
};

// Una CLASE:
class Producto {

    // LOS ATRIBUTOS - LAS VARIABLES...
    public: // peivate: // El alcance que seo darle a las variables y funciones de la clase
        string nombre;
        double precio;

    // LOS METODOS - LAS FUNCIONES...
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
    }

};