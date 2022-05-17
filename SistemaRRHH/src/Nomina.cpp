#include "Nomina.h"
#include "DatosEmpleado.h"
#include "datosPuestos.h"
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

void consultarRegistroPla( fstream& , fstream& );
void mostrarLineaPantallaPla( const DatosEmpleado &, const datosPuestos &);

using namespace std;

Nomina::Nomina()
{
    cout<<"\n\t\t\t---------------------------------"<<endl;
    cout<<"\n\t\t\t\t---------------"<<endl;
	cout<<"\t\t\t\t |   NOMINA  |"<<endl;
	cout<<"\t\t\t\t---------------"<<endl;

    fstream creditoEntradaSalida( "emp.dat", ios::in | ios::out | ios::binary);
    fstream creditoEntradaSalida2( "puest.dat", ios::in | ios::out | ios::binary);

    if ( !creditoEntradaSalida && !creditoEntradaSalida2) {
        cerr << "No se pudo abrir el archivo." << endl;
    }
    consultarRegistroPla( creditoEntradaSalida, creditoEntradaSalida2 );
}

void consultarRegistroPla( fstream &leerDeArchivo, fstream &leer2 )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Apellido" << setw( 15 ) << " Nombre" << setw( 12 ) << "Puesto" <<  setw( 10 ) << " Sueldo" << endl;
    leerDeArchivo.seekg( 0 );
    DatosEmpleado empleados;
    datosPuestos puestos;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    leer2.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
            mostrarLineaPantallaPla(empleados,puestos);
            leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
            leer2.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
   } //FIN WHILE
   cout<<endl;
   system("pause");
} //FIN CONSULTAR REGISTRO

void mostrarLineaPantallaPla( const DatosEmpleado &registro, const datosPuestos &regpu )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 12 ) << regpu.obtenerNombre().data()
          << setw( 10 ) << setprecision( 3 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Nomina::~Nomina()
{
    //dtor
}
