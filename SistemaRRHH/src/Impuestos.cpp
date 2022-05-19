#include "Impuestos.h"
#include <iostream>
#include "datosimpuestos.h"
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


int opcionImp();
void imprimirRegistroImp( fstream& );
void crearArchivoCreditoImp();
void mostrarLineaImp( ostream&, const datosimpuestos & );
void nuevoRegistroImp( fstream& );
int obtenernCodigoImp( const char * const );
int obtenernCodigoImp( const char * const );
void modificarRegistroImp (fstream& );
void eliminarRegistroImp( fstream& );
void consultarRegistroImp( fstream& );
void mostrarLineaPantallaImp( const datosimpuestos &);

using namespace std;


Impuestos::Impuestos()
{
     fstream creditoEntradaSalida( "IMPUESTOS.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoImp();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionImp() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroImp( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroImp( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroImp( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroImp( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroImp( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
}
int opcionImp(){
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
    cout<<"\t\t\t\t-----------------"<<endl;
	cout<<"\t\t\t\t |  IMPUESTOS  |"<<endl;
	cout<<"\t\t\t\t-----------------"<<endl;


    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Impuesto" << endl
        << "\t\t\t 3. Modificar Impuesto" << endl
        << "\t\t\t 4. Eliminar Impuesto" << endl
        << "\t\t\t 5. Mostrar Lista de impuestos" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";

    int opcionMenu;
    cin >> opcionMenu;

    return opcionMenu;

}
void imprimirRegistroImp( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirImpuestos.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Nombre" << right << setw( 10 ) << "Cantidad" << endl;
    leerDeArchivo.seekg( 0 );

    datosimpuestos impuestos;
    leerDeArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );

    while ( !leerDeArchivo.eof() ) {
        if ( impuestos.obtenerCodigo() != 0 )
        mostrarLineaImp( archivoImprimirSalida, impuestos );
        leerDeArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );
    } //FIN DE WHILE
cout<<"\n";
 system("pause");
} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaImp( ostream &salida, const datosimpuestos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 10 ) << registro.obtenerCantidad() << endl;


}//FIN -MOSTRARLINEA-
void crearArchivoCreditoImp()
{
    ofstream creditoSalida( "IMPUESTOS.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    datosimpuestos impuestoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &impuestoEnBlanco ), sizeof( datosimpuestos ) );
cout<<"\n";
 system("pause");
}
void nuevoRegistroImp( fstream &insertarEnArchivo )
{
    int codigo = obtenernCodigoImp( "\nEscriba el Codigo " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( datosimpuestos ) );
    datosimpuestos impuestos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );

    if ( impuestos.obtenerCodigo() == 0 ) {
        char nombre[ 15 ];
        double cantidad;

        cout<<"Escriba el Nombre del impuesto asignado a el empleado: ";
        cin>> setw( 15 ) >> nombre;
        cout<<"Escriba la cantidad del impuesto: ";
        cin>> setw( 10 ) >> cantidad;

        impuestos.establecerNombre( nombre );
        impuestos.establecerCantidad( cantidad );
        impuestos.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( datosimpuestos ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &impuestos ), sizeof( datosimpuestos ) );
        cout<<"\n impuesto agregado con excito..."<<endl;

    } //FIN IF
    else
        cerr << "El impuesto con codigo #" << codigo << " ya contiene informacion.\n" << endl;
cout<<"\n";
 system("pause");
} //FIN REGISTRO
int obtenernCodigoImp( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroImp( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Cantidad\n  R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenernCodigoImp( "\nEscriba el codigo del impuesto que desea modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosimpuestos ));

        datosimpuestos impuestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &impuestos), sizeof( datosimpuestos ) );

        if (impuestos.obtenerCodigo() != 0 ) {
            mostrarLineaImp( cout, impuestos );
            cout << "\nEscriba el nuevo nombre : ";
            string nombre;
            cin >> nombre;
            string nombreanterior = impuestos.obtenerNombre();
            impuestos.establecerNombre( nombre );
            mostrarLineaImp( cout, impuestos );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosimpuestos ));

            actualizarArchivo.write(reinterpret_cast< const char * >( &impuestos ), sizeof( datosimpuestos ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenernCodigoImp( "\nEscriba el ccdigo del impuesto que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosimpuestos ));

        datosimpuestos impuestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );

        //ACTUALIZAR EL REGISTRO
        if (impuestos.obtenerCodigo() != 0 ) {
            mostrarLineaImp( cout, impuestos );
            cout << "\nEscriba el nuevo Nombre: ";
            double cantidad;
            cin >> cantidad;

            double cantidadAnterior = impuestos.obtenerCantidad();
            impuestos.establecerCantidad( cantidad );
            mostrarLineaImp (cout, impuestos );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosimpuestos));
            actualizarArchivo.write(reinterpret_cast< const char * >( &impuestos ), sizeof( datosimpuestos ) );
        }
    }
cout<<"\n";
 system("pause");
} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroImp( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigoImp( "\nEscriba el codigo del Impuesto a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( datosimpuestos ) );
    datosimpuestos impuestos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );

    if ( impuestos.obtenerCodigo() != 0 ) {
        datosimpuestos impuestosEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( datosimpuestos ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &impuestosEnBlanco ), sizeof( datosimpuestos));

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";
cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-
void consultarRegistroImp( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << "Nombre impuesto" << right << setw( 10 ) << " cantidad" << endl;
    leerDeArchivo.seekg( 0 );
    datosimpuestos impuestos;
    leerDeArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );
    while ( !leerDeArchivo.eof() ) {
        if ( impuestos.obtenerCodigo() != 0 )
            mostrarLineaPantallaImp(impuestos);
            leerDeArchivo.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );

   } //FIN WHILE
cout<<"\n";
 system("pause");
} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaImp( const datosimpuestos &registro)
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 14 ) << registro.obtenerCantidad()<< endl;

} //FIN -MOSTRARLINEAENOANTALLA-
Impuestos::~Impuestos()
{
    //dtor
}

