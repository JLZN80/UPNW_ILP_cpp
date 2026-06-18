#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    string numeroCuenta;
    double saldo;

public:
    CuentaBancaria(string titularInicial, string numeroInicial, double saldoInicial) {
        titular = titularInicial;
        numeroCuenta = numeroInicial;
        if (saldoInicial >= 0) {
            saldo = saldoInicial;
        } else {
            saldo = 0;
            cout << "Advertencia: el saldo inicial no puede ser negativo. Se asigno S/ 0.00" << endl;
        }
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito realizado correctamente." << endl;
        } else {
            cout << "Error: el monto a depositar debe ser mayor que cero." << endl;
        }
    }

    void retirar(double monto) {
        if (monto <= 0) {
            cout << "Error: el monto a retirar debe ser mayor que cero." << endl;
        } else if (monto > saldo) {
            cout << "Error: saldo insuficiente para realizar el retiro." << endl;
        } else {
            saldo -= monto;
            cout << "Retiro realizado correctamente." << endl;
        }
    }

    double getSaldo() const {
        return saldo;
    }

    string getTitular() const {
        return titular;
    }

    string getNumeroCuenta() const {
        return numeroCuenta;
    }

    void mostrarResumen() const {
        cout << fixed << setprecision(2);
        cout << "\n--- RESUMEN DE CUENTA ---" << endl;
        cout << "Titular: " << titular << endl;
        cout << "Numero de cuenta: " << numeroCuenta << endl;
        cout << "Saldo actual: S/ " << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta("Maria Torres", "001-2026-777", 500.00);
    int opcion;
    double monto;

    cout << fixed << setprecision(2);
    cout << "=== MI PRIMERA CUENTA BANCARIA DIGITAL ===" << endl;

    do {
        cout << "\n1. Ver resumen" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Retirar" << endl;
        cout << "4. Consultar saldo" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cuenta.mostrarResumen();
                break;
            case 2:
                cout << "Monto a depositar: S/ ";
                cin >> monto;
                cuenta.depositar(monto);
                break;
            case 3:
                cout << "Monto a retirar: S/ ";
                cin >> monto;
                cuenta.retirar(monto);
                break;
            case 4:
                cout << "Saldo disponible: S/ " << cuenta.getSaldo() << endl;
                break;
            case 5:
                cout << "Gracias por usar la cuenta bancaria digital." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}
