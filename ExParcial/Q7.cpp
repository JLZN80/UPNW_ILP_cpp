#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    int equipos[4];
    int total = 0;

    for (int i = 0; i < 4; i++) {
        cout << "Ingrese equipos operativos del aula " << i + 1 << ": ";
        cin >> equipos[i];

        while (equipos[i] <= 0) {
            cout << "Error. Ingrese una cantidad mayor que 0: ";
            cin >> equipos[i];
        }

        total += equipos[i];
    }

    cout << "Total de equipos operativos: " << total << endl;

    system("pause"); // Pausa de Windows 
    return 0;
}
