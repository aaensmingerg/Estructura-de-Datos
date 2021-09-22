#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "File.cpp"
#include "Ordenamiento.hpp"
using namespace std;

int main(){
    File f1("equipo4.csv");
    cout << "Cuantos registros tiene tu archivo? " << endl;
    cout << "R. " << f1.getFecha().size() << endl;
    cout << "Cuantos records hay del segundo dia registrado? " << endl;
    cout << "R. " << f1.buscarSegundaFecha().size() << endl;
    cout << "Que dia es este? "<< endl;
    cout << "R. " << f1.getFecha()[0] << endl;
    cout << "Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond?" << endl;
    f1.busquedaNombre();
    cout << "Cual es la direccion de la red interna de la compania? " << endl;
    cout << "R. " << f1.direcccionIterna()[0] << endl;
    cout << "Que servicio de correo electronico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)? " << endl;
    cout << "R. " << endl;
    f1.correosElectronicos();
    cout << "Considerando solamente los puertos destino. Que puertos abajo del 1000 se estan usando?  " << endl;
    cout << "R. " << endl;
    f1.puertosUsados();
    return 0;
}