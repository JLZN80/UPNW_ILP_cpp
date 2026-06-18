/*
# Ejercicio 10 — Proyecto integrador: perfil de creador de contenido

## Contexto
Un joven creador de contenido administra su perfil digital con nombre del canal, seguidores, ingresos mensuales y estado de monetización.

## Qué se busca
Crea una clase CreadorContenido con atributos privados y constructor. Implementa métodos sumarSeguidores(int), registrarIngreso(double), activarMonetizacion() y mostrarPerfil(). La monetización solo puede activarse si tiene al menos 1000 seguidores.

## Explicación
Este ejercicio integra casi toda la sesión: atributos privados, constructor, métodos, encapsulamiento y reglas internas del negocio. Es un buen cierre progresivo.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class CreadorContenido {
private:
    string canal;
    int seguidores;
    double ingresosMensuales;
    bool monetizado;

public:
    CreadorContenido(const string& c, int s, double ingresos)
        : canal(c), seguidores(s), ingresosMensuales(ingresos), monetizado(false) {}

    void sumarSeguidores(int nuevos) {
        if (nuevos > 0) seguidores += nuevos;
    }

    void registrarIngreso(double monto) {
        if (monto > 0) ingresosMensuales += monto;
    }

    void activarMonetizacion() {
        if (seguidores >= 1000) {
            monetizado = true;
            cout << "Monetizacion activada." << endl;
        } else {
            cout << "No cumple la meta de seguidores para monetizar." << endl;
        }
    }

    void mostrarPerfil() const {
        cout << "Canal: " << canal << endl;
        cout << "Seguidores: " << seguidores << endl;
        cout << "Ingresos: S/ " << ingresosMensuales << endl;
        cout << "Monetizado: " << monetizado << endl;
    }
};

int main() {
    CreadorContenido c1("CodeCampus", 950, 120.0);
    c1.mostrarPerfil();
    c1.sumarSeguidores(100);
    c1.activarMonetizacion();
    c1.registrarIngreso(80.0);
    c1.mostrarPerfil();
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Integración de toda la sesión
- Reglas complejas
- Diseño más completo de clase
*/

