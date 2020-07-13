#include "RSA.h"
#include "Omath.h"

RSA::RSA(ZZ _p, ZZ _q, ZZ _e)
{
    alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    //alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789";
    p = _p;
    q = _q;
    N = p*q;
    fN = (p-1)*(q-1);
    e = _e;
    d = InversaMultiplicativa(e,fN);
    cout <<" ----------------------------------------"<< endl;
    cout <<" p = "<< p <<"\n q = "<< q <<"\n N = "<< N <<"\n fN = "<< fN <<"\n e = "<< e <<"\n d = "<< d << endl;
}
RSA::RSA(ZZ _N, ZZ _e)
{
    alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    //alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789";
    p = 1;
    q = 1;
    N = _N;
    fN = 1;
    e = _e;
    d = 1;
    cout <<" ----------------------------------------"<< endl;
    cout <<" p = "<< p <<"\n q = "<< q <<"\n N = "<< N <<"\n fN = "<< fN <<"\n e = "<< e <<"\n d = "<< d << endl;
}
ZZ RSA::GetN(){return N;}
ZZ RSA::GetCPub(){return e;}
ZZ RSA::Pot2(ZZ base,ZZ exp, ZZ mod){
    ZZ result = ZZ(1);
    for( ; exp > 0; exp /= 2){
        if(exp%2 == 1){result = Modulo(result*base,mod);}
        base = Modulo(base*base,mod);
    }
    //cout <<result<<endl;
    return result;
}
ZZ RSA::RestoChino(ZZ num){
    ZZ P = N;
    ZZ arr[2][2] = {{Pot2(num,Modulo(d,p-1), p),p},{Pot2(num,Modulo(d,q-1),q),q}};
    cout << arr[0][0] <<"  "<< arr[1][0] << endl;
    ZZ result = ZZ(0);
    for(int i = 0 ; i < 2 ; i++){
        ZZ C = P/arr[i][1];
        ZZ D = InversaMultiplicativa(C,arr[i][1]);
        result += (arr[i][0]*C*D);
    }
    result = Modulo(result, P);
    cout << result << endl;
    return result;
}
ZZ RSA::Cifrar(char ch)
{
    ZZ cifrado;
    ZZ pos = ZZ(alfabeto.find(ch));
    cifrado = Pot2(pos,e,N);
    return cifrado;
}
char RSA::Descifrar(ZZ cif)
{
    char descifr;
    ZZ pos = Pot2(cif,d,N);
    long a = 0;
    conv(a,pos);
    descifr = alfabeto[a];
    return descifr;
}
int RSA::Digits(ZZ num){
    int digs = 0;
    for(ZZ i = num ; i > 0 ; i /= 10){digs++;}
    return digs;
}
int RSA::DigitsAlf(int num){
    int digs = 0;
    for(int i = num ; i > 0 ; i /= 10){digs++;}
    return digs;
}
string RSA::IntString(ZZ num, int tam)//tam innecesario
{
    string s;
    for (int j = tam ; j > 0 ; j--, num/=10){
        ZZ b = num%ZZ(10) + ZZ(48);
        long len = ceil(log(b)/log(128));
        char str[len];
        for(long i = len-1; i >= 0; i--){
            str[i] = conv<int>(b % 128);
            b /= 128;
        }
        s += str[0];
    }
    for(int i = 0 ; i < tam/2 ; i++){
        swap(s[i],s[tam-i-1]);
    }
    return s;
}
ZZ RSA::StringInt(string s){
    ZZ result(NTL::INIT_VAL, s.c_str());
    return result;
}

string RSA::CifrarER(string cad,ZZ ReN,ZZ CPub){
    int digAlf = DigitsAlf(alfabeto.length());
    string cifrado = "";
    for(int i = 0 ; i < cad.length() ; i++){
        ZZ pos = ZZ(alfabeto.find(cad[i]));
        int dig = Digits(pos);
        for(int j = dig ; j < digAlf ; j++){cifrado += "0";}
        //cout << pos <<" ";
        cifrado += IntString(pos, dig);
    }
    cout <<"\nAgrupamiento: "<<cifrado <<endl;
    int distrib = Digits(ReN)-1;
    //cout <<"\n"<<distrib <<endl;
    if(cifrado.length() % distrib != 0){
        string comodin = IntString(ZZ(alfabeto.length()),DigitsAlf(alfabeto.length()));
        for(int i = cifrado.length(),j = 0 ; i%distrib != 0 ; i++,j++){cifrado += comodin[j%comodin.length()];}
    }
    cout <<"Extencion(#): "<<cifrado <<endl;
    string cifradoFin = "";
    for(int i = 0 ; i < cifrado.length() ; i += distrib){
        string subcad = cifrado.substr(i,distrib);
        //cout << subcad<<" ";
        ZZ div = StringInt(subcad);
        //cout << div<<endl;
        ZZ pt = Pot2(div,CPub,ReN);
        int dig = Digits(pt);
        for(int j = dig ; j < distrib+1 ; j++){cifradoFin += "0";}
        cifradoFin += IntString(pt,dig);
    }
    cout <<"ExpE, Agrup2: "<< cifradoFin <<endl;
    return cifradoFin;

}
string RSA::CifrarC(string cad){
    int digAlf = DigitsAlf(alfabeto.length());
    string cifrado = "";
    for(int i = 0 ; i < cad.length() ; i++){
        ZZ pos = ZZ(alfabeto.find(cad[i]));
        int dig = Digits(pos);
        for(int j = dig ; j < digAlf ; j++){cifrado += "0";}
        //cout << pos <<" ";
        cifrado += IntString(pos, dig);
    }
    cout <<"Agrupamiento: "<<cifrado <<endl;
    int distrib = Digits(N)-1;
    //cout <<"\n"<<distrib <<endl;
    if(cifrado.length() % distrib != 0){
        string comodin = IntString(ZZ(alfabeto.length()),DigitsAlf(alfabeto.length()));
        for(int i = cifrado.length(),j = 0 ; i%distrib != 0 ; i++,j++){cifrado += comodin[j%comodin.length()];}
    }
    cout <<"Extencion(#): "<<cifrado <<endl;
    string cifradoFin = "";
    for(int i = 0 ; i < cifrado.length() ; i += distrib){
        string subcad = cifrado.substr(i,distrib);
        //cout << subcad<<" ";
        ZZ div = StringInt(subcad);
        //cout << div<<endl;
        ZZ pt = Pot2(div,d,N);
        int dig = Digits(pt);
        for(int j = dig ; j < distrib+1 ; j++){cifradoFin += "0";}
        cifradoFin += IntString(pt,dig);
    }
    cout <<"ExpE, Agrup2: "<< cifradoFin <<endl;
    return cifradoFin;
}
string RSA::CifrarFD(string cad,ZZ ReN,ZZ CPub){
    string clave = CifrarC(cad);
    clave = CifrarER(clave,ReN,CPub);
    return clave;
}

string RSA::Descifrar(string cif){
    string descifrado;
    int digN = Digits(N);
    //cout << digN <<endl;
    for(int i = 0 ; i < cif.length() ; i += digN){
        string subcad = cif.substr(i,digN);
        //cout << subcad <<" ";
        ZZ div = StringInt(subcad);
        //cout << div <<endl;
        ZZ pt = Pot2(div,d,N);
        //cout << pt <<endl;
        int dig = Digits(pt);
        for(int j = dig ; j < digN-1 ; j++){descifrado += "0";}
        descifrado += IntString(pt,dig);
    }
    cout <<"ReCh, Agrup: "<< descifrado <<endl;
    string descifradoFin = "";
    for(int i = 0 ; i < descifrado.length() ; i += DigitsAlf(alfabeto.length())){
        string subcad = descifrado.substr(i,DigitsAlf(alfabeto.length()));
        //cout << subcad <<" ";
        ZZ div = StringInt(subcad);
        //cout << div <<endl;
        long a = 0;
        conv(a,div);
        char l = alfabeto[a];
        descifradoFin += l;
    }
    cout <<"Separ, PAlf: "<< descifradoFin <<endl;
    return descifradoFin;
}
string RSA::DescifrarRC(string cif){
    string descifrado;
    int digN = Digits(N);
    for(int i = 0 ; i < cif.length() ; i += digN){
        string subcad = cif.substr(i,digN);
        //cout << subcad <<" ";
        ZZ div = StringInt(subcad);
        //cout << div <<endl;
        ZZ pt = RestoChino(div);
        //cout << pt <<endl;
        int dig = Digits(pt);
        for(int j = dig ; j < digN-1 ; j++){descifrado += "0";}
        descifrado += IntString(pt,dig);
    }
    cout <<"ReCh, Agrup: "<< descifrado <<endl;
    string descifradoFin = "";
    for(int i = 0 ; i < descifrado.length() ; i += DigitsAlf(alfabeto.length())){
        string subcad = descifrado.substr(i,DigitsAlf(alfabeto.length()));
        //cout << subcad <<" ";
        ZZ div = StringInt(subcad);
        //cout << div <<endl;
        long a = 0;
        conv(a,div);
        char l = alfabeto[a];
        descifradoFin += l;
    }
    cout <<"Separ, PAlf: "<< descifradoFin <<endl;
    return descifradoFin;
}
string RSA::DescifrarC(string cif,ZZ EmN,ZZ CPub){
    string descifrado;
    int digN = Digits(EmN);
    //cout << digN <<endl;
    for(int i = 0 ; i < cif.length() ; i += digN){
        string subcad = cif.substr(i,digN);
        //cout << subcad <<" ";
        ZZ div = StringInt(subcad);
        //cout << div <<endl;
        ZZ pt = Pot2(div,CPub,EmN);
        //cout << pt <<endl;
        int dig = Digits(pt);
        for(int j = dig ; j < digN-1 ; j++){descifrado += "0";}
        descifrado += IntString(pt,dig);
    }
    cout <<"\nReCh, Agrup: "<< descifrado <<endl;
    string descifradoFin = "";
    for(int i = 0 ; i < descifrado.length() ; i += DigitsAlf(alfabeto.length())){
        string subcad = descifrado.substr(i,DigitsAlf(alfabeto.length()));
        //cout << subcad <<" ";
        ZZ div = StringInt(subcad);
        //cout << div <<endl;
        long a = 0;
        conv(a,div);
        char l = alfabeto[a];
        descifradoFin += l;
    }
    cout <<"Separ, PAlf: "<< descifradoFin <<endl;
    return descifradoFin;
}
string RSA::DescifrarFD(string cad,ZZ EmN,ZZ CPub){
    string clave = Descifrar(cad);
    clave = DescifrarC(clave,EmN,CPub);
    return clave;
}
