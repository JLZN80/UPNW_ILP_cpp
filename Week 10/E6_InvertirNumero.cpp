#include <iostream>
using namespace std;

void invertirNumero(int n) {
    // Caso base: si n llega a 0, ya no quedan digitos
    if (n == 0) {
        return;
    }

    // Muestra el ultimo digito
    cout << n % 10;

    // Caso recursivo: elimina el ultimo digito
    invertirNumero(n / 10);
}

int main() {
    int n;

    cout << "Ingrese un numero entero positivo: ";
    cin >> n;

    if (n <= 0) {
        cout << "Debe ingresar un numero mayor que cero." << endl;
    } else {
        cout << "Numero invertido: ";
        invertirNumero(n);
        cout << endl;
    }

    system("pause");
    return 0;
}