#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Ordenamiento.hpp"
using namespace std;

class Fecha{
    private:
        int dia, mes,anio;
    public:
        Fecha(int dia_, int mes_, int anio_){
            dia = dia_;
            mes = mes_;
            anio = anio_;
        }
        Fecha(string fecha_){
            string s1;
            bool index = false;
            s1.push_back(fecha_[0]);
            s1.push_back(fecha_[1]);
            dia = stoi(s1); 

            string s2;
            s2.push_back(fecha_[3]);
            if (stoi(s2) == 1){
                cout<<s2;
                if (fecha_[4] != '-')
                index = true;
                s2.push_back(fecha_[4]);
            }
            mes = stoi(s2); 

            string s3;
            char a3,b3,c3,d3;
            if (index){
                a3 = fecha_[6];
                b3 = fecha_[7];
                c3 = fecha_[8];
                d3 = fecha_[9];
            }
            else{
                a3 = fecha_[5];
                b3 = fecha_[6];
                c3 = fecha_[7];
                d3 = fecha_[8];
            }
            s3.push_back(a3);
            s3.push_back(b3);
            s3.push_back(c3);
            s3.push_back(d3);
            anio = stoi(s3);
        }
        
        int getDia();
        
        int getMes();

        int getAnio();

        friend bool operator > (Fecha const &f1, Fecha const &f2){
            return f1.dia > f2.dia;
        }
        friend bool operator <= (const Fecha &f1, const Fecha &f2){
            return f1.dia <= f2.dia;
        }
        friend bool operator != (const Fecha &f1, const Fecha &f2){
            return f1.dia != f2.dia;
        }
        friend ostream& operator << (ostream &o, const Fecha &f1){
            o << f1.dia <<"-" << f1.mes << "-" << f1.anio << endl;
            return o;
        }
        
};