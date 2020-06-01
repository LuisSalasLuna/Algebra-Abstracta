#ifndef POLYBIOS_H
#define POLYBIOS_H
#include <iostream>

using namespace std;

class Polybios
{
private:
    char** arr;
    //char* cArr;
public:
    Polybios();
    ~Polybios();
    void print();
    string cifrar(string mensaje);
    string descifrar(string menCif);
};

#endif // POLYBIOS_H
