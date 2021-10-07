#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

class ConexionesSalientes{
    private:
    std::string fileName;
    std::queue<string> ipOrigen;
    public:
    ConexionesSalientes(string fileName_){
        fileName = fileName_;
        std::string line,word;
        std::string row[8];
        std::ifstream file;
        int j = 0;
        file.open(fileName);
        while(getline(file, line)){
            stringstream sS(line);
            int i = 0;
            while(getline(sS, word, ',')){
                row[i] = word;
                i++;
            }
            ipOrigen.push(row[2]);
            j++;
        }
        file.close();
    }
    queue<string> getIPOrigen(){
        return ipOrigen;
    }
};