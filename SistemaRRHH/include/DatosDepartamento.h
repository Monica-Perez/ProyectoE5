#ifndef DATOSDEPARTAMENTO_H
#define DATOSDEPARTAMENTO_H
#include <iostream>

using std::string;
class DatosDepartamento
{
    public:
        virtual ~DatosDepartamento();

        DatosDepartamento( int = 0, string = "", string = "" );

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

#endif // DATOSDEPARTAMENTO_H
