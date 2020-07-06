#ifndef DES_H
#define DES_H
#include <iostream>

using namespace std;

class DES
{
    private:
        string K;
        int **PC1;
        int **PC2;
        int lenBits;
    public:
        DES(string, int);
        ~DES();
        string Resolver();
};

#endif // DES_H
