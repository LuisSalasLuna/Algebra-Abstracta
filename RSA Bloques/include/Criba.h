#ifndef CRIBA_H
#define CRIBA_H
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Criba
{
    private:
        int *ptr;
        int tam;
        int ini;
        int fin;
    public:
        Criba(int);
        Criba(int, int);
        ~Criba();
        void Eliminar(int);
        void Print();
        void DetPrimos();
        int RandPrimos();
};

#endif // CRIBA_H
