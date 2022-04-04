#include <iostream>
#include "Empleado.h"
#include "Puestos.h"
#include "Departamento.h"
#include "Impuestos.h"
#include "Nomina.h"

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
            {
                Empleado claseempleado;
            }
            break;
         case puestos:
            {
                Puestos clasepuestos;
            }
            break;
          case departamentos:
            {
                Departamento clasedepartamentos;
            }
            break;
          case impuestos:
            {
                Impuestos claseimpuestos;
            }
            break;
          case nomina:
            {
                Nomina clasenomina;
            }
            break;
        }
    }

    return 0;
}


int escribirOpcion(){
   // mostrar opciones disponibles
   cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA RECURSOS HUMANOS  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout << "\nEscriba su opcion" << endl
        << "1 - Empleados" << endl
        << "2 - Puestos" << endl
        << "3 - Departamentos" << endl
        << "4 - Impuestos" << endl
        << "5 - Generacion de Nomina" << endl
        << "6 - Finalizar el Programa\n R - ";
   int opcionMenu;
   cin >> opcionMenu; // recibir opción del usuario

   return opcionMenu;

}
