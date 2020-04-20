#ifndef VIGENERE_H
#define VIGENERE_H
#include <iostream>

using namespace std;

class Vigenere
{
private:
    string clave;
public:
    string alfabeto;
    Vigenere();
    Vigenere(string, string);
    string Extension(string);
    string Extension2(string);
    string cifrar(string);
    string descifrar(string);
    string cifrado1(string);
    string cifrado2(string);
    string descifrado1(string);
    string descifrado2(string);
};

#endif // VIGENERE_H


