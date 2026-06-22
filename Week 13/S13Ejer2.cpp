#include <iostream>
#include <string>
using namespace std;

// CREANDO LA CLASE PADRE...
class clsPersona {
    
    protected:
        string Nombre;
        int Edad;

    public:    

};

// CRENADO LA CLASE HIJA...
class clsHincha : public clsPersona {

    private:
        string PaisFavorito;

    public:

        clsHincha(string n, int e, string pf) {
            Nombre = n;
            Edad = e;
            PaisFavorito = pf;
        }

        void MostrarDatos() {
            cout << "Nombre: " << Nombre << endl;
            cout << "Edad: " << Edad << endl;
            cout << "Pais Favorito: " << PaisFavorito << endl;
        }
};

// CREAR LA FUNCION PRINCIPAL (EXTERNA)

int main() {

    clsHincha oH1("Jorge", 45, "BRASIL");
    oH1.MostrarDatos();
    oH1.

    clsHincha oH2("Carlos", 35, "ARGENTINA");
    oH2.MostrarDatos();

    system("pause");
    return 0;
}