#include "RailFence.h"

RailFence::RailFence(int num, string mensaje)
{
    len = mensaje.length();
    clave = num;
    regr = false;
    // Crear array
    arr = new char*[len];
    for(int i = 0 ; i < clave ; i++)
        arr[i] = new char[len];
    // Inicializar arr con espacios
    for(int i = 0 ; i < clave; i++){
        for(int j = 0 ; j < len; j++){
            arr[i][j] = ' ';
        }
    }
    //Agregar valores en zig zag
    int j = 0;
    for(int i = 0 ; i < len; i++){
        arr[j][i] = mensaje[i];
        if(j == clave-1){regr = true;}
        if(j == 0){regr = false;}
        if(regr){j--;}
        else{j++;}
    }
    print();
}
RailFence::~RailFence()
{
    for(int i=0 ; i < len ; i++)
        delete[] arr[i];
    delete[] arr;
}
void RailFence::print(){
    cout << endl;
    for(int i = 0 ; i < clave ; i++){
        for(int j = 0 ; j < len ; j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}
string RailFence::cifrar()
{
    string cifrado;
    for(int i = 0 ; i < clave; i++){
        for(int j = 0 ; j < len; j++){
            if (arr[i][j] != ' '){
                cifrado += arr[i][j];
            }
        }
    }
    return cifrado;
}
string RailFence::descifrar()
{
    string descifrado;
    int j = 0;
    regr = false;
    for(int i = 0 ; i < len; i++){
        descifrado += arr[j][i];
        if(j == clave-1){regr = true;}
        if(j == 0){regr = false;}
        if(regr){j--;}
        else{j++;}
    }
    return descifrado;
}
