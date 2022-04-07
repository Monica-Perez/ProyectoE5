#include "datosPuestos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

datosPuestos::datosPuestos(int valorCodigo, string valorApellido, string valorNombre)
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );
}
int datosPuestos::obtenerCodigo() const
{
   return codigo;
}
void datosPuestos::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string datosPuestos::obtenerApellido() const
{
   return apellido;

}
void datosPuestos::establecerApellido( string apellidoString )
{
    const char *valorApellido = apellidoString.data();
    int longitud = strlen( valorApellido );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( apellido, valorApellido, longitud );

    apellido[ longitud ] = '\0';

}
string datosPuestos::obtenerNombre() const
{
   return nombre;
}
void datosPuestos::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';

}


datosPuestos::~datosPuestos()
{
    //dtor
}
