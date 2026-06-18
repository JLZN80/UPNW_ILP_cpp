/*
# Ejercicio 9 — Universidad: curso con vacantes

## Contexto
Una universidad necesita controlar las vacantes de un curso electivo popular entre estudiantes de 18 a 20 años.

## Qué se busca
Crea una clase Curso con nombre, vacantes y matriculados. Implementa un método matricular() que solo incremente matriculados si todavía hay vacantes. Agrega también mostrarEstado().

## Explicación
Aquí el alumno ya maneja una regla de consistencia entre dos atributos internos. El método debe preservar la lógica del objeto incluso frente a múltiples llamadas.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Curso {
private:
    string nombre;
    int vacantes;
    int matriculados;

public:
    Curso(const string& n, int v) : nombre(n), vacantes(v), matriculados(0) {}

    void matricular() {
        if (matriculados < vacantes) {
            matriculados++;
            cout << "Matricula realizada." << endl;
        } else {
            cout << "No hay vacantes disponibles." << endl;
        }
    }

    void mostrarEstado() const {
        cout << "Curso: " << nombre << endl;
        cout << "Vacantes: " << vacantes << endl;
        cout << "Matriculados: " << matriculados << endl;
    }
};

int main() {
    Curso c1("Programacion II", 2);
    c1.mostrarEstado();
    c1.matricular();
    c1.matricular();
    c1.matricular();
    c1.mostrarEstado();
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Reglas internas de coherencia
- Métodos de negocio
- Protección del estado
*/

