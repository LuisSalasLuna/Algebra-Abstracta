#include "RC4.h"

int Mod(int Div, int d){
    int q = Div/d;
    int res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
int Potencia(int x, int y){
    int n = 1;
    while(y > 0){
        n *= x;
        y--;
    }
    return n;
}
int StringInt(string a){
    int in = 0;
    for(int i = 0 ; i < a.length() ; i ++){
        int b = int(a[i]-48);
        in += b*Potencia(10,a.length()-i-1);
    }
    return in;
}

RC4::RC4(int b, string text)
{
    bits = b;
    tam = pow(2,bits);
    S = new int[tam];
    for(int i = 0 ; i < tam ; i++){
        S[i] = i;
    }
    txt = text;
    ObtenerDatos();
    f = 0;
}

RC4::~RC4()
{
    delete[] S;
    delete[] K;
}

int ObtenerTam(string arch){
    ofstream creacion;
    string contador;
    ifstream extraccion;
    int i=0;
    creacion.open(arch.c_str(),ios::app);
    creacion.close();
    extraccion.open(arch.c_str(),ios::in);
    while(!extraccion.eof()){
        getline(extraccion,contador);
        if(contador != ""){++i;}
    }
    extraccion.close();
    return i;
}
void RC4::ObtenerDatos(){
    string texto;
    ifstream extraccion;
    int i = ObtenerTam(txt);
    K = new int[i];
    int c = 0;
    extraccion.open(txt.c_str(),ios::in);
    while(c != i){
            getline(extraccion,texto);
            K[c] = StringInt(texto);
            c++;
    }
    extraccion.close();
}

int* RC4::Resolver(){
    for(int i = 0 ; i < tam ; i++){
        f = Mod((f + S[i] + K[Mod(i,bits)]),tam);
        swap(S[i],S[f]);
    }
    //print();
    return S;
}
void RC4::print(){
    for(int i = 0 ; i < tam ; i++)
        cout << S[i] << "\t";
    cout  <<  endl;
}
