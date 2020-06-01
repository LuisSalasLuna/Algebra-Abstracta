#include <iostream>
#include <RailFence.h>
using namespace std;

int main()
{
    int clave = 3;
    string mensaje = "RailFenceCipher";
    RailFence a(clave, mensaje);
    string cif = a.cifrar();
    cout << " Mensaje Cifrado: " << cif << endl;
    cout << " Mensaje Descifrado: " << a.descifrar() << endl;
    return 0;
}
