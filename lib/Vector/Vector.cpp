#pragma once
#define ttt template <typename T>
#include "Fib.hpp"
#include <cmath>
#include <complex>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;
using Rank = unsigned int; // 秩
#define DEFAULT_CAPACITY 3 // 默认的初始容量（实际应用中可设置为更大）
ttt class Vector
{ // 向量模板类
protected:
    Rank _size;
    Rank _capacity;
    T *_elem;                                    // 规模、容量、数据区
    void copyFrom(T const *A, Rank lo, Rank hi); // 复制数组区间A[lo, hi)
    void expand();                               // 空间不足时扩容
    void shrink();                               // 装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);               // 扫描交换
    void bubbleSort(Rank lo, Rank hi);           // 起泡排序算法
    Rank maxItem(Rank lo, Rank hi);              // 选取最大元素
    void selectionSort(Rank lo, Rank hi);        // 选择排序算法
    void merge(Rank lo, Rank mi, Rank hi);       // 归并算法
    void mergeSort(Rank lo, Rank hi);            // 归并排序算法
    void heapSort(Rank lo, Rank hi);             // 堆排序（稍后结合完全堆讲解）
    Rank partition(Rank lo, Rank hi);            // 轴点构造算法
    void quickSort(Rank lo, Rank hi);            // 快速排序算法
    void shellSort(Rank lo, Rank hi);            // 希尔排序算法
public:
    // 构造方法
    Vector(Rank c = DEFAULT_CAPACITY) // 容量为c的空向量
    {
        _elem = new T[_capacity = c];
        _size = 0;
    }
    Vector(Rank c, Rank s, T v) // 容量为c、规模为s、所有元素初始为v；s<=c
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    }
    Vector(T const *A, Rank n) { copyFrom(A, 0, n); }                           // 数组整体复制
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }               // 区间
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }               // 向量整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } // 区间
    // 析构方法
    ~Vector() { delete[] _elem; } // 释放内部空间
    // 只读访问接口

    Rank size() const { return _size; }                          // 规模
    bool empty() const { return !_size; }                        // 判空
    Rank find(T const &e) const { return find(e, 0, _size); }    // 无序向量整体查找
    Rank find(T const &e, Rank lo, Rank hi) const;               // 无序向量区间查找
    Rank select(Rank k) { return quickSelect(_elem, _size, k); } // 从无序向量中找到第k大的元素
    Rank search(T const &e) const                                // 有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const; // 有序向量区间查找
    // 可写访问接口
    T &operator[](Rank r);                               // 重载下标操作符，可以类似于数组形式引用各元素
    Vector<T> &operator=(Vector<T> const &);             // 重载赋值操作符，以便直接克隆向量
    T remove(Rank r);                                    // 删除秩为r的元素
    int remove(Rank lo, Rank hi);                        // 删除秩在区间[lo, hi)之内的元素
    Rank insert(Rank r, T const &e);                     // 插入元素
    Rank insert(T const &e) { return insert(_size, e); } // 默认作为末元素插入
    void sort(Rank lo, Rank hi);                         // 对[lo, hi)排序
    void sort() { sort(0, _size); }                      // 整体排序
    void unsort(Rank lo, Rank hi);                       // 对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                  // 整体置乱
    int dedup();                                        // 无序去重
    int uniquify();                                     // 有序去重
    // 遍历
    void traverse(void (*)(T &)); // 遍历（使用函数指针，只读或局部性修改）
    template <typename VST>
    void traverse(VST &); // 遍历（使用函数对象，可全局性修改）

    Rank binSearch (T*A,T const& e,Rank lo,Rank hi);
}; // Vector
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

 
