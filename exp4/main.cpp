#include "graph.cpp"
int main()
{
    GraphMatrix<char, int> g;
    // 插入顶点
    g.insert('A');//0
    g.insert('B');//1
    g.insert('C');//2
    g.insert('D');//3
    g.insert('E');//4
    g.insert('F');//5
    g.insert('G');//6

    // 插入边：顶点与顶点之间的关系
    g.insert(1, 5, 0, 1); // A -> B 权重 5
    g.insert(1, 8, 1, 2); // B -> C 权重 8
    g.insert(1, 3, 1, 3); // B -> D 权重 3
    g.insert(1, 2, 2, 4); // C -> E 权重 2
    g.insert(1, 7, 3, 4); // D -> E 权重 7
    g.insert(1, 4, 4, 5); // E -> F 权重 4
    g.insert(1, 9, 0, 6); // A -> G 权重 9
    g.insert(1, 1, 6, 3); // G -> D 权重 1
    /*
    图g信息为
     A 5-> B 8-> C
     9     3     2
     ↓     ↓     ↓
     G 1-> D 7-> E 4-> F

    */
    cout << "graph g:" << endl;
    cout << "     A 5-> B 8-> C" << endl;
    cout << "     9     3     2" << endl;    
    cout << "     ↓     ↓     ↓" << endl;
    cout << "     G 1-> D 7-> E 4-> F" << endl;
    // 测试深度优先搜索（DFS）
    std::cout << "DFS Traversal starting from vertex 'A':" << std::endl;
    g.dfs(0); // 从顶点 'A' 开始深度优先搜索（0 表示顶点 A）

    // 测试广度优先搜索（BFS）
    std::cout << "\nBFS Traversal starting from vertex 'A':" << std::endl;
    g.bfs(0);

    // 测试最短路径算法（Dijkstra）
    DijkstraPU<char, int> dijkstraPU;
    std::cout << "\nDijkstra Traversal starting from vertex 'A':" << std::endl;
    g.pfs(0, dijkstraPU);  
    g.output_distance(0);

    // 测试最小支撑树算法（Prim）
    std::cout << "\nPrim Traversal starting from vertex 'A':" << std::endl;
    PrimPU<char, int> PrimPU;
    g.pfs(0, PrimPU);
    g.printMST();
    return 0;
}