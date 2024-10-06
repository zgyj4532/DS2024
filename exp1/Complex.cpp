#include <cmath>
#include <complex>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include "Vector.cpp"

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
// 输出vector
void printVector(Vector<Complex> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    v[i].print();
  }
}
// 冒泡排序
bool bubble(Vector<Complex> &v, Rank lo, Rank hi)
{
  bool sorted = true;
  while (++lo < hi)
    if (v[lo - 1] > v[lo])
    {
      sorted = false;
      swap(v[lo - 1], v[lo]);
      v[lo - 1].print();
      v[lo].print();
    }
  return sorted;
}

void bubbleSort(Vector<Complex> &v, Rank lo, Rank hi)
{
  while (!bubble(v, lo, hi--))
    ;
}

void merge(Vector<Complex> &v, Rank lo, Rank mi, Rank hi)
{
  int n1 = mi - lo + 1, n2 = hi - mi;
  Vector<Complex> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
  {
    L[i] = v[lo + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = v[mi + 1 + i];
  }
  int i = 0, j = 0, k = lo;
  while (i < n1 && j < n2)
  {
    if (L[i] < R[j])
    {
      v[k] = L[i++];
    }
    else
    {
      v[k] = R[j++];
    }
    k++;
  }
  while (i < n1)
    v[k++] = L[i++];
  while (j < n2)
    v[k++] = R[j++];
}
void mergeSort(Vector<Complex> &v, Rank lo, Rank hi)
{
  if (hi - lo < 2)
    return;
  int mi = (lo + hi) / 2;
  mergeSort(v, lo, mi);
  mergeSort(v, mi, hi);
  merge(v, lo, mi, hi);
}
void revese_sort(Vector<Complex> &v)
{
  Vector<Complex> ev = v;
  int i = 0, j = ev.size() - 1;
  while (i < v.size())
    v[i++] = ev[j--];
}
// 测试排序效率
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
  spendtime = ((double)(end - start) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC = 1000
  cout << "Bubble Sort took " << spendtime << " seconds" << endl;
  // 归并排序
  start = clock();
  mergeSort(v2, 0, v2.size());
  end = clock();
  spendtime = ((double)(end - start) / CLOCKS_PER_SEC);
  cout << "Merge Sort took " << spendtime << " seconds" << endl;

} // 斐波那契查找
int fibsearch(Vector<Complex> &A, double e)
{
  int lo = 0, hi = A.size();
  Fib fib(hi - lo);
  while (lo < hi)
  {
    while (hi - lo < fib.get())
      fib.prev();
    Rank mi = lo + fib.get() - 1;
    if (e < A[mi].getmodulus())
      hi = mi;
    else if (e > A[mi].getmodulus())
      lo = mi + 1;
    else
      return mi;
  }
  return -1;
}
// 区间查找
Vector<Complex> findInRange(Vector<Complex> &v, double m1, double m2)
{
  Vector<Complex> res;
  int lo = fibsearch(v, m1);
  cout << lo << endl;
  int hi = fibsearch(v, m2);
  cout << hi << endl;
  for (int i = lo; i < hi + 1; i++)
  {
    res.insert(v[i]);
  }
  return res;
}

