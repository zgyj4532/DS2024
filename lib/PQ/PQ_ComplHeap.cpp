#include "PQ_ComplHeap.hpp"
template <typename T>
Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i)
{
    Rank j;
    while(i!=(j = ProperParent(_elem,n,i)))
    {swap(_elem[i],_elem[j]);i=j;}
    return i;
}
template <typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i)
{
    while(ParentValid(i))
    {
        Rank j = Parent(i);
        if(lt(_elem[i],_elem[j])) break;//上滤成功
        swap(_elem[i],_elem[j]);i=j;//否则父子交换
    }
    return i;
}
template <typename T>
void PQ_ComplHeap<T>::heapify(Rank n)
{
    for(int i = LastInternal(n);InHeap(n,i);i--)//自底向上
        percolateDown(n,i);//下滤各内部节点
}
template <typename T>
void PQ_ComplHeap<T>::insert(T e)
{
    Vector<T>::insert(e);//先插入末尾
    percolateUp(Vector<T>::_size-1);//再上溢
}
template <typename T>
T PQ_ComplHeap<T>::getMax()
{
    return _elem[0];
}

template <typename T>
T PQ_ComplHeap<T>::delMax()//删除优先级最高的词条
{
    T maxElem = _elem[0];_elem[0] = _elem[--Vector<T>::_size];
    percolateDown(_size,0);
    return maxElem;

}
