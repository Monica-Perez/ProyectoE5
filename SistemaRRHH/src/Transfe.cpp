#include "Transfe.h"
#include "DatosEmpleado.h"
#include "DatosTransfe.h"

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

void crearArchivoCreditoTrans();
void nuevoRegistroTransfe( fstream& ,fstream&);
void consultarRegistroTransfe( fstream& );
void mostrarLineaPantallaTransfe(const DatosTransfe &);
int obtenernCodigoTrans( const char * const );
void eliminarRegistroTransfe( fstream &);

// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632

Transfe::Transfe()

{

    fstream creditoEntradaSalida11( "Transferencia.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida11 ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoTrans();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
     system("cls");
	fstream creditoEntradaSalida( "emp.dat", ios::in | ios::out | ios::binary);
	nuevoRegistroTransfe(creditoEntradaSalida, creditoEntradaSalida11);
	consultarRegistroTransfe(creditoEntradaSalida11);
	eliminarRegistroTransfe(creditoEntradaSalida11);

}

void crearArchivoCreditoTrans()
{
    ofstream creditoSalida11( "Transferencia.dat", ios::out | ios::binary );
    if ( !creditoSalida11 ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosTransfe TransferenciaEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida11.write(reinterpret_cast< const char * >( &TransferenciaEnBlanco ), sizeof( DatosTransfe ) );
    cout<<"\n";
    system("pause");
}

void nuevoRegistroTransfe( fstream &LeerDeEmpleados, fstream &InsertarenTransfe)
{
    int CodTransfe = 1;
    DatosTransfe Bancos;
    LeerDeEmpleados.seekg( 0 );
    InsertarenTransfe.seekg( ( CodTransfe - 1 ) * sizeof( DatosTransfe ) );
    DatosEmpleado empleados;
    LeerDeEmpleados.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    InsertarenTransfe.read( reinterpret_cast< char * >( &Bancos ), sizeof( DatosTransfe ) );

    if ( Bancos.obtenercodicoTransfe() == 0 ) {
        double contador2=0;
        double TransferenciaB;
        LeerDeEmpleados.seekg( 0 );

        int codigo=1;
        LeerDeEmpleados.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
        LeerDeEmpleados.seekg( ( codigo - 1 ) * sizeof( DatosEmpleado ) );
        while ( !LeerDeEmpleados.eof() )
        {
            if ( empleados.obtenerCodigo() != 0 )

                empleados.obtenerTotalF();
                LeerDeEmpleados.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
                contador2 += empleados.obtenerTotalF();

        }
        Bancos.establecerTransfe(contador2);
        Bancos.EstablecerCodTransfe( CodTransfe );
        InsertarenTransfe.seekp( ( CodTransfe - 1 ) * sizeof( DatosTransfe ) );
        InsertarenTransfe.write( reinterpret_cast< const char * >( &Bancos ), sizeof( DatosTransfe ) );
        cout<<"\n Cálculo de transferencia realizado con exito..."<<endl;
    } //FIN IF
    else
        cerr << "La transferencia #" << CodTransfe << " ya contiene informacion.\n" << endl;
    cout<<"\n";
    system("pause");
} //FIN REGISTRO

int obtenernCodigoTrans( const char * const indicador )
{
   int CodTransfe;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> CodTransfe;

    } while ( CodTransfe < 1 || CodTransfe > 100 );

   return CodTransfe;

} //FIN -OBTENERCODIGO-

void consultarRegistroTransfe(fstream &leerTransfe)
{
    cout << left << setw( 25 ) << "\nTranferencia" << endl;
    leerTransfe.seekg( 0 );
    DatosTransfe Bancos;
    leerTransfe.read( reinterpret_cast< char * >( &Bancos ), sizeof( DatosTransfe ) );
        if ( Bancos.obtenercodicoTransfe() != 0 )
            mostrarLineaPantallaTransfe(Bancos);
            leerTransfe.read( reinterpret_cast< char * >( &Bancos ), sizeof( DatosTransfe ) );
   cout<<endl<<endl;
   system("pause");
} //FIN CONSULTAR REGISTRO

void eliminarRegistroTransfe( fstream &eliminarDeArchivoT )
{
    int CodTransfe = 1;
    eliminarDeArchivoT.seekg( ( CodTransfe - 1 ) * sizeof( DatosTransfe ) );
    DatosTransfe Bancos;
    eliminarDeArchivoT.read( reinterpret_cast< char * >( &Bancos ), sizeof( DatosTransfe ) );

    if ( Bancos.obtenercodicoTransfe() != 0 ) {
        DatosTransfe BancoEnBlanco;
        eliminarDeArchivoT.seekp( ( CodTransfe - 1 ) * sizeof( DatosTransfe ) );
        eliminarDeArchivoT.write( reinterpret_cast< const char * >( &BancoEnBlanco ), sizeof( DatosTransfe ) );

      cout << " Transferencia #" << CodTransfe << " Fuera.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << CodTransfe << " esta vacia.\n";
cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-

void mostrarLineaPantallaTransfe( const DatosTransfe &registro)
{
   cout <<" "<< setw( 25 ) << registro.obtenerTransfe()
   << right <<endl;
} //FIN -MOSTRARLINEAENOANTALLA-

Transfe::~Transfe()
{
    //dtor
}
