#include "HuffCode.hpp"
#include <cstdio>
unsigned int* statistics(char* sample_text_file)//统计字符出现频率
{
    cout<<sample_text_file<<endl;
    unsigned int* freq = new unsigned int[N_CHAR];
    memset(freq,0,sizeof(int) * N_CHAR);//清零
    FILE* fp = fopen(sample_text_file,"r");
    if(fp == NULL) {
        perror("error opening file");
        return 0;
    }
    cout <<"fp:"<<fp<<endl;
    for(char ch; 0<fscanf(fp,"%c",&ch);)
        if(ch>=0x20) freq[ch-0x20]++;
    fclose(fp);
    return freq;     
}
void travPre_R(BinNodePosi(HuffChar) x)
{
	if (!x) return;
	std::cout << x->data.ch << ' ';
	travPre_R(x->lc);
	travPre_R(x->rc);
}
int main()
{   
	char file[14] = "exp3/word.txt";
	unsigned int* freq = statistics(file);//根据样本文件，统计各字符的出现频率
	HuffForest* forest = initForest(freq); delete freq; //创建Huffman森林
	HuffTree* tree = generateTree(forest); delete forest;//构造Huffman编码树
	std::cout << "先序遍历的结果为（'^'为默认占位符号）：" << std::endl;
	travPre_R(tree->root());
    // for(int i = 2;i<argc;i++)
    // {
    //     Bitmap* codeString = new Bitmap;
    //     int n = encode(table,codeString,argv[i]);
    //     decode(tree,codeString,n);
    //     codeString = nullptr;
    // }
    // table = nullptr;
    tree = nullptr;
    return 0;
}