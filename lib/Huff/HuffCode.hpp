#include "Bitmap.hpp"
#include "Hufftable.hpp"
#include "BinTree.hpp"
#include "HuffChar.hpp"
#include "HuffForest.hpp"
typedef Bitmap HuffCode;
static void generateCT(Bitmap* code,int length,HuffTable* table,BinNodePosi(HuffChar));
HuffTable* generateTable(HuffTree* tree);
int encode(HuffTable* table,Bitmap* codeString,char* s);
void decode(HuffTree* tree,Bitmap* code);