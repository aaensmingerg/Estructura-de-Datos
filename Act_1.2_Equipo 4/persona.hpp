#include <iostream>
#include <string>

using namespace std;

class Persona{
    protected:
    string nombre;
    string apellido;
    string ine;
    public:
    Persona(){}
    Persona(string _nombre,string _apellido, string _ine):nombre(_nombre),apellido(_apellido),ine(_ine){}
    string getNombre();
    string getApellido();
    string getIne();

    friend ostream & operator<<(ostream & os, const Persona & persona);
};