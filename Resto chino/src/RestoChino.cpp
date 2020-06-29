#include "RestoChino.h"

//funciones
int Mod(int Div, int d){
    int q = Div/d;
    int res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
int MCD(int a, int b){
    if(a>b){swap(a,b);}
    int r = Mod(a,b);
    while(r != 0){
        r = Mod(a,b);
        a = b;
        b = r;
        if(r == 0){return a;}
    }
    return b;
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
int InversaMultiplicativa(int a, int b){
    if(MCD(a,b) == 1){
        int x = EuclidesExtendido(a,b);
        int IM = Mod(x,b);
        return IM;
    }
    else{cout << "no tiene inversa multiplicativa"<< endl;}
}

//Resto Chino
RestoChino::RestoChino(int n){
    fil = n;
    colum = 2;
    p = 1;
    arr = new double*[colum];
    for(int i = 0 ; i < fil ; i++)
        arr[i] = new double[fil];
    for(int i = 0 ; i < fil ; i++){
        cout <<" Ecuacion: " << i+1 << endl;
        cout <<" x = (1) mod (2) " << endl;
        for(int j = 0 ; j < colum ; j++){
            cout <<" "<< j+1 <<": ";
            cin >> *(*(arr+i)+j);
        }
    }
    PrimosRelativos();
}
RestoChino::~RestoChino()
{
    for(int i = 0 ; i < fil ; i++)
        delete[] arr[i];
    delete[] arr;
}
void RestoChino::print(){ //solo imprime una vez
    cout << endl<<"\t\t\t Resto Chino \t" <<endl;
    cout <<"\t-----------------------------------"<< endl;
    for(int i = 0 ; i < fil ; i++){
        for(int j = 0 ; j < colum ; j++){
            cout << "\t| " << *(*(arr+i)+j);
        }
        cout << "\t|" <<endl<<"\t-------------------------------------" <<  endl;
    }
}
void RestoChino::PrimosRelativos(){
    bool sol = true;
    for(int i = 0 ; i < fil-1 ; i++){
        for(int j = i+1 ; j < fil ; j++){
            if(MCD(arr[i][1],arr[j][1]) != 1){sol = false;}
        }
    }
    if(sol){
        for(int i = 0 ; i < fil ; i++)
            p *= arr[i][1];
    }
    else{ p = 0;}
}
int RestoChino::Resolver(){
    if(p){
        int result = 0;
        cout <<"\n";
        for(int i = 0 ; i < fil ; i++){
            int c = p/arr[i][1];
            int d = InversaMultiplicativa(c,arr[i][1]);
            result += (arr[i][0]*c*d);
            cout << arr[i][0] <<"*"<< c <<"*"<< d << endl;
        }
        cout <<" -> "<< result << endl;
        cout <<"\n "<< result <<" mod "<< p << endl;
        result = Mod(result, p);
        cout <<" x = "<< result <<" + "<< p << "k"<< endl;
        return result;
    }
    else{cout << " Bases no coprimas, Irresoluble" <<  endl;return 0;}
}

