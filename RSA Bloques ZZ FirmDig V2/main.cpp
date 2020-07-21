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
void Encriptar2(RSA Emisor, RSA Receptor){
    string men;
    cout <<" Mensaje: ";
    cin.ignore();
    getline(cin, men);
    fflush(stdin);
    //cout <<" Mensaje original: "<< men <<endl;
    cout <<"\nCifrado:\n";
    string cif = Emisor.CifrarFD(men,Receptor.GetN(),Receptor.GetCPub());
}
void Desencriptar2(RSA Receptor, RSA Emisor){
    string cif;
    cout <<" Mensaje cifrado: ";
    cin>> cif;
    //cout <<" Mensaje cifrado: "<< cif <<endl;
    cout <<"\nDescifrado:\n";
    Receptor.DescifrarFD(cif,Emisor.GetN(),Emisor.GetCPub());
}
void Menu2(RSA a, RSA b){
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
            Encriptar2(a,b);
            break;
        case 2:
            Desencriptar2(a,b);
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
   /* string Mensaje = "Luis Enrrique Salas Luna 191-10-45242 A cocachos aprendi mi labor de colegial en el Colegio Fiscal del barrio donde naci. Tener primaria completa era raro en mi ninez (nos sentabamos de a tres en una sola carpeta). Yo creo que la palmeta la inventaron para mi, de la vez que una rompi me apodaron <mano de fierro>, y por ser tan mataperro a cocachos aprendi.";

    string Cifrado = "0648867479281307500823871072957527118242631409877664516850270565511713678434304032522571362338184196202717488289097671722267137127465508327741363870103279876747273043848408260383909739865828737599903670675845792016848813293317600230753022438715570740806119928559500547885897796853319458013413854184724137688459893034040269007076710793546641320649807726495585936387844629699104553595671193178513074023263773842060040655163908065550637056095532302182752063538953321499956582512703981872091849516370654197161509161413601692065790735407408121806601056873858108523758506897949739730157104434267142578364276944681823692803715444414627774968177543326890895214086717507204559344476669502094410634779675168760344881129725146752023707990717325596824979561988807402756565435754811251759417878215233953121790899497923330727476289832880737557983775925313115457684765571184185099655715017994286891711575007512654379924924185470405083342136576309981487370057706315620169316398808889231193802183355687193136273757268322667688779491786792732155009538816111924354103170364835849792774393976019842127832944632759608654126309154326776374169529889903252546628503319676249018004143509661521160294622380892648924823551765225200627852193876988054135894690057";
    //Cifrado = "05142923713417902398889876053702607680304850811033419720567094422143882063171073561266562688229282497013468729334272518208333485671700345278545968074359518571213387524840923160255970895986224030752012801872114068060441411542247910763856501368270853319991908744942872895139481240052287552527788589323537819753585154221783522299551183450717308339353191197040333639426028213691049568205448274315628564629394353869406116281922839595423670910631211398835366901960090847809177547607654683526329479465510961048178631128066882102513153225505130095729219093813074638236408611915216479249319015128544992181774746389338815017514545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545";
    Menu(Mensaje,Cifrado);*/
//-------------------------------------------------RSA sin FD ---------------------------------------------------------------------------------------
   // string men = "PARMESANO";
   // cout <<" Mensaje original: "<< men <<endl;

    cout<<" Yo:\n";
    cout<<" Datos(p,q,e):\n";
    ZZ a,b,c;
    cout<<" p = ";
    cin >> a ;
    cout<<" q = ";
    cin >> b;
    cout<<" e = ";
    cin >> c;
    RSA Yo(a,b,c);

    cout<<" \n Otro:\n";
    cout<<" Datos(N,e):\n";
    ZZ x,y;
    cout<<" N = ";
    cin >> x ;
    cout<<" e = ";
    cin >> y;
    RSA Otro(x,y);

    Menu2(Yo, Otro);

    return 0;
}
