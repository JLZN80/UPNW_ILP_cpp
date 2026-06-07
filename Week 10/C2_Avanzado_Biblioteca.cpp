/*
Ejercicio 2 — Biblioteca: control de préstamos y multas
Enunciado

Una biblioteca universitaria registra libros prestados a estudiantes.
El programa debe registrar 6 libros, indicando el título y los días de atraso.

La multa es de S/ 1.50 por día de atraso.

El programa debe calcular usando recursividad:

La cantidad de libros con atraso.
La multa total.
Buscar un libro por título exacto.
Mostrar los días de atraso y multa del libro buscado.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const int N = 6;
const double MULTA_POR_DIA = 1.50;

int buscarLibro(string titulos[], string buscado, int posicion) {
    // Caso base: llegó al final y no encontró el libro
    if (posicion == N) {
        return -1;
    }

    // Caso base alternativo: encontró el título
    if (titulos[posicion] == buscado) {
        return posicion;
    }

    // Caso recursivo: buscar en la siguiente posición
    return buscarLibro(titulos, buscado, posicion + 1);
}

double calcularMultaTotal(int diasAtraso[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    // Multa actual + multa del resto
    return (diasAtraso[posicion] * MULTA_POR_DIA) + calcularMultaTotal(diasAtraso, posicion + 1);
}

int contarLibrosAtrasados(int diasAtraso[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    if (diasAtraso[posicion] > 0) {
        return 1 + contarLibrosAtrasados(diasAtraso, posicion + 1);
    }

    return contarLibrosAtrasados(diasAtraso, posicion + 1);
}

void pausar() {
    cout << "\nPresione ENTER para finalizar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    string titulos[N];
    int diasAtraso[N];
    string buscado;

    cout << fixed << setprecision(2);

    cout << "CONTROL DE BIBLIOTECA UNIVERSITARIA" << endl;
    cout << "Registre 6 libros prestados." << endl;

    // Esta línea limpia el buffer antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < N; i++) {
        cout << "\nLibro " << i + 1 << ": ";
        getline(cin, titulos[i]);

        cout << "Dias de atraso: ";
        cin >> diasAtraso[i];

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (diasAtraso[i] < 0) {
            cout << "No se aceptan dias negativos. Se registrara 0." << endl;
            diasAtraso[i] = 0;
        }
    }

    cout << "\nIngrese el titulo exacto que desea buscar: ";
    getline(cin, buscado);

    int posicionEncontrada = buscarLibro(titulos, buscado, 0);

    cout << "\nREPORTE DE BIBLIOTECA" << endl;
    cout << "Libros con atraso: " << contarLibrosAtrasados(diasAtraso, 0) << endl;
    cout << "Multa total estimada: S/ " << calcularMultaTotal(diasAtraso, 0) << endl;

    if (posicionEncontrada == -1) {
        cout << "Busqueda: el libro no fue encontrado." << endl;
    } else {
        cout << "Busqueda: libro encontrado en la posicion " << posicionEncontrada + 1 << "." << endl;
        cout << "Dias de atraso del libro: " << diasAtraso[posicionEncontrada] << endl;
        cout << "Multa del libro: S/ " << diasAtraso[posicionEncontrada] * MULTA_POR_DIA << endl;
    }

    pausar();
    return 0;
}