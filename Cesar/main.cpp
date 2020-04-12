#include <iostream>
#include <string>
#include <Cesar.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE,"spanish");
    int clave = 1;
    Cesar emisor(clave);
    Cesar receptor(clave);
    string mensaje;
    cout << "Ingrese mensaje: ";
    getline(cin, mensaje);
    cout << "\n";
    string a = emisor.cifrar(mensaje);
    cout << "Mensaje cifrado: " << a << endl;
    string b = receptor.descifrar(a);
    cout << "Mensaje descifrado: " << b << endl;
    return 0;
}
