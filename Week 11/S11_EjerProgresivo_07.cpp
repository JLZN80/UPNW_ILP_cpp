/*
# Ejercicio 7 — Gimnasio joven: membresía

## Contexto
Un gimnasio universitario ofrece membresías por meses. Cada alumno tiene nombre, meses pagados y si su membresía está activa.

## Qué se busca
Crea una clase Membresia con constructor, getters y un método renovar(int meses). Si los meses a renovar no son positivos, no debe aceptarlos. También crea un método desactivar().

## Explicación
Aquí el estudiante trabaja atributos booleanos y cambios de estado. El foco está en diseñar métodos que representen acciones reales del dominio.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Membresia {
private:
    string nombre;
    int mesesPagados;
    bool activa;

public:
    Membresia(const string& n, int meses, bool estado)
        : nombre(n), mesesPagados(meses), activa(estado) {}

    string getNombre() const { return nombre; }
    int getMesesPagados() const { return mesesPagados; }
    bool estaActiva() const { return activa; }

    void renovar(int meses) {
        if (meses > 0) {
            mesesPagados += meses;
            activa = true;
        } else {
            cout << "Cantidad invalida de meses." << endl;
        }
    }

    void desactivar() { activa = false; }
};

int main() {
    Membresia m1("Paolo", 2, true);
    cout << m1.getNombre() << " | Meses: " << m1.getMesesPagados() << " | Activa: " << m1.estaActiva() << endl;
    m1.renovar(3);
    m1.desactivar();
    cout << m1.getNombre() << " | Meses: " << m1.getMesesPagados() << " | Activa: " << m1.estaActiva() << endl;
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Cambios de estado controlados
- Constructores
- Métodos coherentes con negocio
*/

