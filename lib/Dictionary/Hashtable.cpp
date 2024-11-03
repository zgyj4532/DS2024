#include "Hashtable.hpp"
template <typename K, typename V>
Hashtable<K, V>::Hashtable(int c)
{
    M = primeNLT();
}