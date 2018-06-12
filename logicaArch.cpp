#include <iostream>
#include <fstream>
#include "struct.cpp"


void guardarArch()
{
    ofstream salidaArch("alumnos.bin",ios::out | ios::binary);
    salidaArch.write((char*)alu, sizeof(alu));
    salidaArch.close();
}
