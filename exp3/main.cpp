#include "HuffCode.hpp"
int main(int argc,char* argv[])
{   
    int* freq = statistics(argv[1]);
    HuffForest* forest = initForest(freq); freq = nullptr;
    HuffTree* tree = generateTree(forest); forest = nullptr;
    HuffTable* table = generateTable(tree);
    for(int i = 2;i<argc;i++)
    {
        Bitmap* codeString = new Bitmap;
        int n = encode(table,codeString,argv[i]);
        decode(tree,codeString,n);
        codeString = nullptr;
    }
    table = nullptr;
    tree = nullptr;
    return 0;
}