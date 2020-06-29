#include <iostream>
#include <RSA.h>

using namespace std;

int main()
{
    string men = "comehere";
    cout <<" Mensaje original: "<< men <<endl;
    cout <<" Bits: ";
    int bits;
    cin >> bits;
    cout <<"\n";
    RSA A(bits);

    /*cout<<" Datos(p,q,e):\n";
    int a,b,c;
    cin >> a >> b >> c;
    //a = 17; b = 59; c =3;
    cout <<"\n";
    RSA A(a,b,c);*/

    //cout <<" Cifrado: ";
    string cif = A.Cifrar2(men);
    //cout <<" Descifrado: ";
    A.Descifrar2(cif);

    return 0;
}
