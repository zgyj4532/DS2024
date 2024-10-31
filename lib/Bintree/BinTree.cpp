#include "BinTree.hpp"
#include <ranges>
template(T)
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1+max(stature(x->lc),stature(x->rc));
}
template(T)
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
    
}
template(T)
BinNodePosi(T) BinTree<T>::insertAsRoot(T const &e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}
template(T)
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x,T const &e)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}
template(T)
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}
template(T)
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T> *&S)
{
    if(x->rc = S->_root)x->lc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S=NULL;
    return x;
}
