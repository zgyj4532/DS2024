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

HuffTree *minHChar(HuffForest *forest)
{
    ListNodePosi(HuffTree*) p = forest->first();
    ListNodePosi(HuffTree*) minChar = p;
    int minWeight = p->data->root()->data.weight;
    while(forest->valid(p=p->succ))
    {
        if(minWeight>p->data->root()->data.weight)
        {
            minWeight = p->data->root()->data.weight;
            minChar = p;
        }
    }
    return forest -> remove(minChar);
}

HuffTree *generateTree(HuffForest *forest)
{
    while (forest ->size()>1)
    {
        HuffTree* T1 = minHChar(forest);
        HuffTree* T2 = minHChar(forest);
        HuffTree* S = new HuffTree();
        S->insertAsRoot(HuffChar('^',T1->root()->data.weight+T2->root()->data.weight));
        forest->insertAsLast(S);
    }
    
    return forest->first()->data;
}
