#include <cstring>
#include <cstdio>
using Rank = unsigned int;
class Bitmap
{
private:
    unsigned char *M;
    Rank N, _sz;

protected:
    void init(Rank n)
    {
        M = new unsigned char[N = (n + 7) / 8];
        memset(M, 0, N);
        _sz = 0;
    }
public:
    Bitmap(Rank n = 8 ){init(n);}
    Bitmap(char* file,Rank n =8)
    {
        init(n);
        FILE* fp = fopen(file,"r");
        fread(M,sizeof(char),N,fp);
        fclose(fp);
        for(Rank k = 0,_sz = 0;k<n;k++) _sz+=test(k);
    }
    void expand(Rank& k){k*=2;}
    bool test(Rank k){expand(k);return M[k>>3] &(0x80>>(k&0x07));}

};