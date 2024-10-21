#pragma once
#include "Vector.cpp"
using namespace std;

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
bool operator>(const Complex a, const Complex b)
{

  return ((a.getmodulus() > b.getmodulus()) ||
          (a.getmodulus() == b.getmodulus() &&
           a.getr() > b.getr())); // 优先比较向量模，若模相同比较实部
}
bool operator>=(const Complex a, const Complex b)
{

  return ((a.getmodulus() >= b.getmodulus()) ||
          (a.getmodulus() == b.getmodulus() && a.getr() >= b.getr()));
}
bool operator<(const Complex a, const Complex b)
{

  return ((a.getmodulus() < b.getmodulus()) ||
          (a.getmodulus() == b.getmodulus() && a.getr() < b.getr()));
}
bool operator<=(const Complex a, const Complex b)
{

  return ((a.getmodulus() <= b.getmodulus()) ||
          (a.getmodulus() == b.getmodulus() && a.getr() <= b.getr()));
}
bool operator!=(const Complex a, const Complex b)
{

  return (a.getr() != b.getr()) || (a.geti() != b.geti());
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



void test_time(Vector<Complex> &v)
{
  Vector<Complex> v1 = v;
  Vector<Complex> v2 = v;
  clock_t start, end;
  double spendtime;
  // 冒泡排序
  start = clock();
  bubbleSort(v1, 0, v1.size());
  end = clock();
  spendtime = ((double)(end - start)); // CLOCKS_PER_SEC = 1000
  cout << "Bubble Sort took " << spendtime << " ms" << endl;
  // 归并排序
  start = clock();
  mergeSort(v2, 0, v2.size());
  end = clock();
  spendtime = ((double)(end - start));
  cout << "Merge Sort took " << spendtime << " ms" << endl;

} 
