#include "Kasiski.h"

Kasiski::Kasiski(string a)
{
    alfabeto = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    clave = "";
    mensaje = a;
    i = 0;
    ptr= new int[20];
    for(int j=0 ; j < 20 ; j++){
        ptr[j] = 0;
    }
}

int Kasiski::CuantasVeces(string cadena, string coincidir, int n = 1){
        int posicion = cadena.find(coincidir);
        while ( posicion != string::npos)  {
            int po = posicion;
            cadena.replace( posicion, 1, " " );
            //cout<<cadena<<endl;
            posicion = cadena.find( coincidir, posicion + 1 );
            if(posicion-po > 3){
                //cout<<posicion-po<<endl;
                ptr[i] = posicion-po;
                i++;
            }
            n++;
        }
    //cout<<n<<endl;
    return n;
}
string Kasiski::Repeticiones(){
    int tam = 4;
    for(int i = 0; i < mensaje.size()-tam+1; i++){
        string x = mensaje.substr(i,tam);
        CuantasVeces(mensaje, x);
    }
}
void Kasiski::Distancias(){
    int n= 0;
    while(ptr[n] != 0){
        //cout << ptr[n] << endl;
        n++;
    }
}
int Kasiski::MCD(){
    int n,i,num,mcd,r;
    n = 0;
    while(ptr[n] != 0){
        num = ptr[n];
        if(n==0){
            mcd=num;
        }
        do{
            r=mcd%num;
            mcd=num;
            num=r;
        }while(r!=0);
        n++;
    }
 //cout<<"El MCD es :"<<mcd<<endl;
 return mcd;
}
void Kasiski::Separador(int m = 0){
    int n = MCD();
    string a;
    for(int j=m ; j < mensaje.size() ; j += n){
        a += mensaje[j];
        //cout<< a <<endl;
    }
    int lis[27];
    for(int j=0 ; j < 27 ; j++){
        lis[j] = 0;
    }
    for(int j =0 ; j < mensaje.size()/n ; j++){
        for(int k =0 ; k < alfabeto.size() ; k++){
            if(a[j]== alfabeto[k]){
                lis[k]++;
            }
        }
    }
    /*for(int j=0 ; j < 27 ; j++){
        cout<< lis[j] <<endl;
    }*/
    int mayor = 0;
    int pos;
    for(int j=0 ; j < 26 ; j++){
        if(mayor < lis[j]){
            mayor = lis[j];
            pos = j;
        }
    }
    //cout<< mayor <<endl;
    if(lis[pos+4] >= mayor/3){clave += alfabeto[pos];}
    else{clave += alfabeto[pos-4];}
    //cout<< clave <<endl;
}
string Kasiski::GetClave(){
    Repeticiones();
    for(int j=0 ; j < MCD() ; j++){
        Separador(j);
    }
    return clave;
}

