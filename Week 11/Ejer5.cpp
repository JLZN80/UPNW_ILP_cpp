/*
Ejercicio 4: Inventario simple para una tienda tipo Rappi

• Crea una clase ItemTienda con nombre, precio y stock.
• Valida que precio y stock no sean negativos.
• Crea vender(cantidad) y reponer(cantidad).
• Muestra el valor del inventario: precio * stock

*/

#include <iostream>
#include <string>   
using namespace std;

class clsItemTienda {

    private:
        string nombre;
        double precio;
        int stock;

    public:
        void RegistrarInventario(string n, double p, int s) {
            nombre = n;
            precio = p;
            stock = s;
        }

        void Vender(int cantidad) {
            if (cantidad > 0 && cantidad <= stock) {
                stock = stock - cantidad;  // Restar la cantidad vendida al stock
            } else {
                cout << "Cantidad no válida para vender" << endl;
            }
        }

        void Reponer(int cantidad) {
            if (cantidad > 0) {
                stock = stock + cantidad;  // Adicionar la cantidad repuesta al stock
            } else {
                cout << "Cantidad no válida para reponer" << endl;
            }
        }

        double ValorInventario() {
            return (precio * stock);  // Calcular el valor del inventario
        }

        void MostrarInventario() {
            cout << "Nombre del producto: " << nombre << endl;
            cout << "Precio: " << precio << endl;
            cout << "Stock: " << stock << endl;
            cout << "Valor del inventario: " << ValorInventario() << endl;
        }
};

int main() {
    // INSTANCIAR la clase - CREAR un objeto de la clase
    clsItemTienda oItem1, oItem2;

    oItem1.RegistrarInventario("Camiseta", 20.0, 50);
    oItem1.MostrarInventario();

    system("pause");

    oItem2.RegistrarInventario("Pantalon", 14.5, 15);
    oItem2.MostrarInventario();
    
    system("pause");

    return 0;
}