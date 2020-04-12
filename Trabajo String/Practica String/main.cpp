#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <ctime>
#include <stdlib.h>


using namespace std;
//1
string ArrayToString(char x[],int n){
    string a;
    for(int i = 0 ; i < n ; i++){
        a += x[i];
    }

    return a;
}
char* StringToArray(string a){
    int longitud = a.length();
    char *ptr2 = new char[ longitud + 1 ];
    a.copy( ptr2, longitud, 0 );
    ptr2[ longitud ] = '\0';
    return ptr2;
}
//3
string minMAY(string a){
    string b;
    for(int i=0 ; i < a.length() ; i++){
        char z;
        int y = static_cast<int>(a[i]);
        if(y >= 97 && y <=122)
            {z = static_cast<int>(y-32);
            b += z;
        }
    }
    return b;
}
string MAYmin(string a){
    string b;
    for(int i=0 ; i < a.length() ; i++){
        char z;
        int y = static_cast<int>(a[i]);
        if(y >= 65 && y <= 90){
            z = static_cast<int>(y+32);
             b += z;
        }
    }
    return b;
}
//4
int StringInt(string a){
    int n=0;
    for(int i=0 ; i < a.length() ; i++){
        int g = static_cast<int>(a[i]);
        n +=  (g-48)*pow(10,a.length()-i-1);
    }
    return n;
}
int Pot(int x, int y){
    int n = 1;
    while(y > 0){
        n *= x;
        y--;
    }
    return n;
}
string IntString(int a){
    int n = -1;
    for(int m = a ; m > 0 ; m /= 10){n++;}
    string s;
    int b = a;
    for(int i=0 ; b > 0 ; i++){
        int d = Pot(10,n-i); //pow 99
        int c = b/d;
        b -= c*d;
        char g = static_cast<int>(c+48);
        s += g;
    }
    return s;
}
void SumaEntera(int a, int b){
    cout << a << " " << b << endl;
    string c = IntString(a)+IntString(b);
    cout << c << endl;
    int d = StringInt(c)*2;
    cout << d << endl;
}
//7
int CuantasVeces(string cadena, string coincidir, int n = 0){
        int posicion = cadena.find(coincidir);
        while ( posicion != string::npos )  {
            cadena.replace( posicion, 1, " " );
            posicion = cadena.find( coincidir, posicion + 1 );
            n++;
        }
    cout << n << endl;
    return n;
}
//9
string MiddleString(string a, string b){
    a.insert( a.length()/2, b );
    return a;
}
//10
string ReemplazoStr(string cadena, string coincidir, string cambiar){
        int posicion = cadena.find(coincidir);
        while ( posicion != string::npos )  {
            cadena.replace( posicion, coincidir.length(), cambiar );
            posicion = cadena.find( coincidir , posicion + 1 );
        }

    return cadena;
}
//11
string Comparar(string a, string b){
    int lim = 0;
    if(a.length() < b.length()){lim = a.length();}
    else{lim = b.length();}
    for(int i = 0 ; i < lim+1 ; i++){
        if(a[i] > b[i]){
            return a;
        }
        if(a[i] < b[i]){
            return b;
        }
        if(a[i]=='\0' || b[i]=='\0'){
            if(a.length() < b.length()){return b;}
            else{return a;}
        }
    }
}
//12
void Escritura(int n){
    if( n>9 || n<1 ){cin>>n;}
    ofstream escritura;
    srand(time(NULL));
    escritura.open("numeros.txt",ios::out);
    for(int i=0 ; i < n ; i++){
        escritura<<rand() % 1000 <<"\n";
    }
    cout << "Escritura completa" << endl;
    escritura.close();
}
//13
void Lectura(string arch, int n = 0){
    ifstream lectura;
    string texto;
    lectura.open(arch.c_str(),ios::in);
    //for(int i=0 ; i < lectura. ; i++){}
    while(!lectura.eof()){
        getline(lectura,texto);
        n += StringInt(texto);
        cout << texto << endl;
    }
    cout << n << endl;
    lectura.close();
}
int main(){
    //1
    char m[] = "abcd";
    string prueba;
    prueba = ArrayToString(m,4);
    cout << m <<" AtS "<< prueba << endl;
    string q = "Hola";
    char *p;
    p = StringToArray(q);
    cout << q <<" StA "<< p << endl;

    //2
    /*Ambas son funciones de la librería string, capacity nos permite ver la cantidad de memoria
    asignado para una cadena para que a la hora de alterarla no sea necesario reasignarla, por
    otro lado, size nos indica el número de letras presentes en esta.*/

    cout  << "\n";
    //3
    string z = "HOLA";
    cout << z << " -> " << MAYmin("HOLA")<< endl;
    z = MAYmin(z);
    cout << z << " -> " << minMAY("hola")<< endl;

    cout  << "\n";
    //4
    SumaEntera(12,34);

    cout  << "\n";
    //5
    string texto(100,'a');
    cout << texto << endl;

    cout  << "\n";
    //6
    string cadena("Yo desaprobe el curso de Algebra Abstracta");
    string cadenaNew = cadena.substr(0,3) + cadena.substr(6,36);
    cout << cadena << " -> " << cadenaNew << endl;

    cout  << "\n";
    //7
    string frase = "Como poco coco como, poco coco compro.";
    string coincidencia = "coco";
    cout  << frase << "\n" << coincidencia  << endl;
    CuantasVeces(frase, coincidencia);

    cout  << "\n";
    //8
    string t = "hola";
    string::iterator it = t.begin();
    for(;it != t.end();it++){
        cout << *(it)<< endl;;
    }

    cout  << "\n";
    //9
    string f1 = "gato";
    string f2 = "ti";
    cout  << f1 << endl;
    cout  << f2 << endl;
    cout  << MiddleString(f1,f2)<< endl;

    cout  << "\n";
    //10
    string b1 = "Cuando te diga que te creo, no me creas, porque ya no creo lo que creo.";
    string b2 = "creo";
    string b3 = "temo";
    cout  << b1 << endl;
    cout  <<ReemplazoStr(b1,b2,b3)<< endl;

    cout  << "\n";
    //11
    string pa1("Algebra");
    string pa2("Abstracta");
    cout  << pa1 << " y "<< pa2 << endl;
    cout  << Comparar(pa1,pa2)<< endl;

    cout  << "\n";
    //12
    Escritura(9);

    cout  << "\n";
    //13
    Lectura("numeros.txt");

    return 0;
}
