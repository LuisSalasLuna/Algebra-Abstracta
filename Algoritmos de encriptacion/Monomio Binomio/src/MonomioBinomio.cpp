#include "MonomioBinomio.h"
#include <ctime>
//#include "Random.h"

MonomioBinomio::MonomioBinomio()
{
    arr = new char*[10];
    for(int i = 0 ; i < 3 ; i++)
        arr[i] = new char[10];
    string fila1 = "denarios";
    string fila2 = "bcfghjklmñ";
    string fila3 = "pqtuvwxyz#";
    //vacios
    srand(time(NULL));
    clave1 = rand()%10;
    clave2 = rand()%10;
    while(clave1 == clave2){clave2 = rand()%10;}
    if(clave1 > clave2){swap(clave1,clave2);}
    arr[0][clave1] = ' ';
    arr[0][clave2] = ' ';
    //Primera fila
    for(int i = 0, j = 0 ; i < 10 ; i++){
        if(arr[0][i] != ' '){
            arr[0][i] = fila1[j];
            j++;
        }
    }
    //Segunda y tercer fila
    for(int i = 0 ; i < 10 ; i++){
        arr[1][i] = fila2[i];
        arr[2][i] = fila3[i];
    }
    print();
}
MonomioBinomio::MonomioBinomio(int c1, int c2)
{
    arr = new char*[10];
    for(int i = 0 ; i < 3 ; i++)
        arr[i] = new char[10];
    string fila1 = "denarios";
    string fila2 = "bcfghjklmñ";
    string fila3 = "pqtuvwxyz#";
    //vacios
    clave1 = c1;
    clave2 = c2;
    arr[0][clave1] = ' ';
    arr[0][clave2] = ' ';
    //Primera fila
    for(int i = 0, j = 0 ; i < 10 ; i++){
        if(arr[0][i] != ' '){
            arr[0][i] = fila1[j];
            j++;
        }
    }
    //Segunda y tercer fila
    for(int i = 0 ; i < 10 ; i++){
        arr[1][i] = fila2[i];
        arr[2][i] = fila3[i];
    }
    print();
}
MonomioBinomio::~MonomioBinomio()
{
    for(int i=0 ; i < 10 ; i++)
        delete[] arr[i];
    delete[] arr;
}
void MonomioBinomio::print(){
    char cArr[3] = {' ', char(clave1+48), char(clave2+48)};
    cout << "\t";
    for(int i = 0 ; i < 10 ; i++){cout << i << "\t";}
    cout << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << cArr[i] << "\t";
        for(int j = 0 ; j < 10 ; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

}
string MonomioBinomio::cifrar(string mensaje){
    string menCifr;
    for(int i = 0 ; i < mensaje.length() ; i++){
        if(mensaje[i] == ' '){menCifr += ' ';i++;}
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 10 ; k++){
                if(arr[j][k] == mensaje[i]){
                    if(j == 0){menCifr += char(k+48);}
                    if(j == 1){menCifr += char(clave1+48);menCifr += char(k+48);}
                    if(j == 2){menCifr += char(clave2+48);menCifr += char(k+48);}
                }
            }
        }
    }
    cout << menCifr << endl;
    return menCifr;
}
string MonomioBinomio::descifrar(string menCifr){ //solucionar
    string menDescifr;
    for(int i = 0 ; i < menCifr.length() ; i++){
        if(menCifr[i] == ' '){menDescifr += ' ';i++;}
        int vInt = int(menCifr[i])-48;
        if(vInt == clave1 || vInt == clave2){
            if(vInt == clave1){menDescifr += arr[1][int(menCifr[i+1])-48];}
            if(vInt == clave2){menDescifr += arr[2][int(menCifr[i+1])-48];}
            i++;
        }
        else{menDescifr += arr[0][int(menCifr[i])-48];}
    }
    cout << menDescifr << endl;
    return menDescifr;
}
