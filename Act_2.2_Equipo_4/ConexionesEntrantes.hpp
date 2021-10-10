#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <queue>
#include "File.hpp"
using namespace std;
class ConexionesEntrantes{
    private:
    string fileName;
    stack<string> ipDestino;
    string ipComp = "172.17.230";
    public:
    ConexionesEntrantes(string iP, File f1){
        vector<string> ipDestinoFile = f1.getIpDestino();
        for(int i=0; i < iP.size(); i++){
            ipComp.push_back(iP[i]);
        }
        for(int i=0; i < ipDestinoFile.size(); i++){
            if(ipDestinoFile[i] == ipComp){
                ipDestino.push(ipDestinoFile[i]);
            }
        } 
    }
    stack<string> getIPDestino(){
        return ipDestino;
    }
};