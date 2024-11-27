
#include "graph.cpp"
int main(){
    GraphMatrix<char,int> g;
    // 插入顶点
    g.insert('A');
    g.insert('B');
    g.insert('C');
    g.insert('D');
    g.insert('E');
    g.insert('F');

    // 插入边：顶点与顶点之间的关系
    g.insert(1, 1, 0, 1); // A -> B
    g.insert(1, 1, 1, 2); // B -> C
    g.insert(1, 1, 1, 3); // B -> D
    g.insert(1, 1, 2, 4); // C -> E
    g.insert(1, 1, 3, 4); // D -> E
    g.insert(1, 1, 4, 5); // E -> F
    /*
    图g信息为
     A -> B -> C 
          ↓    ↓    
          D -> E -> F      

    */
    cout << "graph g:" << endl;
    cout << "     A -> B -> C" << endl;
    cout << "          ↓    ↓" << endl;
    cout << "          D -> E -> F" << endl;
    // 测试深度优先搜索（DFS）
    std::cout << "DFS Traversal starting from vertex 'A':" << std::endl;
    g.dfs(0); // 从顶点 'A' 开始深度优先搜索（0 表示顶点 A）

    // 测试广度优先搜索（BFS）
    std::cout << "\nBFS Traversal starting from vertex 'A':" << std::endl;
    g.bfs(0); // 从顶点 'A' 开始广度优先搜索（0 表示顶点 A）

    // 测试广度优先搜索（BFS）
    std::cout << "\ntSort Traversal starting from vertex 'A':" << std::endl;
    g.tSort(0); // 从顶点 'A' 开始广度优先搜索（0 表示顶点 A）
    return 0;
}