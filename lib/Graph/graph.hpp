#include "Stack.hpp"
#include <climits> //INT_MAX所在库
typedef enum{UNDSICOVERED,DISCOVERED,VISITER} VStatus;//节点状态 未发现 已发现 和 已遍历
typedef enum{UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD} EType;//边在遍历树中所属类型

template<typename Tv,typename Te>//顶点和边类型
class Graph{
    private:
        void reset(){//复位
            for(int i = 0;i<n;i++){
                status(i) = UNDSICOVERED;dTime(i) = fTime(i) = -1;//状态 时间复位
                parent(i) =-1;priority(i) = INT_MAX;//父节点 优先级数
                for(int j = 0; j<Vertex_sum; j++) {if(exists(i,j)) type(i,j) = UNDETERMINED;}
            }
        }
        void BFS(int ,int&);//广度优先
        void DFS(int,int&);//深度优先
        void BCC(int ,int& .Stack<int>&)//基于DFS的双连通分量分解
        void TSort(int, int&,Stack<Tv>*)//基于DFS的拓补排序算法
        template<typename PU> void PFS(int ,PU)//优先级搜索框架
    public:
    //顶点

        
        //virtual T A() = 0 为纯虚函数
        virtual int insert(Tv const&) = 0;//插入顶点，返回编号
        virtual Tv remove(int) = 0;//删除顶点及其相关边，返回顶点信息
        virtual Tv& vertex(int) = 0;//顶点v数据
        virtual int inDegree(int) = 0;//顶点入度
        virtual int outDegree(int) = 0;//顶点出度
        virtual int firstNbr(int) = 0;//顶点首个邻接顶点
        virtual int nextNbr(int,int) = 0;//顶点下一个临接顶点
        virtual VStatus& status(int) = 0;//顶点的状态
        virtual int& dTime(int) = 0;//顶点的d时间标签
        virtual int& fTime(int) = 0;//顶点的f时间标签
        virtual int& parent(int) = 0;//父节点
        virtual int& priority(int) =0;//优先级数
        int Vertex_sum;//顶点总数
    //边
        int Edge_sum;//边总数
        virtual bool exist(int,int) = 0 ;//边是否存在
        virtual void insert(Te const& ,int ,int ,int) =0;//插入
        virtual Te remove(int,int) =0;//删除
        virtual EType& type(int,int) =0;//类型检测
        virtual Te& edge(int ,int)=0;//数据
        virtual int& weight(int,int) = 0;//边权重
    //算法
        void bfs(int);//广度优先
        void dfs(int);//深度优先
        void bcc(int);//基于dfs的双连通分量
        Stack<Tv>* tSort(int);//基于dfs的拓扑排序
        void prim(int);//最小支撑树
        void dijkstra(int);//最短路径
        template<typename PU> void pfs(int ,PU);//优先搜素框架    

};
