#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <queue>


class ConexionesEntrantes{
    private:
    std::stack<string> ipDestino;
    public:
    ConexionesEntrantes(string iP, File f1){
         vector<string> ipDestinoFile = f1.getIpDestino();
         vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == iP){
                ipDestino.push(ipDestinoFile[i]);
            }
        } 
    }
    stack<string> getIPDestino(){
        return ipDestino;
    }
    int size(){
        return ipDestino.size();
    }
};