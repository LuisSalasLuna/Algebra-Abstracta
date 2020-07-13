#include <iostream>
#include <RSA.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

int main()
{
    string men = "pomehererightnow";
    cout <<" Mensaje original: "<< men <<endl;
    cout<<" Emisor:\n";
    cout<<" Datos(p,q,e):\n";
    ZZ a,b,c;
    cout<<" p = ";
    cin >> a ;
    cout<<" q = ";
    cin >> b;
    cout<<" e = ";
    cin >> c;
    RSA Emisor(a,b,c);

    cout<<" Receptor:\n";
    cout<<" Datos(p,q,e):\n";
    ZZ x,y,z;
    /*cout<<" p = ";
    cin >> x ;
    cout<<" q = ";
    cin >> y;
    cout<<" e = ";
    cin >> z;*/
    x = 17; y = 59; z =3;
    cout <<"\n";
    RSA Receptor(x,y,z);


    /*cout <<"\nCifrado:\n";
    string cif = Emisor.Cifrar2(men);
    cout <<"\nDescifrado:\n";
    Emisor.DescifrarRC(cif);*/

    /*cout <<"\nCifrado:\n";
    string cif = Emisor.CifrarER(men,Receptor.GetN(),Receptor.GetCPub());
    cout <<"\nDescifrado:\n";
    Receptor.Descifrar(cif);*/

    cout <<"\nCifrado:\n";
    string cif = Emisor.CifrarFD(men,Receptor.GetN(),Receptor.GetCPub());
    cout <<"\nDescifrado:\n";
    Receptor.DescifrarFD(cif,Emisor.GetN(),Emisor.GetCPub());

    return 0;
}
