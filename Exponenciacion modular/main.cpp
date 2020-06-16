#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ Modulo(ZZ Dividendo, ZZ divisor){
    ZZ cociente = Dividendo/divisor;
    ZZ residuo = Dividendo-(divisor*cociente);
    if (residuo < 0){
        residuo += divisor;
        cociente--;
    }
    return residuo;
}
ZZ ExpoMod2(ZZ base,ZZ exp, ZZ mod){
    ZZ result = ZZ(1);
    for( ; exp > 0; exp /= 2){
        if(exp%2 == ZZ(1)){result = Modulo(result*base,mod);}
        base = Modulo(base*base,mod);
    }
    return result;
}
int main()
{
    ZZ base,exp, mod;
    base = 20;
    exp = 101;
    mod = 731;
    ZZ a = ExpoMod2(base, exp, mod);
    cout << a << endl;
    return 0;
}
