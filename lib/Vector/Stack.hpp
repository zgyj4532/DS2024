#include "Vector.cpp"
#include <cstring>
#include <unordered_map>
#define ll long long
#define N_OPTR 11 // 运算符总数
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
    tr_f,
    EOE
} Operator;
int getOperatorIndex(char op)
{
    unordered_map<char, int> opIndex =
        {
            {'+', 0}, {'-', 1}, {'*', 2}, {'/', 3}, {'^', 4}, {'!', 5}, {'(', 6}, {')', 7}, {'\0', 8}, {'s', 9}, {'c', 9}, {'t', 9}, {'l', 10}}; // 一种很取巧的三角函数算法XD
    auto i = opIndex.find(op);
    if (i != opIndex.end())
        return i->second;
    else
        return -1;
}
// 运算符集合
const char pri[N_OPTR][N_OPTR] = { // 运算符优先等级 [栈顶] [当前]
                                   /*              |-------------------- 当 前 运 算 符 --------------------| */
                                   /*               +    -    *    /    ^    !    (    )   \0  sin log*/
    /* --  + */ '>', '>', '<', '<', '<', '<', '<', '>', '>', '<', '<',
    /* |   - */ '>', '>', '<', '<', '<', '<', '<', '>', '>', '<', '<',
    /* 栈  * */ '>', '>', '>', '>', '<', '<', '<', '>', '>', '<', '<',
    /* 顶  / */ '>', '>', '>', '>', '<', '<', '<', '>', '>', '<', '<',
    /* 运  ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>', '>', '>',
    /* 算  ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>', '>', '>',
    /* 符  ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ', '<', '<',
    /* |   ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    /* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '=', '<', '<',
    /* --sin */ '>', '>', '>', '>', '>', '>', '<', '>', '>', '>', '<',
    /* --log */ '>', '>', '>', '>', '>', '>', '<', '>', '>', '>', '<'};
// 运算符映射
ttt class Stack : public Vector<T>
{
public:
    void push(T const &e) { Vector<T>::insert(Vector<T>::size(), e); } // 入栈
    T pop() { return Vector<T>::remove(Vector<T>::size() - 1); }       // 出栈
    T &top() { return (*this)[Vector<T>::size() - 1]; }
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
bool paren(const char exp[])
{
    return paren(exp, 0, strlen(exp) - 1);
}
// 读入操作数 不知道为什么push不进去，丢了
// void readNumber(char *S, Stack<float> opnd)
// {
//     if(S == nullptr) {cerr<<"Null pointer provided"<<endl; return;}
//     istringstream iss(S);
//     float number;
//     if(iss>>number)
//     {
//         opnd.push(number);
//     }
// }
// 重构append函数
void append(char *&R, float a)
{
    if (R == nullptr)
    {
        R = new char[1];
        R[0] = '\0';
    }
    char *b = (char *)malloc(sizeof(50));
    sprintf(b, "%.2f", a); // 将float类型转化为char型
    size_t ol = strlen(R);
    size_t nl = ol + strlen(b) + 1;
    char *nS = new char[nl];
    strcpy(nS, R);
    strcat(nS, b);
    R = nS;
}
char orderBetween(char a, char S)
{
    int op_c = getOperatorIndex(a);
    int op_s = getOperatorIndex(S);
    if (op_c == -1 || op_s == -1)
        return ' ';
    char priority = pri[op_c][op_s];
    return priority;
}
float d_transform(float x)
{
    return x * (M_PI / 180.00);
}
float calcu(char a, float n)
{
    switch (a)
    {
    case ('!'):
    {
        float r = 1.0;
        while (n > 1)
        {
            r *= n--;
        }
        return r;
    }
    case ('s'):
        return sin(d_transform(n));
    case ('c'):
        return cos(d_transform(n));
    case ('t'):
        return tan(d_transform(n));
    case ('l'):
        return logf(n);
    default:
        return -1;
    }
}
float power(float m, float n)
{
    float r = 1.0;
    bool nega = n < 0;
    if (m == 0 && nega)
        return ' '; // 0不能做除数
    n = nega ? -n : n;
    for (int i = 0; i < n; i++)
    {
        r *= m;
    }
    return nega ? 1 / r : r;
}
float calcu(float m, char a, float n)
{
    switch (a)
    {
    case '+':
        return m + n;
    case '-':
        return m - n;
    case '*':
        return m * n;
    case '/':
        return m / n;
    case '^':
        return power(m, n);

    default:
        return ' ';
    }
}
// 表达式求值
float evaluate(char *S, char *&RPN)
{
    Stack<float> opnd;
    Stack<char> optr;
    optr.push('\0');
    // cout<<opnd.top()<<endl;
    while (!optr.empty())
    {
        if (isdigit(*S))
        {
            istringstream iss(S);
            float number;
            while (isdigit(*S) || *S == '.')
                S++;
            if (iss >> number)
            {
                opnd.push(number);
            }
            // if(!opnd.empty()) {cout<<opnd.top()<<endl;}
            // else {cerr<<"error"<<endl;}
            // cout<<opnd.top()<<endl;
            append(RPN, opnd.top());
        }
        else
            switch (orderBetween(optr.top(), *S))
            {
            case '<':
                optr.push(*S);
                if (isalpha(static_cast<Rank>(*S)))
                {
                    while (isalpha(static_cast<Rank>(*S)))
                        S++;
                } // 如果S指向三角函数或者log
                else
                    S++;
                break;
            case '=':
                optr.pop();
                S++;
                break;
            case '>':
            {
                char op = optr.pop();
                append(RPN, op);
                if ('!' == op || 's' == op || 'c' == op || 't' == op || 'l' == op)
                {
                    float p0pnd = opnd.pop();
                    opnd.push(calcu(op, p0pnd));
                }
                else
                {
                    float p0pnd2 = opnd.pop(), p0pnd1 = opnd.pop();
                    opnd.push(calcu(p0pnd1, op, p0pnd2));
                }
                break;
            }
            default:
                exit(-1);
            }
    }
    return opnd.pop();
}