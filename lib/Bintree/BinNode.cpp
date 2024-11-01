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
template(T)
BinNodePosi(T) BinNode<T>::succ()
{
    BinNodePosi(T) s = this;
    if(rc) {
        s = rc;
        while (HasLChild(*s))//一直往左下
        {
            s = s->lc;
        }

    }        
    else
    {
        while (IsRChild(*s))//一直往左上找父节点
        {
            s = s->parent;
        }
        s = s->parent;//最后再朝右，抵达直接后继
                
    }
    return s;    
}
