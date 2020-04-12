#ifndef CESAR_H
#define CESAR_H
#include <iostream>

using namespace std;


class Cesar
{
private:
    int clave;
public:
    string alfabeto;
    Cesar();
    Cesar(int _clave);
    string cifrar(string mensaje);
    string descifrar(string menCif);
};

#endif // CESAR_H
