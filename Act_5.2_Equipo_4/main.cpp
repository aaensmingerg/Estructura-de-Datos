#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include "File.cpp"
#include "ConexionesComputadora.cpp"


int main(){
    /* Inicializar objeto con datos del archivo*/
    File f1("equipo4.csv");

    /* Declarar vector de dominios para busqueda */
    std::vector<string> dominiosFile = f1.getNombreDestino();
    
    /* Declarar vector con direccion ip destino */
    std::vector<string> ipDestino = f1.getIpDestino();

    /* Declarar vector con direccion ip origen */
    std::vector<string> ipOrigen = f1.getIpOrigen();

    /* Inicializar conjunto de dominios */
    std::set<string> dominios;

    /* Conjunto de IP */
    std::set<string> iP;

    /* Inicializar mapa con ip*/
    std::map<string,string> mapDominios;

    /* Inicializar conjunto con ip de reto.com*/
    std::set<string> ipDominiosReto;

    /* Inicializar mapa para conexiones computadora */
    std::map<string,ConexionesComputadora*> mapConexiones;
    
    /* Recorrer el vector con los dominios */
    for (int i=0; i < dominiosFile.size(); i++){
        
        if (dominiosFile[i] != "reto.com" && dominiosFile[i] != "-"){
            /* Insertar en el conjunto*/
            dominios.insert(dominiosFile[i]);
        }
        else{
            ipDominiosReto.insert(ipDestino[i]);
        }
        /* Insertar en el mapa */
        mapDominios.insert(pair<string,string>(dominiosFile[i],ipDestino[i]));
        

    }

    /* Crear conjunto con todas las direcciones IP */
    for(int i=0; i < ipDestino.size(); i++){
        iP.insert(ipDestino[i]);
        iP.insert(ipOrigen[i]);
    }

    /* Insertar conexiones computadora al mapa */
    for(auto ip : iP){
        mapConexiones.insert(pair<string,ConexionesComputadora*>(ip, new ConexionesComputadora(ip,f1)));
    }


    /* Mostrar los elementos del conjunto 
    for (auto a:dominios){
        std::cout << a << std::endl;
    }
    */    
   
    std::cout << "--- Hay algun nombre de dominio en el conjunto que sea anomalo ---  " << std::endl;
    std::cout << "R. " << std::endl;
    std::string domAnomalo1 = "nyvbcosk2llkngjncf9o.net";
    std::string domAnomalo2 = "kdkkgs7z6ptuhv2f8jub.ru";
    std::cout << "1. " << domAnomalo1 << std::endl << "2. " << domAnomalo2 << std::endl;

    std::cout << "--- De los nombres de dominio encontrados en el paso anterior, ¿cual es su IP?---  " << std::endl;
    std::cout << "R. " << std::endl;
    std::cout << "Dominio: " << domAnomalo1 << " --> IP: " << mapDominios[domAnomalo1] << std::endl;
    std::cout << "Dominio: " << domAnomalo2 << " --> IP: " << mapDominios[domAnomalo2] << std::endl;

    std::cout << std::endl <<  "--- De las computadoras pertenecientes al dominio reto.com determina la cantidad de IPs que tienen al menos una conexin entrante. ---  " << std::endl;
    std::cout << "R. " << std::endl;
    for (auto ip : ipDominiosReto){
        int entrantesTotales = mapConexiones[ip]->entrantesTotales();
        if (entrantesTotales > 1 && ip != "1.1.1.1"){
            std::cout << ip << " (" << entrantesTotales << ") conexiones entrantes " << std::endl;
        }

    }
    
    return 0;
}