#include <iostream>
#include <RSA.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int main()
{
    string men = "comehererightnow";
    cout <<" Mensaje original: "<< men <<endl;

    cout<<" Datos(p,q,e):\n";
    ZZ a,b,c;
    cout<<" p = ";
    cin >> a ;
    cout<<" q = ";
    cin >> b;
    cout<<" e = ";
    cin >> c;
    //a = 17; b = 59; c =3;
    cout <<"\n";
    RSA A(a,b,c);

    cout <<"\nCifrado:\n";
    string cif = A.Cifrar2(men);
    cout <<"\nDescifrado:\n";
    A.Descifrar2(cif);

    return 0;
}
