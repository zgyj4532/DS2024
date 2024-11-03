#include "Hashtable.hpp"
#include <memory>
#include <iostream>
#include <cmath>
#define maxNumber 1048576
//初始化素数列表 primes = {2,3,5,7,11,13...1048576}
std::vector<int> init_primes()
{
    std::vector<bool> isPrime(maxNumber,true);
    std::vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i<=sqrt(maxNumber);++i){
        if(isPrime[i]){
            for(int j = i*i;j<=maxNumber;j+=i){
                isPrime[j] = false;
            }
        }}
    for(int i = 2;i<=maxNumber;++i)
    {
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}
std::vector<int> Primes = init_primes();
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
int Hashtable<K, V>::prob4Free(const K &k)
{
    int r = hashCode(k)%M;
    while (ht[r])
    {
        r = (r+1)%M;
    }
    return r;
}
//重散列
template <typename K, typename V>
void Hashtable<K, V>::rehash()
{
    int old_capacity = M;
    Entry<K,V>** old_ht = ht;
    while (M*2>Primes[index])
    {
        index++;
    }
    M = Primes[index];
    N= 0;
    ht = new Entry<K,V>*[M];
    memset(ht,0,sizeof(ENtry<K,V>*)*M);
    release(lazyRemoval);
    lazyRemoval = new Bitmap(M);
    for(int i = 0;i<old_capacity;i++) if(old_ht[i]) put(old_ht[i]->key,old_ht[i]->value);
    release(old_ht);
}
template <typename K, typename V>
Hashtable<K, V>::Hashtable(int c)
{   
    index = 2; 
    M = Primes[index];//不小于c的素数
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
bool Hashtable<K, V>::put(K k, V v)
{
    if(ht[probe4Hit(k)]) return false;
    int r = prob4Free(k);
    ht[r] = new Entry<K,V>(k,v);++N;
    if(N*2 > M)rehash();
    return true;
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
