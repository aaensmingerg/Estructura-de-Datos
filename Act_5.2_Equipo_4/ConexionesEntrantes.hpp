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
    stack<string> ipDestino;
    vector<pair<string,string>> vecIpDestino;
    public:
    
    /* Constructor de la clase */
    ConexionesEntrantes(string iP, File f1){
         vector<string> ipDestinoFile = f1.getIpDestino();
         vector<string> ipPuertoDestinoFile = f1.getPuertoDestino();
         vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipDestinoFile[i] == iP){
                ipDestino.push(ipDestinoFile[i]);
                vecIpDestino.push_back(pair<string,string>(ipDestinoFile[i],ipPuertoDestinoFile[i]));
            }
        } 
    }

    template<class T>
    vector<T> valoresUnicos(vector<T>);

    /* Imprime las ip de las conexiones entrantes */
    vector<string> getEntrantesUnicas();

    /* Getter del stack ipDestino */
    stack<string> getIpDestino();

    vector<pair<string,string>> getVecIpDestino();

    /* size regresa el tamaño del stack ipDestino */
    int size();
    
};