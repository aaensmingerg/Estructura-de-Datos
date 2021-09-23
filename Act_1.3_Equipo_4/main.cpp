/* Este programa es capaz de leer un archivor csv 
y responder a las preguntas requeridas en la primera entrega de
la situación problema utilizando los algoritmos de búsqueda: Búsqueda Secuencial y Binaria
y además utiliza el algoritmo de ordenamiento de MergeSort
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Jueves 24 de Septiembre de 2021  */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "File.cpp"
#include "Ordenamiento.hpp"
using namespace std;

/* En este caso la función main es la encargada de responder a todas las preguntas*/
int main(){
    /* Lectura del archivo csv */
    File f1("equipo4.csv");
    cout << "Cuantos registros tiene tu archivo? " << endl;
    cout << "R. " << f1.getFecha().size() << endl;
    cout << "Cuantos records hay del segundo dia registrado? " << endl;
    cout << "R. ";
    Fecha fecha = f1.buscarSegundaFecha(f1);
    cout << "Que dia es este? "<< endl;
    cout << fecha << endl;
    cout << "Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond?" << endl;
    cout << "R. " << endl;
    f1.busquedaNombre();
    cout << "A quienes" << endl;
    cout << "Cual es la direccion de la red interna de la compania? " << endl;
    cout << "R. " << f1.direcccionIterna()[0] << endl;
    cout << "Que servicio de correo electronico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)? " << endl;
    cout << "R. " << endl;
    f1.correosElectronicos();
    cout << "Considerando solamente los puertos destino. Que puertos abajo del 1000 se estan usando?  " << endl;
    cout << "R. ";
    f1.puertosUsados();
    return 0;
}