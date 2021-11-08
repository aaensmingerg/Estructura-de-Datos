/* Este programa es capaz de leer un archivor csv 
y responder a las preguntas requeridas en la entrega 3.2 
de la situación problema, principalmente la obtención de 
los top 5 de sitios con más conexiones por día de utilizando 
algoritmos de búsqueda y ordenamiento según requeridos,
árboles binarios de búsqueda (BST) así como HashMaps.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Domingo 7 de Octubre de 2021  */

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
    
    cout << "---1. Demostracion mapa primer dia---  " << endl;
    cout << "R. " << endl;
    map<string,int> mapa = f1.conexionesPorDia("10-8-2021");
    for (auto r: mapa){
        cout<< "Nombre conexion: " << r.first << " -> " << "Numero conexiones: " << r.second << endl;
    }

    cout << "" << endl;

    cout << "---2. Demostracion top primer dia---  " << endl;
    cout << "R. " << endl;
    f1.top(5,"10-8-2021");

    cout << "" << endl;

    cout << "--3. Demostracion top 5 dias --" << endl;
    cout << "R. " << endl;
    f1.top5dias();   

    return 0;
}