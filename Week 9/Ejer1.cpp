/*
=======================================================================================================
EJERCICIO A1 — Historial de Transacciones Yape
Banco · Lista de transacciones · saldo actual
=======================================================================================================
Yape necesita mostrar el historial de las ultimas transacciones de un usuario. Cada transaccion tiene: id, 
tipo (DEPOSITO o RETIRO), monto y descripcion. Implementar una lista enlazada donde se agregan transacciones 
al final y se puede calcular el saldo actual sumando depositos y restando retiros.

*/

#include <cstdlib>
#include <cstring>
#include <iostream>
 
using namespace std;
 
struct Transaccion {
    // COMPONENTE AMARILLO (VALOR DEL NODO)
    int id;
    string tipo; // DEPOSITO O RETIRO
    double monto;
    string glosa;  // descripcion de la transaccion o Informacion Extra
 
 
    // COMPONENTE AZUL (PUNTERO AL SIGUIENTE NODO)
    Transaccion* DirPuntero;
};
 
Transaccion* agregarTransaccion(Transaccion* h,int id, string tipo, double monto, string glosa) {
 
    Transaccion* n = new Transaccion;
    n->id = id;
    n->tipo = tipo;
    n->monto = monto;
    n->glosa = glosa;
 
    n->DirPuntero = nullptr;
 
    if (h == nullptr) {
        h = n;
    } else {
        Transaccion* temp = h;
        while (temp->DirPuntero != nullptr) {
            temp = temp->DirPuntero;
        }
        temp->DirPuntero = n;
    }
    return h;
}
 
double calcularSaldo(Transaccion* h) {
    double saldo = 0.0;
 
    Transaccion* temp = h;
 
    while (temp != nullptr) {
        if (temp->tipo == "DEPOSITO") {
            saldo += temp->monto;
        } else if (temp->tipo == "RETIRO") {
            saldo -= temp->monto;
        }
        temp = temp->DirPuntero;
    }
    return saldo;
}
 
 void ImprimirHistorial(Transaccion* h) {
    Transaccion* temp = h;
 
    cout << "Historial de Transacciones:" << endl;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Tipo: " << temp->tipo
             << ", Monto: " << temp->monto << ", Glosa: " << temp->glosa << endl;
        temp = temp->DirPuntero;
    }
 }
 
 int main() {
    Transaccion* historial = nullptr;
 
    historial = agregarTransaccion(historial, 1, "DEPOSITO", 500.0, "Deposito inicial");
    historial = agregarTransaccion(historial, 2, "DEPOSITO", 200.0, "Pago de servicios");
    historial = agregarTransaccion(historial, 3, "RETIRO", 150.0, "Deposito adicional");
    historial = agregarTransaccion(historial, 4, "DEPOSITO", 100.0, "Pago de servicios");
    historial = agregarTransaccion(historial, 5, "RETIRO", 80.0, "Deposito adicional");
 
    ImprimirHistorial(historial);
 
    double saldoFinal = calcularSaldo(historial);
    cout << "Saldo Final: " << saldoFinal << endl;
 
    cin.get();

    return 0;
 
 }