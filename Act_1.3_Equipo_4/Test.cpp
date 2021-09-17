#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Persona{
    protected:
    string fecha,hora,ipOrigen,puertoOrigen,nombreOrigen,ipDestino,puertoDestino,nombreDestino;
    int number = 1;
    public:

    /* Constructor de la clase 
    Persona(string fecha_, string hora_, string ipOrigen_,
    string puertoOrigen_, string nombreOrigen_, string ipDestino_,
    string puertoDestino_, string nombreDestino_){
        fecha = fecha_;
        hora = hora_;
        ipOrigen = ipOrigen_;
        puertoOrigen = puertoOrigen_;
        nombreOrigen = nombreOrigen_;
        ipDestino = ipDestino_;
        puertoDestino = puertoDestino_;
        nombreDestino = nombreDestino_;
    }*/
    
    string getFecha(){
        return fecha;
    }
    /* Set variable fecha*/
    void setFecha(string fecha_){
        fecha = fecha_;
    }
    /* Set variable hora*/
    void setHora(string hora_){
        hora = hora_;
    }
    /* Set variable ipOrigen*/
    void setIpOrigen(string ipOrigen_){
        ipOrigen = ipOrigen_;
    }
    /* Set variable puertoOtrigen*/
    void setPuertoOrigen(string puertoOrigen_){
        puertoOrigen = puertoOrigen_;
    }
    /* Set variable nombreOrigen*/
    void setNombreOrigen(string nombreOrigen_){
        nombreOrigen = nombreOrigen_;
    }
    /* Set variable ipDestino*/
    void setIpDestino(string ipDestino_){
        ipDestino = ipDestino_;
    }
    /* Set variable puertoDestino*/
    void setPuertoDestino(string puertoDestino_){
        puertoDestino = puertoDestino_;
    }
    /* Set variable nombreDestino*/
    void setNombreDestino(string nombreDestino_){
        nombreDestino = nombreDestino_;
    }

    void printInfo(){
        cout << fecha << endl;
        cout << hora << endl;
        cout << ipOrigen << endl;
        cout << puertoOrigen << endl;
        cout << nombreOrigen << endl;
        cout << ipDestino << endl;
        cout << puertoDestino << endl;
        cout << nombreDestino << endl;
    }
    friend bool operator >= (Persona const &c1, Persona const &c2){
        string s1,s2;
        char a = c1.fecha[0];
        char b = c1.fecha[1];
        s1.push_back(a);
        s1.push_back(b);

        char c = c2.fecha[0];
        char d = c2.fecha[1];
        s2.push_back(c);
        s2.push_back(d);
        
        int i1 = stoi(s1);
        int i2 = stoi(s2);
        return i1 >= i2;
    }

};

class File{
    protected:
        string fileName;
        vector<string> fecha,hora,ipOrigen,puertoOrigen,nombreOrigen,ipDestino,puertoDestino,nombreDestino;
    public:
    /* Constructor de la clase*/
    File(string fileName_){
        fileName = fileName_;
        string line,word;
        string row[8];
        ifstream file;
        int j = 0;
        file.open(fileName);
        while(getline(file, line)){
            stringstream sS(line);
            int i = 0;
            while(getline(sS,word,',')){
                row[i] = word;
                i++;
            }
            fecha.push_back(row[0]);
            hora.push_back(row[1]);
            ipOrigen.push_back(row[2]);
            puertoOrigen.push_back(row[3]);
            nombreOrigen.push_back(row[4]);
            ipDestino.push_back(row[5]);
            puertoDestino.push_back(row[6]);
            nombreDestino.push_back(row[7]);
            j++;
        }
        file.close();
        }

        /* Get variable fecha*/
        string getFecha(int i ){
            return fecha[i];
        }
        /* get variable hora*/
        string getHora(int i){
            return hora[i];
        }
        /* Get variable ipOrigen*/
        string getIpOrigen(int i){
            return ipOrigen[i];
        }
        /* Get variable puertoOtrigen*/
        string getPuertoOrigen(int i){
            return puertoOrigen[i];
        }
        /* Get variable nombreOrigen*/
        string getNombreOrigen(int i){
            return nombreOrigen[i];
        }
        /* Get variable ipDestino*/
        string getIpDestino(int i){
            return ipDestino[i];
        }
        /* get variable puertoDestino*/
        string getPuertoDestino(int i){
            return puertoDestino[i];
        }
        /* Get variable nombreDestino*/
        string getNombreDestino(int i){
            return nombreDestino[i];
        }

        /* Regresa el tamaño del vector fecha */
        int getSizeFecha(){
            return fecha.size();
        }

        /* imprimir los valores del vector fecha */
        void Print_info(){
            for (int i = 0; i <= fecha.size(); i++){
                cout <<"Fecha "<<i<<": "<<fecha[i]<<endl;
            }
        }
};

int main(){
    File f1("equipo4.csv");
    vector<Persona> listaPersonas(f1.getSizeFecha());
    for(int i=0; i < f1.getSizeFecha(); i++){
        listaPersonas[i].setFecha(f1.getFecha(i));
        listaPersonas[i].setHora(f1.getHora(i));
        listaPersonas[i].setIpOrigen(f1.getIpOrigen(i));
        listaPersonas[i].setPuertoOrigen(f1.getPuertoOrigen(i));
        listaPersonas[i].setNombreOrigen(f1.getNombreOrigen(i));
        listaPersonas[i].setIpDestino(f1.getIpDestino(i));
        listaPersonas[i].setPuertoDestino(f1.getPuertoDestino(i));
        listaPersonas[i].setNombreDestino(f1.getNombreDestino(i));
    }
    bool test = listaPersonas[0] >= listaPersonas[1];
    cout << test;
}
