#include "Vigenere.h"

Vigenere::Vigenere()
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
}
Vigenere::Vigenere(string _clave, string _alfabeto)
{
    clave = _clave;
    alfabeto = _alfabeto;
}
string Vigenere::Extension(string mensaje){
    string NewClave;
    for(int i = 0 ; i < mensaje.length() ; i++){
        int a = i%clave.length();
        NewClave += clave[a];
    }
    return NewClave;
}
string Vigenere::Extension2(string mensaje){
    string NewClave = clave;
    for(int i = 0 ; i < mensaje.length()-clave.length() ; i++){
        NewClave += mensaje[i];
    }
    return NewClave;
}
string Vigenere::cifrar(string mensaje){
    string mensajeCifrado;
    //string claveN = Extension(mensaje,clave);
    for(int i = 0 ; i < mensaje.length() ; i++){
        int posicionM = alfabeto.find( mensaje[i]);
        int posicionC = alfabeto.find( clave[i]);
        int posicion = posicionM + posicionC;
        if(posicion < alfabeto.length())
            mensajeCifrado += alfabeto[posicion];
        else{mensajeCifrado += alfabeto[posicion-alfabeto.length()];}
    }
    return mensajeCifrado;
}
string Vigenere::descifrar(string mensaje){
    string mensajeDescifrado;
    //string claveN = Extension(mensaje,clave);
    for(int i = 0 ; i < mensaje.length() ; i++){
        int posicionM = alfabeto.find( mensaje[i]);
        int posicionC = alfabeto.find( clave[i]);
        int posicion = posicionM - posicionC;
            if(posicion >= 0)
                mensajeDescifrado += alfabeto[posicion];
            else{mensajeDescifrado += alfabeto[posicion+alfabeto.length()];}
    }
    return mensajeDescifrado;
}
string Vigenere::cifrado1(string mensaje){
    clave = Extension(mensaje);
    return cifrar(mensaje);
}
string Vigenere::cifrado2(string mensaje){
    clave = Extension2(mensaje);
    return cifrar(mensaje);
}
string Vigenere::descifrado1(string mensaje){
    clave = Extension(mensaje);
    return descifrar(mensaje);
}
string Vigenere::descifrado2(string mensaje){
    return descifrar(mensaje);
}
