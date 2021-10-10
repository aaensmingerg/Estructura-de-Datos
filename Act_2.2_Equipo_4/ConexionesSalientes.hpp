#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include "File.hpp"
using namespace std;

class ConexionesSalientes{
    private:
    string fileName;
    queue<string> ipOrigen;
    string ipComp = "172.17.230";
    public:
    ConexionesSalientes(string iP, File f1){
        vector<string> ipOrigenFile = f1.getIpOrigen();
        for(int i=0; i < iP.size(); i++){
            ipComp.push_back(iP[i]);
        }
        for(int i=0; i < ipOrigenFile.size(); i++){
            if(ipOrigenFile[i] == ipComp){
                ipOrigen.push(ipOrigenFile[i]);
            }
        }   
    }
    queue<string> getIPOrigen(){
        return ipOrigen;
    }
};