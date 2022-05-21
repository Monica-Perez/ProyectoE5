#ifndef DATOSEMPLEADO_H
#define DATOSEMPLEADO_H

#include <iostream>
using std::string;

class DatosEmpleado
{
    public:
        virtual ~DatosEmpleado();
        DatosEmpleado( int = 0, string = "", string = "", string = "", double = 0.0, double=0.0, double=0.0, int=0, double=0.0);

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerApellido( string );
        string obtenerApellido() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerSueldo( double );
        double obtenerSueldo() const;

        void establecerCorreo( string );
        string obtenerCorreo() const;

        void establecerIGSS( double );
        double obtenerIGSS() const;

        void establecerISR( double );
        double obtenerISR() const;

        void establecerHoras( int );
        int obtenerHoras() const;

        void establecerHE( double );
        double obtenerHE() const;

    protected:

    private:
        int codigo;
        char apellido[ 15 ];
        char nombre[ 10 ];
        char correo[ 15 ];
        double sueldo;
        double impIGSS;
        double impISR;
        int horas;
        double valorHE;
};

#endif // DATOSEMPLEADO_H
