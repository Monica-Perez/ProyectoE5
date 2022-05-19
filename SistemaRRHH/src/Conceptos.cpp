#include "Conceptos.h"
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

int opcionCon();
void imprimirRegistroCon( fstream& );
void crearArchivoCreditoCon();
void mostrarLineaCon( ostream&, const DatosConceptos & );
void nuevoRegistroCon( fstream& );
int obtenernCodigoCon( const char * const );
void modificarRegistroCon( fstream& );
void eliminarRegistroCon( fstream& );
void consultarRegistroCon( fstream& );
void mostrarLineaPantallaCon( const DatosConceptos &);

using namespace std;

Conceptos::Conceptos()
{
    fstream creditoEntradaSalida( "Conceptos.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoCon();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionCon() ) != FIN ) {
        switch ( opcion ) {
             case agregar:
                imprimirRegistroCon( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroCon( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroCon( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroCon( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroCon( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
}
int opcionCon(){
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
	cout<<"\t\t\t\t |  CONCEPTOS  |"<<endl;
	cout<<"\t\t\t\t-----------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Concepto" << endl
        << "\t\t\t 3. Modificar Concepto" << endl
        << "\t\t\t 4. Eliminar Concepto" << endl
        << "\t\t\t 5. Mostrar Lista de Conceptos" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu ;

    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroCon( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirConcepto.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 20 )<< "Nombre" << setw( 16 ) << "Efecto" << setw( 16 ) << "Estado"<< right
       << setw( 10 ) << "Valor" << endl;
    leerDeArchivo.seekg( 0 );

    DatosConceptos conceptos;
    leerDeArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );

    while ( !leerDeArchivo.eof() ) {
        if ( conceptos.obtenerCodigo() != 0 )
        mostrarLineaCon( archivoImprimirSalida, conceptos );
        leerDeArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );
    } //FIN DE WHILE
    cout<<"\n";
    system("pause");
} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaCon( ostream &salida, const DatosConceptos &registro )
{
   salida << left << setw( 13 ) << registro.obtenerCodigo()
          << setw( 19 ) << registro.obtenerNombre().data()
          << setw( 14 ) << registro.obtenerEfecto()
          << setw( 17 ) << registro.obtenerEstado().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed<< showpoint << registro.obtenerValor() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoCon()
{
    ofstream creditoSalida( "Conceptos.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosConceptos conceptoEnBlanco;
    for ( int i = 0; i < 100; i++ ){
        creditoSalida.write(reinterpret_cast< const char * >( &conceptoEnBlanco ), sizeof( DatosConceptos ) );
    }
    cout<<"\n";
    system("pause");
}
void nuevoRegistroCon( fstream &insertarEnArchivo )
{
    int codigo = obtenernCodigoCon( "\nEscriba el Codigo del Concepto " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosConceptos ) );
    DatosConceptos conceptos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );

    if ( conceptos.obtenerCodigo() == 0 ) {
        char nombre[ 20 ];
        char efecto[ 15 ];
        char estado[ 15 ];
        float valor;
        cout<<"Escriba el Nombre del Concepto: ";
        cin>> setw( 20 ) >> nombre;
        cout<<"Escriba el Efecto del Concepto (+/-): ";
        cin>> setw( 10 ) >> efecto;
        cout<<"Escriba el Estado del Concepto: ";
        cin>> setw( 15 ) >> estado;
        cout<<"Escriba el Valor del Concepto: ";
        cin>> valor;
        conceptos.establecerNombre( nombre );
        conceptos.establecerEfecto( efecto );
        conceptos.establecerEstado( estado );
        conceptos.establecerValor( valor );
        conceptos.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosConceptos ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &conceptos ), sizeof( DatosConceptos ) );
        cout<<"\n Concepto agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Concepto con codigo #" << codigo << " ya contiene informacion.\n" << endl;
    cout<<"\n";
    system("pause");
} //FIN REGISTRO
int obtenernCodigoCon( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroCon( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Efecto\n 3. Estado \n 4. Valor\n  R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenernCodigoCon( "\nEscriba el codigo del Concepto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosConceptos ));

        DatosConceptos conceptos ;
        actualizarArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );

        if (conceptos.obtenerCodigo() != 0 ) {
            mostrarLineaCon( cout, conceptos  );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;
            string nombreAnterior = conceptos.obtenerNombre();
            conceptos.establecerNombre( nombre );
            mostrarLineaCon( cout, conceptos  );


            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosConceptos ));

            actualizarArchivo.write(reinterpret_cast< const char * >( &conceptos  ), sizeof( DatosConceptos ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenernCodigoCon( "\nEscriba el codigo del Concepto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosConceptos ));

        DatosConceptos conceptos ;
        actualizarArchivo.read( reinterpret_cast< char * >( &conceptos  ), sizeof( DatosConceptos ) );

        //ACTUALIZAR EL REGISTRO
        if (conceptos.obtenerCodigo() != 0 ) {
            mostrarLineaCon( cout, conceptos  );
            cout << "\nEscriba el nuevo Efecto: ";
            string efecto;
            cin >> efecto;

            string efectoAnterior = conceptos.obtenerEfecto();
            conceptos.establecerEfecto( efecto );
            mostrarLineaCon( cout, conceptos  );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosConceptos ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &conceptos  ), sizeof( DatosConceptos ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenernCodigoCon( "\nEscriba el codigo del Concepto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosConceptos));

        DatosConceptos conceptos ;
        actualizarArchivo.read( reinterpret_cast< char * >( &conceptos  ), sizeof( DatosConceptos ) );

        if (conceptos.obtenerCodigo() != 0 ) {
                mostrarLineaCon( cout, conceptos  );
                cout << "\nEscriba el nuevo Estado: ";
                string estado;
                cin >> estado;

                string estadoAnterior = conceptos.obtenerEstado();
                conceptos.establecerEstado( estado );
                mostrarLineaCon( cout, conceptos  );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosConceptos ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &conceptos  ), sizeof( DatosConceptos ) );
        }
    }else if(opcionAc == 4){
        int codigo = obtenernCodigoCon( "\nEscriba el codigo del Concepto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosConceptos ));

        DatosConceptos conceptos ;
        actualizarArchivo.read( reinterpret_cast< char * >( &conceptos  ), sizeof( DatosConceptos ) );

        if (conceptos.obtenerCodigo() != 0 ) {
                mostrarLineaCon( cout, conceptos  );
                cout << "\nEscriba el nuevo Valor: ";
                float valor;
                cin >> valor;

                float valorAnterior = conceptos.obtenerValor();
                conceptos.establecerValor( valor );
                mostrarLineaCon( cout, conceptos  );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosConceptos ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &conceptos  ), sizeof( DatosConceptos ) );
        }
    }
cout<<"\n";
 system("pause");
} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroCon( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigoCon( "\nEscriba el codigo del concepto a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosConceptos ) );
    DatosConceptos conceptos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );

    if ( conceptos.obtenerCodigo() != 0 ) {
        DatosConceptos clienteEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosConceptos ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( DatosConceptos ) );

      cout << " Concepto #" << codigo << " eliminado Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "El Concepto #" << codigo << " esta vacia.\n";
cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-

void consultarRegistroCon( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Nombre" << setw( 14 ) << " Efecto" << setw( 16 ) << " Estado" << right << setw( 10 ) << " Valor" << endl;
    leerDeArchivo.seekg( 0 );
    DatosConceptos conceptos;
    leerDeArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );
    while ( !leerDeArchivo.eof() ) {
        if ( conceptos.obtenerCodigo() != 0 )
            mostrarLineaPantallaCon(conceptos);
            leerDeArchivo.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );

   } //FIN WHILE
cout<<"\n";
 system("pause");
} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaCon( const DatosConceptos &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 14 ) << registro.obtenerEfecto().data()
          << setw( 16 ) << registro.obtenerEstado().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerValor() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-
Conceptos::~Conceptos()
{
    //dtor
}
