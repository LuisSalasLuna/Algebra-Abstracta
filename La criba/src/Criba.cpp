#include "Criba.h"

Criba::Criba(int num)
{
    tam = num-1;
    ptr= new int[tam];
    for(int i = 0 ; i < tam ; i++){
        ptr[i] = i+2;
    }
}

Criba::~Criba()
{
    delete[] ptr;
}
void Criba::Eliminar(int a){
    int c = 0;
    tam = tam-1;
    int *Narr= new int[tam];
    int *ptr2 = ptr;
    for(int i = 0 ; i < tam ; i++){
        if(i == a){c++;}
        Narr[i]=*(ptr+c);
        c++;
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
}

void Criba::Print(){
    for(int i = 0 ; i < tam ; i++){
            cout << ptr[i] << endl;
    }
}
void Criba::DetPrimos(){
    for(int i = 0 ; i < tam-1 ;i++){
        for(int j = i+1 ; j < tam ;j++){
            if(ptr[j] % ptr[i] == 0){Eliminar(j);}
        }
    }
    Print();
}
