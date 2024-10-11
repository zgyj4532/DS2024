#include "Complex.h"

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