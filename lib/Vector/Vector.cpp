#include "Vector.h"
// 基于复制的构造方法
ttt void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
        _elem[_size++] = A[lo++];
}
// 重载向量运算符=
ttt Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (_elem)
        free(_elem);
    copyFrom(V._elem, 0, V.size());
    return *this;
}
// 扩容
ttt void Vector<T>::expand()
{
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete[] oldElem;
}
// 缩容
ttt void Vector<T>::shrink()
{
    if (_capacity < DEFAULT_CAPACITY << 1)
        return;
    if (_size << 2 > _capacity)
        return;
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete[] oldElem;
}
// 重载下标操作符，可以类似于数组形式引用各元素
ttt T &Vector<T>::operator[](Rank r)
{
    return _elem[r];
}
// 整体置乱
ttt void unsort(Vector<T> &V)
{

    for (int i = V.size(); i > 0; i--)
        swap(V[i - 1], V[rand() % i]);
}
// 对[lo, hi)置乱
ttt void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *V = _elem + lo;
    for (Rank i = hi - lo; i > 0; i--)
        swap(V[i - 1], V[rand() % i]);
}
// 无序向量区间查找
ttt
    Rank
    Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && (e != _elem[hi]))
        return hi;
}
// 插入元素
ttt
    Rank
    Vector<T>::insert(Rank r, T const &e)
{
    expand();
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return r;
}
// 区间删除
ttt int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}
//单元素区间删除
ttt T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r,r+1);
    return e;
}
//无序去重
ttt int Vector<T>::dedup()
{
    int oldSize = _size;
    Rank i=1;
    while (i<_size)
    {
        find(_elem[i],0,i)<0 ?
        i++ : remove(i);

    }
    return oldSize - _size;
}
// 遍历
ttt void Vector<T>::traverse(void (*visit)(T&))//借助函数指针
{
    for(int i=0;i<_size;i++) visit(_elem[i]);
}
ttt template<typename VST>//借助函数对象 
void Vector<T>::traverse(VST& visit)
{
    for (int i = 0;i<_size;i++) visit(_elem[i]);

}
//基于遍历实现的累加功能
ttt struct  Increase
{
    virtual void operator() (T&e) {e++;}
};
ttt void increase(Vector<T> & V)
{
    V.traverse(Increase<T>());
}



//有序去重
ttt int Vector<T>::uniquify()
{
    Rank i =0,j=0;
    while (++j<_size)
        if(_elem[i]!=_elem[j]) _elem[++i]=_elem[++j];
    _size = ++i;
    shrink();
    return j-i;    
}
//查找
ttt
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
    return(rand()%2)?
        binSearch(_elem,e,lo,hi) : fibSearch(_elem,e,lo,hi);
}
//二分查找
ttt static Rank binSearch (T*A,T const& e,Rank lo,Rank hi)
{
    while(lo<hi)
    {
        Rank mi = (lo+hi) >>1;
        if(e<A[mi]) hi =mi ;
        else if (A[mi]<e) lo = mi + 1;
        else return mi;
    }
    return -1;//查找失败
}
//斐波那契查找
ttt static Rank fibSearch(T* A,T const& e,Rank lo,Rank hi)
{
    Fib fib(hi-lo);
    while (lo<hi)
    {
        while(hi-lo <fib.get()) fib.prev();
        Rank mi = lo +fib.get() -1;
        if (e<A[mi]) hi = mi;
        else if (e>A[mi]) lo = mi +1;
        else return mi;
    }
    return -1;
}
 
