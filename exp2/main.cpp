#include "Stack.hpp"
int main()
{
    Stack<float> op;
    char *equation = (char *)malloc(sizeof(100));
    cout << "请输入算式：" << endl;
    cin >> equation;
    char *RPN = nullptr;
    // istringstream iss(equation);
    // float number;
    // while (isdigit(*equation))
    //     ++equation;
    // if (iss >> number)
    // {
    //     op.push(number);
    // }
    // if (!op.empty())
    // {
    //     cout << op.top() << endl;
    // }
    // else
    //     cerr << "error" << endl;
    // cout<<getOperatorIndex(*equation)<<endl ;

    // cout << "计算结果为：" << evaluate(equation, RPN) << endl;

    return 0;
}