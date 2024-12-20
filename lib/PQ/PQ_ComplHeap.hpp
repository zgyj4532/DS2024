#include "Vector.cpp"
#include "PQ.hpp"
#define InHeap(n, i) (((-1) < (i)) && ((i) < (n))) // 判断PQ是否合法
#define Parent(i) ((i - 1) >> 1)                   // PQ父节点
#define LastInternal(n) Parent(n - 1)              // PQ末节点父亲
#define LChild(i) (1 + ((i) << 1))                 // PQ[i]左孩子
#define RChild(i) ((1 + (i)) << 1)                 // PQ[i]右孩子
#define ParentValid(i) (i > 0)                     // 判断PQ是否有父亲
#define LChildValid(n, i) InHeap(n, LChild(i))
#define RChildValid(n, i) InHeap(n, RChild(i))
#define Bigger(PQ, i, j) (((PQ[i]) < (PQ[j])) ? (j) : (i))  // 取最大值
#define Smaller(PQ, i, j) (((PQ[i]) < (PQ[j])) ? (i) : (j)) // 取较小的值
/*父子三者中的最大者，什么逆天三目运算符嵌套*/
#define ProperParent(PQ, n, i) \
    (RChildValid(n, i) ? Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i)) : (LChildValid(n, i) ? Bigger(PQ, i, LChild(i)) : (i)))
/*
like:
if(RChildValid(n, i))
    return Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i));
else
    if(LChildValid(n, i))
    return Bigger(PQ, i, LChild(i));
    else  return i;
*/

// (RChildValid(n, i) ? Smaller(PQ, Smaller(PQ, i, LChild(i)), RChild(i)) : \
    // (LChildValid(n, i) ? Smaller(PQ, i, LChild(i)) : i))
template <typename T>
class PQ_ComplHeap : public PQ<T>, public Vector<T>
{
protected:
    Rank percolateDown(Rank lo, Rank hi); // 下滤
    Rank percolateUp(Rank i);           // 上滤
    void heapify(Rank lo, Rank hi);               // 建堆
public:
    PQ_ComplHeap() {}
    PQ_ComplHeap(T *A, Rank n)
    {
        Vector<T>::copyFrom(A, 0, n);
        heapify(0,n);
    } // 批量构造
    void insert(T);
    T getMax();
    T delMax();
};
