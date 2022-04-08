#include "Puestos.h"
#include "datosPuestos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

void nuevoRegistro( fstream& );
int obtenernCodigo( const char * const );
void mostrarLinea( ostream&, const datosPuestos & );
void imprimirRegistro( fstream& );
void crearArchivoPuesto();
void modificarRegistro( fstream& );
void eliminarRegistro( fstream& );
void consultarRegistro( fstream& );
void mostrarLineaPantalla( const datosPuestos &);

enum Optios { imprim = 1, nuevo = 2, leer, eliminar, editar, regresar};

Puestos::Puestos()
{
    //ctor
    cout<<"\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t |   PUESTOS  |"<<endl;
	cout<<"\t\t\t\t------------------"<<endl;

	fstream creditoEntradaSalida( "puest.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoPuesto();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
   int opcion=0;

    while ( ( opcion = escribirOption() ) != regresar ) {

        switch ( opcion ) {

         case imprim:
            {
                imprimirRegistro( creditoEntradaSalida );
            }
            break;
         case nuevo:
            {
                nuevoRegistro( creditoEntradaSalida );
            }
            break;
         case leer:
            {
                consultarRegistro( creditoEntradaSalida );

            }
            break;
          case eliminar:
            {
                eliminarRegistro( creditoEntradaSalida );
            }
            break;
          case editar:
            {
                modificarRegistro( creditoEntradaSalida );
            }
            break;
            break;
        }
        creditoEntradaSalida.clear();
    }
}



int Puestos::escribirOption()
{
   // mostrar opciones disponibles
   cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   Módulo de puestos  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout << "\nEscriba su opcion" << endl
        << "1 - crear un archivo de texto para imprimir" << endl
        << "2 - crear un nuevo puesto de trabajo" << endl
        << "3 - ver los puestos de trabajo" << endl
        << "4 - eliminar puesto de trabajo" << endl
        << "5 - editar puesto de trabajo" << endl
        << "6 - Regresar al menu principal\n R - ";
   int opcionMenu;
   cin >> opcionMenu; // recibir opción del usuario

   return opcionMenu;

}

void imprimirRegistro( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirPuestos.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Estatus" << setw( 14 ) << "Nombre" << endl;
    leerDeArchivo.seekg( 0 );

    datosPuestos puestos;
    leerDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

    while ( !leerDeArchivo.eof() ) {
        if ( puestos.obtenerCodigo() != 0 )
        mostrarLinea( archivoImprimirSalida, puestos );
        leerDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    } //FIN DE WHILE
cout << "archivo creado exitosamente"<<endl;
}

void mostrarLinea( ostream &salida, const datosPuestos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()<< endl;

}

void crearArchivoPuesto()
{
    ofstream creditoSalida( "puest.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    datosPuestos puestoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &puestoEnBlanco ), sizeof( datosPuestos ) );
}

void nuevoRegistro( fstream &insertarEnArchivo )
{
    int codigo = obtenernCodigo( "\nEscriba el Codigo del puesto " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( datosPuestos ) );
    datosPuestos puestos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

    if ( puestos.obtenerCodigo() == 0 ) {
        char apellido[ 15 ];
        char nombre[ 10 ];
        cout<<"Escriba el Estatus del Puesto: ";
        cin>> setw( 15 ) >> apellido;
        cout<<"Escriba el Nombre del Puesto: ";
        cin>> setw( 10 ) >> nombre;

        puestos.establecerApellido( apellido );
        puestos.establecerNombre( nombre );
        puestos.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( datosPuestos ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &puestos ), sizeof( datosPuestos ) );
        cout<<"\n Puesto agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Puesto con codigo #" << codigo << " ya contiene informacion.\n" << endl;

}

int obtenernCodigo( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

}

void modificarRegistro( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Estatus\n  R - ";
    cin>>opcionAc;

    if (opcionAc== 1){
        int codigo = obtenernCodigo( "\nEscriba el codigo del Puesto que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosPuestos ));

        datosPuestos puestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

        //ACTUALIZAR EL REGISTRO
        if (puestos.obtenerCodigo() != 0 ) {
            mostrarLinea( cout, puestos );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = puestos.obtenerNombre();
            puestos.establecerNombre( nombre );
            mostrarLinea( cout, puestos );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosPuestos ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &puestos ), sizeof( datosPuestos ) );
        }
    }else if(opcionAc == 2){
        int codigo = obtenernCodigo( "Escriba el codigo del Puesto que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( datosPuestos ));

        datosPuestos puestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

        if (puestos.obtenerCodigo() != 0 ) {
                mostrarLinea( cout, puestos );
                cout << "\nEscriba el nuevo Estatus: ";
                string apellido;
                cin >> apellido;

                string apellidoAnterior = puestos.obtenerApellido();
                puestos.establecerApellido( apellido );
                mostrarLinea( cout, puestos );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( datosPuestos ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &puestos ), sizeof( datosPuestos ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-

void eliminarRegistro( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigo( "\nEscriba el codigo del Puesto a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( datosPuestos ) );
    datosPuestos puestos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

    if ( puestos.obtenerCodigo() != 0 ) {
        datosPuestos puestoEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( datosPuestos ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &puestoEnBlanco ), sizeof( datosPuestos ) );

      cout << " codigo #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "El codigo #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-

void consultarRegistro( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Apellido" << setw( 14 ) << " Nombre" << endl;
    leerDeArchivo.seekg( 0 );
    datosPuestos puestos;
    leerDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    while ( !leerDeArchivo.eof() ) {
        if ( puestos.obtenerCodigo() != 0 )
            mostrarLineaPantalla(puestos);
            leerDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO

void mostrarLineaPantalla( const datosPuestos &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()<< endl;

} //FIN -MOSTRARLINEAENOANTALLA-


Puestos::~Puestos()
{
    //dtor
}
