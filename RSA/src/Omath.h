#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Modulo(int Div, int d){
    int q = Div/d;
    int res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
int mcd(int a, int b){
    if(a>b){swap(a,b);}
    int r = Modulo(a,b);
    while(r != 0){
        r = Modulo(a,b);
        a = b;
        b = r;
        if(r == 0){return a;}
    }
    return b;
}
int EuclidesExtendido(int a, int b){
    if(a>b){swap(a,b);}
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
    //cout << s;
    return s;
}
int InversaMultiplicativa(int a, int b){
    if(mcd(a,b) == 1){
        int x = EuclidesExtendido(a,b);
        int IM = Modulo(x,b);
        return IM;
    }
    else{cout << "no tiene inversa multiplicativa"<< endl;}
}
