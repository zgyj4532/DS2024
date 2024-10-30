#define template(T) template<typename T>
#define BinNodePosi(T) BinNode<T>* //节点位置
#define stature(p) ((p)?(p)->height : -1) //节点高度
typedef enum{RB_RED,RB_BLACK} RBColor ;//节点颜色
template(T) struct BinNode
{
    T data;//数据
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;
    int npl;//Null Path Length
    RBColor color;
    BinNode():
        parent(NULL),lc(NULL),rc(NULL),height(0),npl(1),color(RB_RED){}
    BinNode(T e,BinNodePosi(T) p = NULL,BinNodePosi(T) lc = NULL,BinNodePosi(T) rc = NULL,int h = 0,int l = 1,RBColor c = RB_RED):
    {
        data(e),parent(p),lc(lc),rc(rc),height(h),npl(l),color(c){}
    }    
    int size();
    BinNodePosi(T) insertAsLC(T const&);
    BinNodePosi(T) insertAsRC(T const&);
    BinNodePosi(T) succ();//取后继
    template(VST) void travLevel(VST&);//子树层次遍历
    template(VST) void travPre(VST&);//子树先序遍历
    template(VST) void travIN(VST&);//子树中序遍历
    template(VST) void travPost(VST&);//子树后续遍历
    bool operator< (BinNode const& bn){return data<bn.data;}
    bool operator== (BinNode const& bn){return data==bn.data;}
    bool operator> (BinNode const& bn){return data>bn.data;}
    bool operator!= (BinNode const& bn){return data!=bn.data;}
};
