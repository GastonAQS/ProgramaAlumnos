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