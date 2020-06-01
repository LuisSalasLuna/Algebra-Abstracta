#ifndef RAILFENCE_H
#define RAILFENCE_H
#include <iostream>

using namespace std;

class RailFence
{
private:
    int clave;
    int len;
    char** arr;
    bool regr;
public:
    RailFence(int, string);
    void print();
    string cifrar2();
    string descifrar2();
};

#endif // RAILFENCE_H
