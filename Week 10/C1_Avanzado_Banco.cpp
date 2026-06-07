/*
Ejercicio 1 — Banco: control de movimientos de una cuenta universitaria
Enunciado

Un estudiante universitario administra una cuenta bancaria donde recibe depósitos, hace pagos y retira dinero.
El programa debe permitir ingresar un saldo inicial y luego registrar 8 movimientos bancarios.

Cada movimiento puede ser:

Positivo: depósito.
Negativo: retiro o pago.

El programa debe calcular usando recursividad:

El resultado neto de los movimientos.
El saldo final.
La cantidad de retiros o pagos.
El mayor retiro realizado.
Una alerta si el saldo final queda bajo o en sobregiro.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const int N = 8;

double calcularSaldo(double movimientos[], int posicion) {
    // Caso base: cuando ya se revisaron todos los movimientos
    if (posicion == N) {
        return 0;
    }

    // Caso recursivo: movimiento actual + saldo del resto
    return movimientos[posicion] + calcularSaldo(movimientos, posicion + 1);
}

int contarRetiros(double movimientos[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    // Si el movimiento es negativo, cuenta como retiro o pago
    if (movimientos[posicion] < 0) {
        return 1 + contarRetiros(movimientos, posicion + 1);
    }

    return contarRetiros(movimientos, posicion + 1);
}

double mayorRetiro(double movimientos[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    double actual = 0;

    // Si es retiro, lo convertimos a positivo para compararlo
    if (movimientos[posicion] < 0) {
        actual = movimientos[posicion] * -1;
    }

    double mayorResto = mayorRetiro(movimientos, posicion + 1);

    if (actual > mayorResto) {
        return actual;
    }

    return mayorResto;
}

void pausar() {
    cout << "\nPresione ENTER para finalizar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    double saldoInicial;
    double movimientos[N];

    cout << fixed << setprecision(2);

    cout << "SIMULADOR BANCARIO UNIVERSITARIO" << endl;
    cout << "Ingrese el saldo inicial de la cuenta: S/ ";
    cin >> saldoInicial;

    cout << "\nIngrese 8 movimientos bancarios." << endl;
    cout << "Depositos en positivo. Retiros o pagos en negativo." << endl;

    for (int i = 0; i < N; i++) {
        cout << "Movimiento " << i + 1 << ": S/ ";
        cin >> movimientos[i];
    }

    double resultadoMovimientos = calcularSaldo(movimientos, 0);
    double saldoFinal = saldoInicial + resultadoMovimientos;
    int totalRetiros = contarRetiros(movimientos, 0);
    double retiroMayor = mayorRetiro(movimientos, 0);

    cout << "\nRESUMEN DE CUENTA" << endl;
    cout << "Saldo inicial: S/ " << saldoInicial << endl;
    cout << "Resultado neto de movimientos: S/ " << resultadoMovimientos << endl;
    cout << "Saldo final: S/ " << saldoFinal << endl;
    cout << "Cantidad de retiros/pagos: " << totalRetiros << endl;
    cout << "Mayor retiro o pago: S/ " << retiroMayor << endl;

    if (saldoFinal < 0) {
        cout << "Alerta: la cuenta quedo en sobregiro." << endl;
    } else if (saldoFinal < 100) {
        cout << "Alerta: saldo bajo para cubrir gastos proximos." << endl;
    } else {
        cout << "Estado: saldo suficiente." << endl;
    }

    pausar();
    return 0;
}