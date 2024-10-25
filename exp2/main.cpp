#include "heights.hpp"
int main()
{
    cout << "题目一：" << endl;
    Stack<char> op;
    char *equation = (char *)malloc(sizeof(100));
    const char *data0 = "11^2+(4/2-3)*5!";
    strcpy(equation, data0);
    cout << "测试案例1：" << equation << endl;
    char *RPN = nullptr;
    cout << "计算结果为：" << evaluate(equation, RPN) << endl;
    const char *data1 = "sin(30)+log(2.7182)";
    strcpy(equation, data1);
    cout << "测试案例2：" << equation << endl;
    cout << "计算结果为：" << fs2 evaluate(equation, RPN) << endl;
    const char *data2 = "1/0";
    strcpy(equation, data2);
    cout << "测试案例3：" << equation << endl;
    evaluate(equation, RPN);
    free(equation);
    cout << "题目二：" << endl;
    srand(time(0)); // 初始化随机数种子
    for (int i = 0; i < testConut; ++i)
    {
        // int len = 10;
        int len = rand() % 105 + 1; // 生成1-104的数组长度
        rand_test(len);
    }

    return 0;
}