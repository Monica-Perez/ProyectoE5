#include "Empleado.h"
#include <iostream>

using namespace std;

int main()
{
    int opcion=0;
    cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA RECURSOS HUMANOS  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout << "\nEscriba su opcion" << endl
        << "1 - Empleados" << endl
        << "2 - Puestos" << endl
        << "3 - Departamentos" << endl
        << "4 - Impuestos" << endl
        << "5 - Finalizar el programa\n R - ";
    cin >> opcion;

    if(opcion==1){
        Empleado claseempleado;
    }/*else if(opcion==2){
        return 0;
    }else if(opcion==3){
        return 0;
    }else if(opcion==4){
        return 0;
    }*/else if(opcion==5){
        return 0;
    }

    return 0;
}



