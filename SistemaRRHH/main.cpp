#include <iostream>
#include "Empleado.h"
#include "Puestos.h"
#include "Departamento.h"
#include "Impuestos.h"
#include "Empresas.h"
#include "Nomina.h"
#include "Usuarios.h"

using namespace std;

int escribirOpcion();
enum Opciones { empleados = 1, puestos, departamentos, impuestos, empresas, nomina, FIN };

int main()
{
    Usuarios claseusuarios;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
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
            case empresas:
                {
                    Empresas claseempresa;
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
    system("cls");
    cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA RECURSOS HUMANOS  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. Empleados" << endl
        << "\t\t\t  2. Puestos" << endl
        << "\t\t\t  3. Departamentos" << endl
        << "\t\t\t  4. Impuestos" << endl
        << "\t\t\t  5. Empresas" << endl
        << "\t\t\t  6. Generacion de Nomina" << endl
        << "\t\t\t  7. Finalizar el Programa" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}
