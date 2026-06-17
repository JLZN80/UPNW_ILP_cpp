// ============================================================
// IS6041 - Introducción a los Lenguajes de Programación
// UPNW - Universidad Privada Norbert Wiener - 2026-I
// Sesión 11 - Ejercicio Grupal Breakout EG02
// ============================================================
// TEMA    : POO C++ I - Clases, Encapsulamiento, Constructores
// CONTEXTO: Ficha de Paciente - EsSalud Lima
// NIVEL   : ⭐⭐⭐  Intermedio
// TIEMPO  : 30 minutos | Grupos de 5
// ============================================================
// CONCEPTOS DEMOSTRADOS:
//   - Constructor con validación múltiple de campos
//   - Método que llama a otro método interno (calcularIMC → clasificarIMC)
//   - Protección contra división por cero
//   - Cadena de if/else para clasificación
//   - Múltiples objetos: caso válido, límite e inválido
// ============================================================

#include <iostream>
#include <iomanip>  // para setprecision
#include <string>
using namespace std;

class PacienteClinica {
private:
    string nombre;
    string dni;
    int    edad;   // válida: 1 a 129
    double peso;   // kg, debe ser > 0
    double talla;  // metros, debe ser > 0 y < 3.0

public:
    // ---- Constructor con validación de cada campo ----
    PacienteClinica(string n, string d, int e, double p, double t) {
        nombre = n;
        dni    = d;
        edad   = (e > 0 && e < 130)    ? e : 0;
        peso   = (p > 0)                ? p : 0;
        talla  = (t > 0 && t < 3.0)    ? t : 0;
    }

    // ---- Calcula el IMC ----
    // Retorna 0 si talla es 0 para evitar división por cero
    double calcularIMC() {
        if (talla == 0) return 0;
        return peso / (talla * talla);
    }

    // ---- Clasifica según IMC (OMS) ----
    // Llama internamente a calcularIMC() — no necesita parámetros
    string clasificarIMC() {
        double imc = calcularIMC();
        if (imc == 0)      return "SIN DATOS";
        if (imc < 18.5)    return "BAJO PESO";
        if (imc < 25.0)    return "NORMAL";
        if (imc < 30.0)    return "SOBREPESO";
        return "OBESIDAD";
    }

    // ---- Mostrar ficha completa ----
    void mostrar() {
        cout << fixed << setprecision(2);
        cout << "[" << dni << "] " << nombre
             << " | Edad: " << edad << " anios"
             << " | IMC: " << calcularIMC()
             << " | " << clasificarIMC()
             << endl;
    }

    // ---- Getters ----
    string getNombre() { return nombre; }
    string getDNI()    { return dni;    }
    int    getEdad()   { return edad;   }
};

// ============================================================
// MAIN - Demostración
// ============================================================
int main() {
    cout << "=== EsSalud Lima - Fichas de Pacientes ===" << endl << endl;

    // Paciente 1: datos completamente válidos
    PacienteClinica p1("Rosa Quispe Mamani", "12345678", 35, 68.0, 1.62);

    // Paciente 2: obesidad moderada
    PacienteClinica p2("Juan Lima Torres",   "87654321", 50, 95.0, 1.70);

    // Paciente 3: edad inválida (negativa) — el constructor la pone en 0
    PacienteClinica p3("Ana Torres Ríos",    "11223344", -5, 55.0, 1.58);

    // Paciente 4: talla inválida — el constructor la pone en 0, IMC = 0
    PacienteClinica p4("Luis Puma Ccari",    "44332211", 28, 70.0, 3.5);

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();  // edad queda en 0, IMC calculado igual
    p4.mostrar();  // talla inválida → IMC = 0 → SIN DATOS

    cout << endl << "=== Consulta directa ===" << endl;
    cout << "IMC de " << p1.getNombre() << ": " << p1.calcularIMC() << endl;
    cout << "Clasificacion: " << p1.clasificarIMC() << endl;

    system("pause");
    return 0;
}

// ============================================================
// SALIDA ESPERADA:
// === EsSalud Lima - Fichas de Pacientes ===
//
// [12345678] Rosa Quispe Mamani | Edad: 35 anios | IMC: 25.91 | SOBREPESO
// [87654321] Juan Lima Torres   | Edad: 50 anios | IMC: 32.87 | OBESIDAD
// [11223344] Ana Torres Ríos    | Edad: 0 anios  | IMC: 22.03 | NORMAL
// [44332211] Luis Puma Ccari    | Edad: 28 anios | IMC: 0.00  | SIN DATOS
//
// === Consulta directa ===
// IMC de Rosa Quispe Mamani: 25.91
// Clasificacion: SOBREPESO
// ============================================================
