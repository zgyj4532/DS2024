
#include "graph.cpp"
int main()
{
    GraphMatrix<char, int> g;
    // 插入顶点
    g.insert('A');
    g.insert('B');
    g.insert('C');
    g.insert('D');
    g.insert('E');
    g.insert('F');
    g.insert('G');

    // 插入边：顶点与顶点之间的关系
    g.insert(1, 5, 0, 1); // A -> B 权重 5
    g.insert(1, 8, 1, 2); // B -> C 权重 8
    g.insert(1, 3, 1, 3); // B -> D 权重 3
    g.insert(1, 2, 2, 4); // C -> E 权重 2
    g.insert(1, 7, 3, 4); // D -> E 权重 7
    g.insert(1, 4, 4, 5); // E -> F 权重 4
    g.insert(1, 9, 0, 6); // A -> G 权重 9
    /*
    图g信息为
     A -> B -> C
     ↓     ↓    ↓
     G     D -> E -> F

    */
    cout << "graph g:" << endl;
    cout << "     A -> B -> C" << endl;
    cout << "     ↓    ↓    ↓" << endl;
    cout << "     G    D -> E -> F" << endl;
    // 测试深度优先搜索（DFS）
    std::cout << "DFS Traversal starting from vertex 'A':" << std::endl;
    g.dfs(0); // 从顶点 'A' 开始深度优先搜索（0 表示顶点 A）

    // 测试广度优先搜索（BFS）
    std::cout << "\nBFS Traversal starting from vertex 'A':" << std::endl;
    g.bfs(0); // 从顶点 'A' 开始广度优先搜索（0 表示顶点 A）

    // 测试拓扑排序搜索（tSort）
    std::cout << "\ntSort Traversal starting from vertex 'A':" << std::endl;
    g.tSort(0); // 从顶点 'A' 开始拓扑排序搜索（0 表示顶点 A）

    DijkstraPU<char, int> dijkstraPU;

    return 0;
}