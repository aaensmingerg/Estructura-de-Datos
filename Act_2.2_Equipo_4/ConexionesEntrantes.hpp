#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <queue>


class ConexionesEntrantes{
    private:
    std::string fileName;
    std::stack<string> ipDestino;
    public:
    ConexionesEntrantes(string fileName_){
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
            ipDestino.push(row[5]);
            j++;
        }
        file.close();
    }
    stack<string> getIPDestino(){
        return ipDestino;
    }
};