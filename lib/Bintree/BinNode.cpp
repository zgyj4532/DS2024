#include "BinNode.hpp"
template(T)
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
    return lc = new BinNode (e,this);
}
template(T)
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
    return rc = new BinNode (e,this);
}
