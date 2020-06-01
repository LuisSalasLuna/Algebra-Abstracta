#include "Polybios.h"

Polybios::Polybios()
{
    arr = new char*[5];
    for(int i = 0 ; i < 5 ; i++)
        arr[i] = new char[5];
    //cArr = new char[5];
    //cArr = {'A','B','C','D','E'};
    string fila1 = "abcde";
    string fila2 = "fgh#k"; //i,j
    string fila3 = "lmnop";
    string fila4 = "qrstu";
    string fila5 = "vwxyz";
    for(int i = 0 ; i < 5 ; i++){
        arr[0][i] = fila1[i];
        arr[1][i] = fila2[i];
        arr[2][i] = fila3[i];
        arr[3][i] = fila4[i];
        arr[4][i] = fila5[i];
    }
    print();
}
Polybios::~Polybios()
{
    for(int i=0 ; i < 5 ; i++)
        delete[] arr[i];
    delete[] arr;
}
void Polybios::print(){
    char cArr[5] = {'A','B','C','D','E'};
    cout << "\t";
    for(int i = 0 ; i < 5 ; i++){cout << cArr[i] << "\t";}
    cout <<"\t # = ij"<< endl;
    for(int i = 0 ; i < 5 ; i++){
        cout << cArr[i] << "\t";
        for(int j = 0 ; j < 5 ; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

}
string Polybios::cifrar(string mensaje){
    string menCifr;
    for(int i = 0 ; i < mensaje.length() ; i++){
        if(mensaje[i] == 'i' || mensaje[i] == 'j'){mensaje[i] = '#';}
        if(mensaje[i] == ' '){menCifr += ' ';i++;}
        for(int j = 0 ; j < 5 ; j++){
            for(int k = 0 ; k < 5 ; k++){
                if(arr[j][k] == mensaje[i]){
                    menCifr += char(j+65);
                    menCifr += char(k+65);
                }
            }
        }
    }
    cout << menCifr << endl;
    return menCifr;
}
string Polybios::descifrar(string menCifr){ //solucionar
    string menDescifr;
    for(int i = 0 ; i < menCifr.length() ; i += 2){
        if(menCifr[i] == ' '){menDescifr += ' '; i++;}
        int j = int(menCifr[i])-65;
        int k = int(menCifr[i+1])-65;
        menDescifr += arr[j][k];
    }
    cout << menDescifr << endl;
    return menDescifr;
}
