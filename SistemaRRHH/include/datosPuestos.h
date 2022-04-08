#ifndef DATOSPUESTOS_H
#define DATOSPUESTOS_H
#include <iostream>

using std::string;

class datosPuestos
{
    public:
        virtual ~datosPuestos();

        datosPuestos( int = 0, string = "", string = "");

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerApellido( string );
        string obtenerApellido() const;

        void establecerNombre( string );
        string obtenerNombre() const;

    protected:

    private:
        int codigo;
        char apellido[ 15 ];
        char nombre[ 10 ];
};

#endif // DATOSPUESTOS_H
