#include <iostream>
#include <MonomioBinomio.h>
using namespace std;

int main()
{
    MonomioBinomio b;
    //MonomioBinomio b(2,7);
    string mensaje ="mensaje cifrado" ;
    string cif = b.cifrar(mensaje);
    b.descifrar(cif);

    return 0;
}
