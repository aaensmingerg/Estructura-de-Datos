#include <iostream>
#include <string>
#include "persona.cpp"
#include "vehiculo.cpp"

using namespace std;

class Compra{
    protected:
    int monto;
    Persona persona;
    Vehiculo vehiculo;
    public:
    Compra(){}
    Compra(int _monto, Persona _persona, Vehiculo _vehiculo):monto(_monto),persona(_persona),vehiculo(_vehiculo){}
    int getMonto();
    string getComprador();
    Persona getDireccionComprador();
    string getVehiculoComprado();
    Vehiculo getDireccionVehiculoComprado();
    int getAnio();
    int getKilometraje();

    static bool compara_anio_asc(Compra, Compra);
    static bool compara_anio_desc(Compra, Compra);
    static bool compara_anio_eq(Compra, Compra);

    static bool compara_kilometraje_asc(Compra, Compra);
    static bool compara_kilometraje_desc(Compra, Compra);
    static bool compara_kilometraje_eq(Compra, Compra);

    friend std::ostream & operator<<(std::ostream & os, const Compra & compra);
};