#ifndef RSA_H
#define RSA_H

#include <Criba.h>
#include <iostream>
using namespace std;

class RSA
{
    private:
        int p;
        int q;
        int N;
        int fN;
        int d;
        int e;
        string alfabeto;
    public:
        RSA(int);
        RSA(int, int, int);
        int Pot2(int, int);
        int Cifrar(char);
        char Descifrar(int);
        int Digits(int);
        string IntString(int, int);
        int StringInt(string);
        string Cifrar2(string);
        string Descifrar2(string);
};
#endif // RSA_H
