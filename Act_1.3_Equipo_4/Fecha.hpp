#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Ordenamiento.hpp"
using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class Fecha{
    private:
        int dia, mes,anio;
    public:
        /* Se declara el constructor vacio de la clase */
        Fecha(){}
        /* Se declara el constructor de la clase */
        Fecha(string fecha_){
            string s1;
            string s2;
            string s3;
            for (int i = 0; i < fecha_.size(); i++){
                if (i == 0 || i == 1){
                    s1.push_back(fecha_[i]);
                }
                else if (i == 3 || i == 4 && fecha_[i] != '-'){
                    s2.push_back(fecha_[i]);
                }
                else if (i >= 5 && i <= 8){
                    s3.push_back(fecha_[i]);
                }
            }
            dia = stoi(s1);
            mes = stoi(s2);
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
        friend bool operator == (const Fecha &f1, const Fecha &f2){
            return f1.dia == f2.dia;
        }
        friend ostream& operator << (ostream &o, const Fecha &f1){
            o << f1.dia <<"-" << f1.mes << "-" << f1.anio;
            return o;
        }
        
};