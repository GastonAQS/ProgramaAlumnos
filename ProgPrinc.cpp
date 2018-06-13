#include <iostream>
#include <fstream>
#include <string>
#include <bits/basic_string.h>
#include <stdlib.h>
using namespace std;

const int MAX_ALU = 40;

struct Alumno
{
    int dni;
    int edad;
    string nombre;
    string dir;
};
// Declaracion del registro alumnos y sus campos.
void intrcmb(Alumno a, Alumno b)
{
    Alumno aux;
    aux = a;
    a = b;
    b = aux;
}
// Funcion que intercambia a por b, utilizada en el ordenamiento.
void OrdxBur(Alumno alu[],short card)
{
    int i, j, bandera;
    Alumno aux;
    for(i = 2; i < card; i++)
    {
        bandera = 0;
        for(j = 1; j<card; j++)
        {
            cout << "burbuja";
            if(alu[j].dni>alu[j+1].dni)
            {
                intrcmb(alu[j+1],alu[j]);
                bandera = 1;
            }
        }
        if (bandera == 0) break;
    }
}
// Ordena el registro en base a numeros de dni para poder utilizar busqueda binaria.
void guardarArch(Alumno alu[],ofstream &arch,short card)
{
    arch.open("alumnos.txt");
    for(int i = 1; i < card; i++)
    {
        //cout << "j";
        arch << alu[i].dni << endl;;
        arch << alu[i].edad << endl;
        arch << alu[i].nombre << endl;
        arch << alu[i].dir << endl;
    }
    arch.close();
}
// Guarda los datos de los alumnos en alumnos.txt.
void guarda_card(ofstream &archCardO,short &card)
{
    archCardO.open("card.txt");
    archCardO << card;
    archCardO.close();
}
// Guarda en el archivo card.txt la cardinalidad.
void carga_card(ifstream &archCardI,short &card)
{
    string cardS;
    archCardI.open("card.txt");
    if(archCardI.is_open())
    {
        while(!archCardI.eof())
        {
            getline(archCardI,cardS);
        }
    }
    card = atoi(cardS.c_str());
    archCardI.close();
}
// Carga del archivo card.txt el dato del cardinal.
bool leerArch(Alumno alu[],ifstream &arch, short card)
{
    arch.open("alumnos.txt");
    string dniS,edadS,nombreS,dirS;
    int i = 1;
    
    if(arch.is_open())
    {
        while(!arch.eof())
        {
            getline(arch,dniS);
            getline(arch,edadS);
            getline(arch,nombreS);
            getline(arch,dirS);
            alu[i].dni=atoi(dniS.c_str());
            alu[i].edad=atoi(edadS.c_str());
            alu[i].nombre=nombreS;
            alu[i].dir=dirS;
            cout << alu[i].dni << endl;
            cout << alu[i].edad << endl;
            cout << alu[i].nombre << endl;
            cout << alu[i].dir << endl;
            i++;
            
        }
        return true;
    }else
    {
        return false;
    }
}
// Lee el archivo llamado alumnos.txt.
int busquedaBinaria(Alumno alu[], short card,int auxDNI)
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
// Busca el alumno en base a un numero de dni y devuelve su posicion.
void cantidadAlumnos(Alumno alu[],short &card)
{
    ofstream archCardO;
    cout << "Ingrese la cantidad de alumnos" << endl;
    cin >> card;
    guarda_card(archCardO,card);
    for (int i = 1; i < card ; i++)
    {
        cout << "Ingrese dni para el " << i << " alumno" << endl;
        cin >> alu[i].dni;
        
        cout << "Ingrese edad para el " << i << " alumno" << endl;
        cin >> alu[i].edad;

        cout << "Ingrese nombre para el " << i << " alumno" << endl;
        getline(cin,alu[i].nombre);
        getline(cin,alu[i].nombre);

        cout << "Ingrese direccion para el " << i << " alumno" << endl; 
        getline(cin,alu[i].dir);
    }
    OrdxBur(alu,card);
}
// Toma un numero de alumnos y pide los datos en base a ese numero(cardinal).
bool eliminarAlumno(Alumno alu[], short card,int posicion)
{
    if(posicion == -1) return false;
    alu[posicion].dni=-1;
    alu[posicion].nombre="";
    alu[posicion].edad=-1;
    alu[posicion].dir="";
    OrdxBur(alu,card);
    return true;
}
// Deja en blanco los campos del alumno deseado y vuelve a ordenar el array.
void busquedaAlumno(Alumno alu[],int dniAux, short card)
{
    int aux;
    aux = busquedaBinaria(alu,card,dniAux);
                if(aux==-1)
                {
                    cout << "No se encontro el alumno" << endl;
                }else
                {
                    cout << "Nombre: " << alu[aux].nombre << endl;
                    cout << "Edad: " << alu[aux].edad << endl;
                }
}
// Busca un alumno por numero de dni.
void mostrarAlumnos(Alumno alu[],short card)
{
    cout << "Mostrando alumnos..." << endl;
                for(int i = 1; i <= card; i++)
                {
                    if(alu[i].dni!=-1)
                    {
                    cout << "DNI: " << alu[i].dni << endl;
                    cout << "EDAD: " << alu[i].edad << endl;
                    cout << "NOMBRE: " << alu[i].nombre << endl;
                    cout << "DIRECCION: " << alu[i].dir << endl;
                    cout << "-----------------" << endl;
                    }
                }
}
// Muestra todos los alumnos del archivo.
void menu()
{
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver datos de un alumno" << endl;
    cout << "2. Eliminar datos" << endl;
    cout << "3. Ver todos los alumnos" << endl;
    cout << "4. Cargar datos" << endl;
    cout << "5. Finalizar" << endl;
} 
// Menu de opciones.
int main(int argc, char const *argv[])
{
    short card,opc;
    int dniAux;
    Alumno alu[MAX_ALU];
    ofstream archO;
    ifstream archI,archCardI;

    carga_card(archCardI,card);

    if(leerArch(alu,archI,card))
    {
        cout << "Archivo leido.." << endl;
    }else
    {
        cout << "Se deben cargar datos.. Presione enter" << endl;
        cin.get();
        cantidadAlumnos(alu,card);
        guardarArch(alu,archO,card);
    }
    
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
                mostrarAlumnos(alu,card);
                break;
            case 4:
                
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