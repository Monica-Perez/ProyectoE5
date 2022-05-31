#include "DatosUsuario.h"
#include "Usuarios.h"
#include <cstring>
#include <iostream>

using std::string;
// Monica Gabriela Perez Velásquez - 9959-21-1840
// Alan Abimael Galicia Ruano - 9959-21-3632
DatosUsuario::DatosUsuario(int valorUsuario, int valorContra)
{
    establecerUsuario( valorUsuario );
    establecerContra( valorContra );
}
int DatosUsuario::obtenerUsuario() const
{
   return usuario;
}
void DatosUsuario::establecerUsuario( int valorUsuario )
{
   usuario = valorUsuario;
}
int DatosUsuario::obtenerContra() const
{
   return contra;
}
void DatosUsuario::establecerContra( int valorContra )
{
    contra=valorContra;
}

DatosUsuario::~DatosUsuario()
{
    //dtor
}
