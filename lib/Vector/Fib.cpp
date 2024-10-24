#include "Fib.hpp"

int Fib::get() const
{
    return b;
}

void Fib::next()
{
    int c = a + b;
    a = b;
    b = c;
}

void Fib::prev()
{
    int c = b - a;
    b = a;
    a = c;
}
