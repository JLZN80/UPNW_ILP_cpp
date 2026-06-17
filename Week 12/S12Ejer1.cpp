#include <iostream>
#include <string>
using namespace std;

class clsMascota {
    
    // SECCION DE ATRIBUTOS
    public: 
        string Nombre;
        string Tipo;
        string Color;

    // SECCION DE METODOS
        void PresentarMascota() {
            cout << "Hola, soy " << Nombre << " y soy un(a) " << Tipo << " de color " << Color << "." << endl;
        }
}; 

int main() {

    // Darle Vida a la Clase ++> INSTANCIAR LA CLASE
    clsMascota oMascota;

    // Llenar los Valores que se necesitan para la Clase
    oMascota.Nombre = "Firulais";
    oMascota.Tipo = "Perro";
    oMascota.Color = "Marrón";
    oMascota.PresentarMascota();

    oMascota.Nombre = "Michi";
    oMascota.Tipo = "Gato";
    oMascota.Color = "Blanco";
    oMascota.PresentarMascota();

    oMascota.Nombre = "Juancho";
    oMascota.Tipo = "Lagarto";
    oMascota.Color = "Verde";
    oMascota.PresentarMascota();

    system("pause");
    return 0;
}