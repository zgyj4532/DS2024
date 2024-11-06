#include "HuffForest.hpp"

HuffForest *initForest(int *freq)
{
    HuffForest* f = new HuffForest;
    for(int i=0;i<N_CHAR;i++)
    {
        f -> insertAsLast(new HuffTree);
        f ->last()->data->insertAsRoot(HuffChar(0x20+i,freq[i]));
    }
    return f;
}