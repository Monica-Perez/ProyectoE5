#ifndef DATOSUSUARIO_H
#define DATOSUSUARIO_H

#include <iostream>
using std::string;
// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632

class DatosUsuario
{
    public:
        virtual ~DatosUsuario();
        DatosUsuario( int = 0, int = 0 );

        void establecerUsuario( int );
        int obtenerUsuario() const;

        void establecerContra( int );
        int obtenerContra() const;

    protected:

    private:
        int usuario;
        int contra;
};

#endif // DATOSUSUARIO_H
