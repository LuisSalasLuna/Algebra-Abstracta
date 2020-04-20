#include <iostream>
#include <string>
#include <Vigenere.h>
#include <Kasiski.h>

using namespace std;
//3.b
string ASCCI(){
    string ASCCI;
    for(int i = 0 ; i < 127; i ++){
            char c = static_cast<int>(i);
            ASCCI += c;
    }
    return ASCCI;
}
string SelectionAlf(){
    int opcion;
    do{
        cout<<"\n\t\t\t Seleccion alfabeto\n"<< endl;
        cout<<" 1. ALFABETO NUMERICO"<< endl;
        cout<<" 2. ASCCI"<< endl;
        //cout<<" 3. HEX"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        //system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            return "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
            break;
        case 2:
            return ASCCI();
            break;
       /* case 3:
            return "0123456789ABCDEF";
            break;*/
        }
    }
    while(opcion!=1 || opcion!=2);
}
//3.e
string ModificacionE(string men){
    string Nmen = men;
    int s = 10;
    for(int i = 0 ; i < men.size()/10 ; i ++){
        Nmen.insert(s, "AQUI");
        s += 14;
    }
    for(int i = 0 ; i < men.size()%4 ; i ++){
        Nmen += "W";
    }
    cout << " Mensaje modificado: " << Nmen << endl;
    return Nmen;
}
string ReemplazoStr(string cadena, string coincidir, string cambiar){
        int posicion = cadena.find(coincidir);
        while ( posicion != string::npos )  {
            cadena.replace( posicion, coincidir.length(), cambiar );
            posicion = cadena.find( coincidir , posicion + 1 );
        }

    return cadena;
}
//Division
void Division(int Dividendo, int divisor){
    int residuo = Dividendo%divisor;
    int cociente = (Dividendo+residuo)/divisor;
    if (residuo < 0){
        residuo += divisor;
        cociente--;
    }
    cout << " Cociente: " << cociente << endl;
    cout << " Residuo: " << residuo << endl;

}
int main()
{
    //3.a
    string mensajeA("NOFUEINDESCIFRABLE");
    string claveA("PEROCASI");
    string alfabetoA = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    Vigenere emisorA(claveA,alfabetoA);
    cout << " Mensaje cifrado: " << emisorA.cifrado1(mensajeA) << endl<< endl;

    //3.b

    /*string mensajeB;
    cout << "Ingrese mensaje: ";
    getline(cin, mensajeB);
    string claveB;
    cout << "Ingrese clave: ";
    getline(cin, claveB);
    cout << "\n";
    string alfabetoB = SelectionAlf();
    Vigenere emisor(claveB,alfabetoB);
    string m = emisor.cifrado1(mensajeB);
    cout << "Mensaje cifrado: " << m << endl;
    string n = emisor.descifrado1(m);
    cout << "Mensaje descifrado: " << n << endl<< endl;*/

    //3.c
    string mensaje1 = "Puedo escribir los versos mas tristes esta noche.";
    string mensaje2 = "Escribir, por ejemplo: La noche esta estrellada,";
    string mensaje3 = "y tiritan, azules, los astros, a lo lejos.";
    string mensaje4 = "El viento de la noche gira en el cielo y canta.";
    string mensaje5 = "Puedo escribir los versos mas tristes esta noche.";
    string mensaje6 = "Yo la quise, y a veces ella tambien me quiso.";
    string mensajeC = mensaje1+mensaje2+mensaje3+mensaje4+mensaje5+mensaje6;
    string claveC = "Pablo Neruda";
    string alfabetoC = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    Vigenere emisorC(claveC,alfabetoC);
    string a = emisorC.cifrado1(mensajeC);
    cout << " Mensaje cifrado: " << a << endl;
    cout << " Mensaje descifrado: " << emisorC.descifrado1(a) << endl<< endl;

    //3.d Kasiski

    string TextoCifrado = "PBVRQVICADSKAÑSDETSJPSIEDBGGMPSLRPWRÑPWYEDSDEÑDRDPCRCPQMNPWKUBZVSFNVRDMTIPWUEQVVCBOVNUEDIFQLONMVNUVRSEIKAZYEACEYEDSETFPHLBHGUÑESOMEHLBXVAEEPUÑELISEUEFWHUNMCLPQPMBRRNBPVIÑMTIBVVEÑICANSJAMTJOKMDODSELPWIUFOZMQMVNFOHASESRJWRSFQCOTWVMBJGRPWVSUEXINQRSJEUEMGGRBDGNNILAGSJIDSVSUEEINTGRUEETFGGMPORDFOGTSSTOSEQOÑTGRRYVLPWJIFWXOTGGRPQRRJSKETXRNBLZETGGNEMUOTXJATORVJHRSFHVNUEJIBCHASEHEUEUOTIEFFGYATGGMPIKTBWUEÑENIEEU";
    Kasiski K1(TextoCifrado);
    string claveK = K1.GetClave();
    cout << claveK<< endl;
    string alfabetoD = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    Vigenere emisorD(claveK, alfabetoD);
    cout << " Mensaje descifrado: " << emisorD.descifrado1(TextoCifrado) << endl<< endl;

    //3.e
    string mensajeE = "Volveran las oscuras golondrinas";
    cout << " Mensaje: "<< mensajeE<< endl;
    string claveE = "Mango";
    string alfabetoE = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    string mod = ModificacionE(mensajeE);
    Vigenere emisorE(claveE,alfabetoE);
    string mod2 = emisorE.cifrado1(mod);
    cout << " Mensaje cifrado: "<< mod2<< endl;
    string mod3 = emisorE.descifrado1(mod2);
    cout << " Mensaje descifrado: "<< mod3<< endl;
    string mod4 = ReemplazoStr(mod3, "AQUI","");
    cout <<" Mensaje modificado: "<< mod4.substr(0,mensajeE.size())<< endl<< endl;

    //3.f
    string mensajeF = "mariposa";
    string claveF = "alma";
    string alfabetoF = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    Vigenere emisorF(claveF, alfabetoF);
    string b = emisorF.cifrado2(mensajeF);
    cout << " Mensaje cifrado: " << b << endl;
    cout << " Mensaje descifrado: " << emisorF.descifrado2(b) << endl<< endl;

    //Division
    Division(-255,11);


    return 0;
}
