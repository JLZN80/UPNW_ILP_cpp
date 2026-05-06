
#include <iostream>
#include <cstring>
#include <cstdlib> //system("pause") es parte de la biblioteca cstdlib, que se utiliza para ejecutar comandos del sistema operativo desde el programa. En este caso, se usa para pausar la ejecución del programa hasta que el usuario presione una tecla.
using namespace std;

int main() {

    char codigo[12] = "20241108";
    char estudiante[50] = "Rosa Medina";
    char mensaje[130];

    float nota = 10.5;

    // uso un puntero porque no se la longitud de la cadena final. Puede ser de 7 o de 10 caracteres, dependiendo de la longitud del nombre del estudiante. Si se usara un arreglo de caracteres con una longitud fija, podria haber problemas de desbordamiento de buffer si el nombre del estudiante es muy largo o muy corto.
    const char *resultado = (nota >= 11.0) ? "APROBADO" : "DESAPROBADO"; // el operador ternario es una forma corta de escribir un if-else, en este caso, si la nota es mayor o igual a 11.0, entonces resultado es "APROBADO", de lo contrario, resultado es "DESAPROBADO"

    //Formateo la salida de la variable Mensaje para imprimir la funcion sprintf, que es una funcion de la biblioteca cstring que se utiliza para formatear cadenas de caracteres. En este caso, se usa para crear el mensaje final que se mostrara al usuario, concatenando el codigo del estudiante, el nombre del estudiante y el resultado de su nota (aprobado o desaprobado).
    sprintf(mensaje, "[%s] %s | Nota: %.1f | %s", codigo, estudiante, nota, resultado); // el formato de la cadena mensaje es: [codigo] estudiante | Nota: nota | resultado. El formato de la cadena se especifica usando los caracteres de formato, donde %s se usa para cadenas de caracteres, %.1f se usa para numeros flotantes con un decimal y %d se usa para numeros enteros.

    // Visualizao en pantalla
    cout << mensaje << endl;

    system("pause");
    return 0;
}