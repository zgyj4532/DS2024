#include "List.hpp"
ttt void List<T>::init()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
}
ttt T &List<T>::operator[](Rank r) const
{
    ListNodePosi(T) p = first();
    while (0 < r--)
    {
        p = p->succ;
    }
    return p->data;
}
// 插入接口
ttt ListNodePosi(T) List<T>::insertAsFirst(T const &e)
{
    _size++;
    return header->insertAsSucc(e);
}
ttt ListNodePosi(T) List<T>::insertAsLast(T const &e)
{
    _size++;
    return header->insertAsPred(e);
}
ttt ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const &e)
{
    _size++;
    return p->insertAsSucc(e);
}
ttt ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const &e)
{
    _size++;
    return p->insertAsPred(e);
}
// 插入
ttt ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
{
    ListNodePosi(T) x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}
ttt ListNodePosi(T) ListNode<T>::insertAsSucc(T const &e)
{
    ListNodePosi(T) x = new ListNode(e, this, succ);
    succ->pred = x;
    succ = x;
    return x;
}
// 基于复制的构造
ttt void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
    init();
    while (n--)
    {
        insertAsLast(p->data);
        p = p->succ;
    }
}
// 复制从p起的n项 相当于py中list=list[3:]
ttt List<T>::List(ListNodePosi(T) p, int n) { copyNodes(p, n); }
// 整体复制
ttt List<T>::List(List<T> const &L) { copyNodes(L.first(), L._size); }
// 局部复制
ttt List<T>::List(List<T> const &L, int r, int n) { copyNodes(L[r], n); }
// 删除
ttt T List<T>::remove(ListNodePosi(T) p)
{
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}
// 析构
ttt List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
}
// 清空列表
ttt int List<T>::clear()
{
    int olds = _size;
    while (0 < _size)
    {
        remove(header->succ);
    }
    return olds;
}
// 无序唯一化
ttt int List<T>::deduplicate()
{
    if (_size < 2)
        return 0;
    int olds = _size;
    ListNodePosi(T) p = header;
    Rank r = 0;
    while (trailer != (p = p->succ))
    {
        ListNodePosi(T) q = find(p->data, r, p);
        q ? remove(q) : r++;
    }
    return olds - _size;
}
// 遍历
ttt void List<T>::traverse(void (*visit)(T &))
{
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}
ttt template <typename VST>
void List<T>::traverse(VST &visit)
{
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}
ttt void List<T>::show(T &a)
{
    std::cout << a << " ";
}
// 有序唯一化
ttt Rank List<T>::uniquify()
{
    if (_size < 2)
        return 0;
    int olds = _size;
    ListNodePosi(T) p = first();
    ListNodePosi(T) q;
    while (trailer != (q = p->succ))
    {
        (p->data != q->data) ? p = q : remove(q);
    }
    return olds - _size;
}
// 查找
ttt ListNodePosi(T) List<T>::search(T const &e, Rank n, ListNodePosi(T) p) const
{
    while (0 <= n--)
    {
        if (((p = p->pred)->data) <= e)
            break;
    }
}
// 排序器
ttt void List<T>::sort(ListNodePosi(T) p, Rank n)
{
    switch (rand() % 3)
    {
    case 1:
        insertionSort(p, n);
        break;
    case 2:
        selectionSort(p, n);
        break;
    default:
        mergeSort(p, n);
        break;
    }
}
// 插入排序
ttt void List<T>::insertionSort(ListNodePosi(T) p, Rank n)
{
    for (int r = 0; r < n; r++)
    {
        insertA(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}
// 选择排序
ttt void List<T>::selectionSort(ListNodePosi(T) p, Rank n)
{
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for (int i = 0; i < n; i++)
        tail = tail->succ;
    while (n > 1)
    {
        ListNodePosi(T) max = selectMax(head->succ, n);
        insertB(tail, remove(max));
        tail = tail->pred;
        n--;
    }
}
ttt ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n)
{
    ListNodePosi(T) max = p;
    for (ListNodePosi(T) cur = p; 1 < n; n--)
    {
        if (!lt((cur = cur->succ)->data, max->data)) // lt()比较大小
            max = cur;
    }
    return max;
}
// 归并排序
ttt ListNodePosi(T) List<T>::merge(ListNodePosi(T) p,
                          Rank n,
                          List<T> &L,
                          ListNodePosi(T) q,
                          Rank m)
{
    ListNodePosi(T) pp = p->pred;
    while (m > 0)
        if ((n > 0) && (p->data <= q->data))
        {
            if (q == (p = p->succ))
                break;
            n--;
        }
        else
        {
            insertB(p, L.remove((q = q->succ)->pred));
            m--;
        }
    p = pp->succ;
}
ttt void List<T>::mergeSort(ListNodePosi(T) & p, Rank n)
{
    if (n < 2)
        return;
    int m = n >> 1;
    ListNodePosi(T) q = p;
    for (int i = 0; i < m; i++)
        q = q->succ;
    mergeSort(p, m);
    mergeSort(q, n - m);
    merge(p, m, *this , q, n - m);
}
