#include <iostream>
#include <complex>
#include <random>
#include <ctime>
#include<iomanip>
#include "Vector.cpp"
#define fs2 fixed<<setprecision(2)<< //保留2位小数
using namespace std;
// 复数类
class Complex
{
private:
    double real; // 实部
    double imag; // 虚部
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    double getr() const
    {
        return real;
    }
    double geti() const
    {
        return imag;
    }
    void print() const
    {
        if (imag == 0)
            cout << fs2 real<< " ";
        else
            cout << fs2 (imag >= 0 ? "+" : "") << fs2 imag << "i "; // 三目运算符检测虚部正负号
    }
};
Complex randomcomp(double min, double max)
{

    static default_random_engine generator; // 导入random_engine
    generator.seed(random_device{}());
    static uniform_real_distribution<double> distribution(min, max);
    double real = distribution(generator);
    // double imag = 0.0;
    double imag = distribution(generator);
    return Complex(real, imag);
}

    


int main()
{
    // 生成一个无序的复数向量
    Vector<Complex> cv;
    for (int i = 0; i < 10; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        cv.insert(rc);
    }
    cout << "The original complex vector is :" << endl;
    for(int i = 0 ;i <10 ; i++)
    {
        cv[i].print();
    }
    cout<<endl;
    // 置乱
    cv.unsort();
    cout << "And then unsort complex vector is :" << endl;
    for(int i = 0 ;i <10 ; i++)
    {
        cv[i].print();
    }
    //查找
    cv.search()
    return 0;
}
