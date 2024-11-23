#include "graph.hpp"
#include "Vector.cpp"

template <typename Tv>
struct Vertex
{
    // 顶点对象
    Tv data;//数据
    int inDegree, outDegree;//入度和出度
    VStatus status;//节点状态
    int dTime;//d时间
    int fTime;//f时间
    int parent;//父节点
    int priority;//优先级
    Vertex(Tv const &d = (Tv)0) : // （Tv）0强制类型转换
                                  data(d), inDegree(0), outDegree(0), status(UNDSICOVERED),
                                  dTime(-1), fTime(-1), parent(-1), priority(INT_MAX)// 暂时不考虑权重溢出
    {
    } 
};
template <typename Te>
struct Edge
{
    Te data;
    int weight;
    EType type;
    Edge(Te const &d, int w) : data(d), weight(w), type(UNDETERMINED) {}
};
template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>
{
private:
    Vector<Vertex<Tv>> V;         // 顶点集
    Vector<Vector<Edge<Te> *>> E; // 边集
public:
    GraphMatrix() { Vertex_sum = e = 0; } // 构造
    ~GraphMatrix()
    { // 析构
        for (int j = 0; j < Vertex_sum; j++)
            for (int i = 0; i < Vertex_sum; i++)
                delete E[j][i]; // 逐条清除
    }
    // 顶点的基本操作
    virtual Tv &vertex(int i) { return V[i].data; }
    virtual int inDegree(int i) { return V[i].inDegree;}
    virtual int outDegree(int i) {return V[i].outDegree;}
    virtual int firstNbr(int i) {return nextNbr(i,Vertex_sum);} 
    virtual int nextNbr(int i, int j) {while((-1<j)&&(!exist(i,--j)));return j;}
    virtual VStatus &status(int i){return V[i].status;} 
    virtual int &dTime(int i) {return V[i].dtime;}       // 顶点的d时间标签
    virtual int &fTime(int i) {return V[i].fTime;}       // 顶点的f时间标签
    virtual int &parent(int i) {return V[i].parent;}      // 父节点
    virtual int &priority(int i) {return V[i].priority;}   // 优先级数
    //顶点动态操作
    virtual int insert(Tv const& vertex){
        for(int j = 0;j<Vertex_sum;j++)
        {
            E[j].insert(NULL);Vertex_sum++;
        }
        E.insert(Vector<Edge<Te> *>(Vertex_sum,Vertex_sum,(Edge<Te> *)NULL));//创建一个新顶点对应边向量
        return V.insert(Vertex<Tv> (vertex));
    }
    virtual Tv remove(int i){
        for(int j=0;j<Vertex_sum;j++) if(exists(i,j)){delete E[i][j];V[j].inDegree--;}//逐条删除
        E.remove(i);Vertex_sum--;
        Tv vBak = vertex(i);V.remove(i);
        for(int j=0;j<Vertex_sum;j++)
            if(Edge<Te> *Edge_sum = E[j].remove(i)) {delete e;V[j].outDegree--;}
        return vBak;    
    }
};

