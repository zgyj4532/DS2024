#define N_CHAR (0x80-0x20)
struct HuffChar{
    char ch;int weight;
    HuffChar(char c = '^',int w = 0):ch(c),weight(w) {}
    bool operator<(HuffChar const& hc){return weight>hc.weight;}
    bool operator>(HuffChar const& hc){return weight<hc.weight;}
    bool operator==(HuffChar const& hc){return weight==hc.weight;}
    bool operator!=(HuffChar const& hc){return weight!=hc.weight;}

};
int* statistics(char* sample_text_file)//统计字符出现频率
{
    int* freq = new int[N_CHAR];
    memset(freq,0,sizeof(int) * N_CHAR);//清零
    FILE* fp = fopen(sample_text_file,"r");
    for(char ch; 0<fscanf(fp,"%c",&ch);)
        if(ch>=0x20) freq[ch-0x20]++;
    fclose(fp);
    return freq;     
}