#include "Empresas.h"
#include "DatosEmpresas.h"
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

int opcionEmpre();
void imprimirRegistroEmpre( fstream& );
void crearArchivoCreditoEmpre();
void mostrarLineaEmpre( ostream&, const DatosEmpresas & );
void nuevoRegistroEmpre( fstream& );
int obtenerCodigoEmpre( const char * const );
void modificarRegistroEmpre( fstream& );
void eliminarRegistroEmpre( fstream& );
void consultarRegistroEmpre( fstream& );
void mostrarLineaPantallaEmpre( const DatosEmpresas &);

using namespace std;

Empresas::Empresas()
{
    fstream creditoEntradaSalida( "empres.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoEmpre();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionEmpre() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroEmpre( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroEmpre( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroEmpre( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroEmpre( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroEmpre( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();
   } //FIN WHILE
}
int opcionEmpre(){
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
    cout<<"\n\t\t\t\t-----------------"<<endl;
	cout<<"\t\t\t\t |   EMPRESAS  |"<<endl;
	cout<<"\t\t\t\t-----------------"<<endl;

    cout<< "\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Empresa" << endl
        << "\t\t\t 3. Modificar Empresa" << endl
        << "\t\t\t 4. Eliminar Empresa" << endl
        << "\t\t\t 5. Mostrar Lista de Empresa" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        << "\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";

   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroEmpre( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirEmpresa.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 20 )<< right << "Nombre" << setw( 10 ) << "Numero" << endl;
    leerDeArchivo.seekg( 0 );

    DatosEmpresas empresas;
    leerDeArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );

    while ( !leerDeArchivo.eof() ) {
        if ( empresas.obtenerCodigo() != 0 )
        mostrarLineaEmpre( archivoImprimirSalida, empresas );
        leerDeArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );
    } //FIN DE WHILE
cout<<"\n";
 system("pause");
} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaEmpre( ostream &salida, const DatosEmpresas &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 20 ) << registro.obtenerNombre().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed<< showpoint << registro.obtenerCelular() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoEmpre()
{
    ofstream creditoSalida( "empres.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosEmpresas empresaEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &empresaEnBlanco ), sizeof( DatosEmpresas ) );
cout<<"\n";
 system("pause");
}
void nuevoRegistroEmpre( fstream &insertarEnArchivo )
{
    int codigo = obtenerCodigoEmpre( "\nEscriba el Codigo de la Empresa " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosEmpresas ) );
    DatosEmpresas empresas;
    insertarEnArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );

    if ( empresas.obtenerCodigo() == 0 ) {
        char nombre[ 20 ];
        int celular;
        cout<<"Escriba el Nombre de la Empresa: ";
        cin>> setw( 20 ) >> nombre;
        cout<<"Escriba el Celular de la Empresa: ";
        cin>> celular;
        empresas.establecerNombre( nombre );
        empresas.establecerCelular( celular );
        empresas.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosEmpresas ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &empresas ), sizeof( DatosEmpresas ) );
        cout<<"\n Empresas agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Empresas con codigo #" << codigo << " ya contiene informacion.\n" << endl;
cout<<"\n";
 system("pause");
}
int obtenerCodigoEmpre( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;
}
void modificarRegistroEmpre( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Numero\n  R - ";
    cin>>opcionAc;

    if (opcionAc== 1){
        int codigo = obtenerCodigoEmpre( "\nEscriba el codigo de la Empresa que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpresas ));

        DatosEmpresas empresas;
        actualizarArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );

        //ACTUALIZAR EL REGISTRO
        if (empresas.obtenerCodigo() != 0 ) {
            mostrarLineaEmpre( cout, empresas );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = empresas.obtenerNombre();
            empresas.establecerNombre( nombre );
            mostrarLineaEmpre( cout, empresas );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpresas ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &empresas ), sizeof( DatosEmpresas ) );
        }
    }else if(opcionAc == 2){
        int codigo = obtenerCodigoEmpre( "Escriba el codigo de la Empresa que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpresas ));

        DatosEmpresas empresas;
        actualizarArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );

        if (empresas.obtenerCodigo() != 0 ) {
                mostrarLineaEmpre( cout, empresas );
                cout << "\nEscriba el nuevo Celular: ";
                int celular;
                cin >> celular;

                int celularAnterior = empresas.obtenerCelular();
                empresas.establecerCelular( celular );
                mostrarLineaEmpre( cout, empresas );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpresas ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &empresas ), sizeof( DatosEmpresas ) );
                cout << "\nCelular Modificado Exitosamente...";
        }
    }
cout<<"\n";
 system("pause");
} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroEmpre( fstream &eliminarDeArchivo )
{
    int codigo = obtenerCodigoEmpre( "\nEscriba el codigo de la Empresa que desea Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosEmpresas ) );
    DatosEmpresas empresas;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );

    if ( empresas.obtenerCodigo() != 0 ) {
        DatosEmpresas empresaEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosEmpresas ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &empresaEnBlanco ), sizeof( DatosEmpresas ) );

      cout << " \nCuenta #" << codigo << " se elimino Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";
cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-
void consultarRegistroEmpre( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 20 ) << " Nombre" << right << setw( 10 ) << "Celular" << endl;
    leerDeArchivo.seekg( 0 );
    DatosEmpresas empresas;
    leerDeArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empresas.obtenerCodigo() != 0 )
            mostrarLineaPantallaEmpre(empresas);
            leerDeArchivo.read( reinterpret_cast< char * >( &empresas ), sizeof( DatosEmpresas ) );

   } //FIN WHILE
cout<<"\n";
 system("pause");
} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaEmpre( const DatosEmpresas &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 20 ) << registro.obtenerNombre().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerCelular() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Empresas::~Empresas()
{
    //dtor
}
