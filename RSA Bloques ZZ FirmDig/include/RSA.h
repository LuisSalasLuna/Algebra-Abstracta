#ifndef RSA_H
#define RSA_H
//#include "Omath.h"
//#include <RestoChino.h>
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
        RSA(ZZ, ZZ);
        ZZ GetN();
        ZZ GetCPub();
        ZZ Pot2(ZZ, ZZ, ZZ);
        ZZ RestoChino(ZZ);
        ZZ Cifrar(char);
        char Descifrar(ZZ);
        int Digits(ZZ);
        int DigitsAlf(int);
        string IntString(ZZ, int);
        ZZ StringInt(string);
        //Comparto datos
        string CifrarER(string,ZZ,ZZ);
        string Descifrar(string);
        string DescifrarRC(string);
        //FirmaDigital
        string CifrarC(string);
        string CifrarFD(string,ZZ,ZZ);
        string DescifrarC(string,ZZ,ZZ);
        string DescifrarFD(string,ZZ,ZZ);
};
#endif // RSA_H
