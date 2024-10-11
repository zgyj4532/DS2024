#include <cmath>
#include <complex>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include "Vector/Vector.h"

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
  double getr() const { return real; }
  double geti() const { return imag; }
  void same() { real = this->geti(); }
  void print() const
  {
    if (imag == 0)
      cout << fs2 real << " ";
    else
      cout << fs2 real << (imag >= 0 ? "+" : "") << fs2 imag
           << "i "; // 三目运算符检测虚部正负号
  }
  double getmodulus() const { return sqrt(real * real + imag * imag); }
};
