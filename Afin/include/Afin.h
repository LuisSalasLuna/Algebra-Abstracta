#ifndef AFIN_H
#define AFIN_H
#include <iostream>
#include <ctime>


using namespace std;

class Afin
{
private:
    int clave1;
    int clave2;
public:
    string alfabeto;
    Afin();
    int GetClave1();
    int GetClave2();
    Afin(int a, int b);
    string cifrar(string mensaje);
    string descifrar(string menCif);
};

#endif // AFIN_H
