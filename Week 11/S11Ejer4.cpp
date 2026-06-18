/*
Ejercicio 3: Jugador de fútbol y aporte ofensivo
• Crea una clase Jugador con nombre, goles y asistencias.
• Goles y asistencias no pueden ser negativos. // VALIDACION DE LOS ATRIBUTOS DENTRO DE LA CLASE
• Calcula contribuciones = goles + asistencias.
• Muestra el resumen del jugador.
*/

#include <iostream>
#include <string>
using namespace std;

class clsJugador {

   private:
        string nombre;
        int goles;
        int asistencias;

    public:
        void RegistrarInfo(string NombreJugador, int GolesJugador, int AsistenciasJugador) {
            nombre = NombreJugador;

            if (GolesJugador >= 0) {
                goles = GolesJugador;
            } else {
                cout << "Los goles no pueden ser negativos" << endl;
            }

            if (AsistenciasJugador >= 0) {
                asistencias = AsistenciasJugador;
            } else {
                cout << "Las asistencias no pueden ser negativas" << endl;
            }      
        }

        int Contribuciones() {
            return (goles + asistencias);
        }

        void MostrarResumen() {
            cout << "Nombre del jugador: " << nombre << endl;
            cout << "Goles: " << goles << endl;
            cout << "Asistencias: " << asistencias << endl;
            cout << "Contribuciones totales: " << Contribuciones() << endl;
        }

};     

int main() {

    // INSTANCIAR la clase - CREAR un objeto de la clase
    clsJugador oJugador;

    // Registrar la información del jugador
    oJugador.RegistrarInfo("Lionel Messi", 30, 20);

    // Mostrar el resumen del jugador
    oJugador.MostrarResumen();

    system("pause");

    return 0;
}