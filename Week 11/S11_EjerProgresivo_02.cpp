/*
# Ejercicio 2 — Tienda deportiva: control de stock

## Contexto
Una tienda deportiva en línea vende zapatillas urbanas a jóvenes de 18 a 20 años y quiere evitar registrar stock negativo.

## Qué se busca
Crea una clase Producto con nombre, precio y stock. El setter del stock no debe aceptar valores negativos. Muestra un mensaje si el valor es inválido. Luego prueba la clase en main.

## Explicación
Aquí el alumno ve por qué private + setters aporta seguridad lógica. Aunque el compilador no sabe si un stock negativo es absurdo para el negocio, la clase sí puede proteger esa regla.

## Código C++ validado para VS Code / g++
*/

#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    void setNombre(const string& n) { nombre = n; }
    void setPrecio(double p) { if (p > 0) precio = p; }
    void setStock(int s) {
        if (s >= 0) stock = s;
        else cout << "Error: el stock no puede ser negativo." << endl;
    }

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }
};

int main() {
    Producto p;
    p.setNombre("Zapatillas UrbanX");
    p.setPrecio(249.90);
    p.setStock(12);
    p.setStock(-3);

    cout << "Producto: " << p.getNombre() << endl;
    cout << "Precio: S/ " << p.getPrecio() << endl;
    cout << "Stock: " << p.getStock() << endl;
    system("pause");
    return 0;
}

/*
## Qué refuerza
- Encapsulamiento
- Validación con setters
- Reglas de negocio simples
*/

