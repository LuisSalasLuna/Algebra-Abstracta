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
        //ppt
        /*RSA(int bits);
        RSA(ZZ,ZZ);
        virtual ~RSAC(void);
        ZZ exponenciacion(ZZ , ZZ);
        ZZ resto_chino(ZZ);
        string cifrar(string);
        string descifra_mensaje(string);
        long euclides(ZZ a, ZZ b);
        vector extendido_euclides(ZZ a, ZZ b);
        ZZ inversa(ZZ a, ZZ b);
        ZZ generar_aleatorio(int);
        bool test_primalidad(ZZ);
        */
};
#endif // RSA_H
