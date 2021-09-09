#include <iostream>
#include <string>
#include <vector>
#include "compra.cpp"

using namespace std;

/* Se declara la función "getTraccion"
para recuperar el valor de tracción */
class ListadoCompras{
    protected:
    vector<Compra> compras;
    vector<Compra> compara(Compra, bool(*)(Compra, Compra));
    public:
    /*Declaración de constructor vacío*/
    ListadoCompras(){}
    
    /*Se declara el destructor de la clase*/
    ~ListadoCompras();

    /*La función "agregarCompra" recibe un dato
     de tipo Compra y agrega al vector de compras*/
    void agregarCompra(Compra);

    /*La función "eliminarCompra" recibe un valor 
    de tipo string que busca para eliminar del vector*/
    vector<Compra> eliminarCompra(string);
    
    /*La función "buscarAntesDeAnio" recibe un valor 
    de tipo int y busca los registros de años menores al parámetro*/
    vector<Compra> buscarAntesDeAnio(int);
    
    /*La función "buscarDespuesDeAnio" recibe un valor 
    de tipo int y busca los registros de años mayores al parámetro*/
    vector<Compra> buscarDespuesDeAnio(int);
    
    /*La función "buscarEntreAnios" recibe dos valores
     de tipo int y busca los registros cuyos años se encuentren en el intervalo*/
    vector<Compra> buscarEntreAnios(int, int);

    /*La función "buscarAntesDeKilometraje" recibe un valor 
    de tipo int y busca los registros de kilometrajes menores al parámetro*/
    vector<Compra> buscarAntesDeKilometraje(int);
    
    /*La función "buscarDespuesDeKilometraje" recibe un valor de tipo 
    int y busca los registros de kilómetros mayores al parámetro*/
    vector<Compra> buscarDespuesDeKilometraje(int);
    
    /*La función "buscarEntreKilometrajes" recibe dos valores de tipo int 
    y busca los registros cuyos kilómetros se encuentren en el intervalo*/
    vector<Compra> buscarEntreKilometrajes(int, int);
    
    /*La función "buscarPorComprador" recibe un valor de tipo string que 
    busca por comprador */
    vector<Compra> buscarPorComprador(std::string);

    /*La función "ordenar" ordena los elementos del vector*/  
    void ordenar(
                vector<Compra>(*)(vector<Compra>, bool(*)(Compra, Compra)),
                bool(*)(Compra,Compra)
                );
    
    /*La función size regresa el tamaño del vector*/
    unsigned long size();

    /*Sobrecarga del operador "<<" para imprimir todos los elementos del vector*/ 
    friend ostream & operator<<(ostream & os, const ListadoCompras & listadoCompras);
};