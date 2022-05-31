#ifndef DATOSPUESTOS_H
#define DATOSPUESTOS_H
#include <iostream>

using std::string;
// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632

class datosPuestos
{
    public:
        virtual ~datosPuestos();

        datosPuestos( int = 0, string = "", string = "");

        void establecerCodigoP( int );
        int obtenerCodigoP() const;

        void establecerEstatus( string );
        string obtenerEstatus() const;

        void establecerNombrePuestos( string );
        string obtenerNombre() const;

    protected:

    private:
        int codigoP;
        char Estatus[ 15 ];
        char nombreP[ 10 ];
};

#endif // DATOSPUESTOS_H
