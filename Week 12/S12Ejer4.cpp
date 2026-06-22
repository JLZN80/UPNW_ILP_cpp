#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    Producto(string n, double p, int s) {
        nombre = n;
        precio = (p >= 0) ? p : 0;
        stock = (s >= 0) ? s : 0;
    }

    void setStock(int nuevoStock) {
        if (nuevoStock >= 0) stock = nuevoStock;
        else cout << "Error: stock negativo no permitido." << endl;
    }

    int getStock() const { return stock; }

    void mostrar() const {
        cout << nombre << " | Precio: S/ " << precio << " | Stock: " << stock << endl;
    }
};

int main() {
    Producto teclado("Teclado", 85.50, 10);
    teclado.mostrar();
    teclado.setStock(-50);
    teclado.setStock(15);
    cout << "Stock final: " << teclado.getStock() << endl;
    
    system("pause");
    return 0;
}
