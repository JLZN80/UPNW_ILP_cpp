/* CUenta Bancaria Digial:
• Implementa una clase CuentaBancaria.
• El saldo debe ser private.
• Crea depositar(), retirar() y consultarSaldo().
• No permitas depósitos negativos 
*/

#include <iostream>
using namespace std;

class clsCuentaBancaria {
    private:
        double saldo;

    public:

        void Depositar (double monto) {
            if (monto > 0) {
                saldo = saldo + monto;  // Adicionar el monto del deposito al saldo / Siempre y cuando el monto > 0
            } else {
                cout << "El monto a depositar debe ser positivo" << endl;
            }
        }

        void Retirar (double monto) {
            if (monto > 0) {
                saldo = saldo - monto;  // Restar el monto del retiro al saldo / Siempre y cuando el monto > 0
            } else {
                cout << "El monto a retirar debe ser positivo" << endl;
            }
        }
        
        void ConsultarSaldo() {
            cout << "El saldo actual es: " << saldo << endl;
        }
};


int main() {

    // INSTANCIAR la clase - CREAR un objeto de la clase 
    clsCuentaBancaria oCuenta;

    // Depositar dinero en la cuenta
    oCuenta.Depositar(1000);
    oCuenta.ConsultarSaldo();

    system("pause");

    oCuenta.Retirar(500);
    oCuenta.ConsultarSaldo();
    
    system("pause");
    
    oCuenta.Depositar(150);
    oCuenta.Depositar(150);
    oCuenta.ConsultarSaldo();
    
    system("pause");
    
    return 0;
}