#include "DatosConceptos.h"
#include "Conceptos.h"
#include <cstring>
#include <iostream>

using std::string;

/*REALIZADO POR MONICA PEREZ, 9959-21-1840*/

DatosConceptos::DatosConceptos(int valorCodigo, string valorNombre, string valorEfecto, string valorEstado, float valorV )
{
    establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerEfecto( valorEfecto );
    establecerEstado( valorEstado );
    establecerValor( valorV );
}
/*CODIGO*/
int DatosConceptos::obtenerCodigo() const
{
   return codigo;
}
void DatosConceptos::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}

/*NOMBRE*/
string DatosConceptos::obtenerNombre() const
{
   return nombre;
}
void DatosConceptos::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 20 ? longitud : 19 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';
}
/*EFECTO*/
string DatosConceptos::obtenerEfecto() const
{
   return efecto;
}
void DatosConceptos::establecerEfecto( string efectoString )
{
    const char *valorEfecto = efectoString.data();
    int longitud = strlen( valorEfecto );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( efecto, valorEfecto, longitud );

    efectoString[ longitud ] = '\0';
}
/*ESTADO*/
string DatosConceptos::obtenerEstado() const
{
   return estado;
}
void DatosConceptos::establecerEstado( string estadoString )
{
    const char *valorEstado = estadoString.data();
    int longitud = strlen( valorEstado );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( estado, valorEstado, longitud );

    estadoString[ longitud ] = '\0';
}
/*VALOR*/
float DatosConceptos::obtenerValor() const
{
   return valor;
}
void DatosConceptos::establecerValor( float valorV )
{
   valor = valorV;
}

DatosConceptos::~DatosConceptos()
{
    //dtor
}
