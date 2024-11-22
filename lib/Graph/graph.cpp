#include "graph.hpp"
#include "Vector.cpp"

template<typename Tv> struct Vertex
{
    //顶点对象
    Tv data ;int inDegree,outDegree;VStatus status;
    int dTime;int fTime;
    int parent;int priority;
    Vertex(Tv const& d = (Tv)0)://（Tv）0强制类型转换
        data(d),inDegree(0),outDegree(0),status(UNDSICOVERED),
        dTime(-1),fTime(-1),parent(-1),priority(INT_MAX){}//暂时不考虑权重溢出
};
template<typename Te> struct Edge{
    Te data ;int weight;EType type;
    Edge(Te const& d,int w) :data(d),weight(w),type(UNDETERMINED){}
};
template<typename Tv,typename Te>
class GraphMatrix: public Graph<Tv,Te>
{
    private:
        Vector<Vertex<Tv>> V;//顶点集
        Vector<Vector<Edge<Te>*>> E;//边集
    public:
        GraphMatrix() {n=e=0;}//构造
        ~GraphMatrix() {//析构
            for(int j=0;j<n;j++)
                for(int i = 0;i<n;i++)
                    delete E[j][i];//逐条清除
        }    
};