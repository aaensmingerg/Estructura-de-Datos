#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class ConexionesEntrantes{
    private:
    stack<string> ipDestino;
    public:
    
    /* Constructor de la clase */
    ConexionesEntrantes(string iP, File f1){
         vector<string> ipDestinoFile = f1.getIpDestino();
         vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == iP){
                ipDestino.push(ipDestinoFile[i]);
            }
        } 
    }

    /* Getter del stack ipDestino */
    stack<string> getIPDestino();

    /* size regresa el tamaño del stack ipDestino */
    int size();
    
};