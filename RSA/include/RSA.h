#ifndef RSA_H
#define RSA_H
#include <iostream>
using namespace std;

class RSA
{
    private:
        int p;
        int q;
        int d;
    public:
        string alfabeto;
        int N;
        int fN;
        int e;
        RSA(int);
        RSA(int, int);
        int GetOdds(int);
        int Pot(int, int);
        int Pot2(int, int);
        int Cifrar(char);
        char Descifrar(int);
};

#endif // RSA_H
