#include <iostream>
#include <string>
using namespace std;

class clsProducto {
    private: // El alcance que seo darle a las variables y funciones de la clase
        /* VAN A ESTAR CUIDADDOS O PROTEGIDOS POR DEFECTO*/
        string nombre;
        double precio;
        int stock;

    public:
        string marca;
        char TipoLocExt;

        // LOS METODOS - LAS FUNCIONES...
    public: 
        // Funcion de Tipo SETTER - ASIGNAR VALORES A LOS ATRIBUTOS
        // Almacena inofmracion en la Clase (pudiemdo ser esta clonada)
        void SetStock(int NuevoStock) {
            // TODAS LAS VALIDACCION Y REGLAS, viven dentro del objeto!
            if (NuevoStock >= 0) {
                stock = NuevoStock;
            }
            else {
                cout << "El stock no puede ser negativo" << endl;
            }

        }

        // Funcion de Tipo GETTER - OBTENER VALORES DE LOS ATRIBUTOS
        // Devuelve informacion del objeto (pudiendo ser esta clonada)
        int GetStock() {
            return stock;
        }   

};

int main() {

    // Intanciar la Clase - CREAR UN OBJETO DE LA CLASE
    clsProducto oProducto;

    // Asignar valores a los atributos del objeto
    oProducto.SetStock(15);


}
