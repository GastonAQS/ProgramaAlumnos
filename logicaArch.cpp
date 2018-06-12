#include <iostream>
#include <fstream>
#include "struct.cpp"


void guardarArch(short card)
{
    ofstream salidaArch("alumnos.dat",ios::out | ios::binary);
    for(int i = 1; i < card; i++)
    {
    salidaArch.write((char*)&(alu[i]), sizeof(Alumno));
    }
    salidaArch.close();
}

bool abrirArch()
{
    fstream arch;
    arch.open("alumnos.dat",ios::in|ios::out|ios::binary);
    if(arch.is_open())
    {
        cout << "Leyendo..";
        while(!arch.eof())
        {
            arch.read((char*)&alu,sizeof(Alumno));
        }
        arch.close();
        return true;
    }else{
        return false;
    }
    

}