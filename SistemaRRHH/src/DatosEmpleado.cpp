#include "DatosEmpleado.h"
#include "Empleado.h"
#include <cstring>
#include <iostream>

using std::string;
// Monica Gabriela Perez Velásquez - 9959-21-1840

DatosEmpleado::DatosEmpleado(int valorCodigo, string valorApellido, string valorNombre, string valorCorreo, double valorSueldo, double valorIGSS, double valorISR , int valorHoras, double valorHorasExtras, double valorAnticipo, double TotalFilas)
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );
    establecerCorreo( valorCorreo );
    establecerSueldo( valorSueldo );
    establecerIGSS (valorIGSS);//Daniel Alexander Hall Alvarez - 9959-21-1395
    establecerISR (valorISR);// Monica Gabriela Perez Velásquez - 9959-21-1840
    establecerHoras (valorHoras);// Monica Gabriela Perez Velásquez - 9959-21-1840
    establecerHE (valorHorasExtras);// Alan Abimael Galicia Ruano - 9959-21-3632
    establecerAnticipo( valorAnticipo);//Abigail Elizabeth Vásquez Herrera - 9959-21-13777
    establecerTotalF (TotalFilas);// Alan Abimael Galicia Ruano - 9959-21-3632

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

double DatosEmpleado::obtenerIGSS() const
{
   return impIGSS;
}

void DatosEmpleado::establecerIGSS( double valorIGSS )
{
   impIGSS = valorIGSS;
}

double DatosEmpleado::obtenerISR() const
{
   return impISR;
}
void DatosEmpleado::establecerISR( double valorISR )
{
   impISR = valorISR;
}

int DatosEmpleado::obtenerHoras() const
{
   return horas;
}
void DatosEmpleado::establecerHoras( int valorHoras )
{
   horas = valorHoras;
}

double DatosEmpleado::obtenerHE() const
{
   return valorHE;
}
void DatosEmpleado::establecerHE( double valorHorasExtras )
{
   valorHE = valorHorasExtras;
}
double DatosEmpleado::obtenerAnticipo () const
{
    return anticipo;
}
void DatosEmpleado::establecerAnticipo ( double valorAnt )
{
    anticipo = valorAnt;
}
double DatosEmpleado::obtenerTotalF() const
{
   return totalF;
}
void DatosEmpleado::establecerTotalF( double TotalFilas )
{
   totalF = TotalFilas;
}

DatosEmpleado::~DatosEmpleado()
{
    //dtor
}
