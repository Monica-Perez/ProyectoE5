#include <iostream>
#include "Empleado.h"
#include "Puestos.h"
#include "Departamento.h"
#include "Impuestos.h"
#include "Empresas.h"
#include "Nomina.h"
#include "Usuarios.h"
#include "Nomina.h"
#include "Conceptos.h"
#include "Transfe.h"
#include <ctime>
#include <vector>

using namespace std;

int escribirOpcion();
enum Opciones { empleados = 1, puestos, departamentos, impuestos, empresas, conceptos, nomina, bancos, FIN };

int main()
{
    Usuarios claseusuarios;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
            case empleados:
                {
                    Empleado claseempleado;// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
                }
            break;
            case puestos:
                {
                    Puestos clasepuestos;// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632

                }
            break;
            case departamentos:
                {
                    Departamento clasedepartamentos;//Realizado por Daniel Alexander Hall Alvarez - 9959-21-1395
                }
            break;
            case impuestos:
                {
                    Impuestos claseimpuestos;//Realizado por Abigail Elizabeth Vásquez Herrera - 9959-21-13777
                }
            break;
            case empresas:
                {
                    Empresas claseempresa;// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
                }
            break;
            case conceptos:
                {
                    Conceptos claseconceptos;// Realizado por Monica Gabriela Perez Velásquez - 9959-21-1840
                }
            break;
            case nomina:
                {
                    Nomina clasenomina;// Realizado por grupo
                }
            break;
            case bancos:
                {
                    Transfe clasetransfe;// Realizado por  Alan Abimael Galicia Ruano - 9959-21-3632

                }
            break;
        }
    }
    return 0;
}

int escribirOpcion(){
    system("cls");
    system("color F");

    time_t now = time(0);//Hora y fecha por Daniel Alexander Hall Alvarez - 9959-21-1395
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
    cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
    cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;

    cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA RECURSOS HUMANOS  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout<< "\n\t\t\t  1. Empleados" << endl
        << "\t\t\t  2. Puestos" << endl
        << "\t\t\t  3. Departamentos" << endl
        << "\t\t\t  4. Impuestos" << endl
        << "\t\t\t  5. Empresas" << endl
        << "\t\t\t  6. Conceptos" << endl
        << "\t\t\t  7. Generacion de Nomina" << endl
        << "\t\t\t  8. Bancos" << endl
        << "\t\t\t  9. Finalizar el Programa" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}
