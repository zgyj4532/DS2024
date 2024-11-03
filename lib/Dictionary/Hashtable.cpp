#include "Hashtable.hpp"
template <typename K, typename V>
Hashtable<K, V>::Hashtable(int c)
{
    M = 113;//不小于c的素数
    N = 0;
    ht = new Entry<K,V>*[M];
    memset(ht,0,sizeof(Entry<K,V>*) *M);
    lazyRemoval = new Bitmap(M);
}