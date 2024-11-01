#include "Stack.hpp"
#define case_return(a, b) \
    case a:               \
        return b;
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
    EOE,
    SIN,
    LOG,
} Operator;
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
int getOperatorIndex(char op)
{
    // unordered_map<char, int> opIndex =
    //     {
    //         {'+', 0}, {'-', 1}, {'*', 2}, {'/', 3}, {'^', 4}, {'!', 5}, {'(', 6}, {')', 7}, {'\0', 8}, {'s', 9}, {'c', 9}, {'t', 9}, {'l', 10}}; // 一种很取巧的三角函数算法XD
    // auto i = opIndex.find(op);
    // if (i != opIndex.end())
    //     return i->second;
    // else
    //     return -1;
    switch (op)
    {
        case_return('+', ADD)
            case_return('-', SUB)
                case_return('*', MUL)
                    case_return('/', DIV)
                        case_return('^', POW)
                            case_return('!', FAC)
                                case_return('(', L_P)
                                    case_return(')', R_P)
                                        case_return('s', SIN)
                                            case_return('c', SIN)
                                                case_return('t', SIN)
                                                    case_return('l', LOG)
                                                        case_return('\0', EOE) default : return -1;
    }
}
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

void append(char *&R, float a)
{
    if (R == nullptr)
    {
        R = new char[1];
        R[0] = '\0';
    }
    char *b = new char[50];
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
        { cerr<<"错误：未能找到字符"<<endl;
            return ' ';}
    char priority = pri[op_c][op_s];
    return priority;
}

float d_transform(float x) { return x * (M_PI / 180.00); }

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
        cerr<<"0不能作为除数"<<endl; // 0不能做除数
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
    case_return('+', m + n)
    case_return('-', m - n)
    case_return('*', m * n)
    case '/':
        if(n!=0) return m / n;
        else cerr<<"错误：0不能做除数"<<endl;
    case '^':
        return power(m, n);

        default : return ' ';
    }
}

float evaluate(char *S, char *&RPN)
{
    if(!paren(S)){cerr<<"错误：括号不匹配"<<endl;exit(-1);}
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
            while (isdigit(*S) || *S == '.')//检测是否有小数
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
                    while (isalpha(static_cast<Rank>(*S)))// 如果S指向三角函数或者log
                        S++;
                } 
                else
                    S++;
                break;
            case '=':
                optr.pop();
                if(*S) S++;//兼容VS
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
