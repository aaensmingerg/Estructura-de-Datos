#include <iostream>
#include <string>
#include <vector>
#include "compra.cpp"

using namespace std;

#pragma once
class ListadoCompras{
    protected:
    vector<Compra> compras;
    vector<Compra> compara(Compra, bool(*)(Compra, Compra));
    public:
    ListadoCompras(){}
    ~ListadoCompras();
    void agregarCompra(Compra);
    vector<Compra> eliminarCompra(string);
    vector<Compra> buscarAntesDeAnio(int);
    vector<Compra> buscarDespuesDeAnio(int);
    vector<Compra> buscarEntreAnios(int, int);
    vector<Compra> buscarAntesDeKilometraje(int);
    vector<Compra> buscarDespuesDeKilometraje(int);
    vector<Compra> buscarEntreKilometrajes(int, int);
    vector<Compra> buscarPorComprador(std::string);
    void ordenar(
                vector<Compra>(*)(vector<Compra>, bool(*)(Compra, Compra)),
                bool(*)(Compra,Compra)
                );
    unsigned long size();
    friend ostream & operator<<(ostream & os, const ListadoCompras & listadoCompras);
};