#include "datosPuestos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;
// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632

datosPuestos::datosPuestos(int valorCodigoP, string valorEstatus, string valorNombrePuestos)
{
    establecerCodigoP( valorCodigoP );
    establecerEstatus( valorEstatus );
    establecerNombrePuestos( valorNombrePuestos );
}
int datosPuestos::obtenerCodigoP() const
{
   return codigoP;
}
void datosPuestos::establecerCodigoP( int valorCodigoP )
{
   codigoP = valorCodigoP;
}
string datosPuestos::obtenerEstatus() const
{
   return Estatus;

}
void datosPuestos::establecerEstatus( string EstatusString )
{
    const char *valorEstatus = EstatusString.data();
    int longitudP = strlen( valorEstatus );
    longitudP = ( longitudP < 15 ? longitudP : 14 );
    strncpy( Estatus, valorEstatus, longitudP );

    Estatus[ longitudP ] = '\0';

}
string datosPuestos::obtenerNombre() const
{
   return nombreP;
}
void datosPuestos::establecerNombrePuestos( string nombrePuestos )
{
    const char *valorNombrePuestos = nombrePuestos.data();
    int longitudP = strlen( valorNombrePuestos );
    longitudP = ( longitudP < 10 ? longitudP : 9 );
    strncpy( nombreP, valorNombrePuestos, longitudP );

    nombrePuestos[ longitudP ] = '\0';

}


datosPuestos::~datosPuestos()
{
    //dtor
}
