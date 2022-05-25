#include "Empleado.h"
#include "DatosEmpleado.h"
#include "DatosConceptos.h"
#include "datosimpuestos.h"
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

int opcionEmp();
void imprimirRegistroEmp( fstream& );
void crearArchivoCreditoEmp();
void mostrarLineaEmp( ostream&, const DatosEmpleado & );
void nuevoRegistroEmp( fstream& , fstream&, fstream&);
int obtenernCodigoEmp( const char * const );
void modificarRegistroEmp( fstream& );
void eliminarRegistroEmp( fstream& );
void consultarRegistroEmp( fstream& );
void mostrarLineaPantallaEmp( const DatosEmpleado &);
int obtenernCodigoImp( const char * );
int obtenernCodigoCon( const char * );

using namespace std;

Empleado::Empleado()
{
    fstream creditoEntradaSalida( "emp.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoEmp();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    fstream creditoEntradaSalida22( "Conceptos.dat", ios::in | ios::out | ios::binary);
    fstream creditoEntradaSalida23( "IMPUESTOS.dat", ios::in | ios::out | ios::binary);
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionEmp() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroEmp( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroEmp( creditoEntradaSalida, creditoEntradaSalida22, creditoEntradaSalida23 );
            break;
            case modificar:
                modificarRegistroEmp( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroEmp( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroEmp( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
}
int opcionEmp(){
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


    cout<<"\n\t\t\t-----------------------------------------------";
    cout<<"\n\t\t\t\t     -------------------"<<endl;
	cout<<"\t\t\t\t      |   EMPLEADOS   |"<<endl;
	cout<<"\t\t\t\t     -------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Empleado" << endl
        << "\t\t\t 3. Modificar Empleado" << endl
        << "\t\t\t 4. Eliminar Empleado" << endl
        << "\t\t\t 5. Mostrar Lista de Empleados" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t-----------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu ;

    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroEmp( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirEmpleado.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 14 ) << "Codigo" << setw( 16 )<< "Apellido" << setw( 14 ) << "Nombre" << setw( 20 ) << "Correo"
       << setw( 16 ) << "Sueldo" << right << setw( 12 ) << "Horas Extras" << endl;
    leerDeArchivo.seekg( 0 );

    DatosEmpleado empleados;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
        mostrarLineaEmp( archivoImprimirSalida, empleados );
        leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    } //FIN DE WHILE
    cout<<"\n";
    system("pause");
} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaEmp( ostream &salida, const DatosEmpleado &registro )
{
   salida << left << setw( 18 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 15 ) << registro.obtenerCorreo().data()
          << setw( 15 ) << registro.obtenerSueldo()
          << setw( 10 ) << registro.obtenerHoras()<< endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoEmp()
{
    ofstream creditoSalida( "emp.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosEmpleado empleadoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &empleadoEnBlanco ), sizeof( DatosEmpleado ) );
    cout<<"\n";
    system("pause");
}
void nuevoRegistroEmp( fstream &insertarEnArchivo, fstream &leerDeArchivoC, fstream &LeerImp)
{
    int codigo = obtenernCodigoEmp( "\nEscriba el Codigo del Empleado " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosEmpleado ) );
    datosimpuestos impuestos;
    DatosConceptos conceptos;
    DatosEmpleado empleados;
    insertarEnArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    leerDeArchivoC.read( reinterpret_cast< char * >( &conceptos ), sizeof( DatosConceptos ) );
    LeerImp.read( reinterpret_cast< char * >( &impuestos ), sizeof( datosimpuestos ) );

    if ( empleados.obtenerCodigo() == 0 ) {
        char apellido[ 15 ];
        char nombre[ 10 ];
        char correo[ 15 ];
        double sueldo;
        double impIGSS2;
        double impISR;
        double valorHE, ValHorasEx, ValIgss, ValISR;
        int horas;
        double anticipo, sueldo2;
        cout<<"Escriba el Apellido del Empleado: ";
        cin>> setw( 15 ) >> apellido;
        cout<<"Escriba el Nombre del Empleado: ";
        cin>> setw( 10 ) >> nombre;
        cout<<"Escriba el Correo del Empleado: ";
        cin>> setw( 15 ) >> correo;
        cout<<"Escriba el Sueldo del Empleado: ";
        cin>> sueldo;
        cout<<"Escriba las Horas Extras del Empleado: ";
        cin>> horas;
        cout<<"Escriba el anticipo del empleado: ";
        cin>> anticipo;

        empleados.establecerApellido( apellido );
        empleados.establecerNombre( nombre );
        empleados.establecerCorreo( correo );
        empleados.establecerSueldo( sueldo );
        sueldo2=empleados.obtenerSueldo();
        empleados.establecerHoras( horas );
        empleados.establecerHE((((sueldo2/30)/8)*1.5)*horas);
        empleados.establecerAnticipo( anticipo );

        int codigoConceptos = 1;
        impIGSS2 = conceptos.obtenerValor();
        leerDeArchivoC.seekg(( codigoConceptos - 1 ) * sizeof( DatosConceptos ));
        empleados.establecerIGSS((impIGSS2/100)*sueldo2);

        int codigoImpuestos = 1;
        impISR = impuestos.obtenerCantidad();
        LeerImp.seekg(( codigoImpuestos - 1 ) * sizeof( datosimpuestos ));
        empleados.establecerISR((impISR/100)*sueldo2);

        ValHorasEx=empleados.obtenerHE();
        ValIgss=empleados.obtenerIGSS();
        ValISR=empleados.obtenerISR();
        double ValAnt=empleados.obtenerAnticipo();
        empleados.establecerTotalF(sueldo+ValHorasEx-ValIgss-ValISR-ValAnt);
        empleados.establecerCodigo( codigo );
        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosEmpleado ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &empleados ), sizeof( DatosEmpleado ) );
        cout<<"\n Empleado agregado Exitosamente..."<<endl;
    } //FIN IF
    else
        cerr << "El Empleado con codigo #" << codigo << " ya contiene informacion.\n" << endl;
    cout<<"\n";
    system("pause");
} //FIN REGISTRO
int obtenernCodigoEmp( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroEmp( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Sueldo\n 2. Nombre\n 3. Apellido \n 4. Correo\n 5. Horas extra \n  R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Empleado que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpleado ));

        DatosEmpleado empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

        if (empleados.obtenerCodigo() != 0 ) {
            mostrarLineaEmp( cout, empleados );
            cout << "\nEscriba aumento (+) o descuento (-): ";
            double cambiosu;
            cin >> cambiosu;
            double sueldoAnterior = empleados.obtenerSueldo();
            empleados.establecerSueldo( sueldoAnterior + cambiosu );
            mostrarLineaEmp( cout, empleados );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpleado ));

            actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosEmpleado ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Empleado que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpleado ));

        DatosEmpleado empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

        //ACTUALIZAR EL REGISTRO
        if (empleados.obtenerCodigo() != 0 ) {
            mostrarLineaEmp( cout, empleados );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = empleados.obtenerNombre();
            empleados.establecerNombre( nombre );
            mostrarLineaEmp( cout, empleados );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpleado ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosEmpleado ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Empleado que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpleado ));

        DatosEmpleado empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

        if (empleados.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, empleados );
                cout << "\nEscriba el nuevo Apellido: ";
                string apellido;
                cin >> apellido;

                string apellidoAnterior = empleados.obtenerApellido();
                empleados.establecerApellido( apellido );
                mostrarLineaEmp( cout, empleados );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpleado ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosEmpleado ) );
        }
    }else if(opcionAc == 4){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Empleado que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpleado ));

        DatosEmpleado empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

        if (empleados.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, empleados );
                cout << "\nEscriba el nuevo Correo: ";
                string correo;
                cin >> correo;

                string correoAnterior = empleados.obtenerCorreo();
                empleados.establecerCorreo( correo );
                mostrarLineaEmp( cout, empleados );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpleado ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosEmpleado ) );
        }
    }
    else if(opcionAc == 5){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Empleado que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosEmpleado ));

        DatosEmpleado empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

        if (empleados.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, empleados );
                cout << "\nEscriba la nueva cantidad de horas extra: ";
                double horas;
                cin >> horas;

                double horaAnterior = empleados.obtenerHoras();
                empleados.establecerHoras( horas );
                mostrarLineaEmp( cout, empleados );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosEmpleado ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosEmpleado ) );
        }
    }
cout<<"\n";
 system("pause");
} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroEmp( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Empleado a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosEmpleado ) );
    DatosEmpleado empleados;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

    if ( empleados.obtenerCodigo() != 0 ) {
        DatosEmpleado clienteEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosEmpleado ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( DatosEmpleado ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";
cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-
void consultarRegistroEmp( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 14 ) << " Apellido" << setw( 12 ) << " Nombre" << setw( 16 ) << " Correo" << setw( 15 )
    << " Sueldo" << setw( 10 ) << "Horas Extras " << setw( 13 ) << "Anticipo"<< endl;
    leerDeArchivo.seekg( 0 );
    DatosEmpleado empleados;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
            mostrarLineaPantallaEmp(empleados);
            leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosEmpleado ) );

   } //FIN WHILE
    cout<<"\n";
    system("pause");
} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaEmp( const DatosEmpleado &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerApellido().data()
          << setw( 12 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerCorreo().data()
          << setw( 15 ) << registro.obtenerSueldo()
          << setw( 12 ) << registro.obtenerHoras()
          << setw( 15 ) << registro.obtenerAnticipo() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-
Empleado::~Empleado()
{
    //dtor
}
