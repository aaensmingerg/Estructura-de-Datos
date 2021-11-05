#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;

class Conexiones{
    private:
        string iP;
        int frecuencia;
    public:
        Conexiones(string ip, int frec){
            iP = ip;
            frecuencia = frec;
        }

        string getIp(){
            return iP;
        }

        int getFrecuencia(){
            return frecuencia;
        }

        /* Sobrecarga de Operador "<" */
        friend bool operator < (const Conexiones &c1, const Conexiones &c2){
            return c1.frecuencia < c2.frecuencia;
        }

        /* Sobrecarga de Operador ">" */
        friend bool operator > (const Conexiones &c1, const Conexiones &c2){
            return c1.frecuencia > c2.frecuencia;
        }       

};