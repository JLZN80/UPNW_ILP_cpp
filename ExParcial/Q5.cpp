#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    char codigo[12] = "20241108";
    char estudiante[50] = "Rosa Medina";
    char mensaje[130];
    float nota = 10.5f;

    const char *estado = (nota >= 11.0f) ? "APROBADO" : "DESAPROBADO";

    sprintf(mensaje, "[%s] %s | Nota: %.1f | %s", codigo, estudiante, nota, estado);

    cout << mensaje << endl;

    system("pause"); // Pausa de Windows
    return 0;
}

