#ifndef DATOSCONCEPTOS_H
#define DATOSCONCEPTOS_H

#include <iostream>
using std::string;

class DatosConceptos
{
    public:
        virtual ~DatosConceptos();
        DatosConceptos( int = 0, string = "", string = "", string = "", double = 0.0 );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerEfecto( string );
        string obtenerEfecto() const;

        void establecerEstado( string );
        string obtenerEstado() const;

        void establecerValor( double );
        double obtenerValor() const;

    protected:

    private:
        int codigo;
        char nombre[ 20 ];
        char efecto[ 15 ];
        char estado[ 15 ];
        double valor;
};

#endif // DATOSCONCEPTOS_H
