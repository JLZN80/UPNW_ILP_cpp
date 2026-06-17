// ============================================================
// IS6041 - Introducción a los Lenguajes de Programación
// UPNW - Universidad Privada Norbert Wiener - 2026-I
// Sesión 11 - Ejercicio Grupal Breakout EG01
// ============================================================
// TEMA    : POO C++ I - Clases, Encapsulamiento, Constructores
// CONTEXTO: Sistema Semafórico - Municipalidad de Miraflores
// NIVEL   : ⭐⭐  Básico+
// TIEMPO  : 30 minutos | Grupos de 5
// ============================================================
// CONCEPTOS DEMOSTRADOS:
//   - Clase con atributos privados
//   - Constructor con validación (operador ternario)
//   - Setter con validación de estado (if con ||)
//   - Getter simple
//   - Método con lógica de negocio (esPaso)
//   - Múltiples objetos en main()
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Semaforo {
private:
    string ubicacion;
    string estado;   // Solo acepta: "ROJO", "AMARILLO", "VERDE"
    int    segundos; // Duración del estado actual en segundos

public:
    // ---- Constructor ----
    // Valida que segundos sea positivo; si no, usa 30 por defecto
    Semaforo(string ub, string est, int seg) {
        ubicacion = ub;
        estado    = est;
        segundos  = (seg > 0) ? seg : 30;
    }

    // ---- Setter con validación ----
    // Solo acepta los 3 estados válidos; rechaza cualquier otro
    void cambiar(string nuevoEstado, int seg) {
        if (nuevoEstado == "ROJO" ||
            nuevoEstado == "AMARILLO" ||
            nuevoEstado == "VERDE") {
            estado   = nuevoEstado;
            segundos = (seg > 0) ? seg : 30;
        } else {
            cout << "Estado invalido: " << nuevoEstado << endl;
        }
    }

    // ---- Getters ----
    string getEstado()    { return estado;    }
    string getUbicacion() { return ubicacion; }

    // ---- Lógica de negocio ----
    // Retorna true solo si el estado es VERDE (paso libre)
    bool esPaso() {
        return estado == "VERDE";
    }

    // ---- Mostrar estado completo ----
    void mostrar() {
        cout << "[" << ubicacion << "] "
             << estado << " (" << segundos << "s)"
             << " | " << (esPaso() ? "PASO LIBRE" : "DETENERSE")
             << endl;
    }
};

// ============================================================
// MAIN - Demostración
// ============================================================
int main() {
    // Crear dos semáforos con ubicaciones reales de Miraflores
    Semaforo s1("Av. Larco / Benavides",    "ROJO",  45);
    Semaforo s2("Javier Prado / La Marina", "VERDE", 60);

    cout << "=== Estado inicial ===" << endl;
    s1.mostrar();
    s2.mostrar();

    cout << endl << "=== Cambios ===" << endl;

    // Cambio válido
    s1.cambiar("VERDE", 30);
    s1.mostrar();

    // Intento con estado inválido — debe rechazarse
    s2.cambiar("MORADO", 10);

    // Cambio válido
    s2.cambiar("AMARILLO", 5);
    s2.mostrar();

    cout << endl << "=== ¿Cuáles permiten paso? ===" << endl;
    cout << "s1 (" << s1.getUbicacion() << "): " << (s1.esPaso() ? "SI" : "NO") << endl;
    cout << "s2 (" << s2.getUbicacion() << "): " << (s2.esPaso() ? "SI" : "NO") << endl;

    system("pause");
    
    return 0;
}

// ============================================================
// SALIDA ESPERADA:
// === Estado inicial ===
// [Av. Larco / Benavides] ROJO (45s) | DETENERSE
// [Javier Prado / La Marina] VERDE (60s) | PASO LIBRE
//
// === Cambios ===
// [Av. Larco / Benavides] VERDE (30s) | PASO LIBRE
// Estado invalido: MORADO
// [Javier Prado / La Marina] AMARILLO (5s) | DETENERSE
//
// === ¿Cuáles permiten paso? ===
// s1 (Av. Larco / Benavides): SI
// s2 (Javier Prado / La Marina): NO
// ============================================================
