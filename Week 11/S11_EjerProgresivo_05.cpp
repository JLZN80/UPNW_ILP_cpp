/*
# Ejercicio 5 — Wallet universitaria

## Contexto
Una billetera digital para estudiantes permite recargar saldo y pagar consumos dentro del campus.

## Qué se busca
Crea una clase Wallet con saldo privado. Agrega métodos recargar(double monto) y pagar(double monto). El pago solo debe realizarse si hay saldo suficiente. Muestra mensajes apropiados.

## Explicación
Este problema consolida encapsulamiento con reglas de negocio más visibles. La clase no solo guarda saldo, sino que protege cómo cambia y bajo qué condiciones.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
using namespace std;

class Wallet {
private:
    double saldo;

public:
    Wallet(double sInicial) : saldo(sInicial) {}

    double getSaldo() const { return saldo; }

    void recargar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Recarga exitosa." << endl;
        }
    }

    void pagar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            cout << "Pago realizado correctamente." << endl;
        } else {
            cout << "No se puede realizar el pago." << endl;
        }
    }
};

int main() {
    Wallet w1(50.0);
    cout << "Saldo inicial: S/ " << w1.getSaldo() << endl;
    w1.pagar(20.0);
    w1.recargar(15.0);
    w1.pagar(60.0);
    cout << "Saldo final: S/ " << w1.getSaldo() << endl;
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Encapsulamiento con reglas de negocio
- Métodos con decisiones internas
- Validación de saldo
*/


