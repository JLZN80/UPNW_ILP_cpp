#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;

public:
    CuentaBancaria(string t, double s) {
        titular = t;
        saldo = (s >= 0) ? s : 0;
    }

    void depositar(double monto) {
        if (monto > 0) saldo += monto;
        else cout << "Deposito invalido." << endl;
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) saldo -= monto;
        else cout << "Retiro invalido o saldo insuficiente." << endl;
    }

    void mostrarSaldo() const {
        cout << titular << " tiene S/ " << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta("Ana", 200);
    cuenta.depositar(100);
    cuenta.retirar(50);
    cuenta.mostrarSaldo();
    system("pause");
    return 0;
}
