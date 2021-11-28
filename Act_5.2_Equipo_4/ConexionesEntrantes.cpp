
#include "ConexionesEntrantes.hpp"
using namespace std;

template<class T>
vector<T> ConexionesEntrantes::valoresUnicos(vector<T> vectorBusqueda){
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

vector<string> ConexionesEntrantes::getEntrantesUnicas(){
    vector<string> dummy = vecIpOrigen;
    sort(dummy.begin(), dummy.end(), Ordenamiento<string>::asc);
    return valoresUnicos(dummy);
}

stack<string> ConexionesEntrantes::getIpOrigen(){
    return ipOrigen;
}

int ConexionesEntrantes::size(){
    return ipOrigen.size();
}