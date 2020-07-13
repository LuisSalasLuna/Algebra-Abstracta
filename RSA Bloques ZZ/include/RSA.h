#ifndef RSA_H
#define RSA_H

//#include <Criba.h>
#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class RSA
{
    private:
        ZZ p;
        ZZ q;
        ZZ N;
        ZZ fN;
        ZZ d;
        ZZ e;
        string alfabeto;
    public:
        RSA(ZZ, ZZ, ZZ);
        ZZ Pot2(ZZ, ZZ);
        ZZ Cifrar(char);
        char Descifrar(ZZ);
        int Digits(ZZ);
        int DigitsAlf(int);
        string IntString(ZZ, int);
        ZZ StringInt(string);
        string Cifrar2(string);
        string Descifrar2(string);
};
#endif // RSA_H
