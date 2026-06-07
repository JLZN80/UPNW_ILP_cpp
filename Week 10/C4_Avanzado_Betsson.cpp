/*
Ejercicio 4 — Betsson: simulador académico de control de presupuesto
Enunciado

Un grupo de estudiantes analiza un caso ficticio de uso de presupuesto en una plataforma de apuestas deportivas tipo Betsson.

El objetivo del ejercicio no es promover apuestas reales, sino practicar programación y control de riesgos personales.

El usuario debe ingresar:

Un presupuesto ficticio.
6 operaciones ficticias.
Por cada operación: monto apostado y ganancia cobrada.

El programa debe calcular usando recursividad:

Total apostado.
Resultado neto.
Operaciones mayores al 20% del presupuesto.
Alertas presupuestales.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const int N = 6;

double calcularResultado(double montos[], double ganancias[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    // Resultado neto de una operación = ganancia cobrada - monto apostado
    return ganancias[posicion] - montos[posicion] + calcularResultado(montos, ganancias, posicion + 1);
}

double totalApostado(double montos[], int posicion) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    return montos[posicion] + totalApostado(montos, posicion + 1);
}

int contarAlertas(double montos[], int posicion, double presupuesto) {
    // Caso base
    if (posicion == N) {
        return 0;
    }

    // Alerta si una operación supera el 20% del presupuesto ficticio
    if (montos[posicion] > presupuesto * 0.20) {
        return 1 + contarAlertas(montos, posicion + 1, presupuesto);
    }

    return contarAlertas(montos, posicion + 1, presupuesto);
}

void pausar() {
    cout << "\nPresione ENTER para finalizar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    double presupuesto;
    double montos[N];
    double ganancias[N];

    cout << fixed << setprecision(2);

    cout << "SIMULADOR ACADEMICO DE CONTROL DE APUESTAS FICTICIAS" << endl;
    cout << "Contexto: caso universitario para analizar presupuesto y riesgo." << endl;
    cout << "Este programa no promueve apuestas reales." << endl;

    cout << "\nIngrese el presupuesto ficticio disponible: S/ ";
    cin >> presupuesto;

    if (presupuesto <= 0) {
        cout << "El presupuesto debe ser positivo." << endl;
        pausar();
        return 0;
    }

    cout << "\nIngrese 6 operaciones ficticias." << endl;
    cout << "Monto apostado: dinero arriesgado." << endl;
    cout << "Ganancia cobrada: coloque 0 si se perdio." << endl;

    for (int i = 0; i < N; i++) {
        cout << "\nOperacion " << i + 1 << endl;

        cout << "Monto apostado: S/ ";
        cin >> montos[i];

        cout << "Ganancia cobrada: S/ ";
        cin >> ganancias[i];

        if (montos[i] < 0) {
            montos[i] = 0;
        }

        if (ganancias[i] < 0) {
            ganancias[i] = 0;
        }
    }

    double apostado = totalApostado(montos, 0);
    double resultadoNeto = calcularResultado(montos, ganancias, 0);
    int alertas = contarAlertas(montos, 0, presupuesto);

    cout << "\nREPORTE DE CONTROL" << endl;
    cout << "Presupuesto ficticio: S/ " << presupuesto << endl;
    cout << "Total apostado: S/ " << apostado << endl;
    cout << "Resultado neto: S/ " << resultadoNeto << endl;
    cout << "Operaciones mayores al 20% del presupuesto: " << alertas << endl;

    if (apostado > presupuesto) {
        cout << "Alerta: el total apostado supera el presupuesto ficticio." << endl;
    } else if (alertas > 0) {
        cout << "Alerta: existen operaciones concentradas respecto al presupuesto." << endl;
    } else {
        cout << "Estado: no se detectan alertas presupuestales en la simulacion." << endl;
    }

    pausar();
    return 0;
}