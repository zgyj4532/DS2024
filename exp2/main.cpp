#include "Stack.hpp"
int main()
{
    Stack<char> op;
    char *equation = (char *)malloc(sizeof(100));
    const char *s="1+(4/2-3)*5!";
    strcpy(equation,s);
    cout << "测试案例1：" << equation<<endl;
    char *RPN = nullptr;
    cout << "计算结果为：" << evaluate(equation, RPN) << endl;
    strcpy(equation,"sin(30)+log(2.7182)");
    cout << "测试案例2：" << equation<<endl;
    cout << "计算结果为：" << fs2 evaluate(equation, RPN) << endl;
    free(equation);
    return 0;
}