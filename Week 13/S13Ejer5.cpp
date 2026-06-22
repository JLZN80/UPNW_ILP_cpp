#include <iostream>
#include <string>
using namespace std;

//CREANDO LA CLASE ABSTRACTA... (ES TM+AMBIEN UNA CLASE PADRE)
class clsEstadio {
    
    protected:
        // NO  TIENE ATRIBUTOS CREADOS

    public:
        // TIENE UN METODO INCOMPLETO
        virtual void DescribirEstadio() = 0;
        virtual void PintarEstadio() = 0;
        virtual void CapacidadEstadio() = 0;
};

// CREANDO LAS CLASES DERIVADAS...
class clsEstadioGrupo : public clsEstadio {

    public:
        // LOS HIZO ACTIVAN OVERRIDE (Sobrecarga del Metodo)
        void DescribirEstadio() override {
            cout << "El estadio de MIAMI alojara los partidos de Grupos del Mundial 2026." << endl;
        }
};

class clsEstadioFinal : public clsEstadio {

    public:
        // LOS HIZO ACTIVAN OVERRIDE (Sobrecarga del Metodo)
        void DescribirEstadio() override {
            cout << "El estadio de AZTECA alojara la Final del Mundial 2026." << endl;
        }
};


int main() {

    clsEstadio* E1 = new clsEstadioGrupo; 
    clsEstadio* E2 = new clsEstadioFinal; 

    E1->DescribirEstadio();
    E2->DescribirEstadio();
    
    system("pause");
    return 0;
}