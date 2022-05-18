#include "DatosEmpleado.h"
#include "Empleado.h"
#include <cstring>
#include <iostream>

using std::string;

DatosEmpleado::DatosEmpleado(int valorCodigo, string valorApellido, string valorNombre, string valorCorreo, double valorSueldo )
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );
    establecerCorreo( valorCorreo );
    establecerSueldo( valorSueldo );

}
int DatosEmpleado::obtenerCodigo() const
{
   return codigo;
}
void DatosEmpleado::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosEmpleado::obtenerApellido() const
{
   return apellido;

}
void DatosEmpleado::establecerApellido( string apellidoString )
{
    const char *valorApellido = apellidoString.data();
    int longitud = strlen( valorApellido );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( apellido, valorApellido, longitud );

    apellido[ longitud ] = '\0';

}
string DatosEmpleado::obtenerNombre() const
{
   return nombre;
}
void DatosEmpleado::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';

}
double DatosEmpleado::obtenerSueldo() const
{
   return sueldo;
}
void DatosEmpleado::establecerSueldo( double valorSueldo )
{
   sueldo = valorSueldo;
}
string DatosEmpleado::obtenerCorreo() const
{
   return correo;
}
void DatosEmpleado::establecerCorreo( string correostring )
{
    const char *valorCorreo = correostring.data();
    int longitud = strlen( valorCorreo );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( correo, valorCorreo, longitud );

    correostring[ longitud ] = '\0';
}

DatosEmpleado::~DatosEmpleado()
{
    //dtor
}
