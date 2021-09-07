#include <iostream>
#include <string>
#include "compra.hpp"

using namespace std;


int Compra::getMonto(){
    return monto;
}

string Compra::getComprador(){
    return persona.getNombre();
}

Persona Compra::getDireccionComprador(){
    return persona;
}

string Compra::getVehiculoComprado(){
    return vehiculo.getMarca();
}

Vehiculo Compra::getDireccionVehiculoComprado(){
    return vehiculo;
}

int Compra::getAnio(){
    return vehiculo.getModelo();
}

int Compra::getKilometraje(){
    return vehiculo.getKilometraje();
}

bool Compra::compara_anio_asc(Compra a, Compra b){
    return a.getAnio() < b.getAnio();
}

bool Compra::compara_anio_desc(Compra a, Compra b){
    return a.getAnio() > b.getAnio();
}

bool Compra::compara_anio_eq(Compra a, Compra b){
    return a.getAnio() == b.getAnio();
}

bool Compra::compara_kilometraje_asc(Compra a, Compra b){
    return a.getKilometraje() < b.getKilometraje();
}

bool Compra::compara_kilometraje_desc(Compra a, Compra b){
   return a.getKilometraje() > b.getKilometraje();
}

bool Compra::compara_kilometraje_eq(Compra a, Compra b){
   return a.getKilometraje() == b.getKilometraje();
}

ostream & operator<<(ostream & os, const Compra & compra){
    os << compra.vehiculo;
    os << compra.persona << " ";
    os << endl;
    
    return os;
}