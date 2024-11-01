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
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,Stack<BinNodePosi(T)>& S)//从最左侧自顶而下访问节点（深度优先算法，不完全是（
{
    while (x)
    {
        visit(x->data);
        S.push(x->rc);
        x=x->lc;
    }
    
}
template <typename T,typename VST>//先序遍历2.0
inline void travPre_I2(BinNodePosi(T) x, VST &visit)
{   
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        visitAlongLeftBranch(x,visit,S);
        if(S.empty()) break;
        x=S.pop;
    }
    
}
template <typename T>//从当前节点出发，沿着左边不断深入，直至没有左分支的节点
static void goAlongLeftBranch(BinNodePosi(T) x,Stack<BinNodePosi(T)>& S)
{
    while (x)
    {
        S.push(x);
        x=x->lc;
    }
    
}
template <typename T,typename VST>//中序遍历2.0
inline void travPre_I1(BinNodePosi(T) x, VST &visit)
{   
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        goAlongLeftBranch(x,S);
        if(S.empty()) break;
        x=S.pop;visit(x->data);
        x=x->rc;
    }
    
}
template <typename T,typename VST>//中序遍历3.0
inline void travPre_I2(BinNodePosi(T) x, VST &visit)
{   
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        if(x){
            S.push(x);
            x = x->lc;
        }
        else if(!S.empty())
        {
            x= S.pop();
            visit(x->data);
            x = x->rc;
        }
        else break;
    }
    
}
template <typename T,typename VST>//中序遍历4.0
inline void travPre_I2(BinNodePosi(T) x, VST &visit)
{   
    bool backtrack = false;//回溯算法
    while (true)
    {
        if(!backtrack && HasLChild(*x)){//有左子树但是没回溯
            x = x->lc;
        }
        else
        {
            visit(x->data);
        }
        if(HasRChild(*x)){//若右子树非空，关闭回溯标志
            x = x->rc;
            backtrack = false;
        }
        else{//否则进行回溯
            if(!(x=x->succ())) break;
            backtrack = true;
        }
        
    }
    
}
template(T)//在S栈顶节点找到最高左侧可见叶子节点
static void gotoHLVFL(Stack<BinNodePosi(T)>& S)
{
    while(BinNodePosi(T) x = S.top())
        if(HasLChild(*x)){//尽可能向左 但是有右孩子优先入栈（
            if(HasRChild(*x)) S.push(x->rc);
            S.push(x->rc);
        } else S.push(x-rc);
    S.pop();    
}
template <typename T,typename VST>//中序遍历3.0
inline void travPost_I(BinNodePosi(T) x, VST &visit)
{   
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        if(x){
            S.push(x);
            x = x->lc;
        }
        else if(!S.empty())
        {
            x= S.pop();
            visit(x->data);
            x = x->rc;
        }
        else break;
    }
    
}



