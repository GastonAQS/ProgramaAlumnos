#include <iostream>

using namespace std;

const int MAX_ALU = 40;

struct Alumno
{
    int dni;
    int edad;
    string nombre;
    string dir;
};

Alumno alu[MAX_ALU+1];

void cantidadAlumnos(Alumno alu[],short &card)
{
    cout << "Ingrese la cantidad de alumnos" << endl;
    cin >> card;
    for (int i = 1; i < card ; i++)
    {
        cout << "Ingrese dni para el " << i << " alumno" << endl;
        cin >> alu[i].dni;
        



    }
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
    cout << "5. Guardar datos" << endl;
    cout << "6. Finalizar" << endl;
    cin >> opc;

    return opc;
    
    
} 


int main(int argc, char const *argv[])
{
    Alumno alu;
    short card;
    int dniAux;

    cantidadAlumnos(alu,card);

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




