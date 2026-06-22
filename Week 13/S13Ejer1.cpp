#include <iostream>
#include <string>
using namespace std;

// DEFINICION DE NUESTRA CLASE BASE (CLASE PADRE)...
class clsEmpleado {

    //private:
    protected:
        
        string NomEmpleado;
        int IDEmpleado;
        double MtoSalarioMes;

        double CalcularSalarioAnual() {
            double SalarioAnual;

            int NroMesesxAnio = 12;
            int NroGratificaciones = 2;

            SalarioAnual = (NroMesesxAnio + NroGratificaciones) * MtoSalarioMes;
            return(SalarioAnual);
        }

    public:

        // *********************************************************************************
        // CONSTRUCTOR DE LA CLASE : Porque el Nombre del Metodo = Nombre de la Clase
        // *********************************************************************************
        clsEmpleado(string Nom, int cod, double sueldom) {
            NomEmpleado = Nom;
            IDEmpleado = cod;
            MtoSalarioMes = sueldom;
        }
        // *********************************************************************************

        void MostrarDatos() {

            cout << "REPORTE MAESTRO DE EMPLEADOS" << endl;
            cout << "============================" << endl;
            cout << "CODIGO EMPLEADO: " << IDEmpleado << endl;
            cout << "NOMBRE EMPLEADO: " << NomEmpleado << endl;
            cout << "HABER EMPLEADO: S/. " << MtoSalarioMes << endl;
            cout << "COMPENSACION ANUAL: S/. " << CalcularSalarioAnual() << endl << endl;
        }
};

// DEFINICION DE LA 1ra CLASE DERIVADA (CLASE HIJA)...
class clsGerente : public clsEmpleado {

    private:
        string NombreDpto;

    public:
        // *********************************************************************************
        // CONSTRUCTOR DE LA CLASE : Porque el Nombre del Metodo = Nombre de la Clase
        // *********************************************************************************
        clsGerente(string Nom, int cod, double sueldom) {
            NomEmpleado = Nom;
            IDEmpleado = cod;
            MtoSalarioMes = sueldom;
        }
        // *********************************************************************************
        void GestionarEquipo() {
            // Cuerpo del Metodo (Funcion)...
        }
};

// DEFINICION DE LA 2da CLASE DERIVADA (CLASE HIJA)...
class clsDesarrollador : public clsEmpleado {
    
    private:
        string LeguajeProgram;

    public:
        void EscribirCodigo() {
            // Cuerpo del Metodo (Funcion)...
        }
};


int main() {

    clsEmpleado ObjE1("Jorge", 1001, 1500);
    clsEmpleado ObjE2("Carlos", 4001, 3500);
    
    ObjE1.MostrarDatos();
    ObjE2.MostrarDatos();

    clsGerente oGerente;
    clsDesarrollador oDesarrollador;

    oGerente.GestionarEquipo();
    oGerente.MostrarDatos();

    oDesarrollador.EscribirCodigo();
    oDesarrollador.MostrarDatos();

    system("pause");
    return 0;

}