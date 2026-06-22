#include <iostream>
#include <string>
using namespace std;

//CREANDO LA CLASE BASE..
class clsSeleccion {
    
    protected:
        string NombreSeleccion;
        string Continente;
        string ColorUniforme;
    
    public:

};

// CREANDO UNA CLASE DERIVADA...
class clsSeleccionConCapitan : protected clsSeleccion {

    private:
        string Capitan;
        int RankingFIFA;

    public:
        // CONSTRUCTOR DE LA CLASE HIJA PARA ACCEDER A LOS DATOS DEL PADRE 
        clsSeleccionConCapitan(string n, string c, string cap, int r, string cu) {
            NombreSeleccion = n;
            Continente = c;
            Capitan = cap;
            ColorUniforme = cu;

            // Aplicar el control al rankig, siempreq que sea diferente de 0...
            if (r > 0)
                RankingFIFA = r;
            else
                RankingFIFA = 1;
        }


        void MostrarSeleccion() {

            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "         REPORTE FIFA DE SELECCIONES 2026" << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "Equipo: " << NombreSeleccion << endl;
            cout << "Continente: " << Continente << endl;
            cout << "Capitan: " << Capitan << endl;
            cout << "Ranking FIFA: " << RankingFIFA << endl;
            cout << "Color Uniforme: " << ColorUniforme << endl;

        }
};

// IMPLEMENTAR LA FUNCION PRINCIPAL...

int main() {

    clsSeleccionConCapitan oSel1("PERU", "AMERICA", "XXXXX", 15, "BLANQUIROJA");
    clsSeleccionConCapitan oSel2("BRASIL", "AMERICA", "NEYMAR", 0, "VERDEAMARELLA");

    oSel1.MostrarSeleccion();
    oSel2.MostrarSeleccion();

    system("pause");
    return 0;
}