#include "Stack.hpp"
int main(){
    char *equation=(char*) malloc (sizeof(100));
    cout<<"请输入算式："<<endl;
    cin>>equation;
    char *RPN = nullptr;
    cout<<"计算结果为："<<evaluate(equation,RPN)<<endl;
    free(equation);
    return 0;
}