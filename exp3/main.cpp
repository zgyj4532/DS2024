#include "HuffCode.hpp"
#include <cstdio>
#include <vector>
#include <unordered_map>
unsigned int* statistics(char* sample_text_file)//统计字符出现频率
{
    // cout<<sample_text_file<<endl;
    unsigned int* freq = new unsigned int[N_CHAR];
    memset(freq,0,sizeof(int) * N_CHAR);//清零
    FILE* fp = fopen(sample_text_file,"r");
    // cout <<"fp:"<<fileno(fp)<<endl;
    if(fp == NULL) {
        perror("error opening file");
        return 0;
    }
    // cout <<"fp:"<<fp<<endl;
    for(char word; 0<fscanf(fp,"%c",&word);)
        if (('a' <= word) && (word <= 'z')) {freq[word - 'a']++;}
		else if (('A' <= word) && (word <= 'Z')) {freq[word - 'A']++;} 
    fclose(fp);
    return freq;     
}
std::unordered_map<char,std::string> huffmanTable;//散装哈夫曼编码表

void travPre_R(BinNodePosi(HuffChar) x ,std::string code = "")
{
	if (!x) return;
	// std::cout << x->data.ch << ' ';
	// travPre_R(x->lc);
	// travPre_R(x->rc);
    if(!x->lc && !x->rc) huffmanTable[x->data.ch] = code;
    if(x->lc) {travPre_R(x->lc,code + '0');}
    if(x->rc) {travPre_R(x->rc,code + '1');}
}

int main()
{   
	char file[45] = "/home/crayzamb/projects/DS2024/exp3/word.txt";
	unsigned int* freq = statistics(file);//根据样本文件，统计各字符的出现频率
	HuffForest* forest = initForest(freq); delete freq; //创建Huffman森林
	HuffTree* tree = generateTree(forest); delete forest;//构造Huffman编码树
    // HuffTable* table - generateTable(tree);
	std::cout << "哈夫曼编码表为" << std::endl;
	travPre_R(tree->root());//初始化编码表
    for(const auto&i : huffmanTable)
    {
        char data = i.first;
        std::string code = i.second;
        std::cout << data<<": "<< code<<std::endl;
    }
    std::cout<<std::endl;
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