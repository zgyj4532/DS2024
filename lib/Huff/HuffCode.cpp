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

int encode(HuffTable *table, Bitmap *codeString, char *s)
{
    int n = 0;
    for(size_t m = strlen(s),i = 0; i<m;i++)
    {
        char** pCharCode = table -> get(s[i]);
        if(!pCharCode) pCharCode = table->get(s[i]+'A'-'a');
        if(!pCharCode) pCharCode = table->get(' ');
        printf("%s",*pCharCode);
        for(size_t m = strlen(*pCharCode),i = 0; i<m;i++)
        '1' == *(*pCharCode + i) ? codeString->set(n++) : codeString->clear(n++);
    }
    printf("\n");
    return n;
}

void decode(HuffTree *tree, Bitmap *code,int n)
{
    BinNodePosi(HuffChar) x = tree->root();
    for(int i =0;i<n;i++)
    {
        x = code->test(i) ? x->rc : x->lc;
        if(IsLeaf(*x)) {printf("%c",x->data.ch);x= tree->root();}
    }

}
