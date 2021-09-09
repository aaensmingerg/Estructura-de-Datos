#include <iostream>
#include <string>
#include "persona.cpp"
#include "vehiculo.cpp"

using namespace std;
/* Definición de la clase "Compra" */
class Compra{
    protected:
    int monto;
    Persona persona;
    Vehiculo vehiculo;
    public:
    /*Declaración de constructor vacío*/
    Compra(){}
    
    /*Declaración de constructor */
    Compra(int _monto, Persona _persona, Vehiculo _vehiculo):monto(_monto),persona(_persona),vehiculo(_vehiculo){}
    
    /* La función "getMonto" recupera el valor de monto */
    int getMonto();
    
    /* La función "getComprador" recupera el valor de comprador */
    string getComprador();
    
    /* La función "getDirección comprador" recupera el valor de la direccionComprador*/
    Persona getDireccionComprador();
    
    /* La función "getVehiculoComprado" recupera el valor de VehiculoComprado */
    string getVehiculoComprado();
    
    /* La función "getDireccionVehiculoComprado" recupera el valor de VehiculoComprado*/
    Vehiculo getDireccionVehiculoComprado();
    
    /* La función "getAnoo" recupera el valor de Anio*/
    int getAnio();
    
    /* La función "getKilometraje" recupera el valor de kilometraje */
    int getKilometraje();
    
    /* La función "compara_anio_asc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el año del primer valor es mayor que el año del segundo valor */
    static bool compara_anio_asc(Compra, Compra);
    
    /* La función "compara_anio_desc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el año del primer valor es menor que el año del segundo valor */
    static bool compara_anio_desc(Compra, Compra);
    
    /* La función "compara_anio_eq" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el año del primer valor es igual que el año del segundo valor */
    static bool compara_anio_eq(Compra, Compra);
    
    
    /* La función "compara_kilometraje_asc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el kilometraje del primer valor es mayor que el kilometraje del segundo valor */
    static bool compara_kilometraje_asc(Compra, Compra);
    
    /* La función "compara_kilometraje_desc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el kilometraje del primer valor es menor que el kilometraje del segundo valor */
    static bool compara_kilometraje_desc(Compra, Compra);
    
    /* La función "compara_kilometraje_eq" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el kilometraje del primer valor es igual que el kilometraje del segundo valor */
    static bool compara_kilometraje_eq(Compra, Compra);

    /* Se sobre carga el operador "<<" para imprimir los resultados en el formato: vehículo,persona */
    friend std::ostream & operator<<(std::ostream & os, const Compra & compra);
};