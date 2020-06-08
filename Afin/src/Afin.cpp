#include "Afin.h"
#include "Omath.h"

Afin::Afin()
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    int ran = rand()%(alfabeto.length());
    clave1 = PrimosRelativos(ran,alfabeto.length());
    int ran2 = rand()%(alfabeto.length()*10);
    clave2 = Modulo(ran2,alfabeto.length());
    //clave1 = 5;
    //clave2 = 8;
    cout << "\nCifrado: "<<endl;
    cout << "clave1 = "<< clave1 << ", clave2 = " << clave2 <<endl;
}
int Afin::GetClave1(){
    return clave1;
}
int Afin::GetClave2(){
    return clave2;
}
Afin::Afin(int a,int b)
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz";
    cout << "clave1 = inv("<< a << "), clave2 = " << b <<endl;
    clave1 = InversaMultiplicativa(a,alfabeto.length());
    clave2 = b;
    cout << "clave1 = "<< clave1 << ", clave2 = " << clave2 <<endl;

}
string Afin::cifrar(string mensaje)
{
    string mensajeCifrado;
    for(int i = 0 ; i < mensaje.length() ; i++){
        int pos = alfabeto.find( mensaje[i]);
        int v = (clave1*pos)+ clave2;
        cout << Modulo(v,alfabeto.length()) << " = " << clave1 << "*" << pos << " + " << clave2 <<endl;
        mensajeCifrado += alfabeto[ Modulo(v,alfabeto.length())];
    }
    cout << mensajeCifrado <<endl;
    return mensajeCifrado;
}
string Afin::descifrar(string mensaje)
{
    string mensajeDescifrado;
    for(int i = 0 ; i < mensaje.length() ; i++){
        int pos = alfabeto.find( mensaje[i]);
        int v = clave1*(pos - clave2);
        cout << Modulo(v,alfabeto.length()) << " = " << clave1 << "*(" << pos << "-" << clave2 << ")"<<endl;
        mensajeDescifrado += alfabeto[ Modulo(v,alfabeto.length())];
    }
    cout << mensajeDescifrado <<endl;
    return mensajeDescifrado;
}


