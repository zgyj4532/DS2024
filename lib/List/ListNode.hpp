#pragma once
using Rank = unsigned int;
#include <cstddef>
#define ListNodePosi(T) ListNode<T> *
template <typename T>
struct ListNode
{
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ; // 数值 前驱 后驱
    ListNode() {}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) : data(e), pred(p), succ(s) {}
    ListNodePosi(T) insertAsPred(T const &e);
    ListNodePosi(T) insertAsSucc(T const &e);
    bool operator==(const ListNode<T> &other) const { return this->data == other.data; }
    bool operator!=(const ListNode<T> &other) const { return this->data != other.data; }
};

