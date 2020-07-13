#include <iostream>
#include <RSA.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

void Encriptar(string mensaje){
    string men = mensaje;
    cout <<" Mensaje original: "<< men <<endl;

    cout<<" Emisor:\n";
    cout<<" Datos(p,q,e):\n";
     ZZ a,b,c;
    cout<<" p = ";
    cin >> a ;
    cout<<" q = ";
    cin >> b;
    cout<<" e = ";
    cin >> c;

    cout<<" Receptor:\n";
    cout<<" Datos(N,e):\n";
    ZZ x,y;
    cout<<" N = ";
    cin >> x ;
    cout<<" e = ";
    cin >> y;

    RSA Emisor(a,b,c);
    RSA Receptor(x,y);

    cout <<"\nCifrado:\n";
    string cif = Emisor.CifrarFD(men,Receptor.GetN(),Receptor.GetCPub());
}
void Desencriptar(string cifrado){
    cout<<" Emisor:\n";
    cout<<" Datos(N,e):\n";
    ZZ x,y;
    cout<<" N = ";
    cin >> x ;
    cout<<" e = ";
    cin >> y;

    cout<<" Receptor:\n";
    cout<<" Datos(p,q,e):\n";
    ZZ a,b,c;
    cout<<" p = ";
    cin >> a ;
    cout<<" q = ";
    cin >> b;
    cout<<" e = ";
    cin >> c;

    RSA Emisor(x,y);
    RSA Receptor(a,b,c);

    cout <<"\nCifrado:\n";
    string cif = cifrado;
    cout <<"\nDescifrado:\n";
    Receptor.DescifrarFD(cif,Emisor.GetN(),Emisor.GetCPub());
}
void Menu(string mensaje, string cifrado){
    int opcion;
    do{
        cout<<"\n\t\t\t RSA\n"<< endl;
        cout<<" 1. Cifrar"<< endl;
        cout<<" 2. Descifrar"<< endl;
        cout<<" 3. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            system("pause");
            system("CLS");
            break;
        case 1:
            Encriptar(mensaje);
            break;
        case 2:
            Desencriptar(cifrado);
            break;
        case 3:
            system("CLS");
            break;
        }
    }
    while(opcion!=3);
}
int main()
{
    string Mensaje = "mensaje xd";
    string Cifrado = "06466165531084862988430753479457758301633322825475793179020900037604723263245456232336177758126250954046012554652484029366567814669370590110315786730956609963654183633521791417685751296949710359215266680018750723343924255030490810111046165336348616720057013907283148697271383679275109529773783423908593327301802495995852631703857259391285881743087812991014837804927917034530189773175015952296441908679569735303318568189369885435153580776305326145437176560706670388055972554758743432655944572091182327075717277853534965167734037337139974951115917964306443325955721941359845563261099448645419031124397974503132167422398";
    Menu(Mensaje,Cifrado);
//-------------------------------------------------RSA sin FD ---------------------------------------------------------------------------------------
    /*
    string men = "PARMESANO";
    cout <<" Mensaje original: "<< men <<endl;

    cout<<" Emisor:\n";
    cout<<" Datos(p,q,e):\n";
    ZZ a,b,c;
    /*cout<<" p = "; cin >> a ;
    cout<<" q = "; cin >> b;
    cout<<" e = "; cin >> c;/
    a = 29; b = 31; c =37;

    cout<<" Receptor:\n";
    cout<<" Datos(p,q,e):\n";
    ZZ x,y,z;
    /*cout<<" p = "; cin >> x ;
    cout<<" q = "; cin >> y;
    cout<<" e = "; cin >> z; /
    x = 11; y = 13; z =7;

    RSA Emisor(a,b,c);
    RSA Receptor(x,y,z);

    cout <<"\nCifrado:\n";
    string cif = Emisor.CifrarER(men,Receptor.GetN(),Receptor.GetCPub());
    cout <<"\nDescifrado:\n";
    Receptor.Descifrar(cif);
    //Receptor.DescifrarRC(cif);
    */

    return 0;
}
