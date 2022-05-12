#include "Nomina.h"
#include "DatosEmpleado.h"
#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>
using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;
#include <cstdlib>

void consultarRegistroPla( fstream& );
void mostrarLineaPantallaPla( const DatosEmpleado &);

using namespace std;

Nomina::Nomina()
{
    fstream creditoEntradaSalida( "emp.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
    }
    consultarRegistroPla( creditoEntradaSalida );
}
void consultarRegistroPla( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Apellido" << setw( 14 ) << " Nombre" << setw( 16 ) << " Sueldo" << endl;
    leerDeArchivo.seekg( 0 );
    DatosEmpleado empleados;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
            mostrarLineaPantallaPla(empleados);
            leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
   } //FIN WHILE
   system("pause");
} //FIN CONSULTAR REGISTRO

void mostrarLineaPantallaPla( const DatosEmpleado &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 9 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Nomina::~Nomina()
{
    //dtor
}
