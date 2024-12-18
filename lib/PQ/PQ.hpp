template <typename T> struct PQ
{
    virtual void insert(T) = 0;
    virtual T getMax()=0;
    virtual T delMax()=0;
};
#define InHeap(n,i) (((-1)<(i))&&((i)<(n)))//判断PQ是否合法
#define Parent(i) ((i-1)>>1)//PQ父节点
#define LastInternal(n) Parent(n-1)//PQ末节点父亲
#define LChild(i) (1+((i)<<1))//PQ[i]左孩子
#define RChild(i) ((1+(i))<<1)//PQ[i]右孩子
#define ParentValid(i) (i>0)//判断PQ是否有父亲
#define LChildValid(n,i) InHeap(n,LChild(i))
#define RChildValid(n,i) InHeap(n,RChild(i))
#define Bigger(PQ,i,j) ((PQ[i])<(PQ[j])?j:i)//取最大值
/*父子三者中的最大者，什么逆天三目运算符嵌套*/
#define ProperParent(PQ,n,i)\
    (RChildValid(n,i)?Bigger(PQ,Bigger(PQ,i,LChild(i)),RChild(i)):\
    (LChildValid(n,i)?Bigger(PQ,i,LChild(i)) : i\
    )\
    )
