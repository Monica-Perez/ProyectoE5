#include "Nomina.h"
#include "DatosEmpleado.h"
#include "datosPuestos.h"
#include <iostream>
#include <ctime>
#include <vector>

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

    system("cls");
    time_t now = time(0);
        tm * time = localtime(&now);

vector<string> dia_semana;
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");

vector<string> mes;
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");

int year = 1900 + time->tm_year;

//Formato=hoy miercoles, 27 de mayo del 2015
cout<< "\n";
cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
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
