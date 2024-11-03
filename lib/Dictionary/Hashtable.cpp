#include "Hashtable.hpp"
#include <memory>
template <typename K, typename V>
int Hashtable<K, V>::probe4Hit(const K &k)
{
    int r = hashCode(k)%M;
    while ((ht[r]&&k!=ht[r]->key)||(!ht[r]&&lazilyRemoved(r)))
    {
        r = (r+1)%M;
    }
    return r;
}
template <typename K, typename V>
Hashtable<K, V>::Hashtable(int c)
{
    M = 113;//不小于c的素数
    N = 0;
    ht = new Entry<K,V>*[M];
    memset(ht,0,sizeof(Entry<K,V>*) *M);
    lazyRemoval = new Bitmap(M);
}

template <typename K, typename V>
Hashtable<K, V>::~Hashtable()
{
    for(int i = 0;i<M;i++)
    if(ht[i]) release(hi[i]);
    release(ht);
    release(lazyRemoval);
}

template <typename K, typename V>
V *Hashtable<K, V>::get(K k)
{
    int r = probe4Hit(k);
    return ht[r] ? &(ht[r]->value) : NULL;
}

template <typename K, typename V>
bool Hashtable<K, V>::remove(K k)
{
    int r = probe4Hit(k);
    if(!ht[r]) return false;
    release(ht[r]);
    ht[r] = NULL;
    MarkAsRemoved(r);
    N--;
    return true;
}
