#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "File.hpp"
#include "Busqueda.hpp"
#include "Ordenamiento.hpp"
#include <algorithm>
using namespace std;
        

Fecha File::buscarSegundaFecha(){
        int encontrados;
        int inicial;
        Fecha fechaInicial = fecha[0];
        Fecha fechaBuscar;
        for (int i = 0; i < fecha.size(); i++){
            if (fecha[i] != fechaInicial){
                inicial = i;
                fechaBuscar = fecha[i];
                break;
            }
        }
        while (fecha[inicial] == fechaBuscar){
            encontrados++;
            inicial++;
        }
        cout << encontrados << endl;
        return fechaBuscar;
    }

vector<Fecha> File::getFecha(){
    return fecha;
}

vector<string> File::getNombreDestino(){
    return nombreDestino;
}

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

template<class T>
vector<T> File::valoresUnicosDia(vector<T> vectorBusqueda,Fecha dia){
    vector<T> unicos = {vectorBusqueda[0]};
    T valorComparar = vectorBusqueda[0];
    for(int i=0; i < vectorBusqueda.size(); i++){
        if(vectorBusqueda[i] != valorComparar && fecha[i] == dia){
            if(i > 0 && vectorBusqueda[i-1] != valorComparar){
                unicos.push_back(vectorBusqueda[i]);
                valorComparar = vectorBusqueda[i];
            }
        }
    }
    return unicos;
}

void File::busquedaNombre(){
    vector<string> nombres = {"jeffrey.reto.com","betty.reto.com","katherine.reto.com",
    "scott.reto.com","benjamin.reto.com","samuel.reto.com","raymond.reto.com","server.reto.com"};
    for(int i=0; i < nombres.size(); i++){
        int indice = Busqueda<string>::busquedaSecuencial(nombreOrigen, nombres[i]);
        if(indice == -1){
            cout << "El nombre: " << nombres[i] << " |no se encuentra|" << endl;
        }
        else{
            cout << "El nombre: " << nombres[i] << " |si se encuentra| " << endl;
        }

    }
}

void File::printNombresUnicos(){
    vector<string> dummy = nombreOrigen;
    sort(dummy.begin(), dummy.end(), Ordenamiento<string>::asc);
    vector<string> unico;
    unico = valoresUnicos(dummy);
    for(int i=0; i < unico.size(); i++){
        cout << "Nombre Registrado: " << unico[i] << endl;
    }
}
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

void File::correosElectronicos(){
    vector<string> dummy = nombreDestino;
    sort(dummy.begin(), dummy.end(), Ordenamiento<string>::asc);
    vector<string> unico;
    unico = valoresUnicos(dummy);
    for(int i=0; i < unico.size(); i++){
        cout << "Direccion registrada: " << unico[i] << endl; 
    }
}

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

map<string,int> File::conexionesPorDia(string dia_){
    
    map<string,int> conexiones;
    Fecha dia = Fecha(dia_);
    vector<string> ipDestinoUnicos = valoresUnicosDia(ipDestino,dia);
    int f = 0;
    
    /* Recorrer la lista de direcciones por cada direccion en la lista*/
    for(int i=0; i < ipDestinoUnicos.size(); i++){
        int contador = 0;
        /* recorrer la lista de direcciones buscando el dia y la conexion dada*/
        for (int i=0; i <fecha.size(); i ++){

            /* Comprobar que sea el mismo dia y misma conexion*/
            if (fecha[i] == dia && ipDestino[i] == ipDestinoUnicos[f] && ipDestino[i] != "-"){
                contador ++;
            }
        }
        /* Insertar en el mapa */
        conexiones.insert(pair<string,int>(ipDestinoUnicos[f],contador));
        f ++;
    }

    return conexiones;

}
