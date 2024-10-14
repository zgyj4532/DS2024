#include "Vector.cpp"
#define ll long long 
ttt class Stack : public Vector<T>
{
    public:
    void push(T const &e) { insert(size(), e); } // 入栈
    T pop() { return remove(size() - 1); }       // 出栈
    T &top() { return (*this)[size() - 1];  }
};
//进制转换
void convert( Stack<char>& S ,ll n,int base)
{
    static char digit[]
    ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n>0)
    {
        int re = (int)(n%base);
        S.push(digit[re]);
        n/=base;
    }
}
//括号匹配算法
bool paren(const char exp[],int lo,int hi)
{
    Stack<char> S;
    for(int i = lo; i<=hi;i++)
    {
        switch (exp[i]){
            case '(':case '[':case '{': S.push(exp[i]);break;
            case ')':if((S.empty())||('(' != S.pop())) return false;break;
            case ']':if((S.empty())||('[' != S.pop())) return false;break;
            case '}':if((S.empty())||('{' != S.pop())) return false;break;
            default: break;
        }
    }
    return S.empty();
}
