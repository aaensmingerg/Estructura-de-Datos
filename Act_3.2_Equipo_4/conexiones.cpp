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
        int diasSeguidos;
        int diasAparece;
    public:
        Conexiones(){
            iP = "";
            frecuencia = 0;
        }
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

        void setDiasSeguidos(int dias){
            diasSeguidos = dias;
        }

        int getDiasSeguidos(){
            return diasSeguidos;
        }

        void setDiasAparece(int dias){
            diasAparece = dias;
        }

        int getDiasAparece(){
            return diasAparece;
        }


        /* Sobrecarga de Operador "<" */
        friend bool operator < (const Conexiones &c1, const Conexiones &c2){
            return c1.frecuencia < c2.frecuencia;
        }

        /* Sobrecarga de Operador ">" */
        friend bool operator > (const Conexiones &c1, const Conexiones &c2){
            return c1.frecuencia > c2.frecuencia;
        } 

        /* Sobrecarga de Operador "==" */
        friend bool operator == (const Conexiones &c1, const Conexiones &c2){
            return c1.iP == c2.iP;
        }      

        /* Sobrecarga de Operador "<<" */
        friend ostream& operator << (ostream &o, const Conexiones &c1){
            o << "iP: " <<c1.iP << " Frecuencia: "<< c1.frecuencia;
            return o;
        }

};