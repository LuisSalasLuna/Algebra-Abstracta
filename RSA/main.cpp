#include <iostream>
#include <RSA.h>

using namespace std;

int main()
{
    //RSA a(13,17);
    RSA a(200);
    int b = a.Cifrar('t');
    cout <<"cifrado = " << b << endl;
    cout <<"cifrado = " << a.Descifrar(b) << endl;
    return 0;

}
