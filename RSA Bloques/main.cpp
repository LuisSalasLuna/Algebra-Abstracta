#include <iostream>
#include <RSA.h>

using namespace std;

void PorBits(char men){//strings
    cout<<"\nBits: ";
    int bits;
    cin >> bits;
    RSA A(bits);
    char cif = A.Cifrar(men);
    A.Descifrar(cif);
}
void PorDatos(char men){
    cout<<"\nDatos(p,q,e):\n";
    int a,b,c;
    cin >> a >> b >> c;
    RSA A(a,b,c);
}
int main()
{
    /*char mensaje = 'a';
    int opcion;
    cout<<"\n\t\t RSA\t\t\t\t\n";
    cout<<"1. Dar bits\n";
    cout<<"2. Dar datos\n";
    cout<<"3. Salir\n";
    cout<<"Opci\242n: ";
    cin>>opcion;
    switch(opcion)
    {
    default:
        cout<<"Ha ingresado una opci\242n no valida!\n\n";
        break;
    case 1:
        PorBits(mensaje);
        break;
    case 2:
        PorDatos(mensaje);
        break;
    case 3:
        break;
    }*/
    string men = "comehere";
    /*cout<<"\nBits: ";
    int bits;
    cin >> bits;
    RSA A(bits);
    string cif = A.Cifrar2(men);*/
    //A.Descifrar2(cif);
    cout<<"\nDatos(p,q,e):\n";
    int a,b,c;
    //cin >> a >> b >> c;
    a = 17; b = 59; c =3;
    RSA A(a,b,c);
    string cif = A.Cifrar2(men);
    A.Descifrar2(cif);

    return 0;
}
