#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

class ConexionesSalientes{
    private:
    std::vector<string> ipOrigen;
    std::vector<pair<string,string>> vecIpDestino;
    public:

    /* Constructor de la clase */
    ConexionesSalientes(string iP, File f1){
        vector<string> ipOrigenFile = f1.getIpOrigen();
        vector<string> ipPuertoDestinoFile = f1.getPuertoDestino();
        vector<string> ipDestinoFile = f1.getIpDestino();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == iP){
                ipOrigen.push_back(ipOrigenFile[i]);
                vecIpDestino.push_back(pair<string,string>(ipDestinoFile[i],ipPuertoDestinoFile[i]));
            }
        }   
    }
    
    /* Getter de la queue ipOrigen */
    vector<string> getIPOrigen();

    /* Getter de la queue ipOrigen */
    vector<pair<string,string>> getVecIpDestino();
    
    /* size Regresa el tamaño de la queue ipOrigen */ 
    int size();
};