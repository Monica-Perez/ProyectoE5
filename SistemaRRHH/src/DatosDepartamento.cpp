#include "DatosDepartamento.h"
#include "Departamentos.h"
#include <cstring>
#include <iostream>

using std::string;

// Realizado Daniel Alexander Hall Alvarez - 9959-21-1395
DatosDepartamento::DatosDepartamento(int valorCodigo, string valorApellido, string valorNombre )
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );

}
int DatosDepartamento::obtenerCodigo() const
{
   return codigo;
}
void DatosDepartamento::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosDepartamento::obtenerApellido() const
{
   return apellido;
}
void DatosDepartamento::establecerApellido(string apellidoString)
{
    const char *valorApellido = apellidoString.data();
    int longitud =strlen(valorApellido);
    longitud = ( longitud < 15 ? longitud : 14);
    strncpy(apellido, valorApellido, longitud );

    apellido [ longitud ] = '\0';
}
string DatosDepartamento::obtenerNombre() const
{
    return nombre;
}
void DatosDepartamento::establecerNombre ( string primerNombre)
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 20 ? longitud : 19 );
    strncpy( nombre, valorNombre, longitud );

}
DatosDepartamento::~DatosDepartamento()
{
    //dtor
}
