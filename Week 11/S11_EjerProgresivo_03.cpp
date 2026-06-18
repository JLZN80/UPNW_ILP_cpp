/*
# Ejercicio 3 — Streaming: plan de suscripción

## Contexto
Una app de streaming para universitarios ofrece planes Básico, Estándar y Premium.

## Qué se busca
Crea una clase Suscripcion con usuario, plan y pagoMensual. Agrega un método mostrarResumen() que imprima un resumen bonito. Usa constructor con parámetros para inicializar el objeto.

## Explicación
Este ejercicio refuerza el constructor como forma ordenada de inicializar objetos desde el momento de creación. También introduce un método que encapsula la responsabilidad de mostrar información.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Suscripcion {
private:
    string usuario;
    string plan;
    double pagoMensual;

public:
    Suscripcion(const string& u, const string& p, double pago)
        : usuario(u), plan(p), pagoMensual(pago) {}

    void mostrarResumen() const {
        cout << "Usuario: " << usuario << endl;
        cout << "Plan: " << plan << endl;
        cout << "Pago mensual: S/ " << pagoMensual << endl;
    }
};

int main() {
    Suscripcion s1("andres_19", "Premium", 29.90);
    s1.mostrarResumen();
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Constructor con parámetros
- Métodos públicos
- Uso de objetos en contexto real
*/

