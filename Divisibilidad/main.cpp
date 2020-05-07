#include <iostream>

using namespace std;
int Divisibilidad(int Dividendo, int divisor){
    int cociente = Dividendo/divisor;
    int residuo = Dividendo-(divisor*cociente);
    if (residuo < 0){
        residuo += divisor;
        cociente--;
    }
    cout << " " << Dividendo << " = " << divisor << "*" << cociente << " + " << residuo << endl;
    return residuo;
}
int main()
{
    cout << " Caso positivo: "<< endl;
    Divisibilidad(255,11);
    cout << " Caso negativo: " << endl;
    Divisibilidad(-255,11);
    return 0;
}
