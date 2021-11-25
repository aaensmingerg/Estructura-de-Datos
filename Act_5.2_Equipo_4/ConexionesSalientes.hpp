#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

class ConexionesSalientes{
    private:
    std::queue<string> ipDestino;
    public:

    /* Constructor de la clase */
    ConexionesSalientes(string iP, File f1){
        vector<string> ipOrigenFile = f1.getIpOrigen();
        vector<string> ipDestinoFile = f1.getIpDestino();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == iP){
                ipDestino.push(ipDestinoFile[i]);
            }
        }   
    }
    
    /* Getter de la queue ipOrigen */
    queue<string> getIPOrigen();
    
    /* size Regresa el tamaño de la queue ipOrigen */ 
    int size();
};