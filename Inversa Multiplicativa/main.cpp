#include <iostream>

using namespace std;
int Modulo(int Dividendo, int divisor){
    int cociente = Dividendo/divisor;
    int residuo = Dividendo-(divisor*cociente);
    if (residuo < 0){
        residuo += divisor;
        cociente--;
    }
    return residuo;
}
int Euclides(int a, int b){
    int r;
    while(true){
        r = Modulo(a,b);
        if(r==0){
            return b;
        }
        a=b;
        b=r;
    }
}
int EuclidesExtendido(int a, int b){
    int s = 0, s1 =1, s2 = 0;
    while(b > 0){
        int q = a/b;
        int r = a - (q*b);
        a = b;
        b=r;
        s = s1 - (q*s2);
        s1 = s2;
        s2 = s;
    }
    s = s1;
    return s;
}
int InversaMultiplicativa(int a, int n){
    if(Euclides(n,a) == 1){
        int x = EuclidesExtendido(a,n);
        int IM = Modulo(x,n);
        cout << "El inverso multiplicativo de "<< a <<" en base " << n <<" es "<< IM << endl;
    }
    else{cout << "El numero " << a <<" no tiene inversa multiplicativa en base " << n <<endl;}
}
int main()
{
    InversaMultiplicativa(17, 26);
    return 0;
}
