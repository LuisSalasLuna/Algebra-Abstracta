#include "Criba.h"

/*Criba::Criba(int num)
{
    tam = num-1;
    ptr= new int[tam];
    for(int i = 0 ; i < tam ; i++){
        ptr[i] = i+2;
    }
}*/
Criba::Criba(int a, int b)
{
    ini = a;
    fin = b;
    tam = b-1;
    ptr= new int[tam];
    for(int i = 0 ; i < tam ; i++){
        ptr[i] = i+2;
    }
    for(int i = 0 ; ptr[i] < sqrt(fin) ;i++){
        for(int j = i+1 ; j < tam ;j++){
            if(ptr[j] % ptr[i] == 0){Eliminar(j);}
        }
    }
    for(int i = 0 ; i < tam ;i++){
        if(ptr[i] < ini){Eliminar(i);i--;}
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
/*void Criba::DetPrimos(){
    //cout << sqrt(fin) << endl;

    //Print();
}*/
int Criba::RandPrimos(){
    //DetPrimos();
    srand(time(NULL));
    int ran = rand()% tam;
    return ptr[ran];
}
