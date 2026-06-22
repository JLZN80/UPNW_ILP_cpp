#include <iostream>
#include <string>
using namespace std;

// CREANDO LA CLASE ABSTRACTA...
class clsParticipanteMundial {
protected:
    string Nombre;

public:
    clsParticipanteMundial(string n) {
        Nombre = n;
    }

    // TIENE UN METODO INCOMPLETO
    virtual void Presentar() = 0;
};

class clsJugadorMundial : public clsParticipanteMundial {
private:
    string Posicion;

public:
    clsJugadorMundial(string n, string p) : clsParticipanteMundial(n) {
        Posicion = p;
    }

    void Presentar() override {
        cout << "Jugador: " << Nombre << " | Posicion en el campo: " << Posicion << endl;
    }
};

class clsTecnicoMundial : public clsParticipanteMundial {
private:
    string Seleccion;

public:
    clsTecnicoMundial(string n, string s) : clsParticipanteMundial(n) {
        Seleccion = s;
    }

    void Presentar() override {
        cout << "Entrenador: " << Nombre << " | Dirige a: " << Seleccion << endl;
    }
};

class clsArbitroMundial : public clsParticipanteMundial {
private:
    string Confederacion;

public:
    clsArbitroMundial(string n, string c) : clsParticipanteMundial(n) {
        Confederacion = c;
    }

    void Presentar() override {
        cout << "Arbitro: " << Nombre << " | Afiliado a: " << Confederacion << endl;
    }
};

int main() {
    clsParticipanteMundial* participantes[3];

    participantes[0] = new clsJugadorMundial("Mbappe", "Delantero");
    participantes[1] = new clsTecnicoMundial("Scaloni", "Argentina");
    participantes[2] = new clsArbitroMundial("Lopez", "UEFA");

    for (int i = 0; i < 3; i++) {
        participantes[i]->Presentar();
    }

    for (int i = 0; i < 3; i++) {
        delete participantes[i];
    }

    system("pause");
    return 0;
}