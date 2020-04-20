#ifndef KASISKI_H
#define KASISKI_H

#include <iostream>

using namespace std;

class Kasiski
{
    public:
        int i;
        int *ptr;
        string mensaje;
        Kasiski(string a);
        int CuantasVeces(string, string, int);
        string Repeticiones();
        void Distancias();
        int MCD();
        void Separador(int m);
        string GetClave();
    private:
        string alfabeto;
        string clave;

};

#endif // KASISKI_H
