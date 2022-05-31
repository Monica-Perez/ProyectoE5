#ifndef DATOSTRANSFE_H
#define DATOSTRANSFE_H
#include "DatosTransfe.h"
#include "Transfe.h"

#include <iostream>
using std::string;
// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632


class DatosTransfe
{
    public:
        virtual ~DatosTransfe();
        DatosTransfe(int=0, double=0.0);

        void EstablecerCodTransfe( int );
        int obtenercodicoTransfe() const;

        void establecerTransfe ( double );
        double obtenerTransfe () const;

    protected:

    private:
        double TransferenciaB;
        int CodTransfe;
};

#endif // DATOSTRANSFE_H
