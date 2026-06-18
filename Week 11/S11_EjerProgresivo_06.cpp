/*
# Ejercicio 6 — Rappi universitario: pedido express

## Contexto
Un estudiante pide comida por delivery desde una app. El pedido tiene cliente, total, estado y costo de envío.

## Qué se busca
Crea una clase Pedido con atributos privados. Implementa métodos calcularTotalFinal() y cambiarEstado(string nuevoEstado). Solo permite estados: Pendiente, En camino, Entregado.

## Explicación
El ejercicio agrega reglas de negocio sobre texto y muestra que un objeto también puede controlar transiciones de estado, no solo números.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Pedido {
private:
    string cliente;
    double total;
    double envio;
    string estado;

public:
    Pedido(const string& c, double t, double e)
        : cliente(c), total(t), envio(e), estado("Pendiente") {}

    void cambiarEstado(const string& nuevoEstado) {
        if (nuevoEstado == "Pendiente" || nuevoEstado == "En camino" || nuevoEstado == "Entregado") {
            estado = nuevoEstado;
        } else {
            cout << "Estado invalido." << endl;
        }
    }

    double calcularTotalFinal() const { return total + envio; }

    void mostrar() const {
        cout << "Cliente: " << cliente << endl;
        cout << "Estado: " << estado << endl;
        cout << "Total final: S/ " << calcularTotalFinal() << endl;
    }
};

int main() {
    Pedido p1("Camila", 24.50, 4.00);
    p1.mostrar();
    p1.cambiarEstado("En camino");
    p1.mostrar();
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Métodos con validación de texto
- Estados controlados
- Comportamiento derivado
*/

