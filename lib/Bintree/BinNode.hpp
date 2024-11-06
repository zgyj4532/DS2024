#include <cstddef>
#include "Stack.hpp"
#define template(x) template <typename x>
#define BinNodePosi(T) BinNode<T> *         // 节点位置
#define stature(p) ((p) ? (p)->height : -1) // 节点高度
/**********************************************************************/
// 书上的代码爆了，直接扔结构体里当函数写了（
//  /*
//  BinNode状态与性质的判断
//  */
//  #define IsRoot(x) (!((x).parent))
//  #define IsLChild(x) ((!IsRoot(x)) && ((&(x) == (x).parent->lc)))
//  #define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
//  #define HasParent(x) (!IsRoot(x))
//  #define HasLChild(x) ((x).lc)
//  #define HasRChild(x) ((x).rc)
//  #define HasChild(x) (HasLChild(x) || HasRChild(x))
//  #define HasBothChild(x) (HasLChild(x) && HasRChild(x))
//  #define IsLeaf(x) (!HasChild(x))
//  /*
//  与BinNode具有特定关系的节点和指针
//  */
//  #define sibling(p) \ //兄弟节点
//      ((IsLChild(*(p))) ? (p)->parent->rc : (p)->parent->lc)
//  #define uncle(p) \ //叔叔节点
//          ((IsLChild(*((p)->parent))) ? (p)->parent->parent->rc : (p)->parent->parent->lc)
//  #define FromParentTo(p) \ //来自父亲引用节点
//              (IsRoot(p) ? _root : (IsLChild(p) ? (p).parent->lc : (p).parent->rc))
/**********************************************************************/
typedef enum
{
    RB_RED,
    RB_BLACK
} RBColor; // 节点颜色
template(T) struct BinNode
{
    T data; // 数据
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;
    int npl; // Null Path Length
    RBColor color;
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    int size();
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();               // 取后继
    void travLevel(VST &);               // 子树层次遍历
    template(VST) void travLevel(VST &); // 子树层次遍历
    template(VST) void travPre(VST &);   // 子树先序遍历
    template(VST) void travIN(VST &);    // 子树中序遍历
    template(VST) void travPost(VST &);  // 子树后续遍历
    bool operator<(BinNode const &bn) { return data < bn.data; }
    bool operator==(BinNode const &bn) { return data == bn.data; }
    bool operator>(BinNode const &bn) { return data > bn.data; }
    bool operator!=(BinNode const &bn) { return data != bn.data; }
    /*
    BinNode状态与性质的判断
    */
    bool IsRoot(T const &x) { return !(x.parent); }
    bool IsLChild(T const &x) { return (!IsRoot(x)) && ((&(x) == (x).parent->lc)); }
    bool IsRChild(T const &x) { return (!IsRoot(x)) && ((&(x) == (x).parent->rc)); }
    bool HasParent(T const &x) { return !IsRoot(x); }
    // BinNodePosi(T) HasLChild(T const &x) { return x.lc; }
    // BinNodePosi(T) HasRChild(T const &x) { return x.rc; }
    // bool HasChild(T const &x) { return HasLChild(x) || HasRChild(x); }
    // bool HasBothChild(T const &x) { return HasLChild(x) && HasRChild(x); }
    // bool IsLeaf(T const &x) { return !HasChild(x); }
     #define HasLChild(x) ((x).lc)
    #define HasRChild(x) ((x).rc)
    #define HasChild(x) (HasLChild(x) || HasRChild(x))
    #define HasBothChild(x) (HasLChild(x) && HasRChild(x))
    #define IsLeaf(x) (!HasChild(x))
    /*
    与BinNode具有特定关系的节点和指针
    */
    BinNodePosi(T) sibling(BinNode const &p) // 兄弟节点
    {
        return (IsLChild(*p)) ? p->parent->rc : p->parent->lc;
    }
    BinNodePosi(T) uncle(BinNode const &p) // 叔叔节点
    {
        return (IsLChild(*(p->parent))) ? p->parent->parent->rc : p->parent->parent->lc;
    }
    BinNodePosi(T) FromParentTo(BinNode const &p);
#define FromParentTo(p) (IsRoot(p) ? _root : (IsLChild(p) ? (p).parent->lc : (p).parent->rc)) // 来自父亲引用节点
};
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST &);
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST &visit);
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST &visit);
template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S);
template <typename T, typename VST> // 先序遍历2.0
void travPre_I2(BinNodePosi(T) x, VST &visit);
template <typename T> // 从当前节点出发，沿着左边不断深入，直至没有左分支的节点
static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S);
template <typename T, typename VST> // 中序遍历2.0
void travPre_I1(BinNodePosi(T) x, VST &visit);
template <typename T, typename VST> // 中序遍历3.0
void travPre_I2(BinNodePosi(T) x, VST &visit);
template <typename T, typename VST> // 中序遍历4.0
void travPre_I2(BinNodePosi(T) x, VST &visit);
template(T) // 在S栈顶节点找到最高左侧可见叶子节点
static void gotoHLVFL(Stack<BinNodePosi(T)> &S);
template <typename T, typename VST> // 后序遍历1.0
void travPost_I(BinNodePosi(T) x, VST &visit);
