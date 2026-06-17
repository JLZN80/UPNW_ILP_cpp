#include <iostream>
#include <string>
using namespace std;

class clsMascota {
    
    // SECCION DE ATRIBUTOS
    public: 
        string Nombre;
        string Tipo;

    // SECCION DE METODOS
        void PresentarMascota() {
            cout << "Hola, soy " << Nombre << " y soy un(a) " << Tipo << "," << endl;
        }
}; 

int main() {

    // Darle Vida a la Clase ++> INSTANCIAR LA CLASE
    clsMascota oMascota;

    // Llenar los Valores que se necesitan para la Clase
    oMascota.Nombre = "Firulais";
    oMascota.Tipo = "Perro";

    // Llamar al método para presentar la mascota
    oMascota.PresentarMascota()

    system("pause");
    return 0;
}