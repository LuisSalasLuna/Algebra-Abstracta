#include "RSA.h"
#include "Omath.h"
#include "Criba.h"

RSA::RSA(int num)
{
    alfabeto = "abcdefghijklmnñopqrstuvwxyz";
    Criba a(num);
    p = a.RandPrimos();
    q = a.RandPrimos();
    while(p == q){q = a.RandPrimos();}
    N = p*q;
    fN = (p-1)*(q-1);
    e = GetOdds(fN);
    d = InversaMultiplicativa(e,fN);
    cout <<" p = "<< p <<"  q = "<< q <<"  N = "<< N <<"  fN = "<< fN <<"  e = "<< e <<"  d = "<< d << endl<< endl;
}
RSA::RSA(int p1, int p2)
{
    alfabeto = "abcdefghijklmnñopqrstuvwxyz";
    p = p1;
    q = p2;
    N = p*q;
    fN = (p-1)*(q-1);
    //e = 5;
    e = GetOdds(fN);
    d = InversaMultiplicativa(e,fN);
    cout << p <<" "<< q <<" "<< N <<" "<< fN <<" "<< e <<" "<< d << endl<< endl;
}
int RSA::GetOdds(int num){
    Criba a(num);
    return a.RandPrimos();
}
int RSA::Pot(int base,int exp){
    int a = exp;
    int resp = base;
    cout << a <<" "<< a%2 <<" "<< base <<" "<< resp <<endl;
    a /= 2;
    for( ; a != 0; a /= 2){
        int b = a%2;
        base = Modulo(base*base,N);
        if(b == 1){resp = Modulo(base*resp,N);}
        cout << a <<" "<< b <<" "<< base <<" "<< resp <<endl;
    }
    cout << resp <<endl;
    return resp;
}
int RSA::Pot2(int base,int exp){
    int result = 1;
    for( ; exp > 0; exp /= 2){
        if(exp%2 == 1){result = Modulo(result*base,N);}
        base = Modulo(base*base,N);
    }
    return result;
}
int RSA::Cifrar(char ch)
{
    int cifrado;
    int pos = alfabeto.find(ch);
    cifrado = Pot2(pos,e);
    return cifrado;
}
char RSA::Descifrar(int cif)
{
    char descifr;
    int pos = Pot2(cif,d);
    descifr = alfabeto[pos];
    return descifr;
}
