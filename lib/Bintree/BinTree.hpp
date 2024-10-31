#include "BinNode.hpp"
#include "Stack.hpp"
template(T) class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);

public:
    BinTree() : _size(0), _root(NULL) {}
    ~BinTree()
    {
        if (size > 0)
            remove(_root);
    }
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return root; }
    BinNodePosi(T) insertAsRoot(T const &e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&S);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&S);
    int remove(BinNodePosi(T) x);
    static int removeAt(BinNodePosi(T) x);
    BinTree<T> *secede(BinNodePosi(T) x);
    
    template(VST) void travLevel(VST &visit)
    {
        if (_root)
            _root->travLevel(visit);
    } // 层次遍历
    template(VST) void travPre(VST &visit)
    {
        if (_root)
            _root->travPre(visit);
    } // 先序遍历
    template(VST) void travIn(VST &visit)
    {
        if (_root)
            _root->travIn(visit);
    } // 中序遍历
    template(VST) void travPost(VST &visit)
    {
        if (_root)
            _root->travPost(visit);
    } // 后序遍历
    template(VST) bool operator<(BinTree<VST> const &t)
    {
        return _root && t._root && lt(_root, t.root());
    }
    template(VST) bool operator==(BinTree<VST> const &t)
    {
        return _root && t._root && (_root == t.root());
    }
    template(VST) bool operator>=(BinTree<VST> const &t)
    {
        return _root && t._root && !lt(_root, t.root());
    }
};
template <typename T,typename VST>
inline void travPre_R(BinNodePosi(T) x, VST &visit)//先序遍历
{
    if(!x) return;
    travIN_R(x->lc,visit);
    visit(x->data);
    travIN_R(x->rc,visit);
} 
template <typename T,typename VST>
inline void travPost_R(BinNodePosi(T) x, VST &visit)//后序遍历
{
    if(!x) return;
    travPost_R(x->lc,visit);
    travPost_R(x->rc,visit);
    visit(x->data);
    
} 
template <typename T,typename VST>
inline void travIn_R(BinNodePosi(T) x, VST &visit)//中序遍历
{
    if(!x) return;
    travIn_R(x->lc,visit);
    visit(x->data);
    travIn_R(x->rc,visit);
    
} 
template <typename T,typename VST>
inline static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,Stack<BinNodePosi(T)>& S)
{
    while (x)
    {
        visit(x->data);
        S.push(x->rc);
        x=x->lc;
    }
    
}
