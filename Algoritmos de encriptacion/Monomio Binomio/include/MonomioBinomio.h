#ifndef MONOMIOBINOMIO_H
#define MONOMIOBINOMIO_H
#include <iostream>

using namespace std;

class MonomioBinomio
{
private:
    char** arr;
    int clave1;
    int clave2;
public:
    MonomioBinomio();
    ~MonomioBinomio();
    MonomioBinomio(int,int);
    void print();
    string cifrar(string mensaje);
    string descifrar(string menCif);
};

#endif // MONOMIOBINOMIO_H
