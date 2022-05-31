#include "DatosEmpresas.h"
#include "Empresas.h"
#include <cstring>
#include <iostream>

using std::string;

// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
DatosEmpresas::DatosEmpresas(int valorCodigo, string valorNombre, int valorCelular)
{
    establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerCelular( valorCelular );
}
int DatosEmpresas::obtenerCodigo() const
{
   return codigo;
}
void DatosEmpresas::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosEmpresas::obtenerNombre() const
{
   return nombre;
}
void DatosEmpresas::establecerNombre( string nombreEmpre )
{
    const char *valorNombre = nombreEmpre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 20 ? longitud : 19 );
    strncpy( nombre, valorNombre, longitud );

    nombreEmpre[ longitud ] = '\0';

}
int DatosEmpresas::obtenerCelular() const
{
   return celular;
}
void DatosEmpresas::establecerCelular( int valorCelular )
{
   celular = valorCelular;
}
DatosEmpresas::~DatosEmpresas()
{
    //dtor
}
