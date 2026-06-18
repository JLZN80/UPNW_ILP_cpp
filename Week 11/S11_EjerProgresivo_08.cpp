/*
# Ejercicio 8 — Tienda gamer: carrito de compra

## Contexto
Una tienda gamer para jóvenes vende accesorios. Cada carrito debe registrar el nombre del producto, cantidad y precio unitario.

## Qué se busca
Crea una clase ItemCarrito con constructor, getters y método calcularSubtotal(). Luego, en main, crea dos objetos y muestra el subtotal de cada uno.

## Explicación
Este ejercicio muestra reutilización concreta: una misma clase permite construir varios objetos con estados diferentes, pero todos con el mismo comportamiento.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class ItemCarrito {
private:
    string producto;
    int cantidad;
    double precioUnitario;

public:
    ItemCarrito(const string& p, int c, double precio)
        : producto(p), cantidad(c), precioUnitario(precio) {}

    string getProducto() const { return producto; }
    int getCantidad() const { return cantidad; }
    double getPrecioUnitario() const { return precioUnitario; }
    double calcularSubtotal() const { return cantidad * precioUnitario; }
};

int main() {
    ItemCarrito i1("Mouse RGB", 2, 79.90);
    ItemCarrito i2("Audifonos Gamer", 1, 189.00);
    cout << i1.getProducto() << " -> Subtotal: S/ " << i1.calcularSubtotal() << endl;
    cout << i2.getProducto() << " -> Subtotal: S/ " << i2.calcularSubtotal() << endl;
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Objetos múltiples
- Métodos de cálculo
- Uso repetido de una misma clase
*/

