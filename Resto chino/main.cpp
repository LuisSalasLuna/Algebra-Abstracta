#include <iostream>
#include <RestoChino.h>

using namespace std;

int main()
{
    int ec;
    cout << "Numero de ecuaciones: ";
    cin >> ec;
    RestoChino g(ec);
    cout << g.Resolver();;

    return 0;
}
