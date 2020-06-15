#ifndef CRIBA_H
#define CRIBA_H
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Criba
{
    private:
        int *ptr;
        int tam;
    public:
        Criba(int);
        ~Criba();
        void Eliminar(int);
        void Print();
        void DetPrimos();
        int RandPrimos();
};

#endif // CRIBA_H
