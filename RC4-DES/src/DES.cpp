#include "DES.h"

DES::DES(string S, int b)
{
    K = S;
    lenBits = b;
    //PC1
    PC1 = new int*[8];
    for(int i = 0 ; i < 8 ; i++)
        PC1[i] = new int[7];
    int PC1x[56] = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,
                    63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    for(int i = 0,c = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            PC1[i][j] = PC1x[c];c++;
        }
    }
    //PC2
    PC2 = new int*[8];
    for(int i = 0 ; i < 8 ; i++)
        PC2[i] = new int[6];
    int PC2x[48] = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,
                    41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    for(int i = 0,c = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            PC2[i][j] = PC2x[c];c++;
        }
    }
}
DES::~DES()
{
    for(int i = 0 ; i < 7 ; i++)
        delete[] PC1[i];
    delete[] PC1;

    for(int i = 0 ; i < 6 ; i++)
        delete[] PC2[i];
    delete[] PC2;
}
string DES::Resolver(){
    string _K = "";
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            _K += K[PC1[i][j]-1];
        }
    }
    K = _K;
    string C  = K.substr(0,28);// corri izq
    string D  = K.substr(28,28);// corr der
    string Kf = "";
    int despl[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    while(true){
        for(int k = 0 ; k < 16 ; k++){
            for(int l = 0 ; l < despl[k]; l++){
                //C
                char Cx = C[0];
                C = C.substr(1,27);
                C += Cx;
                //D
                string Dx = D.substr(0,27);
                D = D[27];
                D += Dx;
            }
            string Ki = C + D;
            string _Ki = "";
            for(int i = 0 ; i < 8 ; i++){
                for(int j = 0 ; j < 6 ; j++){
                    _Ki += Ki[PC2[i][j]-1];
                    if(Kf.size()+ _Ki.size() == lenBits){
                        Kf += _Ki;
                        if (Kf[lenBits-1] == '0'){Kf[lenBits-1] = '1';}
                        if (Kf[0] == '0'){Kf[0] = '1';}
                        //cout << Kf << endl;
                        return Kf;
                    }
                }
            }
            Kf += _Ki;
        }
    }
}
