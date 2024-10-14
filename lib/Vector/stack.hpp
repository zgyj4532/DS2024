#include "Vector.cpp"
#include <cstring>
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
} Operator;                        // 运算符集合
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
#define ll long long
ttt class Stack : public Vector<T>
{
public:
    void push(T const &e) { insert(size(), e); } // 入栈
    T pop() { return remove(size() - 1); }       // 出栈
    T &top() { return (*this)[size() - 1]; }
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
    int s = (int)S;
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
            case '<':
            }
    }
}