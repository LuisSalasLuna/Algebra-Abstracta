#include "RSA.h"
#include "Omath.h"

RSA::RSA(int bits)
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz";
    Criba a(pow(2, bits)/2,pow(2, bits)-1);
    p = a.RandPrimos();
    q = a.RandPrimos();
    while(p == q){q = a.RandPrimos();}
    N = p*q;
    fN = (p-1)*(q-1);
    e = a.RandPrimos();
    while(e == q){e = a.RandPrimos();}
    d = InversaMultiplicativa(e,fN);
    cout <<" p = "<< p <<"  q = "<< q <<"  N = "<< N <<"  fN = "<< fN <<"  e = "<< e <<"  d = "<< d << endl;
}
RSA::RSA(int _p, int _q, int _e)
{
    //alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    alfabeto = "abcdefghijklmnopqrstuvwxyz";
    p = _p;
    q = _q;
    N = p*q;
    fN = (p-1)*(q-1);
    e = _e;
    d = InversaMultiplicativa(e,fN);
    cout <<" p = "<< p <<"  q = "<< q <<"  N = "<< N <<"  fN = "<< fN <<"  e = "<< e <<"  d = "<< d << endl;
}
int RSA::Pot2(int base,int exp){
    int result = 1;
    for( ; exp > 0; exp /= 2){
        if(exp%2 == 1){result = Modulo(result*base,N);}
        base = Modulo(base*base,N);
    }
    cout <<result<<endl;
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
int RSA::Digits(int num){
    int digs = 0;
    for(int i = num ; i > 0 ; i /= 10){digs++;}
    return digs;
}
string RSA::IntString(int a, int tam){
    string s = "";
    for(int i = a ; i > 0 ; i /= 10){
        int b = i%10;
        s += char(b+48);
    }
    for(int i = 0 ; i < tam/2 ; i++){
        swap(s[i],s[tam-i-1]);
    }
    return s;
}
int Potencia(int x, int y){
    int n = 1;
    while(y > 0){
        n *= x;
        y--;
    }
    return n;
}
int RSA::StringInt(string a){
    int in = 0;
    for(int i = 0 ; i < a.length() ; i ++){
        int b = int(a[i]-48);
        in += b*Potencia(10,a.length()-i-1);
    }
    cout << in <<endl;
    return in;
}
string RSA::Cifrar2(string cad)
{
    int digAlf = Digits(alfabeto.length());
    string cifrado = "";
    for(int i = 0 ; i < cad.length() ; i++){
        int pos = alfabeto.find(cad[i]);
        int dig = Digits(pos);
        for(int j = dig ; j < digAlf ; j++){cifrado += "0";}
        cout << pos <<" ";
        cifrado += IntString(pos, dig);
    }
    cout <<"\n"<<cifrado <<endl;
    int distrib = Digits(N)-1;
    if(cifrado.length() % distrib != 0){
        string comodin = IntString(alfabeto.length(),Digits(alfabeto.length()));
        for(int i = cifrado.length(),j = 0 ; i%distrib != 0 ; i++,j++){cifrado += comodin[j%comodin.length()];}
    }
    cout << cifrado <<endl;
    string cifradoFin = "";
    for(int i = 0 ; i < cifrado.length() ; i += distrib){
        string subcad = cifrado.substr(i,distrib);
        int div = StringInt(subcad);
        int pt = Pot2(div,e);
        int dig = Digits(pt);
        for(int j = dig ; j < distrib+1 ; j++){cifradoFin += "0";}
        cifradoFin += IntString(pt,dig);
    }
    cout << cifradoFin <<endl;
    return cifradoFin;
}
string RSA::Descifrar2(string cif)
{
    string descifrado;
    int digN = Digits(N);
    for(int i = 0 ; i < cif.length() ; i += digN){
        string subcad = cif.substr(i,digN);
        int div = StringInt(subcad);
        int pt = Pot2(div,d);
        int dig = Digits(pt);
        for(int j = dig ; j < digN-1 ; j++){descifrado += "0";}
        descifrado += IntString(pt,dig);
    }
    cout << descifrado <<endl;
    string descifradoFin = "";
    for(int i = 0 ; i < descifrado.length() ; i += Digits(alfabeto.length())){
        string subcad = descifrado.substr(i,Digits(alfabeto.length()));
        int div = StringInt(subcad);
        char l = alfabeto[div];
        descifradoFin += l;
    }
    cout << descifradoFin <<endl;
    return descifrado;
}
