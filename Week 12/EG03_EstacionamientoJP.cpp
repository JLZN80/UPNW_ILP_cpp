// ============================================================
// IS6041 - Introducción a los Lenguajes de Programación
// UPNW - Universidad Privada Norbert Wiener - 2026-I
// Sesión 11 - Ejercicio Grupal Breakout EG03
// ============================================================
// TEMA    : POO C++ I - Clases, Encapsulamiento, Constructores
// CONTEXTO: Estacionamiento CC Jockey Plaza
// NIVEL   : ⭐⭐⭐  Intermedio
// TIEMPO  : 30 minutos | Grupos de 5
// ============================================================
// CONCEPTOS DEMOSTRADOS:
//   - Atributo booleano de estado (ocupada)
//   - Constructor con valor por defecto para tarifa inválida
//   - Método que retorna bool (ingresar)
//   - Ciclo de vida completo: libre → ocupada → libre
//   - Limpieza de estado en salir() (reset de atributos)
//   - Array de objetos en main()
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CasillaEstacionamiento {
private:
    int    numero;
    string sector;
    bool   ocupada;
    string placaAuto;
    double tarifaPorHora;

public:
    // ---- Constructor ----
    // Si tarifa inválida se usa S/.5.00 por defecto
    CasillaEstacionamiento(int num, string sec, double tarifa) {
        numero        = num;
        sector        = sec;
        tarifaPorHora = (tarifa > 0) ? tarifa : 5.0;
        ocupada       = false;
        placaAuto     = "";
    }

    // ---- Ingresar auto ----
    // Retorna true si la casilla estaba libre; false si estaba ocupada
    bool ingresar(string placa) {
        if (!ocupada) {
            ocupada   = true;
            placaAuto = placa;
            cout << "Auto " << placa
                 << " ingreso a casilla " << numero
                 << " [sector " << sector << "]" << endl;
            return true;
        }
        cout << "Casilla " << numero
             << " ocupada por " << placaAuto << endl;
        return false;
    }

    // ---- Salir y cobrar ----
    // Calcula cobro, libera la casilla y retorna el monto
    double salir(int horas) {
        if (ocupada) {
            double cobro = horas * tarifaPorHora;
            cout << fixed << setprecision(2);
            cout << "Auto " << placaAuto
                 << " salio de casilla " << numero
                 << " | " << horas << "h x S/." << tarifaPorHora
                 << " = S/." << cobro << endl;
            // Liberar la casilla
            ocupada   = false;
            placaAuto = "";
            return cobro;
        }
        cout << "Casilla " << numero << " ya estaba libre." << endl;
        return 0;
    }

    // ---- Getters ----
    bool   getOcupada() { return ocupada;   }
    int    getNumero()  { return numero;     }
    string getSector()  { return sector;     }

    // ---- Mostrar estado ----
    void mostrar() {
        cout << "Casilla " << numero
             << " [" << sector << "] | "
             << (ocupada ? "OCUPADA: " + placaAuto : "LIBRE")
             << endl;
    }
};

// ============================================================
// MAIN - Demostración con array de casillas
// ============================================================
int main() {
    // Array de 4 casillas en sector A
    CasillaEstacionamiento casillas[4] = {
        CasillaEstacionamiento(101, "A", 4.50),
        CasillaEstacionamiento(102, "A", 4.50),
        CasillaEstacionamiento(103, "B", 6.00),
        CasillaEstacionamiento(104, "B", -1.0)  // tarifa inválida → usa 5.0
    };

    cout << "=== Jockey Plaza - Estado inicial ===" << endl;
    for (int i = 0; i < 4; i++) casillas[i].mostrar();

    cout << endl << "=== Ingresos ===" << endl;
    casillas[0].ingresar("ABC-123");
    casillas[0].ingresar("XYZ-789");  // debe rechazar: ya ocupada
    casillas[1].ingresar("XYZ-789");
    casillas[2].ingresar("DEF-456");

    cout << endl << "=== Estado tras ingresos ===" << endl;
    for (int i = 0; i < 4; i++) casillas[i].mostrar();

    cout << endl << "=== Salidas y cobros ===" << endl;
    casillas[0].salir(2);
    casillas[1].salir(3);
    casillas[3].salir(1);  // intento en casilla libre

    cout << endl << "=== Estado final ===" << endl;
    for (int i = 0; i < 4; i++) casillas[i].mostrar();

      system("pause");
    return 0;
}

// ============================================================
// SALIDA ESPERADA:
// === Jockey Plaza - Estado inicial ===
// Casilla 101 [A] | LIBRE
// Casilla 102 [A] | LIBRE
// Casilla 103 [B] | LIBRE
// Casilla 104 [B] | LIBRE
//
// === Ingresos ===
// Auto ABC-123 ingreso a casilla 101 [sector A]
// Casilla 101 ocupada por ABC-123
// Auto XYZ-789 ingreso a casilla 102 [sector A]
// Auto DEF-456 ingreso a casilla 103 [sector B]
//
// === Salidas y cobros ===
// Auto ABC-123 salio... | 2h x S/.4.50 = S/.9.00
// Auto XYZ-789 salio... | 3h x S/.4.50 = S/.13.50
// Casilla 104 ya estaba libre.
// ============================================================
