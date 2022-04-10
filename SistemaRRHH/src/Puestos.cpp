#include "Puestos.h"
#include "datosPuestos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

void nuevoRegistroPuesto( fstream& );
int obtenernCodigoPuesto( const char * const );
void mostrarLineaP( ostream&, const datosPuestos & );
void imprimirRegistroPuesto( fstream& );
void crearArchivoPuesto();
void modificarRegistroPuesto( fstream& );
void eliminarRegistroPuesto( fstream& );
void consultarRegistroPuesto( fstream& );
void mostrarLineaPantallaP( const datosPuestos &);

enum Optios { imprim = 1, nuevo = 2, leer, eliminar, editar, regresar};

Puestos::Puestos()
{
    cout<<"\n\t\t\t---------------------------------"<<endl;
    cout<<"\t\t\t\t----------------"<<endl;
	cout<<"\t\t\t\t |   PUESTOS  |"<<endl;
	cout<<"\t\t\t\t----------------"<<endl;

	fstream puestoEntradaSalida( "puest.dat", ios::in | ios::out | ios::binary);
    if ( !puestoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoPuesto();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
   int opcionP=0;

    while ( ( opcionP = escribirOption() ) != regresar ) {

        switch ( opcionP ) {

         case imprim:
            {
                imprimirRegistroPuesto( puestoEntradaSalida );
            }
            break;
         case nuevo:
            {
                nuevoRegistroPuesto( puestoEntradaSalida );
            }
            break;
         case leer:
            {
                consultarRegistroPuesto( puestoEntradaSalida );

            }
            break;
          case eliminar:
            {
                eliminarRegistroPuesto( puestoEntradaSalida );
            }
            break;
          case editar:
            {
                modificarRegistroPuesto( puestoEntradaSalida );
            }
            break;
            break;
        }
        puestoEntradaSalida.clear();
    }
}



int Puestos::escribirOption()
{
    cout<<"\n\t\t\t   --------------------------"<<endl;
	cout<<"\t\t\t    |   Modulo de Puestos  |"<<endl;
	cout<<"\t\t\t   --------------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Crear un archivo de texto para imprimir" << endl
        << "\t\t\t 2. Crear un nuevo puesto de trabajo" << endl
        << "\t\t\t 3. Ver los puestos de trabajo" << endl
        << "\t\t\t 4. Eliminar puesto de trabajo" << endl
        << "\t\t\t 5. Editar puesto de trabajo" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        << "\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenuP;
   cin >> opcionMenuP; // recibir opción del usuario

   return opcionMenuP;

}

void imprimirRegistroPuesto( fstream &leerDeArchivoP )
{
    ofstream archivoImprimirSalidaP( "ImprimirPuestos.txt", ios::out );
    if ( !archivoImprimirSalidaP ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalidaP << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Estatus" << setw( 14 ) << "Nombre" << endl;
    leerDeArchivoP.seekg( 0 );

    datosPuestos puestos;
    leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

    while ( !leerDeArchivoP.eof() ) {
        if ( puestos.obtenerCodigoP() != 0 )
        mostrarLineaP( archivoImprimirSalidaP, puestos );
        leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    } //FIN DE WHILE
cout << "archivo creado exitosamente"<<endl;
}

void mostrarLineaP( ostream &salida, const datosPuestos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigoP()
          << setw( 16 ) << registro.obtenerEstatus().data()
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

void nuevoRegistroPuesto( fstream &insertarEnArchivo )
{
    int codigoP = obtenernCodigoPuesto( "\nEscriba el Codigo del puesto " );
    insertarEnArchivo.seekg( ( codigoP - 1 ) * sizeof( datosPuestos ) );
    datosPuestos puestos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

    if ( puestos.obtenerCodigoP() == 0 ) {
        char Estatus[ 15 ];
        char nombreP[ 10 ];
        cout<<"Escriba el Estatus del Puesto: ";
        cin>> setw( 15 ) >> Estatus;
        cout<<"Escriba el Nombre del Puesto: ";
        cin>> setw( 10 ) >> nombreP;

        puestos.establecerEstatus( Estatus );
        puestos.establecerNombrePuestos( nombreP );
        puestos.establecerCodigoP( codigoP );

        insertarEnArchivo.seekp( ( codigoP - 1 ) * sizeof( datosPuestos ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &puestos ), sizeof( datosPuestos ) );
        cout<<"\n Puesto agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Puesto con codigo #" << codigoP << " ya contiene informacion.\n" << endl;

}

int obtenernCodigoPuesto( const char * const indicador )
{
   int codigoP;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigoP;

    } while ( codigoP < 1 || codigoP > 100 );

   return codigoP;

}

void modificarRegistroPuesto( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Estatus\n  R - ";
    cin>>opcionAc;

    if (opcionAc== 1){
        int codigoP = obtenernCodigoPuesto( "\nEscriba el codigo del Puesto que desea Modifcar" );

        actualizarArchivo.seekg(( codigoP - 1 ) * sizeof( datosPuestos ));

        datosPuestos puestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

        //ACTUALIZAR EL REGISTRO
        if (puestos.obtenerCodigoP() != 0 ) {
            mostrarLineaP( cout, puestos );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombreP;
            cin >> nombreP;

            string nombreAnterior = puestos.obtenerNombre();
            puestos.establecerNombrePuestos( nombreP );
            mostrarLineaP( cout, puestos );

            actualizarArchivo.seekp(( codigoP - 1 ) * sizeof( datosPuestos ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &puestos ), sizeof( datosPuestos ) );
        }
    }else if(opcionAc == 2){
        int codigoP = obtenernCodigoPuesto( "Escriba el codigo del Puesto que desea Modifcar" );

        actualizarArchivo.seekg(( codigoP - 1 ) * sizeof( datosPuestos ));

        datosPuestos puestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

        if (puestos.obtenerCodigoP() != 0 ) {
                mostrarLineaP( cout, puestos );
                cout << "\nEscriba el nuevo Estatus: ";
                string Estatus;
                cin >> Estatus;

                string apellidoAnterior = puestos.obtenerEstatus();
                puestos.establecerEstatus( Estatus );
                mostrarLineaP( cout, puestos );

                actualizarArchivo.seekp(( codigoP - 1 ) * sizeof( datosPuestos ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &puestos ), sizeof( datosPuestos ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-

void eliminarRegistroPuesto( fstream &eliminarDeArchivo )
{
    int codigoP = obtenernCodigoPuesto( "\nEscriba el codigo del Puesto a Eliminar" );
    eliminarDeArchivo.seekg( ( codigoP - 1 ) * sizeof( datosPuestos ) );
    datosPuestos puestos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

    if ( puestos.obtenerCodigoP() != 0 ) {
        datosPuestos puestoEnBlanco;
        eliminarDeArchivo.seekp( ( codigoP - 1 ) * sizeof( datosPuestos ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &puestoEnBlanco ), sizeof( datosPuestos ) );

      cout << " codigo #" << codigoP << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "El codigo #" << codigoP << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-

void consultarRegistroPuesto( fstream &leerDeArchivoP )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << "Estatus" << setw( 14 ) << " Nombre" << endl;
    leerDeArchivoP.seekg( 0 );
    datosPuestos puestos;
    leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );
    while ( !leerDeArchivoP.eof() ) {
        if ( puestos.obtenerCodigoP() != 0 )
            mostrarLineaPantallaP(puestos);
            leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( datosPuestos ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO

void mostrarLineaPantallaP( const datosPuestos &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigoP()
          << setw( 16 ) << registro.obtenerEstatus().data()
          << setw( 14 ) << registro.obtenerNombre().data()<< endl;

} //FIN -MOSTRARLINEAENOANTALLA-


Puestos::~Puestos()
{
    //dtor
}
