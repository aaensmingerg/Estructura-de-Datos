#include <iostream>
#include <string>
#include "compra.hpp"

using namespace std;

#pragma once
int Compra::getMonto(){
    return monto;
}

string Compra::getComprador(){
    return persona->getNombre();
}

Persona* Compra::getDireccionComprador(){
    return persona;
}

string Compra::getVehiculoComprado(){
    return vehiculo->getMarca();
}

Vehiculo* Compra::getDireccionVehiculoComprado(){
    return vehiculo;
}

int Compra::getAnio(){
    return vehiculo->getModelo();
}

int Compra::getKilometraje(){
    return vehiculo->getKilometraje();
}

void Compra::setAnio(int _anio){
    vehiculo->setModelo(_anio);
}

void Compra::setKilometraje(int _kilometraje){
    vehiculo->setKilometraje(_kilometraje);
}

void Compra::setNombre(string _nombre){
    persona->setNombre(_nombre);
}

void Compra::setApellido(string _apellido){
    persona->setApellido(_apellido);
}

bool Compra::compara_anio_asc(Compra a, Compra b){
    return a.getAnio() < b.getAnio();
}

bool Compra::compara_anio_desc(Compra a, Compra b){
    return a.getAnio() > b.getAnio();
}

bool Compra::compara_kilometraje_asc(Compra a, Compra b){
    return a.getKilometraje() < b.getKilometraje();
}

bool Compra::compara_kilometraje_desc(Compra a, Compra b){
   return a.getKilometraje() > b.getKilometraje();
}

bool Compra::compara_comprador_eq(Compra a, Compra b){
   return a.getComprador() == b.getComprador();
}

void Compra::printCompra(){
    persona->printPersona();
    vehiculo->printVehiculo();
}