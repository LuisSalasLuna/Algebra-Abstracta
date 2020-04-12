#include "Cesar.h"

Cesar::Cesar()
{
    alfabeto = "AaBbCcDdEeFfGgHhIiJjKkLlMmNn—ÒOoPpQqRrSsTtUuVvWwXxYyZz";
}
Cesar::Cesar(int _clave)
{
    clave = _clave;
    alfabeto = "AaBbCcDdEeFfGgHhIiJjKkLlMmNn—ÒOoPpQqRrSsTtUuVvWwXxYyZz";
}
string Cesar::cifrar(string mensaje){
    string mensajeCifrado;
    for(int i = 0 ; i < mensaje.length() ; i++){
        int posicion = alfabeto.find( mensaje[i]);
        if (posicion < 0){mensajeCifrado += mensaje[i];}
        else{
            if(posicion+(clave*2) < alfabeto.length())
                mensajeCifrado += alfabeto[posicion+(clave*2)];
            else{mensajeCifrado += alfabeto[posicion+(clave*2)-alfabeto.length()];}
        }
    }
    return mensajeCifrado;
}
string Cesar::descifrar(string mensaje){
    string mensajeDescifrado;
    for(int i = 0 ; i < mensaje.length() ; i++){
        int posicion = alfabeto.find( mensaje[i]);
        if (posicion < 0){mensajeDescifrado += mensaje[i];}
        else{
            if(posicion-(clave*2) >= 0)
                mensajeDescifrado += alfabeto[posicion-(clave*2)];
            else{mensajeDescifrado += alfabeto[posicion-(clave*2)+alfabeto.length()];}
        }
    }
    return mensajeDescifrado;
}


