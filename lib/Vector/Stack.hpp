#include "Vector.cpp"
#include <cstring>
#include <unordered_map>
#define ll long long
#define N_OPTR 9 // 运算符总数
typedef enum
{
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    FAC,
    L_P,
    R_P,
    EOE
} Operator;
int getOperatorIndex(char op)
{
    unordered_map<char,int> opIndex = 
    {
        {'+',0},{'-',1},{'*',2},{'/',3},{'^',4},{'!',5},{'(',6},{')',7},{'\0',8}
    };
    auto i = opIndex.find(op);
    if(i != opIndex.end()) return i->second;
    else return -1;
}                       
// 运算符集合
const char pri[N_OPTR][N_OPTR] = { // 运算符优先等级 [栈顶] [当前]
    /*              |-------------------- 当 前 运 算 符 --------------------| */
    /*              +      -      *      /      ^      !      (      )      \0 */
    /* --  + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /* |   - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /* 栈  * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* 顶  / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* 运  ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
    /* 算  ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
    /* 符  ( */ '<', '<', '<', '<', '<', '<', '<', '~', ' ',
    /* |   ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    /* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '~'};
//运算符映射
ttt class Stack : public Vector<T>
{   
public:
    
    void push(T const &e) { Vector<T>::insert(e); } // 入栈
    T pop() { return Vector<T>::remove(Vector<T>::size() - 1); }       // 出栈
    T& top() { return (*this)[Vector<T>::size() - 1]; }
};

// 进制转换
void convert(Stack<char> &S, ll n, int base)
{
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0)
    {
        int re = (int)(n % base);
        S.push(digit[re]);
        n /= base;
    }
}
// 括号匹配算法
bool paren(const char exp[], int lo, int hi)
{
    Stack<char> S;
    for (int i = lo; i <= hi; i++)
    {
        switch (exp[i])
        {
        case '(':
        case '[':
        case '{':
            S.push(exp[i]);
            break;
        case ')':
            if ((S.empty()) || ('(' != S.pop()))
                return false;
            break;
        case ']':
            if ((S.empty()) || ('[' != S.pop()))
                return false;
            break;
        case '}':
            if ((S.empty()) || ('{' != S.pop()))
                return false;
            break;
        default:
            break;
        }
    }
    return S.empty();
}
// 读入操作数
void readNumber(char *S, Stack<float> opnd)
{
    float s = static_cast<float>(*S);
    opnd.push(s);
}
// 重构append函数
void append(char *&R, float a)
{
    char b[50];
    sprintf(b, "%f", a); // 将float类型转化为char型
    size_t ol = strlen(R);
    size_t nl = strlen(b);
    char *nS = new char[ol + nl + 1];
    strcpy(nS, R);
    strcat(nS, b);
    delete[] R;
    R = nS;
}
char orderBetween(char a,char S)
{
    int op_c = getOperatorIndex(a);
    int op_s = getOperatorIndex(S);
    if(op_c == -1 || op_s ==-1) return ' ';
    char priority = pri[op_s][op_c];
    switch (priority)
    {
    case '<': return a;
    case '>': return S;    
    case ' ':
    case '-':
    
    default:
        return ' ';
    }
}
float calcu(char a,float n)
{
    float r = 1.0;
        while(n>1) {r*=n--;}
    return r;    
}
float power(float m , float n)
{
    float r = 1.0;
    bool nega=n<0;
    if(m==0 && nega) return ' ';//0不能做除数
    n=nega?-n:n;
    for(int i=0;i<n;i++)
    {
        r *=m;
    }
    return nega?1/r:r;
}
float calcu(float m,char a,float n)
{
    switch (a)
    {
    case '+':return m+n;
    case '-':return m-n;
    case '*':return m*n;
    case '/':return m/n;
    case '^':return power(m,n);
    default: return ' ';
    }  
}
// 表达式求值
float evaluate(char *S, char *&RPN)
{
    Stack<float> opnd;
    Stack<char> optr;
    optr.push('\0');
    while (!optr.empty())
    {
        if (isdigit(*S))
        {
            readNumber(S, opnd);
            append(RPN, opnd.top());
        }
        else
            switch (orderBetween(optr.top(), *S))
            {
            case '<': optr.pop();S++;break;
            case '=': optr.pop();S++;break;
            case '>': {
            char op = optr.pop();append(RPN,op);
            if('!' == op) {float p0pnd = opnd.pop();opnd.push(calcu(op,p0pnd));}
            else {float p0pnd2 = opnd.pop(),p0pnd1 = opnd.pop();opnd.push(calcu(p0pnd1,op,p0pnd2));}
            break;
            }
            default:exit(-1);
            }
            
    }
    return opnd.pop();
}