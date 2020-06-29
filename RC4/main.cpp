#include <iostream>
#include <windows.h>
#include <RC4.h>

using namespace std;

void Datos(string F, int num){
    //Data
    SYSTEM_INFO SysInfo;
    Sleep(500);
    WORD arr[9] = {SysInfo.dwProcessorType,SysInfo.dwOemId,SysInfo.dwNumberOfProcessors,SysInfo.dwPageSize,SysInfo.dwActiveProcessorMask,
                    SysInfo.dwAllocationGranularity,SysInfo.wProcessorLevel,SysInfo.wProcessorRevision,SysInfo.wReserved};
    ofstream escritura;
    escritura.open(F.c_str(),ios::app);
    for(int i = 0; i < num; i++){escritura << arr[i]<<"\n";}
    escritura.close();
}
void Acumulador(double num, int var){
    //Clean
    ofstream limpiar;
    limpiar.open("datos.txt",ios::out);
    limpiar.close();
    for(; num > 0 ;num -= var){
        if(num - var > 0){Datos("datos.txt",var);}
        else{Datos("datos.txt",num);}
        Sleep(10);}
}

int main()
{
    int bits;
    double Ndatos;
    cout <<"Numero de bits de S: ";
    cin >> bits;
    cout <<"Numero de datos de K: ";
    cin >> Ndatos;
    Acumulador(Ndatos,9);
    RC4 a(bits, "datos.txt");
    a.Resolver();

    return 0;
}
