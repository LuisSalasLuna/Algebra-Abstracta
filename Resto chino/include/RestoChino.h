#ifndef RESTOCHINO_H
#define RESTOCHINO_H
#include <iostream>

using namespace std;

class RestoChino{
    private:
        int fil;
        int colum;
        double **arr;
        int p;
    public:
        RestoChino(int);
        RestoChino(double**, int);
        ~RestoChino();
        void print();
        void PrimosRelativos();
        int Resolver();
        void Solucion();
};
#endif // RESTOCHINO_H


