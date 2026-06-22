#include <iostream>
#include <string>
using namespace std;

//CREANDO LA CLASE BASE..
class clsEmpleado {
    
    protected:
        int IDEmpleado;
        string NomEmpleado;
    
    public:
        virtual double CalcularSalarioAnual() {
            // Codigo del Metodo...
        }
};

// CREANDO UNA CLASE DERIVADA...
class clsGerente : protected clsEmpleado {

    private:
        string NomDpto;
        
    public:
        double CalcularSalarioAnual() override {
            // Codigo del Metodo...
        }
};

int main() {

    clsEmpleado* oEmp;
    clsGerente* oGer;

    // oEmp.CalcularSalarioAnual(); // SI SABE A QUIEN EJECUTAR
    
    // oGer.CalcularSalarioAnual(); // TENGO LA DUDA DE CUAL EJECUATR?

    oEmp -> CalcularSalarioAnual(); // SI SABE A QUIEN EJECUTAR (Invoca al Metodo de la Clase EMPLEADO)
    oGer -> CalcularSalarioAnual(); // SI SABE A QUIEN EJECUTAR (Invoca al Metodo de la Clase GERENTE)

}