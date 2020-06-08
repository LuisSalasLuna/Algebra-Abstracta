#include <iostream>
#include <Afin.h>

using namespace std;

int main()
{
    string mensaje = "itscool";
    Afin Emisor;
    string cifr = Emisor.cifrar(mensaje);
    cout << "\nDescifrado: "<<endl;
    Afin Receptor(Emisor.GetClave1(),Emisor.GetClave2());
    Receptor.descifrar(cifr);
    return 0;
}
