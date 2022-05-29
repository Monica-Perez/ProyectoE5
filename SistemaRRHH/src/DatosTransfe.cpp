#include "DatosTransfe.h"
#include <cstring>
#include <iostream>

using std::string;

DatosTransfe::DatosTransfe(int ValorCodTransfe, double ValorTransfe)
{
    EstablecerCodTransfe(ValorCodTransfe);
    establecerTransfe(ValorTransfe);
}

int DatosTransfe::obtenercodicoTransfe() const
{
   return CodTransfe;
}
void DatosTransfe::EstablecerCodTransfe( int ValorCodTransfe )
{
   CodTransfe = ValorCodTransfe;
}

double DatosTransfe::obtenerTransfe() const
{
   return TransferenciaB;
}
void DatosTransfe::establecerTransfe( double ValorTransfe )
{
   TransferenciaB = ValorTransfe;
}

DatosTransfe::~DatosTransfe()
{
    //dtor
}
