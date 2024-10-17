#include "Stack.hpp"
int main()
{
    Stack<char> op;
    char *equation = (char *)malloc(sizeof(100));
    cout << "请输入算式：" << endl;
    cin >> equation;


    char *RPN = nullptr;
    cout << "计算结果为：" << evaluate(equation, RPN) << endl;

    
    return 0;
}