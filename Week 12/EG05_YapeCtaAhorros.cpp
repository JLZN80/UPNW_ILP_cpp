// ============================================================
// IS6041 - Introducción a los Lenguajes de Programación
// UPNW - Universidad Privada Norbert Wiener - 2026-I
// Sesión 11 - Ejercicio Grupal Breakout EG05
// ============================================================
// TEMA    : POO C++ I - Clases, Encapsulamiento, Constructores
// CONTEXTO: Transferencias Yape - BCP Pagos Digitales
// NIVEL   : ⭐⭐⭐⭐⭐  Desafío integrador
// TIEMPO  : 30 minutos | Grupos de 5
// ============================================================
// CONCEPTOS DEMOSTRADOS:
//   - Atributos static: compartidos por TODOS los objetos
//   - Destructor: ciclo de vida completo del objeto
//   - Referencia (&) entre objetos: transferir modifica el real
//   - Métodos static: accesibles sin instancia (::)
//   - Invariante del sistema: el dinero total no cambia al transferir
//   - depositar() sí cambia totalDineroSistema (ingreso real)
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CuentaAhorrosYape {
private:
    string titular;
    string celular;
    double saldo;
    double limiteTransferencia;  // máximo S/.500 por operación

    // ---- Atributos ESTÁTICOS ----
    // Compartidos por TODOS los objetos — no pertenecen a ninguno en particular
    static int    totalCuentas;
    static double totalDineroSistema;

public:
    // ---- Constructor ----
    // Valida saldo >= 0 y limite (0 < lim <= 500)
    // Incrementa los contadores estáticos
    CuentaAhorrosYape(string t, string cel, double s, double lim) {
        titular              = t;
        celular              = cel;
        saldo                = (s >= 0)              ? s   : 0;
        limiteTransferencia  = (lim > 0 && lim <= 500) ? lim : 500;
        totalCuentas++;
        totalDineroSistema  += saldo;
    }

    // ---- Destructor ----
    // Se ejecuta automáticamente al salir del scope
    // Decrementa los contadores estáticos
    ~CuentaAhorrosYape() {
        totalCuentas--;
        totalDineroSistema -= saldo;
    }

    // ---- Transferir ----
    // Recibe destino por REFERENCIA (&) — modifica el saldo real del receptor
    // El dinero no se crea ni se destruye: solo cambia de cuenta
    // Por eso totalDineroSistema NO cambia al transferir
    bool transferir(CuentaAhorrosYape& destino, double monto) {
        if (monto <= 0 || monto > limiteTransferencia) {
            cout << "RECHAZADO [" << titular << "]: monto S/." << monto
                 << " fuera de limite (max S/." << limiteTransferencia << ")" << endl;
            return false;
        }
        if (monto > saldo) {
            cout << "RECHAZADO [" << titular << "]: saldo insuficiente"
                 << " (tiene S/." << saldo << ", quiere transferir S/." << monto << ")" << endl;
            return false;
        }
        saldo          -= monto;
        destino.saldo  += monto;
        cout << "YAPE OK: " << titular << " → " << destino.titular
             << " | S/." << monto << endl;
        return true;
    }

    // ---- Depositar ----
    // Un depósito SÍ aumenta el dinero total del sistema (ingreso externo)
    void depositar(double monto) {
        if (monto > 0) {
            saldo              += monto;
            totalDineroSistema += monto;
            cout << "DEPOSITO [" << titular << "]: +S/." << monto
                 << " | Nuevo saldo: S/." << saldo << endl;
        }
    }

    // ---- Getters de instancia ----
    double getSaldo()   { return saldo;   }
    string getTitular() { return titular; }
    string getCelular() { return celular; }

    // ---- Métodos ESTÁTICOS ----
    // Se llaman con CuentaAhorrosYape::metodo() — sin necesidad de objeto
    static int    getTotalCuentas()       { return totalCuentas;       }
    static double getTotalDineroSistema() { return totalDineroSistema; }

    // ---- Mostrar estado de la cuenta ----
    void mostrar() {
        cout << fixed << setprecision(2);
        cout << "[" << celular << "] " << titular
             << " | Saldo: S/." << saldo
             << " | Limite: S/." << limiteTransferencia
             << endl;
    }
};

// ---- Inicializar atributos estáticos FUERA de la clase ----
// (obligatorio en C++ — no va en el constructor)
int    CuentaAhorrosYape::totalCuentas       = 0;
double CuentaAhorrosYape::totalDineroSistema = 0;

// ============================================================
// Función auxiliar: imprime los totales del sistema
// ============================================================
void imprimirTotales() {
    cout << fixed << setprecision(2);
    cout << "  Cuentas activas : " << CuentaAhorrosYape::getTotalCuentas()       << endl;
    cout << "  Dinero sistema  : S/." << CuentaAhorrosYape::getTotalDineroSistema() << endl;
}

// ============================================================
// MAIN - Demostración completa
// ============================================================
int main() {
    cout << "=== Sistema Yape - BCP ===" << endl;
    cout << "--- Antes de crear cuentas ---" << endl;
    imprimirTotales();

    // Crear 3 cuentas
    CuentaAhorrosYape c1("Maria Quispe",  "999001001", 300.0, 200.0);
    CuentaAhorrosYape c2("Carlos Mamani", "999002002", 150.0, 500.0);
    CuentaAhorrosYape c3("Ana Torres",    "999003003", 500.0, 100.0);

    cout << endl << "--- Tras crear 3 cuentas ---" << endl;
    imprimirTotales();
    c1.mostrar(); c2.mostrar(); c3.mostrar();

    cout << endl << "=== Transferencias ===" << endl;

    // OK: c1 → c2, S/.100 (dentro del limite de c1: 200)
    c1.transferir(c2, 100.0);

    // RECHAZO: c3 → c1, S/.150 (supera limite de c3: 100)
    c3.transferir(c1, 150.0);

    // RECHAZO: c2 → c1, S/.200 (c2 solo tiene S/.250, pero el saldo sí alcanza)
    //          veamos si pasa el límite de c2 (500) — sí pasa, y el saldo alcanza
    c2.transferir(c1, 200.0);

    // RECHAZO: c2 → c1, S/.600 (supera limite de c2: 500)
    c2.transferir(c1, 600.0);

    cout << endl << "--- Estado tras transferencias ---" << endl;
    c1.mostrar(); c2.mostrar(); c3.mostrar();
    imprimirTotales();  // totalDineroSistema NO debe cambiar

    cout << endl << "=== Deposito externo (sí cambia el total) ===" << endl;
    c3.depositar(200.0);
    imprimirTotales();  // ahora sí cambió

    // ---- Demostración del destructor ----
    // Al salir del bloque, el destructor de cTemp se ejecuta
    cout << endl << "=== Demo destructor (cuenta temporal) ===" << endl;
    {
        CuentaAhorrosYape cTemp("Cuenta Temporal", "000000000", 50.0, 100.0);
        cout << "Dentro del bloque: ";
        imprimirTotales();
    }  // <-- destructor de cTemp se llama aquí
    cout << "Fuera del bloque : ";
    imprimirTotales();

    system("pause");
    return 0;
}

// ============================================================
// SALIDA ESPERADA (extracto):
// Antes: 0 cuentas, S/.0.00
// Tras crear: 3 cuentas, S/.950.00
// YAPE OK: Maria → Carlos S/.100
// RECHAZADO [Ana]: limite max S/.100
// YAPE OK: Carlos → Maria S/.200
// RECHAZADO [Carlos]: limite max S/.500 (pero supera con S/.600)
// totalDineroSistema permanece en S/.950 tras transferencias
// Depósito externo +200 → S/.1150
// ============================================================
