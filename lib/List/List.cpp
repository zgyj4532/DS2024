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
//插入接口
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
ttt ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p,T const &e)
{
    _size++;
    return p->insertAsSucc(e);
}
ttt ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p,T const &e)
{
    _size++;
    return p->insertAsPred(e);
}
ttt
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e)
{
    ListNodePosi(T) x = new ListNode(e,pred,this);
    pred ->succ = x;pred = x;
    return x;
}
ttt
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
    ListNodePosi(T) x = new ListNode(e,this,succ);
    succ ->pred = x;succ = x;
    return x;
}