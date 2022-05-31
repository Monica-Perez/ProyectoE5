#include "Nomina.h"
#include "DatosEmpleado.h"
#include "datosPuestos.h"
#include "DatosDepartamento.h"
#include "DatosConceptos.h"

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

int opcionNomi();
void imprimirRegistroNomi( fstream& ,fstream& ,fstream& );
void mostrarLineaNom( ostream&, const DatosEmpleado & , const datosPuestos &,const DatosDepartamento &);
void consultarRegistroPla( fstream& , fstream& , fstream&);
void mostrarLineaPantallaPla( const DatosEmpleado &, const datosPuestos &, const DatosDepartamento &);


using namespace std;
// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840

Nomina::Nomina()
{
    fstream creditoEntradaSalida( "emp.dat", ios::in | ios::out | ios::binary);
    fstream creditoEntradaSalida2( "puest.dat", ios::in | ios::out | ios::binary);
    fstream creditoEntradaSalida3( "DEPARTAMENTOS.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida && !creditoEntradaSalida2 && !creditoEntradaSalida3) {
        cerr << "No se pudo abrir el archivo." << endl;
    } //Daniel Alexander Hall Alvarez - 9959-21-1395
    enum Opciones { nuevo= 1, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionNomi() ) != FIN ) {
        switch ( opcion ) {
            case nuevo:
                imprimirRegistroNomi( creditoEntradaSalida, creditoEntradaSalida2, creditoEntradaSalida3 );
            break;
            case mostrar:
                consultarRegistroPla( creditoEntradaSalida, creditoEntradaSalida2, creditoEntradaSalida3 );
             break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;
        }//FIN SWITCH
        creditoEntradaSalida.clear();
    }
    }//FIN WHILE


    int opcionNomi(){ //Daniel Alexander Hall Alvarez - 9959-21-1395
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

    cout<<"\n\t\t\t\t\t\t\t  ----------------------------"<<endl; //Daniel Alexander Hall Alvarez - 9959-21-1395
	cout<<"\t\t\t\t\t\t\t   |   NOMINA DE EMPLEADOS  |"<<endl;
	cout<<"\t\t\t\t\t\t\t  ----------------------------"<<endl<<endl;

	cout<< "\n\n\t\t\t 1. Crear un archivo de texto para imprimir" << endl
   << "\t\t\t 2. Mostrar Nomina" << endl
    << "\t\t\t 3. Regresar al Menu Principal" << endl
   << "\n\t\t\tIngrese su opcion: ";

    int opcionMenu;
    cin >> opcionMenu;

    return opcionMenu;


}
void imprimirRegistroNomi( fstream &leerDeArchivo, fstream &leer2 , fstream &leer3 ) //Daniel Alexander Hall Alvarez - 9959-21-1395
{
    ofstream archivoImprimirSalida( "ImprimirNomina.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;

        exit( 1 );
    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "\nCodigo" << setw( 14 ) << " Apellido" << setw( 15 ) << " Nombre"<<  setw( 10 ) << "Sueldo" << setw( 15 ) << "Horas Extras "<< setw( 14 )
    << "Valor Horas"<< setw( 10 ) << "  IGSS"<< setw( 10 ) << "  ISR"<< setw( 11 ) << " Anticipo "<< setw( 11 ) << " Total"<< endl;
    leerDeArchivo.seekg( 0 );
    leer2.seekg( 0 );
    leer3.seekg( 0 );
    DatosEmpleado empleados;
    datosPuestos puestos;
    DatosDepartamento Departamentos;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    leer2.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    leer3.read (reinterpret_cast< char * >( &Departamentos ), sizeof( DatosDepartamento ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
        mostrarLineaNom( archivoImprimirSalida,empleados,puestos,Departamentos);
        leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
        leer2.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
        leer3.read (reinterpret_cast< char * >( &Departamentos ), sizeof( DatosDepartamento ) );
    } //FIN DE WHILE
    cout<<"\n";
    system("pause");
} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaNom( ostream &salida, const DatosEmpleado &registro, const datosPuestos &regpu , const DatosDepartamento &regdep ) //Daniel Alexander Hall Alvarez - 9959-21-1395
{
      salida << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 12 ) << setprecision( 2 ) << fixed
          << showpoint << registro.obtenerSueldo()
          << setw( 14 ) <<  registro.obtenerHoras()
          << setw( 14 ) << registro.obtenerHE()
          << setw( 10 ) << setprecision( 2 ) << registro.obtenerIGSS()
          << setw( 10 ) << setprecision( 2 ) << registro.obtenerISR()
           << setw( 10 ) << setprecision( 2 ) << registro.obtenerAnticipo()
          << setw( 10 ) << setprecision( 2 ) << registro.obtenerTotalF()<< endl;
}//FIN -MOSTRARLINEA-
void consultarRegistroPla( fstream &leerDeArchivo, fstream &leer2 , fstream &leer3) // Monica Gabriela Perez Velásquez - 9959-21-1840
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 14 ) << " Apellido" << setw( 15 ) << " Nombre"  << setw( 17 ) << "Departamento" << setw( 14 ) << "Puesto"
    <<  setw( 10 ) << "Sueldo" << setw( 15 ) << "Horas Extras "<< setw( 14 ) << "Valor Horas"<< setw( 10 ) << "  IGSS"<< setw( 10 ) << "  ISR"<< setw( 11 ) << " Anticipo "<< setw( 11 ) << " Total"<< endl;
    DatosEmpleado empleados;
    datosPuestos puestos;// Alan Abimael Galicia Ruano - 9959-21-3632
    DatosDepartamento Departamentos; //Daniel Alexander Hall Alvarez - 9959-21-1395
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    leer2.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    leer3.read (reinterpret_cast< char * >( &Departamentos ), sizeof( DatosDepartamento ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
            mostrarLineaPantallaPla(empleados,puestos,Departamentos);
            leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
            leer2.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
            leer3.read (reinterpret_cast< char * >( &Departamentos ), sizeof( DatosDepartamento ) );
   } //FIN WHILE
   cout<<endl<<endl;
   system("pause");
} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaPla( const DatosEmpleado &registro, const datosPuestos &regpu , const DatosDepartamento &regdep)// Monica Gabriela Perez Velásquez - 9959-21-1840
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 17 ) << regdep.obtenerApellido().data() //DEPARTAMENTO
          << setw( 14 ) << regpu.obtenerNombre().data() //PUESTO
          << setw( 12 ) << setprecision( 2 ) << fixed
          << showpoint << registro.obtenerSueldo()
          << setw( 14 ) <<  registro.obtenerHoras()//Daniel Alexander Hall Alvarez - 9959-21-1395
          << setw( 14 ) << registro.obtenerHE()//Daniel Alexander Hall Alvarez - 9959-21-1395
          << setw( 10 ) << setprecision( 2 ) << registro.obtenerIGSS()// Alan Abimael Galicia Ruano - 9959-21-3632
          << setw( 10 ) << setprecision( 2 ) << registro.obtenerISR()// Alan Abimael Galicia Ruano - 9959-21-3632
           << setw( 10 ) << setprecision( 2 ) << registro.obtenerAnticipo()//Abigail Elizabeth Vásquez Herrera - 9959-21-13777
          << setw( 10 ) << setprecision( 2 ) << registro.obtenerTotalF()<<endl;// Alan Abimael Galicia Ruano - 9959-21-3632
} //FIN -MOSTRARLINEAENOANTALLA-


Nomina::~Nomina()
{
    //dtor
}
