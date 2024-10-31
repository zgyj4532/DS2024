#include <cstddef>
#define template(T) template <typename T>
#define BinNodePosi(T) BinNode<T> *         // 节点位置
#define stature(p) ((p) ? (p)->height : -1) // 节点高度
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
    template(VST) void travLevel(VST &); // 子树层次遍历
    template(VST) void travPre(VST &);   // 子树先序遍历
    template(VST) void travIN(VST &);    // 子树中序遍历
    template(VST) void travPost(VST &);  // 子树后续遍历
    bool operator<(BinNode const &bn) { return data < bn.data; }
    bool operator==(BinNode const &bn) { return data == bn.data; }
    bool operator>(BinNode const &bn) { return data > bn.data; }
    bool operator!=(BinNode const &bn) { return data != bn.data; }

};
/*
BinNode状态与性质的判断
*/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) ((!IsRoot(x)) && ((&(x) == (x).parent->lc)))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
/*
与BinNode具有特定关系的节点和指针
*/
#define sibling(p) \ //兄弟节点
    (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)
#define uncle(p) \ //叔叔节点
        (IsLChild(*((p)->parent)) ? (p)->parent->parent->rc : (p)->parent->parent->lc)
#define FromParentTo(p) \ //来自父亲引用节点
            (IsRoot(p) ? _root : (IsLChild(p) ? (p).parent->lc : (p).parent->rc))
