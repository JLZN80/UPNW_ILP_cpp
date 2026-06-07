/*
Ejercicio 3 — Universidad: promedio ponderado de notas
Enunciado

Un estudiante de sexto ciclo desea calcular su promedio ponderado.
Debe ingresar la nota final y los créditos de 5 cursos.

El programa debe calcular usando recursividad:

La suma ponderada de notas.
El total de créditos.
El promedio ponderado.
La cantidad de cursos desaprobados.
La nota más baja.
Un mensaje de estado académico.

Considerar nota aprobatoria: 12.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const int N = 5;

double sumaPonderada(double notas[], int creditos[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    // Nota * crédito del curso actual + resto
    return (notas[posicion] * creditos[posicion]) + sumaPonderada(notas, creditos, posicion + 1);
}

int sumaCreditos(int creditos[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    return creditos[posicion] + sumaCreditos(creditos, posicion + 1);
}

int contarCursosDesaprobados(double notas[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    if (notas[posicion] < 12) {
        return 1 + contarCursosDesaprobados(notas, posicion + 1);
    }

    return contarCursosDesaprobados(notas, posicion + 1);
}

double menorNota(double notas[], int posicion) {
    // Caso base: si estoy en el último curso, esa es la menor nota de esa parte
    if (posicion == N - 1) {
        return notas[posicion];
    }

    double menorResto = menorNota(notas, posicion + 1);

    if (notas[posicion] < menorResto) {
        return notas[posicion];
    }

    return menorResto;
}

void pausar() {
    cout << "\nPresione ENTER para finalizar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    double notas[N];
    int creditos[N];

    cout << fixed << setprecision(2);

    cout << "PROMEDIO PONDERADO UNIVERSITARIO" << endl;
    cout << "Ingrese las notas y creditos de 5 cursos." << endl;

    for (int i = 0; i < N; i++) {
        cout << "\nCurso " << i + 1 << endl;

        cout << "Nota final: ";
        cin >> notas[i];

        cout << "Creditos: ";
        cin >> creditos[i];

        // Validaciones simples
        if (notas[i] < 0) {
            notas[i] = 0;
        }

        if (notas[i] > 20) {
            notas[i] = 20;
        }

        if (creditos[i] <= 0) {
            creditos[i] = 1;
        }
    }

    int totalCreditos = sumaCreditos(creditos, 0);
    double promedio = sumaPonderada(notas, creditos, 0) / totalCreditos;
    int desaprobados = contarCursosDesaprobados(notas, 0);
    double notaMasBaja = menorNota(notas, 0);

    cout << "\nREPORTE ACADEMICO" << endl;
    cout << "Total de creditos: " << totalCreditos << endl;
    cout << "Promedio ponderado: " << promedio << endl;
    cout << "Cursos desaprobados: " << desaprobados << endl;
    cout << "Nota mas baja: " << notaMasBaja << endl;

    if (desaprobados > 0) {
        cout << "Estado: requiere reforzamiento academico." << endl;
    } else if (promedio >= 16) {
        cout << "Estado: rendimiento destacado." << endl;
    } else if (promedio >= 12) {
        cout << "Estado: rendimiento aprobatorio." << endl;
    } else {
        cout << "Estado: riesgo academico." << endl;
    }

    pausar();
    return 0;
}