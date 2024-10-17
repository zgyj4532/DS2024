#include "Stack.hpp"
int main()
{
    Stack<char> op;
    char *equation = (char *)malloc(sizeof(100));
    cout << "请输入算式：" << endl;
    cin >> equation;
    // while(isalpha(static_cast<Rank>(*equation))) {equation++;}

    // char a = *equation;    
    // bool g = isalpha(static_cast<Rank>('('));
    // cout<<a<<" "<<g<<endl;

    char *RPN = nullptr;
    cout << "计算结果为：" << evaluate(equation, RPN) << endl;
    // while (*equation !='\0')
    // {
    //     if(isdigit(*equation)){
    //                     istringstream iss(equation);
    //         float number;
    //         while (isdigit(*equation))
    //             equation++;
    //         if (iss >> number)
    //         {
    //             opnd.push(number);
    //         }
    //     }
    //     else
    //         char sz[3];

    // }
    
    return 0;
}