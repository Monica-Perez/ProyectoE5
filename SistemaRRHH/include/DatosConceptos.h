#ifndef DATOSCONCEPTOS_H
#define DATOSCONCEPTOS_H

#include <iostream>
using std::string;
// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
class DatosConceptos
{
    public:
        virtual ~DatosConceptos();
        DatosConceptos( int = 0, string = "", string = "", string = "", float = 0.0000 );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerEfecto( string );
        string obtenerEfecto() const;

        void establecerEstado( string );
        string obtenerEstado() const;

        void establecerValor( float );
        float obtenerValor() const;

    protected:

    private:
        int codigoConceptos;
        char nombre[ 20 ];
        char efecto[ 15 ];
        char estado[ 15 ];
        float valor;
};

#endif // DATOSCONCEPTOS_H
