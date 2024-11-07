#include "BinNode.hpp"
#include "Queue.hpp"

template(T)
    BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
    return lc = new BinNode(e, this);
}
template(T)
    BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
    return rc = new BinNode(e, this);
}
template(T)
    BinNodePosi(T) BinNode<T>::succ()
{
    BinNodePosi(T) s = this;
    if (rc)
    {
        s = rc;
        while (HasLChild(*s)) // 一直往左下
        {
            s = s->lc;
        }
    }
    else
    {
        while (IsRChild(*s)) // 一直往左上找父节点
        {
            s = s->parent;
        }
        s = s->parent; // 最后再朝右，抵达直接后继
    }
    return s;
}

template(T) template(VST) void BinNode<T>::travLevel(VST &visit)
{
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this); // 根节点入队
    while (!Q.empty())
    {
        BinNodePosi(T) x = Q.dequeue();
        visit(x->data); // 出队元素访问
        if (HasLChild(*x))
            Q.enqueue(x->lc);
        if (HasRChild(*x))
            Q.enqueue(x->rc);
    }
}
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST &visit) // 先序遍历
{
    if (!x)
        return;
    travPre_R(x->lc, visit);
    visit(x->data);
    travPre_R(x->rc, visit);
}
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST &visit) // 后序遍历
{
    if (!x)
        return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST &visit) // 中序遍历
{
    if (!x)
        return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}
// template <typename T, typename VST>
// static void visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S) // 从最左侧自顶而下访问节点（深度优先算法，不完全是（
// {
//     while (x)
//     {
//         visit(x->data);
//         S.push(x->rc);
//         x = x->lc;
//     }
// }
// template <typename T, typename VST> // 先序遍历2.0
// void travPre_I2(BinNodePosi(T) x, VST &visit)
// {
//     Stack<BinNodePosi(T)> S;
//     while (true)
//     {
//         visitAlongLeftBranch(x, visit, S);
//         if (S.empty())
//             break;
//         x = S.pop;
//     }
// }
// template <typename T> // 从当前节点出发，沿着左边不断深入，直至没有左分支的节点
// static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S)
// {
//     while (x)
//     {
//         S.push(x);
//         x = x->lc;
//     }
// }
// template <typename T, typename VST> // 中序遍历2.0
// void travPre_I1(BinNodePosi(T) x, VST &visit)
// {
//     Stack<BinNodePosi(T)> S;
//     while (true)
//     {
//         goAlongLeftBranch(x, S);
//         if (S.empty())
//             break;
//         x = S.pop;
//         visit(x->data);
//         x = x->rc;
//     }
// }
// template <typename T, typename VST> // 中序遍历3.0
// void travPre_I2(BinNodePosi(T) x, VST &visit)
// {
//     Stack<BinNodePosi(T)> S;
//     while (true)
//     {
//         if (x)
//         {
//             S.push(x);
//             x = x->lc;
//         }
//         else if (!S.empty())
//         {
//             x = S.pop();
//             visit(x->data);
//             x = x->rc;
//         }
//         else
//             break;
//     }
// }
// template <typename T, typename VST> // 中序遍历4.0
// void travPre_I2(BinNodePosi(T) x, VST &visit)
// {
//     bool backtrack = false; // 回溯算法
//     while (true)
//     {
//         if (!backtrack && HasLChild(*x))
//         { // 有左子树但是没回溯
//             x = x->lc;
//         }
//         else
//         {
//             visit(x->data);
//         }
//         if (HasRChild(*x))
//         { // 若右子树非空，关闭回溯标志
//             x = x->rc;
//             backtrack = false;
//         }
//         else
//         { // 否则进行回溯
//             if (!(x = x->succ()))
//                 break;
//             backtrack = true;
//         }
//     }
// }
// template(T) // 在S栈顶节点找到最高左侧可见叶子节点
//     static void gotoHLVFL(Stack<BinNodePosi(T)> &S)
// {
//     while (BinNodePosi(T) x = S.top())
//         if (HasLChild(*x))
//         { // 尽可能向左 但是有右孩子优先入栈（
//             if (HasRChild(*x))
//                 S.push(x->rc);
//             S.push(x->rc);
//         }
//         else
//             S.push(x -> rc);
//     S.pop();
// }
// template <typename T, typename VST> // 后序遍历1.0
// void travPost_I(BinNodePosi(T) x, VST &visit)
// {
//     Stack<BinNodePosi(T)> S;
//     if (x)
//         S.push(x); // 根节点入栈
//     while (!S.empty())
//     {
//         if (S.top() = x->parent)
//         {                 // 若栈顶非当前节点之父（则必为后兄）
//             gotoHLVFL(S); // （递归深入其中）
//         }
//         x = S.pop();
//         visit(x->data);
//     }
// }
