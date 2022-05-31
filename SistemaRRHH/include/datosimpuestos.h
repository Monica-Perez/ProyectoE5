#ifndef DATOSIMPUESTOS_H
#define DATOSIMPUESTOS_H
#include <iostream>

using std::string;
// Realizado por Abigail Elizabeth Vásquez Herrera - 9959-21-13777
class datosimpuestos
{
    public:

        virtual ~datosimpuestos();

        datosimpuestos( int = 0, string = "", double = 0.0 );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerCantidad( double);
        double obtenerCantidad() const;
    protected:

    private:
        int codigoImpuestos;
        char nombre[ 15 ];
        double cantidad;

};

#endif // DATOSIMPUESTOS_H






