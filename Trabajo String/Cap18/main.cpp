#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;
//18.7
string CifradoRot13(string a){
    string b;
    for(int i=0 ; i < a.length() ; i++){
        char z;
        int y = static_cast<int>(a[i]);
        if(y >= 97 && y <=122){
            if(y+13 > 122){y = 97+y-123;}
            z = static_cast<int>(y+13);
            b += z;
        }
    }
    cout << a << " " << b << endl;
    return b;
}
string DescifradoRot13(string a){
    string b;
    for(int i=0 ; i < a.length() ; i++){
        char z;
        int y = static_cast<int>(a[i]);
        if(y >= 97 && y <=122){
            if(y-13 < 97){y = 122+y-96;}
            z = static_cast<int>(y-13);
            b += z;
        }
    }
    cout << a << " " << b << endl;
    return b;
}
//18.11
string NombreApellido(string a, string b){
    return a + " " + b;
}
//18.12
void colgado(int n){
    string a,b,c,d,e,f;
    a =  "   O \n ";
    b =  " /";
    c =  "|";
    d =  "\\ \n ";
    e =  "  |   \n";
    f =  "  / ";
    string arr[] = {a,b,c,d,e,f,d};
    for(int i = 0 ; n > i ; i++){
        cout<< arr[i];
    }
    return;
    }
void Ahorcado(string a){
    string op;
    string rec(a.length(),'x');
    string pistas;
    string errores;
    cout <<rec<<endl;
    int fallos = 0;
    while( fallos != 7){
        bool fallo = true;
        cout<< "Ingrese letra: ";
        cin >> op;
        system("cls");
        for(int j = 0; j < a.length(); j++){
            string sol;
            if(rec[j] == a[j]){
                sol += rec[j];
                rec[j] = sol[0];
            }
            else{
                if(op[0] == a[j] ){
                    sol +=  a[j];
                    rec[j] = sol[0];
                    fallo = false;
                }
                else{sol += "x";
                 rec[j] = sol[0];
                }
            }
        }
        if(fallo == true){
            ++fallos;
            errores += op + ", ";
        }
        pistas += rec+ "\n";
        cout << "Errores: " << errores << "\n\n";
        cout << pistas << endl;
        colgado(fallos);
        cout<< "\n\n";
        if (rec == a){
            cout << "Felicidades!! Adivino mi palabra. Desea jugar otra vez? si/no \n";
            string ng;
            cin >> ng;
            if (ng == "si"){Ahorcado(a);}
            if (ng == "no"){return;}
            break;
        }
        if (fallos == 7){
            cout << "Perdiste" << endl;
            return;
        }
    }
}
//18.19
string MitadObj(string a){
    a.insert( a.length()/2, "******" );
    return a;
}
//18.21
string ReemplazoSP(string cadena){
    string arrSP[] = {".",",",";",":","-","_","¿","?","¡","!","{","}","(",")","[","]","''","*","/"};
    for(int i = 0; i < 19 ; i++){
        int posicion = cadena.find( arrSP[i]);
        while ( posicion != string::npos )  {
            cadena.replace( posicion, 1, " " );
            posicion = cadena.find( arrSP[i], posicion + 1 );
        }
    }
    return cadena;
}
char* StringArray(string a){
    int longitud = a.length();
    char *ptr2 = new char[ longitud + 1 ];
    a.copy( ptr2, longitud, 0 );
    ptr2[ longitud ] = '\0';
    return ptr2;
}
//19.22
string Invertir(string s, int n=1){
    string::iterator it = s.begin();
    string inv;
    for(;it != s.end();it++){
        inv += *(it+s.length()-inv.length()-n);
        n++;
    }
    return inv;
}
//18.27
bool CompararString(string a, string b){
    int lim = 0;
    if(a.length() < b.length()){lim = a.length();}
    else{lim = b.length();}
    for(int i = 0 ; i < lim+1 ; i++){
        if(a[i] > b[i]){
            return false;
        }
        if(a[i] < b[i]){
            return true;
        }
        if(a[i]=='\0' || b[i]=='\0'){
            if(a.length() < b.length()){return true;}
            else{return false;}
        }
    }
}
void Selection(string arr[],int tam){
    for(int i = 0; i < tam-1; i++){
        int mini=i;
        for(int j = i+1; j < tam; j++){
            bool val = CompararString(arr[mini],arr[j]);
            if (val == false){
                mini=j;
            }
        }
        swap(arr[mini],arr[i]);
    }
    for(int i = 0; i < 8; i++){
        cout  << arr[i] << endl;
    }
}
int main()
{
    //18.7
    string a = "abcdefghijklmnopqrstuvwxyz";
    string cif = CifradoRot13(a);
    DescifradoRot13(cif);
    //c
    /*Sería muy difícil, para hacerlo debería girar a cada uno hasta que la combinación cobre sentido,
    lo cual sería tardado y tedioso. Al contar con tecnología avanzada estos procesos tomarían menos
    de un segundo, ahorrándome tiempo y esfuerzo.*/
    cout  << "\n";
    //18.11
    string nom("Diego");
    string ape("Brando");
    string conca = NombreApellido(nom,ape);
    cout << conca << endl;
    cout  << "\n";
    //18.12
    cout  << "Juego comentado"<< endl;
     //string palabra = "google";
    //Ahorcado(palabra);
    cout  << "\n";
    //18.19
    string f = "gato";
    cout  << MitadObj(f) << endl;
    cout  << "\n";
    //18.21
    string str = "Hi, I. am; .learning:  about- c++_xd";
    cout  << str << endl;
    string cadena1( ReemplazoSP(str) );
    cout  <<StringArray(ReemplazoSP(str)) << endl;
    char* ptr2[10000] = {StringArray(ReemplazoSP(str))};
    char* pointer;
    pointer = strtok(*ptr2," ");
    while(pointer != NULL){
        cout  << pointer << endl;
        pointer = strtok(NULL," ");
    }
    delete [] ptr2;
    cout  << "\n";
    //18.22
    string s = "murcielago";
    cout  << s  << "\n" << Invertir(s)<< endl;
    cout  << "\n";
    //18.27
    string arr[] = {"uno","dos","tres","cuatro","cinco","seis","siete","ocho"};
    Selection(arr,8);

    return 0;
}
