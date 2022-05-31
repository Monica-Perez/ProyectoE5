#ifndef DATOSEMPRESAS_H
#define DATOSEMPRESAS_H

#include <iostream>
using std::string;
// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
class DatosEmpresas
{
    public:
        virtual ~DatosEmpresas();

        DatosEmpresas( int = 0, string = "", int = 0 );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerCelular( int );
        int obtenerCelular() const;

    protected:

    private:
        int codigo;
        char nombre[ 20 ];
        int celular;
};

#endif // DATOSEMPRESAS_H
