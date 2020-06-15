#include "Criba.h"

/*Criba::Criba(int num)
{
    tam = num-1;
    ptr= new int[tam];
    for(int i = 0 ; i < tam ; i++){
        ptr[i] = i+2;
    }
}*/
Criba::Criba(int num) //simplificacion
{
    tam = num-1;
    ptr= new int[tam];
    int a = 0;
    int tam2 = tam;
    for(int i = 0 ; a < tam ; i++){
        if((i+2)%2 != 0 && (i+2)%3 != 0 && (i+2)%5 != 0 && (i+2)%7 != 0 && (i+2)%11 != 0){
            ptr[a] = i+2;
            a++;
        }
        else{Eliminar(tam);}
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
            cout << ptr[i] << "\t";
    }
}
void Criba::DetPrimos(){
    for(int i = 0 ; i < tam-1 ;i++){
        for(int j = i+1 ; j < tam ;j++){
            if(ptr[j] % ptr[i] == 0){Eliminar(j);}
        }
    }
    //Print();
}
int Criba::RandPrimos(){
    DetPrimos();
    srand(time(NULL));
    int ran = rand()% tam;
    return ptr[ran];
}
