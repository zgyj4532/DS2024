#include "PQ_ComplHeap.hpp"
template <typename T>
Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i)
{
    Rank j;
    // cout << "i = " << i << " ProperParent = " << ProperParent(Vector<T>::_elem, n, i) << endl;
    while (i != (j = ProperParent(Vector<T>::_elem, n, i)))
    {
        swap(Vector<T>::_elem[i], Vector<T>::_elem[j]);
        i = j;
        cout << i << "yes" << endl;
    }
    return i;

}
template <typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i)
{
    while (ParentValid(i))
    {
        Rank j = Parent(i);
        if (Vector<T>::_elem[i] < Vector<T>::_elem[j])
            break; // 上滤成功
        swap(Vector<T>::_elem[i], Vector<T>::_elem[j]);
        i = j; // 否则父子交换
    }
    return i;
}
template <typename T>
void PQ_ComplHeap<T>::heapify(Rank lo, Rank hi)
{
    // for (int i = LastInternal(n); InHeap(n, i); i--) // 自底向上
    //     percolateDown(n, i);                         // 下滤各内部节点
    //破防了，chatgpt启动（
    // 对区间 [lo, hi) 建立最小堆
    for (Rank i = (hi - 2) / 2; i >= lo; --i) {
        percolateDown(i, hi);
    }
}
template <typename T>
void PQ_ComplHeap<T>::insert(T e)
{
    Vector<T>::insert(e);              // 先插入末尾
    percolateUp(Vector<T>::_size - 1); // 再上溢
}
template <typename T>
T PQ_ComplHeap<T>::getMax()
{
    return Vector<T>::_elem[0];
}

template <typename T>
T PQ_ComplHeap<T>::delMax() // 删除优先级最高的词条
{
    T maxElem = Vector<T>::_elem[0];
    Vector<T>::_elem[0] = Vector<T>::_elem[--Vector<T>::_size];
    percolateDown(Vector<T>::_size, 0);
    return maxElem;
}

// // 基于向量的就地堆排序（不知道放哪了，就放这里了）
// template <typename T>
// void Vector<T>::heapSort(Rank lo, Rank hi)
// {
//     PQ_ComplHeap<T> H(_elem + lo, hi - lo); // 建议一个完全二叉堆
//     while (!H.empty())                      // 移除已排序的后缀
//     {
//         // cout<<H.getMax()<<" ";
//         _elem[hi-1] = H.delMax(); // 堆顶与末元素交换后下滤
//         hi--;
//     }
// }
