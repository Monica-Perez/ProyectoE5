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

    cout << "\nEscriba su opcion" << endl
        << " 1. Empleados" << endl
        << " 2. Puestos" << endl
        << " 3. Departamentos" << endl
        << " 4. Impuestos" << endl
        << " 5. Empresas" << endl
        << " 6. Generacion de Nomina" << endl
        << " 7. Finalizar el Programa\n  R - ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}
