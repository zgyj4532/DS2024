#include "Vector.cpp"
#include "PQ.hpp"
template <typename T> class PQ_ComplHeap: public PQ<T>,public Vector<T>
{
protected:
    Rank percolateDown(Rank n ,Rank i);//下滤
    Rank percolateUp(Rank i);//上滤
    void heapify(Rank n);//建堆
public:
    PQ_ComplHeap() { }
    PQ_ComplHeap(T* A,Rank n) {Vector<T>::copyFrom(A,0,n);heapify(n);}//批量构造
    void insert(T);
    T getMax();
    T delMax();
};

