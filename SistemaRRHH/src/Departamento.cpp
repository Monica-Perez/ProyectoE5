#include "Departamento.h"
#include "DatosDepartamento.h"
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

int opcionDepa();
void crearArchivoCreditoDepa();
void imprimirRegistroDepa( fstream& );
void mostrarLineaDepa( ostream&, const DatosDepartamento & );
void nuevoRegistroDepa( fstream& );
int obtenernCodigoDepa( const char * const );
void modificarRegistroDepa( fstream& );
void eliminarRegistroDepa( fstream& );
void consultarRegistroDepa( fstream& );
void mostrarLineaPantallaDepa( const DatosDepartamento &);
using namespace std;

Departamento::Departamento()
{
    fstream creditoEntradaSalida( "DEPARTAMENTOS.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoDepa();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion1;
    while ( ( opcion1 = opcionDepa() ) != FIN ) {
        switch ( opcion1 ) {
            case agregar:
                imprimirRegistroDepa( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroDepa( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroDepa( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroDepa( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroDepa( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE

}
int opcionDepa(){
    //system("cls");

    cout<<"\n\t\t\t---------------------------------"<<endl;
    cout<<"\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t|  DEPARTAMENTOS  |"<<endl;
	cout<<"\t\t\t\t------------------"<<endl;


    cout<< "\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Departamento" << endl
        << "\t\t\t 3. Modificar Departamento" << endl
        << "\t\t\t 4. Eliminar Departamento" << endl
        << "\t\t\t 5. Mostrar Lista Departamento" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        << "\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";

    int opciionMenu;
    cin >> opciionMenu;

    return opciionMenu;

}
void imprimirRegistroDepa( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirDepa.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "NombreDepartamento" << right << setw( 10 ) << "Area" << endl;
    leerDeArchivo.seekg( 0 );

    DatosDepartamento departamentos;
    leerDeArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );

    while ( !leerDeArchivo.eof() ) {
        if ( departamentos.obtenerCodigo() != 0 )
        mostrarLineaDepa( archivoImprimirSalida, departamentos );
        leerDeArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaDepa( ostream &salida, const DatosDepartamento &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data() << endl;


}//FIN -MOSTRARLINEA-
void crearArchivoCreditoDepa()
{
    ofstream creditoSalida( "DEPARTAMENTOS.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosDepartamento empleadoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &empleadoEnBlanco ), sizeof( DatosDepartamento ) );
}
void nuevoRegistroDepa( fstream &insertarEnArchivo )
{
    int codigo = obtenernCodigoDepa( "\nEscriba el Codigo " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosDepartamento ) );
    DatosDepartamento departamentos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );

    if ( departamentos.obtenerCodigo() == 0 ) {
        char apellido[ 15 ];
        char nombre[ 10 ];

        cout<<"Escriba el Nombre del departamento: ";
        cin>> setw( 15 ) >> apellido;
        cout<<"Escriba el Nombre el area: ";
        cin>> setw( 10 ) >> nombre;

        departamentos.establecerApellido( apellido );
        departamentos.establecerNombre( nombre );
        departamentos.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosDepartamento ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &departamentos ), sizeof( DatosDepartamento ) );
        cout<<"\n Departamento agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Departamento con codigo #" << codigo << " ya contiene informacion.\n" << endl;

} //FIN REGISTRO
int obtenernCodigoDepa( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroDepa( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Area \n 2. Nombre\n   R - ";
    cin>>opcionAc;

     if (opcionAc== 1){
        int codigo = obtenernCodigoDepa( "\nEscriba el codigo del Departamento que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosDepartamento ));

        DatosDepartamento departamentos;
        actualizarArchivo.read( reinterpret_cast< char * >( &departamentos), sizeof( DatosDepartamento ) );

        //ACTUALIZAR EL REGISTRO
        if (departamentos.obtenerCodigo() != 0 ) {
            mostrarLineaDepa( cout, departamentos );
            cout << "\nEscriba el Nuevo Nombre de Area: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = departamentos.obtenerNombre();
            departamentos.establecerNombre( nombre );
            mostrarLineaDepa( cout, departamentos );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosDepartamento ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &departamentos ), sizeof( DatosDepartamento ) );
        }
    }else if(opcionAc == 2){
        int codigo = obtenernCodigoDepa( "Escriba el codigo del Departamento que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosDepartamento ));

        DatosDepartamento departamentos;
        actualizarArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );

        if (departamentos.obtenerCodigo() != 0 ) {
                mostrarLineaDepa( cout, departamentos );
                cout << "\nEscriba el nuevo nombre departamento: ";
                string apellido;
                cin >> apellido;

                string apellidoAnterior = departamentos.obtenerApellido();
                departamentos.establecerApellido( apellido );
                mostrarLineaDepa( cout, departamentos );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosDepartamento ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &departamentos ), sizeof( DatosDepartamento ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroDepa( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigoDepa( "\nEscriba el codigo del Departamento a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosDepartamento ) );
    DatosDepartamento departamentos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );

    if ( departamentos.obtenerCodigo() != 0 ) {
        DatosDepartamento clienteEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosDepartamento ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( DatosDepartamento ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-
void consultarRegistroDepa( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << "Nombre Depa" << right << setw( 10 ) << " Area" << endl;
    leerDeArchivo.seekg( 0 );
    DatosDepartamento departamentos;
    leerDeArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );
    while ( !leerDeArchivo.eof() ) {
        if ( departamentos.obtenerCodigo() != 0 )
            mostrarLineaPantallaDepa(departamentos);
            leerDeArchivo.read( reinterpret_cast< char * >( &departamentos ), sizeof( DatosDepartamento ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaDepa( const DatosDepartamento &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerNombre().data()<< endl;

} //FIN -MOSTRARLINEAENOANTALLA-
Departamento::~Departamento()
{
    //dtor
}
