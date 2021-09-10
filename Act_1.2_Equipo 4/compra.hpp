#include <iostream>
#include <string>
#include "persona.cpp"
#include "vehiculo.cpp"
using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class Compra{
    protected:
    int monto;
    Persona* persona;
    Vehiculo* vehiculo;
    public:
    friend class Vehiculo;
    friend class Persona;

    /*Declaración de constructor */
    Compra():persona(new Persona), vehiculo(new Vehiculo){}
    
    /*Declaración de constructor */
    Compra(int _monto, Persona* _persona, Vehiculo* _vehiculo):monto(_monto),persona(_persona),vehiculo(_vehiculo){}
    
    /* La función "getMonto" recupera el valor de monto */
    int getMonto();
    
    /* La función "getComprador" recupera el valor de comprador */
    string getComprador();
    
    /* La función "getDirección comprador" recupera el valor de la direccionComprador*/
    Persona* getDireccionComprador();
    
    /* La función "getVehiculoComprado" recupera el valor de VehiculoComprado */
    string getVehiculoComprado();
    
    /* La función "getDireccionVehiculoComprado" recupera el valor de VehiculoComprado*/
    Vehiculo* getDireccionVehiculoComprado();
    
    /* La función "getAnoo" recupera el valor de Anio*/
    int getAnio();
    
    /* La función "getKilometraje" recupera el valor de kilometraje */
    int getKilometraje();

    /* Declaración del Set de la variable anio*/
    void setAnio(int);
    /*Declaración del Set de la variable kilometraje*/
    void setKilometraje(int);
    /*Declaración del Set de la variable nombre*/
    void setNombre(string);
    /*Declaración Set de la variable apellido*/
    void setApellido(string);


    
    /* La función "compara_anio_asc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el año del primer valor es mayor que el año del segundo valor */
    static bool compara_anio_asc(Compra, Compra);
    
    /* La función "compara_anio_desc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el año del primer valor es menor que el año del segundo valor */
    static bool compara_anio_desc(Compra, Compra);
    
    
    /* La función "compara_kilometraje_asc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el kilometraje del primer valor es mayor que el kilometraje del segundo valor */
    static bool compara_kilometraje_asc(Compra, Compra);
    
    /* La función "compara_kilometraje_desc" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el kilometraje del primer valor es menor que el kilometraje del segundo valor */
    static bool compara_kilometraje_desc(Compra, Compra);
    
    /* La función "compara_kilometraje_eq" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el kilometraje del primer valor es igual que el kilometraje del segundo valor */
    static bool compara_kilometraje_eq(Compra, Compra);
    
    /* La función "compara_comprador_eq" tiene como argumento dos valores de tipo compra
    sobre los cuales compara si el comprador del primer valor es igual que el comprador del segundo valor */
    static bool compara_comprador_eq(Compra, Compra);

    /* La función "printCompra" imprime la información de la compra*/
    void printCompra();

};