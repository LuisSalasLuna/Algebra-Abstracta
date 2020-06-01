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
    ~RailFence();
    void print();
    string cifrar();
    string descifrar();
};

#endif // RAILFENCE_H
