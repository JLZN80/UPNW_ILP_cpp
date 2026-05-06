#include <iostream>
using namespace std;

struct  Persona {
    int edad;
    char nombre[50];
};

int main() {
    Persona alumno;
    Persona profesor;

    Persona *p = nullptr;

    alumno.edad = 20;

    cout << "Edad del alumno: " << alumno.edad << endl;

    // No quiero que se cierre rapidamente la consola...
    system("pause");

    return 0;
}