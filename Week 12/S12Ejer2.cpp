#include <iostream>
#include <string>
using namespace std;

class clsEstudiante {
    private:
        string NombreAlumno;
        double N1, N2, N3;
    
        // 1er METODO: CALCULAR EL PROMEDIO PONDERADO DE LAS NOTAS
        double Promedio() {
            // double Prom = (N1 + N2 +N3) / 3.0;
            double Prom = (N1*.3 + N2*.3 + N3*.4);
            return (Prom);
        }

        
        string EstadoFinal() {
            // Si la Nora del Alumno es mayor o igual a 11, entonces el Alumno Aprobo, caso contrario Reprobo
            string Estado;

            if (Promedio() >= 11)
                Estado = "Alumno APROBADO";
            else
                Estado = "Alumno DESAPROBADO";

                return(Estado);
        }

    public:
        // CONSTRUCTOR de la Clase:
        clsEstudiante(string Nom, double not1, double not2, double not3) {
            NombreAlumno = Nom;
            N1 = not1;
            N2 = not2;
            N3 = not3;
        }

        void MostrarResultado() {

            cout << "REPORTE DE RESULTADOS POR ALUMNO: " << endl;
            cout << "==================================" << endl;
            cout << "NOMBRE ALUMNO: " << NombreAlumno << endl;
            cout << "PROMEDIO: " << Promedio() << endl;
            cout << "ESTADO FINAL: " << EstadoFinal() << endl;

        }
};

int main() {
    
    // INSTANCIAR LA CLASE

    clsEstudiante oEstudiante1("Jorge", 15, 13, 17);
    clsEstudiante oEstudiante2("Luis", 9, 10, 9);
    
    oEstudiante1.MostrarResultado();
    oEstudiante2.MostrarResultado();

    system("pause");
    return 0;

}
    