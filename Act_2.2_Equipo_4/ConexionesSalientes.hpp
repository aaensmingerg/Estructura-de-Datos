#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

class ConexionesSalientes{
    private:
    std::queue<string> ipOrigen;
    public:
    ConexionesSalientes(string iP, File f1){
        vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == iP){
                ipOrigen.push(ipOrigenFile[i]);
            }
        }   
    }
    queue<string> getIPOrigen(){
        return ipOrigen;
    }
    int size(){
        return ipOrigen.size();
    }
};