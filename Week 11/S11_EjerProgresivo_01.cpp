/*
# Ejercicio 1 — Universidad: perfil de estudiante

## Contexto
La oficina de tutoría de una universidad quiere registrar el nombre, la edad y el promedio de un estudiante de primer ciclo.

## Qué se busca
Crea una clase Estudiante con atributos privados nombre, edad y promedio. Implementa setters y getters. En main, crea un objeto, asigna valores válidos y muestra la información.

## Explicación
Este ejercicio introduce la idea central de la sesión: los datos dejan de estar expuestos directamente y pasan a estar protegidos por la clase. El estudiante practica atributos privados y acceso controlado mediante setters y getters.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    double promedio;

public:
    void setNombre(const string& n) { nombre = n; }
    void setEdad(int e) { if (e >= 15 && e <= 100) edad = e; }
    void setPromedio(double p) { if (p >= 0 && p <= 20) promedio = p; }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getPromedio() const { return promedio; }
};

int main() {
    Estudiante e1;
    e1.setNombre("Lucia Perez");
    e1.setEdad(18);
    e1.setPromedio(16.7);

    cout << "Nombre: " << e1.getNombre() << endl;
    cout << "Edad: " << e1.getEdad() << endl;
    cout << "Promedio: " << e1.getPromedio() << endl;
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Clase y objeto
- Atributos privados
- Setters y getters básicos
*/

