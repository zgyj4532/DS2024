#include "List.hpp"
#include "HuffChar.hpp"
#include "BinTree.hpp"
#define HuffTree BinTree<HuffChar>
typedef List<HuffTree*> HuffForest;
HuffForest* initForest(int* freq);
HuffTree* minHChar(HuffForest* forest);
HuffTree* generateTree(HuffForest* forest);
