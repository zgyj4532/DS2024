#include "BinTree.hpp"
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
