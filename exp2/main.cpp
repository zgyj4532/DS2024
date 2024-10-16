#include "Stack.hpp"
int main()
{
    Stack<char> op;
    char *equation = (char *)malloc(sizeof(100));
    cout << "请输入算式：" << endl;
    cin >> equation;
    char *RPN = nullptr;
    // op.push('\0');
    // op.push('b');
    // op.push('c');
    // op.push('d');
    // cout <<op.top()<<endl;
    // char a = op.pop();
    // char b = op.pop();
    // char c = op.pop();
    // char d = op.pop();
    // cout <<a<<b<<c<<d<<op.pop()<<endl;
    cout << "计算结果为：" << evaluate(equation, RPN) << endl;

    return 0;
}