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
//清空列表
ttt int List<T>::clear()
{
    int olds = _size;
    while (0 < _size)
    {
        remove(header->succ);
    }
    return olds;
}
//唯一化
ttt int List<T>::deduplicate()
{
    if(_size <2) return 0;
    int olds = _size;
    ListNodePosi(T) p=header;
    Rank r = 0;
    while (trailer != (p=p->succ))
    {
        ListNodePosi(T) q = find(p->data,r,p);
        q?remove(q):r++;
    }
    return olds - _size;
}
