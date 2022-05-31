#include "datosimpuestos.h"
#include "Impuestos.h"
#include <cstring>
#include <iostream>

using std::string;

// Realizado Por Abigail Elizabeth Vásquez Herrera - 9959-21-13777
datosimpuestos::datosimpuestos(int valorCodigo, string valorNombre, double valorCantidad)
{
     establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerCantidad( valorCantidad );

    //ctor
}
int datosimpuestos::obtenerCodigo() const
{
   return codigoImpuestos;
}
void datosimpuestos::establecerCodigo( int valorCodigo )
{
   codigoImpuestos = valorCodigo;
}
string datosimpuestos::obtenerNombre() const
{
   return nombre;
}
void datosimpuestos::establecerNombre(string nombreString)
{
    const char *valorNombre = nombreString.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nombre, valorNombre, longitud );

    nombreString[ longitud ] = '\0';

}

double datosimpuestos::obtenerCantidad() const
{
   return cantidad;
}
void datosimpuestos::establecerCantidad( double valorCantidad )
{
   cantidad = valorCantidad;
}
datosimpuestos::~datosimpuestos()
{
    //dtor
}
