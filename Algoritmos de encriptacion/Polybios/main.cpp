#include <iostream>
#include <Polybios.h>

using namespace std;

int main()
{
    Polybios a;
    string mensaje = "mensaje encriptado";
    string menCif = a.cifrar(mensaje);
    a.descifrar(menCif);

    return 0;
}
