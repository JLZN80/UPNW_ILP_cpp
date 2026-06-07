/*
Ejercicio 5 — Rappi: control de entregas e ingresos
Enunciado

Un estudiante universitario trabaja algunas horas haciendo entregas tipo Rappi.
El programa debe registrar 7 entregas.

Por cada entrega se debe ingresar:

Kilómetros recorridos.
Minutos utilizados.
Propina recibida.

La fórmula del pago estimado será:
pago = 4.00 + kilometros * 1.20 + propina

El programa debe calcular usando recursividad:

Ingresos totales.
Kilómetros totales.
Ingreso promedio por entrega.
Cantidad de entregas con más de 30 minutos.
Mejor entrega según pago estimado.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const int N = 7;
const double PAGO_BASE = 4.00;
const double PAGO_POR_KM = 1.20;

double calcularPagoEntrega(double kilometros, double propina) {
    return PAGO_BASE + (kilometros * PAGO_POR_KM) + propina;
}

double totalIngresos(double kilometros[], double propinas[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    // Pago actual + pagos del resto
    return calcularPagoEntrega(kilometros[posicion], propinas[posicion]) + totalIngresos(kilometros, propinas, posicion + 1);
}

int contarTardanzas(int minutos[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    if (minutos[posicion] > 30) {
        return 1 + contarTardanzas(minutos, posicion + 1);
    }

    return contarTardanzas(minutos, posicion + 1);
}

double totalKilometros(double kilometros[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    return kilometros[posicion] + totalKilometros(kilometros, posicion + 1);
}

int mejorEntrega(double kilometros[], double propinas[], int posicion) {
    // Caso base: si estoy en la última entrega, esa es la mejor de esa parte
    if (posicion == N - 1) {
        return posicion;
    }

    int mejorResto = mejorEntrega(kilometros, propinas, posicion + 1);

    double pagoActual = calcularPagoEntrega(kilometros[posicion], propinas[posicion]);
    double pagoResto = calcularPagoEntrega(kilometros[mejorResto], propinas[mejorResto]);

    if (pagoActual > pagoResto) {
        return posicion;
    }

    return mejorResto;
}

void pausar() {
    cout << "\nPresione ENTER para finalizar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    double kilometros[N];
    double propinas[N];
    int minutos[N];

    cout << fixed << setprecision(2);

    cout << "CONTROL DE ENTREGAS TIPO RAPPI" << endl;
    cout << "Registre 7 entregas realizadas por un estudiante universitario." << endl;

    for (int i = 0; i < N; i++) {
        cout << "\nEntrega " << i + 1 << endl;

        cout << "Kilometros recorridos: ";
        cin >> kilometros[i];

        cout << "Minutos utilizados: ";
        cin >> minutos[i];

        cout << "Propina recibida: S/ ";
        cin >> propinas[i];

        if (kilometros[i] < 0) {
            kilometros[i] = 0;
        }

        if (minutos[i] < 0) {
            minutos[i] = 0;
        }

        if (propinas[i] < 0) {
            propinas[i] = 0;
        }
    }

    double ingresos = totalIngresos(kilometros, propinas, 0);
    double kms = totalKilometros(kilometros, 0);
    int tardanzas = contarTardanzas(minutos, 0);
    int mejor = mejorEntrega(kilometros, propinas, 0);

    cout << "\nREPORTE DE ENTREGAS" << endl;
    cout << "Ingresos totales estimados: S/ " << ingresos << endl;
    cout << "Kilometros totales: " << kms << " km" << endl;
    cout << "Ingreso promedio por entrega: S/ " << ingresos / N << endl;
    cout << "Entregas con mas de 30 minutos: " << tardanzas << endl;
    cout << "Mejor entrega: entrega " << mejor + 1 << endl;
    cout << "Pago de la mejor entrega: S/ " << calcularPagoEntrega(kilometros[mejor], propinas[mejor]) << endl;

    if (tardanzas >= 3) {
        cout << "Alerta: revisar rutas, tiempos o zonas de entrega." << endl;
    } else if (ingresos / N >= 10) {
        cout << "Estado: buen rendimiento promedio por entrega." << endl;
    } else {
        cout << "Estado: rendimiento moderado; evaluar eficiencia por kilometro." << endl;
    }

    pausar();
    return 0;
}