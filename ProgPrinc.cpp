#include <iostream>
#include <fstream>
//#include "struct.cpp"
#include "logicaArch.cpp"
using namespace std;



void intrcmb(Alumno a, Alumno b)
{
    Alumno aux;
    aux = a;
    a = b;
    b = aux;
}

void OrdxBur(short card)
{
    int i, j, bandera;
    Alumno aux;
    for(i = 1; i < card; i++)
    {
        bandera = 0;
        for(j = card-1; j>=i; j--)
        {
            if(alu[j-1].dni>alu[j].dni)
            {
                intrcmb(alu[j],alu[j-1]);
                bandera = 1;
            }
        }
        if (bandera == 0) break;
    }
}

int busquedaBinaria(short card,int auxDNI)
{
    int prim=1;
    int medio=0;
    int ult = card;
    

    while(prim <= ult)
    {
        medio = (prim+ult)/2;
        if(auxDNI == alu[medio].dni)
        {
            return medio;
        }else
        {
            if(alu[medio].dni > auxDNI)
            {
                ult = medio - 1;
            }else
            {
                prim = medio + 1;
            }
        }
    }
    return -1;

}

void cantidadAlumnos(short &card)
{
    cout << "Ingrese la cantidad de alumnos" << endl;
    cin >> card;
    for (int i = 1; i < card ; i++)
    {
        cout << "Ingrese dni para el " << i << " alumno" << endl;
        cin >> alu[i].dni;
        
        cout << "Ingrese edad para el " << i << " alumno" << endl;
        cin >> alu[i].edad;

        cout << "Ingrese nombre para el " << i << " alumno" << endl;
        cin >> alu[i].nombre;

        cout << "Ingrese direccion para el " << i << " alumno" << endl;
        cin >> alu[i].dir;
    }
    OrdxBur(card);
}






short menu()
{
    int dniAux;
    short opc;
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver datos de un alumno" << endl;
    cout << "2. Reescribir datos" << endl;
    cout << "3. Eliminar datos" << endl;
    cout << "4. Ver todos los alumnos" << endl;
    cout << "6. Finalizar" << endl;
    cin >> opc;

    return opc;
    
    
} 


int main(int argc, char const *argv[])
{
    short card;
    int dniAux;



    cantidadAlumnos(card);

    do
    {
        switch(menu())
        {
            case 1:
                cout << "Ingrese el numero de dni a buscar" << endl;
                cin >> dniAux;
                break;

        }
    } while(menu()!=6);

    return 0;
}




