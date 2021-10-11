#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

class ConexionesSalientes{
    private:
    std::queue<string> ipOrigen;
    public:

    /* Constructor de la clase */
    ConexionesSalientes(string iP, File f1){
        vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == iP){
                ipOrigen.push(ipOrigenFile[i]);
            }
        }   
    }
    
    /* Getter de la queue ipOrigen */
    queue<string> getIPOrigen();
    
    /* size Regresa el tamaño de la queue ipOrigen */ 
    int size();
};