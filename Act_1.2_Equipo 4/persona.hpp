#include <iostream>
#include <string>

using namespace std;

/* La implementación se encuentra en su respectivo .cpp*/
class Persona{
    protected:
    string nombre;
    string apellido;
    string ine;
    public:
    /* Declaración del constructor vacío*/
    Persona(){}
    /*Declaración del constructor*/
    Persona(string _nombre,string _apellido, string _ine):nombre(_nombre),apellido(_apellido),ine(_ine){}
    
    /*La función "getNombre" regresa el valor de la variable nombre*/
    string getNombre();
    
    /*La función "getApellido" regresa el valor de la variable apellido*/
    string getApellido();
    
    /*La función "getNombre" regresa el valor de la variable ine*/
    string getIne();

    /*Declaración del Set de la variable nombre*/
    void setNombre(string);
    /*Declaración del Set de la variable apellido*/
    void setApellido(string);



    /*La función "printPersona" imprime los valores de la clase
    en formato: nombre, apellido. (ine)*/
    void printPersona();

};