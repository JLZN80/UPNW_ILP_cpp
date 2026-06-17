// ============================================================
// IS6041 - Introducción a los Lenguajes de Programación
// UPNW - Universidad Privada Norbert Wiener - 2026-I
// Sesión 11 - Ejercicio Grupal Breakout EG04
// ============================================================
// TEMA    : POO C++ I - Clases, Encapsulamiento, Constructores
// CONTEXTO: Sistema de Mesas - La Rosa Náutica, Lima
// NIVEL   : ⭐⭐⭐⭐  Avanzado
// TIEMPO  : 30 minutos | Grupos de 5
// ============================================================
// CONCEPTOS DEMOSTRADOS:
//   - Validación de DOS condiciones en reservar()
//   - Acumulador protegido (consumoTotal solo suma si ocupada)
//   - Ciclo de vida completo: libre→reservada→consumo→cierre→libre
//   - Reset completo de estado en cerrarCuenta()
//   - Método que retorna double (cerrarCuenta)
//   - Demostración de corrupción imposible gracias a private
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class MesaRestaurante {
private:
    int    numero;
    int    capacidad;      // máximo de personas (1 a 12)
    bool   disponible;
    string clienteActual;
    double consumoTotal;   // acumulado durante la estadía

public:
    // ---- Constructor ----
    // Capacidad válida entre 1 y 12; estado inicial: libre
    MesaRestaurante(int num, int cap) {
        numero        = num;
        capacidad     = (cap >= 1 && cap <= 12) ? cap : 4;
        disponible    = true;
        clienteActual = "";
        consumoTotal  = 0;
    }

    // ---- Reservar mesa ----
    // Valida DOS condiciones: disponibilidad Y capacidad suficiente
    bool reservar(string cliente, int personas) {
        if (!disponible) {
            cout << "Mesa " << numero
                 << " ya esta ocupada por " << clienteActual << endl;
            return false;
        }
        if (personas > capacidad) {
            cout << "Capacidad insuficiente: mesa "
                 << numero << " tiene max " << capacidad
                 << " personas." << endl;
            return false;
        }
        disponible    = false;
        clienteActual = cliente;
        consumoTotal  = 0;
        cout << "Mesa " << numero << " reservada para "
             << cliente << " (" << personas << " personas)" << endl;
        return true;
    }

    // ---- Agregar consumo ----
    // Solo acumula si la mesa está ocupada y el monto es positivo
    void agregarConsumo(double monto) {
        if (!disponible && monto > 0) {
            consumoTotal += monto;
        } else if (monto <= 0) {
            cout << "Monto invalido: S/." << monto << endl;
        } else {
            cout << "Mesa " << numero << " esta libre, sin consumo activo." << endl;
        }
    }

    // ---- Cerrar cuenta ----
    // Imprime resumen completo, libera la mesa, retorna total cobrado
    double cerrarCuenta(double propina) {
        if (disponible) {
            cout << "Mesa " << numero << " esta libre, nada que cobrar." << endl;
            return 0;
        }
        double total = consumoTotal + propina;
        cout << fixed << setprecision(2);
        cout << "=== CUENTA MESA " << numero << " ===" << endl;
        cout << "Cliente  : " << clienteActual << endl;
        cout << "Consumo  : S/." << consumoTotal << endl;
        cout << "Propina  : S/." << propina << endl;
        cout << "TOTAL    : S/." << total << endl;

        // Reset completo — la mesa queda libre
        disponible    = true;
        clienteActual = "";
        consumoTotal  = 0;
        return total;
    }

    // ---- Getters ----
    bool   getDisponible() { return disponible;   }
    int    getNumero()     { return numero;        }
    double getConsumo()    { return consumoTotal;  }

    // ---- Mostrar estado actual ----
    void mostrar() {
        cout << fixed << setprecision(2);
        cout << "Mesa " << numero
             << " (cap:" << capacidad << ") | "
             << (disponible ? "LIBRE" : "OCUPADA: " + clienteActual)
             << " | Consumo acumulado: S/." << consumoTotal
             << endl;
    }
};

// ============================================================
// MAIN - Demostración del ciclo completo
// ============================================================
int main() {
    MesaRestaurante m1(5,  6);  // Mesa 5, hasta 6 personas
    MesaRestaurante m2(8,  4);  // Mesa 8, hasta 4 personas
    MesaRestaurante m3(12, 2);  // Mesa 12, romántica: 2 personas

    cout << "=== La Rosa Nautica - Estado inicial ===" << endl;
    m1.mostrar(); m2.mostrar(); m3.mostrar();

    cout << endl << "=== Reservas ===" << endl;
    m1.reservar("Familia Torres",  4);
    m2.reservar("Empresa SAC",     6);  // supera capacidad de 4
    m2.reservar("Pareja Lima",     2);
    m3.reservar("Ana y Carlos",    2);
    m1.reservar("Otro cliente",    2);  // ya ocupada

    cout << endl << "=== Consumos mesa 1 ===" << endl;
    m1.agregarConsumo(85.0);    // entrada
    m1.agregarConsumo(120.0);   // plato de fondo
    m1.agregarConsumo(45.0);    // postre
    m1.agregarConsumo(-10.0);   // inválido
    m1.mostrar();

    cout << endl << "=== Consumos mesa 2 ===" << endl;
    m2.agregarConsumo(60.0);
    m2.agregarConsumo(80.0);
    m2.mostrar();

    cout << endl << "=== Cierre de cuentas ===" << endl;
    m1.cerrarCuenta(25.0);
    cout << endl;
    m2.cerrarCuenta(15.0);
    cout << endl;
    m3.cerrarCuenta(0);         // sin consumo aún, cero propina

    cout << endl << "=== Estado final ===" << endl;
    m1.mostrar(); m2.mostrar(); m3.mostrar();

    system("pause");
    return 0;
}

// ============================================================
// SALIDA ESPERADA (resumen):
// Mesa 5  → reservada Familia Torres → consumo S/.250 → total S/.275
// Mesa 8  → capacidad insuficiente para 6 → reservada Pareja Lima
// Mesa 12 → reservada Ana y Carlos
// Mesa 5  → libre tras cerrar cuenta
// ============================================================
