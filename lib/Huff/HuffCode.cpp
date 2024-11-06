#include "HuffCode.hpp"
void generateCT(Bitmap *code, int length, HuffTable *table, BinNodePosi(HuffChar) v)
{
    if(IsLeaf(*v))
    {table->put(v->data.ch,code->bits2string(length));return;}
    if(HasLChild(*v))//left =0
    {code->clear(length);generateCT(code,length+1,table,v->lc);}
    if(HasRChild(*v))//right = 1
    {code->set(length);generateCT(code,length+1,table,v->rc);}
}
HuffTable* generateTable(HuffTree* tree)
{
    HuffTable* table = new HuffTable;
    Bitmap* code = new Bitmap;
    generateCT(code,0,table,tree->root());
    // release(code);
    code = nullptr;
    return table;
}