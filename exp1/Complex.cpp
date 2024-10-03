#include <iostream>
#include <complex>
#include <random>
#include <ctime>
#include <iomanip>
#include "Fib.h"
using namespace std;
#define fs2 fixed << setprecision(2) << // 保留2位小数
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
    void same()
    {
        real = this->geti();
    }
    void print() const
    {
        if (imag == 0)
            cout << fs2 real << " ";
        else
            cout << fs2 real << (imag >= 0 ? "+" : "") << fs2 imag << "i "; // 三目运算符检测虚部正负号
    }
};
bool operator>(const Complex a, const Complex b)
{

    return (a.getr() > b.getr()) ? true : (a.geti() > b.geti ? true : false);
}
bool operator>=(const Complex a, const Complex b)
{

    return (a.getr() >= b.getr()) ? true : (a.geti() >= b.geti ? true : false);
}
bool operator<(const Complex a, const Complex b)
{

    return (a.getr() < b.getr()) ? true : (a.geti() < b.geti ? true : false);
}
bool operator<=(const Complex a, const Complex b)
{

    return (a.getr() <= b.getr()) ? true : (a.geti() <= b.geti ? true : false);
}
bool operator!=(const Complex a, const Complex b)
{

    return (a.getr() != b.getr()) && (a.geti() != b.geti());
}
bool operator==(const Complex a, const Complex b)
{

    return (a.getr() == b.getr()) && (a.geti() == b.geti());
}
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
