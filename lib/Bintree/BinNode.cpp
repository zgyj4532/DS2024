#include "BinNode.hpp"
#include "Queue.hpp"
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

template(T) template(VST)
void BinNode<T>::travLevel(VST &visit)
{
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this);//根节点入队
    while (!Q.empty())
    {
        BinNodePosi(T) x = Q.dequeue();visit(x->data);//出队元素访问
        if(HasLChild(*x)) Q.enqueue(x->lc);
        if(HasRChild(*x)) Q.enqueue(x->rc);
    }
    
}
