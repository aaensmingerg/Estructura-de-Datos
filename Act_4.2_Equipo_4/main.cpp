/* Este programa es capaz de leer un archivor csv 
y responder a las preguntas requeridas en la entrega 3.2 
de la situación problema, principalmente la obtención de 
los top 5 de sitios con más conexiones por día de utilizando 
algoritmos de búsqueda y ordenamiento según requeridos,
árboles binarios de búsqueda (BST) así como HashMaps.
Aquiles Ensminger A01781243 y Javier Lozano A01029756
Fecha de Entrega: Domingo 21 de Noviembre de 2021 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
#include <iterator>
#include <queue>
#include "Graph.hpp"
#include "File.cpp"
#include "Ordenamiento.hpp"


/* En este caso la función main es la encargada de responder a todas las preguntas*/
int main(){
    /* Lectura del archivo csv */
    File f1("equipo4.csv");
    string ipA = "172.17.230.22";
    vector< pair<Fecha, Graph<string,int> * > > grafos = f1.vectorGrafos();
    vector< pair<Fecha,int> > conexionesA;
    vector< pair<Fecha, pair< Vertex<string,int> *, int> > >maxConeciones;
    
    cout << "--- 1. Determina la cantidad de computadoras con las que se ha conectado A por dia. ---" << endl;
    for (auto par : grafos){
        int max = 0;
        int contador = 0;

        Vertex<string,int> * maxVertex;
        vector< Vertex<string,int> * > nodos = par.second->getNodes();
        for (auto nodo : nodos){
            if (nodo->getEdges()->size() > max){
                maxVertex = nodo;
                max = nodo->getEdges()->size();
            }
            if (nodo->getInfo() == ipA){
                cout << "La computadora -> " << ipA << " se conecto con: " << nodo->getEdges()->size() << " computadoras";
                cout << " en la fecha -> " << par.first << endl;
            }
            else{
                vector< Edge<string,int>* > * conexiones = nodo->getEdges();
                for (auto conexion : *conexiones){
                    if (conexion->getTarget()->getInfo() == ipA){
                        contador++;
                    }
                }
            }
            
        }
        maxConeciones.push_back(make_pair(par.first,make_pair(maxVertex,max)));
        conexionesA.push_back(make_pair(par.first,contador));

    }
    
    cout << endl << "--- 1.1 ¿Es el vertice: " << ipA << " el que mas conexiones salientes tiene hacia la red interna?  " << endl;
    for (auto maxC : maxConeciones){
        if (maxC.second.first->getInfo() == ipA){
            cout << "Si, en En la fecha: " << maxC.first << " La ip A es la computadora con mas conexiones. Tiene (" << maxC.second.second << ") " << endl;
        }
        else{
            cout << "No, La computadora com mas conexiones en el dia -> " << maxC.first << " Es la computadora: " << maxC.second.first->getInfo();
            cout << " con (" << maxC.second.second << ") conexiones" << endl;
        }
    }
    cout << endl << " --- 2. Ubica la cantidad de computadoras que se han conectado hacia A por día --- " << endl;
    if (conexionesA.size() == 0 ){
        cout << "No hay conexiones de otras computadoras hacia " << ipA << endl;
    }
    else{
        for(auto a : conexionesA){
            cout << "En la fecha -> " << a.first << " hubieron (" << a.second <<") Conexiones" <<  endl;
        }
    }   
    
    return 0;
}

