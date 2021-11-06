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
    
    cout << "---7. Demostracion mapa ---  " << endl;
    cout << "R. " << endl;
    map<string,int> mapa = f1.conexionesPorDia("10-8-2021");
    for (auto r: mapa){
        cout<< "Nombre conexion: " << r.first << " -> " << "Numero conexiones: " << r.second << endl;
    }

    cout << "---1. Demostración top ---  " << endl;
    cout << "R. " << endl;
    f1.top(6,"10-8-2021");

    cout << "---3. Demostración top ---  " << endl;
    cout << "R. " << endl;
    f1.top(6,"10-8-2021");
    


    return 0;
}