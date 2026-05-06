
#include <iostream>
#include <cstring>
#include <cstdlib> //system("pause") es parte de la biblioteca cstdlib, que se utiliza para ejecutar comandos del sistema operativo desde el programa. En este caso, se usa para pausar la ejecución del programa hasta que el usuario presione una tecla.
using namespace std;

int main() {

    // declarando un Array de Notas de Tipo Float (La nota usa decimales, por eso se usa el tipo de dato float)
    float notas[5] = {12.5, 17.0, 10.0, 15.5, 8.5};

    float suma = 0.0;
    float promedio = 0.0;
    float NotaMenor;
    int NroEstAprob = 0; // esta variable se usara para contar el numero de estudiantes aprobados (con nota mayor o igual a 11)

    //float notas[5];
    //notas[0] = 12.5;
    //notas[1] = 17.0;
    //notas[2] = 10.0;
    //notas[3] = 15.5;
    //notas[4] = 8.5;

    NotaMenor = notas[0]; // Inicializo NotaMenor con la primera nota

    // Recooro el Arreglo de Notas para mostrar su contenido
    for (int i = 0; i < 5; i++) {
        // el promedio se calcula sumando todas las notas y dividiendo entre el numero de notas (5 en este caso)
       suma = suma + notas[i]; // suma = suma + notas[i] es lo mismo que suma += notas[i] 
       //suma += notas[i]; // esta es una forma mas corta de escribir suma = suma + notas[i]
       
       if (notas[i] >= 11.0) {
            NroEstAprob++; // NroEstAprob = NroEstAprob + 1 es lo mismo que NroEstAprob++
       }  
       
       if (notas[i] < NotaMenor) {
            NotaMenor = notas[i]; // si la nota actual es menor que la nota menor registrada, entonces actualizo la nota menor con la nota actual
       }
    }
   
    promedio = suma / 5.0; // el numero 5.0 es un float, para que el resultado de la division sea un float y no un int (si se usara 5 sin el punto decimal, el resultado seria un int y se perderia la parte decimal del promedio)


    cout << "Promedio de Notas: " << promedio << endl;
    cout << "Nota Menor: " << NotaMenor << endl;
    cout << "Número de Estudiantes Aprobados: " << NroEstAprob << endl;

    system("pause");
    return 0;
    
}