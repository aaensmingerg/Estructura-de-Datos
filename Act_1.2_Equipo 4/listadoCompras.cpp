#include <iostream>
#include <string>
#include <vector>
#include "listadoCompras.hpp"

using namespace std;

#pragma once
ListadoCompras::~ListadoCompras(){
    compras.clear();
}

std::vector<Compra> ListadoCompras::compara(Compra buscar, bool(comparador)(Compra, Compra)){
    int i = 0;
    
    std::vector<Compra> encontrados;
    
    long int size = compras.size();
    
    while (i < size) {
        if ( comparador(compras[i], buscar) ) {
            encontrados.push_back(compras[i]);
        }
        ++i;
    }
    
    return encontrados;
}

void ListadoCompras::agregarCompra(Compra compra){
    compras.push_back(compra);
}

vector<Compra> ListadoCompras::eliminarCompra(string marca){
    int i = 0;
    
    vector<Compra> eliminados;
    
    long int size = compras.size();
    
    while (i < size) {
        if ( compras[i].getVehiculoComprado() == marca) {
            eliminados.push_back(compras[i]);
            compras.erase(compras.begin()+i);
        }
        ++i;
    }
    
    return eliminados;
}

vector<Compra> ListadoCompras::buscarAntesDeAnio(int anio){
    Compra buscar;
    //buscar.getAnio()=anio;
    
    return compara(buscar, Compra::compara_anio_asc);
}

vector<Compra> ListadoCompras::buscarDespuesDeAnio(int anio)
{
    Compra buscar;
    //buscar.getAnio() = anio;
    
    return compara(buscar, Compra::compara_anio_desc);
}

vector<Compra> ListadoCompras::buscarEntreAnios(int despues, int antes){
    int i = 0;
    
    vector<Compra> encontrados;
    
    long int size = compras.size();
    
    while (i < size) {
        if (compras[i].getAnio() >= despues && compras[i].getAnio() <= antes) {
            encontrados.push_back(compras[i]);
        }
        ++i;
    }
    
    return encontrados;
}

vector<Compra> ListadoCompras::buscarAntesDeKilometraje(int kilometraje){
    Compra buscar;
    //buscar.getAnio()=anio;
    
    return compara(buscar, Compra::compara_kilometraje_asc);
}

vector<Compra> ListadoCompras::buscarDespuesDeKilometraje(int kilometraje)
{
    Compra buscar;
    //buscar.getAnio() = anio;
    
    return compara(buscar, Compra::compara_kilometraje_desc);
}

vector<Compra> ListadoCompras::buscarEntreKilometrajes(int despues, int antes){
    int i = 0;
    
    vector<Compra> encontrados;
    
    long int size = compras.size();
    
    while (i < size) {
        if (compras[i].getAnio() >= despues && compras[i].getAnio() <= antes) {
            encontrados.push_back(compras[i]);
        }
        ++i;
    }
    
    return encontrados;
}

void ListadoCompras::ordenar(
                        vector<Compra>(* algoritmo)(vector<Compra>, bool(*)(Compra, Compra)),
                        bool(* compara)(Compra, Compra)
)
{
    compras = algoritmo(compras, compara);
}

unsigned long ListadoCompras::size()
{
    return compras.size();
}

void ListadoCompras::printLista(){
    for (int i=0; i<size(); i++){
        Compra compra=compras[i];
        compra.printCompra();
    }
}