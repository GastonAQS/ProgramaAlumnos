#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ALU = 40;

struct Alumno
{
    int dni;
    int edad;
    string nombre;
    string dir;
};
// --------------------------------------------------------------------------------------------------------
void intrcmb(Alumno* a, Alumno* b)
{
    Alumno* aux;
    aux = a;
    a = b;
    b = aux;
}
// --------------------------------------------------------------------------------------------------------
void OrdxBur(Alumno* alu[],short card)
{
    int i, j, bandera;
    Alumno aux;
    for(i = 1; i < card; i++)
    {
        bandera = 0;
        for(j = card-1; j>=i; j--)
        {
            if(alu[j-1]->dni>alu[j]->dni)
            {
                intrcmb(alu[j],alu[j-1]);
                bandera = 1;
            }
        }
        if (bandera == 0) break;
    }
}
// --------------------------------------------------------------------------------------------------------
void guardarArch(Alumno* alu[],fstream &arch,short card)
{
    for(int i = 1; i < card; i++)
    {
        arch << alu[i]->dni;
        arch << alu[i]->edad;
        arch << alu[i]->nombre;
        arch << alu[i]->dir;
    }
}
// --------------------------------------------------------------------------------------------------------
void leerArch(Alumno* alu[],fstream arch, short card)
{
    for(int i = 1; i < card; i++)
    {
        arch >> alu[i]->dni;
        arch >> alu[i]->edad;
        arch >> alu[i]->nombre;
        arch >> alu[i]->dir;
    }
}
// --------------------------------------------------------------------------------------------------------
int busquedaBinaria(Alumno* alu[], short card,int auxDNI)
{
    int prim=1;
    int medio=0;
    int ult = card;
    

    while(prim <= ult)
    {
        medio = (prim+ult)/2;
        if(auxDNI == alu[medio]->dni)
        {
            return medio;
        }else
        {
            if(alu[medio]->dni > auxDNI)
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
// --------------------------------------------------------------------------------------------------------
void cantidadAlumnos(Alumno* alu[],short &card)
{
    cout << "Ingrese la cantidad de alumnos" << endl;
    cin >> card;
    for (int i = 1; i < card ; i++)
    {
        cout << "Ingrese dni para el " << i << " alumno" << endl;
        cin >> alu[i]->dni;
        
        cout << "Ingrese edad para el " << i << " alumno" << endl;
        cin >> alu[i]->edad;

        cout << "Ingrese nombre para el " << i << " alumno" << endl;
        cin >> alu[i]->nombre;

        cout << "Ingrese direccion para el " << i << " alumno" << endl;
        cin >> alu[i]->dir;
    }
    OrdxBur(alu,card);
}
// --------------------------------------------------------------------------------------------------------
bool eliminarAlumno(Alumno* alu[], short card,int posicion)
{
    if(posicion == -1) return false;
    alu[posicion]->dni=-1;
    alu[posicion]->nombre="";
    alu[posicion]->edad=-1;
    alu[posicion]->dir="";
    OrdxBur(alu,card);
    return true;
}
// --------------------------------------------------------------------------------------------------------
void busquedaAlumno(Alumno* alu[],int dniAux, short card)
{
    int aux;
    aux = busquedaBinaria(alu,card,dniAux);
                if(aux==-1)
                {
                    cout << "No se encontro el alumno" << endl;
                }else
                {
                    cout << "Nombre: " << alu[aux]->nombre << endl;
                    cout << "Edad: " << alu[aux]->edad << endl;
                }
}
void menu()
{
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver datos de un alumno" << endl;
    cout << "2. Eliminar datos" << endl;
    cout << "3. Ver todos los alumnos" << endl;
    cout << "4. Cargar datos" << endl;
    cout << "5. Finalizar" << endl;
} 
// --------------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    short card,opc;
    int dniAux;
    Alumno* alu[MAX_ALU];
    fstream arch;
    arch.open("alumnos.txt",ios::in|ios::out);
    guardarArch(alu,arch,card);
    
    do
    {
        menu();
        cin >> opc;
        switch(opc)
        {
            case 1:
                cout << "Ingrese el numero de dni a buscar" << endl;
                cin >> dniAux;
                busquedaAlumno(alu,dniAux,card);
                break;
            case 2:
                cout << "Ingrese el dni del alumno a eliminar" << endl;
                cin >> dniAux;
                if(eliminarAlumno(alu,card,busquedaBinaria(alu,card,dniAux)))
                {
                    cout << "Eliminado exitosamente" << endl;
                }else
                {
                    cout << "DNI invalido" << endl;
                }
                break;
            case 3:
                cout << "Mostrando alumnos..." << endl;
                for(int i = 1; i < card; i++)
                {
                    cout << "DNI: " << alu[i]->dni << endl;
                    cout << "-----------------" << endl;
                }
                break;
            case 4:
                cantidadAlumnos(alu,card);
                break;
            case 5:
                cout << "Finalizando..." << endl;
                break;
            default:
                cout << "Opcion invalida";
                break;
        }
    } while(opc!=5);

    return 0;
}