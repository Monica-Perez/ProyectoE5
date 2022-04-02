#include <iostream>
#include "Empleado.h"

using namespace std;

int escribirOpcion();

enum Opciones { empleados = 1, puestos, departamentos, impuestos, nomina, FIN };

int main()
{
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {

         // crear el archivo de texto a partir del archivo de registros
         case empleados:
            Empleado claseempleado;
            break;
        }
    }



    return 0;
}

int escribirOpcion()
{
    int opcionMenu;
    cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA RECURSOS HUMANOS  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout << "\nEscriba su opcion" << endl
        << "1 - Empleados" << endl
        << "2 - Puestos" << endl
        << "3 - Departamentos" << endl
        << "4 - Impuestos" << endl
        << "5 - generación de nomina" << endl
        << "6 - Finalizar el programa\n R - ";
    cin >> opcionMenu;
    return opcionMenu;
}
