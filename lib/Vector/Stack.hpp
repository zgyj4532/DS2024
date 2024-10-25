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
int getOperatorIndex(char op);
// 运算符映射
ttt class Stack : public Vector<T>
{
public:
    void push(T const &e) { Vector<T>::insert(Vector<T>::size(), e); } // 入栈
    T pop() { return Vector<T>::remove(Vector<T>::size() - 1); }       // 出栈
    T &top() { return (*this)[Vector<T>::size() - 1]; }
};

// 进制转换
void convert(Stack<char> &S, ll n, int base);

// 括号匹配算法
bool paren(const char exp[], int lo, int hi);
bool paren(const char exp[]);
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
void append(char *&R, float a);

char orderBetween(char a, char S);
float d_transform(float x);
float calcu(char a, float n);
float power(float m, float n);
float calcu(float m, char a, float n);
// 表达式求值
float evaluate(char *S, char *&RPN);