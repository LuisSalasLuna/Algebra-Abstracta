#ifndef RC4_H
#define RC4_H
#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;

class RC4
{
    private:
        int bits;
        int tam;
        string txt;
        int *S;
        int *K;
        int f;
    public:
        RC4(int, string);
        ~RC4();
        void ObtenerDatos();
        int* Resolver();
        void print();

};

#endif // RC4_H
