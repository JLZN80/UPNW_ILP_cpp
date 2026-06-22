#include <iostream>
#include <string>
using namespace std;

class clsEmpleado {

    private:
        
        string NomEmpleado;
        int IDEmpleado;
        double MtoSalarioMes;
        char EstadoCivil;

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

class clsGerente {

    private:
        
        string NomEmpleado;
        int IDEmpleado;
        double MtoSalarioMes;
        char EstadoCivil;

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
        clsGerente(string Nom, int cod, double sueldom) {
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

class clsDesarrollador {

    private:
        
        string NomEmpleado;
        int IDEmpleado;
        double MtoSalarioMes;
        //char EstadoCivil;

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
        clsDesarrollador(string Nom, int cod, double sueldom) {
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

int main() {

    clsEmpleado ObjE1("Jorge", 1001, 1500);
    clsEmpleado ObjE2("Carlos", 4001, 3500);
    
    ObjE1.MostrarDatos();
    ObjE2.MostrarDatos();

    system("pause");
    return 0;

}