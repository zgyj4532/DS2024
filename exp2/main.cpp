#include "Stack.hpp"
int main(){
    char equation[100];
    cout<<"请输入算式："<<endl;
    cin>>equation;
    char *RPN;
    cout<<"计算结果为："<<evaluate(equation,RPN)<<endl;
    return 0;
}