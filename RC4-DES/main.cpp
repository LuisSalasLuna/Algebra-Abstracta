#include <iostream>
#include <windows.h>
#include <RC4.h>
#define B 1024
#include <DES.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;


void Datos(string F, int num){
    SYSTEM_INFO SysInfo;
    MEMORYSTATUSEX memStat;
    memStat.dwLength = sizeof (memStat);
    GlobalMemoryStatusEx(&memStat);
    SYSTEMTIME sysTime;
    GetSystemTime(&sysTime);
    WORD arr[5] = {SysInfo.dwProcessorType,memStat.ullTotalPhys/B,memStat.ullAvailPhys/B,memStat.ullAvailPageFile/B,sysTime.wMilliseconds};
    ofstream escritura;
    escritura.open(F.c_str(),ios::app);
    for(int i = 0; i < num; i++){escritura << arr[i]<<"\n";}
    escritura.close();
}
void Acumulador(double num, int var){
    ofstream limpiar;
    limpiar.open("datos.txt",ios::out);
    limpiar.close();
    for(; num > 0 ;num -= var){
        if(num - var > 0){Datos("datos.txt",var);}
        else{Datos("datos.txt",num);}
        Sleep(10);}
}
//A Binario
string IntString(int a){
    //tam
    int tam = 0;
    for(int i = a ; i > 0 ; i /= 10){tam++;}
    //conversion
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
string DecimalBinarioString(int a, int bits){
    string Bin = "";
    int v = 0;
    for (int x = 1; a != 0 ;x *= 10){
        int residuo = a%2;
        v = v + residuo*x;
        a /= 2;
    }
    string val = IntString(v);
    for(int i = val.length() ; i < bits; i++){
        Bin += "0";
    }
    Bin += val;
    return Bin;
}
//Primalidad
ZZ StringZZ(string s){
    int tam = s.size();
    ZZ base = ZZ(1);
    ZZ result = ZZ(0);
    for(int i = tam-1 ; i >= 0 ; i--){
        ZZ val = ZZ(s[i])-ZZ(48);
        if(val == ZZ(1)){result += val*base;}
        base = base*2;
    }
    return result;
}
ZZ Modulo(ZZ Div, ZZ d){
    ZZ q = Div/d;
    ZZ res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
ZZ Primo(ZZ a,ZZ p){
    ZZ result = ZZ(1);
    for(ZZ exp = p-1; exp > 0; exp /= 2){
        if(exp%2 == 1){result = Modulo(result*a,p);}
        a = Modulo(a*a,p);
    }
    return result;
}
//Testing
void Testeo(int b){
    ZZ x,num;
    x = 2;
    num = 4;
    Acumulador(5,5);
    RC4 a(8, "datos.txt");
    int* S = a.Resolver();
    string CadBin = "";
    for(int i = 0 ; i < 8 ; i++){
        CadBin += DecimalBinarioString(S[i],8);// int -> binario -> string
    }
    int bits;
    bits = b;
    DES des(CadBin, bits);
    string cadBits = des.Resolver();
    num = StringZZ(cadBits); // stringBin -> ZZDecimal
    cout << num <<endl;
}
void TesteoPrimo(int b){
    ZZ x,num;
    x = 2;
    num = 4;
    Acumulador(5,5);
    RC4 a(8, "datos.txt");
    int* S = a.Resolver();
    string CadBin = "";
    for(int i = 0 ; i < 8 ; i++){
        CadBin += DecimalBinarioString(S[i],8);// int -> binario -> string
    }
    int bits;
    bits = b;
    DES des(CadBin, bits);
    string cadBits = des.Resolver();
    num = StringZZ(cadBits);  // stringBin -> ZZDecimal
    while(Primo(x,num) != ZZ(1)){num += ZZ(2);}
    cout << num<<endl;
}
int main()
{
    int bits,num;

    cout << "Cantidad de numero a generar: ";
    cin >> num;
    cout << "Numero de bits: ";
    cin >> bits;
    for(int i = 0 ; i < num ; i++)
        Testeo(bits);

    return 0;
}
