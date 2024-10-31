#include "BinNode.hpp"
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
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const &e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const &e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&S);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&S);
    int remove(BinNodePosi(T) x);
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
    bool operator<(BinTree<T> const &t)
    {
        return _root && t._root && lt(_root, t.root);
    }
    bool operator==(BinTree<T> const &t)
    {
        return _root && t._root && (_root == t.root);
    }
    bool operator>=(BinTree<T> const &t)
    {
        return _root && t._root && !lt(_root, t.root);
    }
};