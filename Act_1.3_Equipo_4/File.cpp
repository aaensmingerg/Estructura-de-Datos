#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "File.hpp"
#include "Busqueda.hpp"
#include "Ordenamiento.hpp"
using namespace std;
        
    /* Hace falta ordenar primero */
vector<Fecha> File::buscarSegundaFecha(){
    int i = 0;
    Fecha fechaInicial = fecha[(fecha.size()-1)];
    vector<Fecha> encontrados;
    long int size = fecha.size();
        while (i < size) {
            if (fecha[i] > fecha[0] && fecha[i] <= fechaInicial) {
                encontrados.push_back(fecha[i]);
                fechaInicial = fecha[i];
            }
            ++i;
        }
        return encontrados;
    }

vector<Fecha> File::getFecha(){
    return fecha;
}

vector<string> File::getNombreDestino(){
    return nombreDestino;
}


/* Valores unicos- ordenar po campos, hacer un ciclo, primer registro mientraas el valor 
no sea diferente elimino hast otro  */
template<class T>
vector<T> File::valoresUnicos(vector<T> vectorBusqueda){
    vector<T> unicos = {vectorBusqueda[0]};
    T valorComparar = vectorBusqueda[0];
    for(int i=0; i < vectorBusqueda.size(); i++){
        if(vectorBusqueda[i] != valorComparar){
            if(i > 0 && vectorBusqueda[i-1] != valorComparar){
                unicos.push_back(vectorBusqueda[i]);
                valorComparar = vectorBusqueda[i];
            }
        }
    }
    return unicos;
}


/* Busqueda por nombre */
void File::busquedaNombre(){
    vector<string> nombres = {"jeffrey.reto.com","betty.reto.com","katherine.reto.com",
    "scott.reto.com","benjamin.reto.com","samuel.reto.com","raymond.reto.com","server.reto.com"};
    for(int i=0; i < nombres.size(); i++){
        int indice = Busqueda<string>::busquedaSecuencial(nombreOrigen, nombres[i]);
        if(indice == -1){
            cout << "El nombre: " << nombres[i] << "|no se encuentra|" << endl;
        }
        else{
            cout << "El nombre: " << nombres[i] << " si se encuentra " << endl;
        }

    }
}


/* Direccion interna */
vector<string> File::direcccionIterna(){
    vector<string> almacena;
    string s1;
    for(int i=0; i < ipOrigen.size(); i++){
        if (ipOrigen[i].size() > 1){
            for(int b=0; b < 10; b++){
                s1.push_back(ipOrigen[i][b]);
            }
            almacena.push_back(s1);
            s1.clear();
        }
        
    }   
    
    return valoresUnicos(almacena);
}

/* Servicio de correo electronico */
void File::correosElectronicos(){
    vector<string> correos = {"gmail.com","hotmail.com","outlook.com","protonmail.com"};
    for(int i=0; i < correos.size(); i++){
        int indice = Busqueda<string>::busquedaSecuencial(nombreDestino, correos[i]);
        if(indice == -1){
            cout << "El nombre: " << correos[i] << "|no se encuentra|" << endl;
        }
        else{
            cout << "El nombre: " << correos[i] << " si se encuentra " << endl;
        }

    }
}

/* Puertos destino debajo del 1000 */
void File::puertosUsados(){
    vector<int> puertos = {};
    int puerto;
    for(int i=0; i < puertoDestino.size(); i++){
        if (puertoDestino[i] != "-"){
            puerto =  stoi(puertoDestino[i]);  
            if(puerto<=1000 && find(puertos.begin(), puertos.end(), puerto) == puertos.end()){
                puertos.push_back(puerto);
            }
        }
    }
    printPuertos(puertos);
}

void File::printPuertos(vector<int> puertos){
    puertos = Ordenamiento<int>::mergesort(puertos,Ordenamiento<int>::asc);
    cout << "Los puertos encontrados debajo del mil son: " << endl;
    for (int i=0; i < puertos.size(); i++){
        if (i == puertos.size()-1){
            cout << puertos[i] << "." << endl;
        }
        else{
            cout << puertos[i] << ", ";
        }  
    }
}