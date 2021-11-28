#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <queue>
#include "Ordenamiento.hpp"
using namespace std;

class ConexionesEntrantes{
    private:
    stack<string> ipOrigen;
    vector<string> vecIpOrigen;
    public:
    
    /* Constructor de la clase */
    ConexionesEntrantes(string iP, File f1){
         vector<string> ipDestinoFile = f1.getIpDestino();
         vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipDestinoFile[i] == iP){
                ipOrigen.push(ipOrigenFile[i]);
                vecIpOrigen.push_back(ipOrigenFile[i]);
            }
        } 
    }

    template<class T>
    vector<T> valoresUnicos(vector<T>);

    /* Imprime las ip de las conexiones entrantes */
    vector<string> getEntrantesUnicas();

    /* Getter del stack ipDestino */
    stack<string> getIpOrigen();

    /* size regresa el tamaño del stack ipDestino */
    int size();
    
};