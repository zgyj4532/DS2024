#include "BinNode.hpp"
template(T)
class BinTree
{
    protected:
        int _size;BinNodePosi(T) _root;
        virtual int updateHeight(BinNodePosi(T) x);
        void updateHeightAbove(BinNodePosi(T) x);
    public:
        BinTree():_size(0),_root(NULL){}
        ~BinTree() {if(size>0) remove(_root);}

}; 