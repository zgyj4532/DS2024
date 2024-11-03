#pragma once
#include "Dictionary.hpp"
#include "Bitmap.hpp"
template <typename K,typename V>
class Hashtable
{
private:
    Entry<K,V>** ht;//桶数组
    int M;//容量
    int N; //数量
    Bitmap* lazyRemoval;
#define lazilyRemoved(x) (lazyRemoval -> test(x))
#define MarkAsRemoved(x) (lazyRemoval -> set(x))
protected:
    int probe4Hit(const K& k);//找词条匹配的桶
    int prob4Free(const K& k);//找首个可用的桶
    void rehash();//扩充
public:
    Hashtable(int c = 5);
    ~Hashtable();
    int size()const{return N;}
    bool put(K,V);
    V* get(K k);
    bool remove(K k);
};


