// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// template<class T>
// class UnionFindSet
// {
// public:
//     UnionFindSet(const T*a,size_t n)
//     {
//         for(size_t i=0;i<n;i++)
//         {
//             _a.push_back(a[i]);
//             _indexMap[a[i]]=i;
//         }
//     }
// private:
//     vector<T> _a;
//     map<T,int> _indexMap;
// }
// int main()
//{
// string a[]={"张三","李四","王五","赵六"};
// UnionFindSet<string> ufs(4);
// return 0;
//}

// 并查集(森林)--双亲表示法--初始值都为-1，然后父亲的值是所有孩子的值的叠加

// class UnionFindSet
// {
// public:
//     UnionFindSet(size_t n)
//     :_ufs(n,-1)
//     {}
//     void Union(int x1,int x2)
//     {
//         int root1 = FindRoot(x1);
//         int root2 = FindRoot(x2);
//         //如果本身就在一个集合就没必要合并
//         if(root1==root2) return;

//         _ufs[root1] +=_ufs[root2];
//         _ufs[root2] = root1;
//     }
//     int FindRoot(int x)
//     {
//         int parent = x;
//         while(_ufs[parent]>=0)
//         {
//             parent = _ufs[parent];
//         }
//         return parent;
//     }
//     bool InSet(int x1,int x2)
//     {
//         return FindRoot(x1) == FindRoot(x2);
//     }
//     size_t SetSize()
//     {
//         size_t size = 0;
//         for(size_t i = 0;i<_ufs.size();i++)
//         {
//             if(_ufs[i]<0) size++;
//         }
//         return size;
//     }

// private:
//     vector<int> _ufs;
// };

// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;
// namespace matrix
// {
//     template <class V, class W, W MAX_W = INT_MAX, bool Direction = false>
//     class Graph
//     {
//     public:
//         Graph(const V *a, size_t n)
//         {
//             _vertexs.reserve(n);
//             for (size_t i = 0; i < n; i++)
//             {
//                 _vertexs.push_back(a[i]);
//                 _indexMap[a[i]] = i;
//             }
//             _matrix.resize(n);
//             for (size_t i = 0; i < n; i++)
//             {
//                 _matrix[i].resize(n, MAX_W);
//             }
//         }
//         size_t GetVertexIndex(const V &v)
//         {
//             auto it = _indexMap.find(v);
//             if (it != _indexMap.end())
//                 return it->second;
//             throw invalid_argument("vertex error");
//             return -1;
//         }
//         void AddEdge(const V &src, const V &dst, const W &w)
//         {
//             size_t srci = GetVertexIndex(src);
//             size_t dsti = GetVertexIndex(dst);
//             _matrix[srci][dsti] = w;
//             if (Direction == false)
//                 _matrix[dsti][srci] = w;
//         }
//         void Print()
//         {
//             for (size_t i = 0; i < _vertexs.size(); i++)
//             {
//                 cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
//             }
//             for (size_t i = 0; i < _matrix.size(); i++)
//             {
//                 for (size_t j = 0; j < _matrix[i].size(); j++)
//                 {
//                     if (_matrix[i][j] == MAX_W)
//                     {
//                         cout << "∞ ";
//                     }
//                     else cout << _matrix[i][j]<<" ";
//                 }
//                 cout << endl;
//             }
//         }

//     private:
//         vector<V> _vertexs;        // 顶点集合
//         map<V, int> _indexMap;     // 顶点映射下标
//         vector<vector<W>> _matrix; // 邻接矩阵
//     };
//     void TestGraph1()
//     {
//         Graph<char, int, INT_MAX, true> g("0123", 4);
//         g.AddEdge('0', '1', 1);
//         g.AddEdge('0', '3', 4);
//         g.AddEdge('1', '3', 2);
//         g.AddEdge('1', '2', 9);
//         g.AddEdge('2', '3', 8);
//         g.AddEdge('2', '1', 5);
//         g.AddEdge('2', '0', 3);
//         g.AddEdge('3', '2', 6);
//         g.Print();
//     }
// }

// int main()
// {
//     matrix::TestGraph1();
//     return 0;
// }

// 7-1 有向图的创建、求度、遍历
// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
// #include <limits.h>
// using namespace std;
// template <class V, class W, W MAX_W = INT_MAX, bool Direction = true>
// class Graph
// {
// public:
//     Graph(const V *a, size_t n, size_t m)
//         : _arcnum(m), od(n, 0), id(n, 0)
//     {
//         _vertexs.reserve(n);
//         for (size_t i = 0; i < n; i++)
//         {
//             _vertexs.push_back(a[i]);
//             _indexMap[a[i]] = i;
//         }
//         _matrix.resize(n);
//         for (size_t i = 0; i < n; i++)
//         {
//             _matrix[i].resize(n, MAX_W);
//         }
//     }
//     size_t GetVertexIndex(const V &v)
//     {
//         auto it = _indexMap.find(v);
//         if (it != _indexMap.end())
//             return it->second;
//         throw invalid_argument("vertex error");
//         return -1;
//     }
//     void CreatGraph()
//     {
//         for (size_t i = 0; i < _arcnum; i++)
//         {
//             getchar();
//             char src, dst;
//             scanf("%c%c", &src, &dst);
//             AddEdge(src, dst);
//         }
//     }
//     void AddEdge(const V &src, const V &dst)
//     {
//         size_t srci = GetVertexIndex(src);
//         size_t dsti = GetVertexIndex(dst);
//         _matrix[srci][dsti] = 1;
//     }
//     void Degree()
//     {
//         for (int i = 0; i < _matrix.size(); i++)
//         {
//             for (int j = 0; j < _matrix[i].size(); j++)
//             {
//                 if (_matrix[i][j] != MAX_W)
//                 {
//                     od[i]++;
//                     id[j]++;
//                 }
//             }
//         }
//         for (int i = 0; i < _vertexs.size(); i++)
//         {
//             cout << _vertexs[i] << " " << od[i] << " " << id[i] << " " << od[i] + id[i] << endl;
//         }
//     }
//     void BFS()
//     {
//         size_t srci = 0;
//         queue<int> q;
//         vector<bool> visited(_vertexs.size(), false);

//         q.push(srci);
//         visited[srci] = true;

//         size_t n = _vertexs.size();
//         while (!q.empty())
//         {
//             int front = q.front();
//             q.pop();
//             cout << _vertexs[front];
//             for (size_t i = 0; i < n; ++i)
//             {
//                 if (_matrix[front][i] != MAX_W && visited[i] == false)
//                 {
//                     q.push(i);
//                     visited[i] = true;
//                 }
//             }
//         }
//         cout << endl;
//     }
//     void BFSlevel(const V &src)
//     {
//         size_t srci = GetVertexIndex(src);

//         queue<int> q;
//         vector<bool> visited(_vertexs.size(), false);

//         q.push(srci);
//         visited[srci] = true;
//         int levelSize = 1;

//         size_t n = _vertexs.size();
//         while (!q.empty())
//         {
//             // 一层一层出
//             for (int i = 0; i < levelSize; ++i)
//             {
//                 int front = q.front();
//                 q.pop();
//                 cout << front << ":" << _vertexs[front] << " ";
//                 for (size_t i = 0; i < n; ++i)
//                 {
//                     if (_matrix[front][i] != MAX_W)
//                     {
//                         if (visited[i] == false)
//                         {
//                             q.push(i);
//                             visited[i] = true;
//                         }
//                     }
//                 }
//             }
//             cout << endl;
//             levelSize = q.size();
//         }
//         cout << endl;
//     }
//     void _DFS(size_t srci, vector<bool> &visited)
//     {
//         cout << _vertexs[srci];
//         visited[srci] = true;

//         // 找一个srci相邻的没有访问过的点，去往深度遍历
//         for (size_t i = 0; i < _vertexs.size(); ++i)
//         {
//             if (_matrix[srci][i] != MAX_W && visited[i] == false)
//             {
//                 _DFS(i, visited);
//             }
//         }
//     }

//     void DFS()
//     {
//         size_t srci = 0;
//         vector<bool> visited(_vertexs.size(), false);

//         _DFS(srci, visited);
//         cout << endl;
//     }

// private:
//     vector<V> _vertexs;        // 顶点集合
//     map<V, int> _indexMap;     // 顶点映射下标
//     vector<vector<W>> _matrix; // 邻接矩阵
//     size_t _arcnum;            // 边数
//     vector<int> od;
//     vector<int> id;
// };
// int main()
// {
//     size_t vexnum, arcnum;
//     cin >> vexnum >> arcnum;
//     char a[20];
//     cin >> a;
//     Graph<char, int> g(a, vexnum, arcnum);
//     g.CreatGraph();
//     g.Degree();
//     g.DFS();
//     g.BFS();
//     return 0;
// }

// 7-2

// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
// using namespace std;
// class UnionFindSet
// {
// public:
//     UnionFindSet(size_t n)
//         : _ufs(n, -1)
//     {
//     }
//     void Union(int x1, int x2)
//     {
//         int root1 = FindRoot(x1);
//         int root2 = FindRoot(x2);
//         // 如果本身就在一个集合就没必要合并
//         if (root1 == root2)
//             return;

//         _ufs[root1] += _ufs[root2];
//         _ufs[root2] = root1;
//     }
//     int FindRoot(int x)
//     {
//         int parent = x;
//         while (_ufs[parent] >= 0)
//         {
//             parent = _ufs[parent];
//         }
//         return parent;
//     }
//     bool InSet(int x1, int x2)
//     {
//         return FindRoot(x1) == FindRoot(x2);
//     }
// private:
//     vector<int> _ufs;
// };
// template <class V, class W, W MAX_W = INT_MAX, bool Direction = false>
// class Graph
// {
//     typedef Graph<V, W, MAX_W, Direction> Self;

// public:
//     Graph() = default;
//     Graph(const V *a, size_t n, size_t m)
//         : _arcnum(m), _chosen(m, false)
//     {
//         _vertexs.reserve(n);
//         for (size_t i = 0; i < n; i++)
//         {
//             _vertexs.push_back(a[i]);
//             _indexMap[a[i]] = i;
//         }
//         _matrix.resize(n);
//         for (size_t i = 0; i < n; i++)
//         {
//             _matrix[i].resize(n, MAX_W);
//         }
//     }
//     size_t GetVertexIndex(const V &v)
//     {
//         auto it = _indexMap.find(v);
//         if (it != _indexMap.end())
//             return it->second;
//         throw invalid_argument("vertex error");
//         return -1;
//     }
//     void CreatGraph()
//     {
//         getchar();
//         for (size_t i = 0; i < _arcnum; i++)
//         {
//             char src, dst;
//             int w;
//             scanf("(%c,%c,%d)", &src, &dst, &w);
//             AddEdge(src, dst, w);
//         }
//     }
//     void _AddEdge(size_t srci, size_t dsti, const W &w)
//     {
//         _matrix[srci][dsti] = w;
//         // 无向图
//         if (Direction == false)
//         {
//             _matrix[dsti][srci] = w;
//         }
//     }

//     void AddEdge(const V &src, const V &dst, const W &w)
//     {
//         size_t srci = GetVertexIndex(src);
//         size_t dsti = GetVertexIndex(dst);
//         _AddEdge(srci, dsti, w);
//     }
//     struct Edge
//     {
//         size_t _srci;
//         size_t _dsti;
//         W _w;

//         Edge(size_t srci, size_t dsti, const W &w)
//             : _srci(srci), _dsti(dsti), _w(w)
//         {
//         }

//         bool operator>(const Edge &e) const
//         {
//             return _w > e._w;
//         }
//     };

//     W Kruskal(Self &minTree)
//     {
//         size_t n = _vertexs.size();

//         minTree._vertexs = _vertexs;
//         minTree._indexMap = _indexMap;
//         minTree._matrix.resize(n);
//         for (size_t i = 0; i < n; ++i)
//         {
//             minTree._matrix[i].resize(n, MAX_W);
//         }

//         priority_queue<Edge, vector<Edge>, greater<Edge>> minque;
//         for (size_t i = 0; i < n; ++i)
//         {
//             for (size_t j = 0; j < n; ++j)
//             {
//                 if (i < j && _matrix[i][j] != MAX_W)
//                 {
//                     minque.push(Edge(i, j, _matrix[i][j]));
//                 }
//             }
//         }
//         // 选出n-1条边
//         size_t size = 0;
//         W totalW = W();
//         UnionFindSet ufs(n);
//         while (!minque.empty())
//         {
//             Edge min = minque.top();
//             minque.pop();

//             if (!ufs.InSet(min._srci, min._dsti))
//             {
//                 cout << "(" << _vertexs[min._srci] << "," << _vertexs[min._dsti] << "," << min._w << ",1)";
//                 minTree._AddEdge(min._srci, min._dsti, min._w);
//                 ufs.Union(min._srci, min._dsti);
//                 ++size;
//                 totalW += min._w;
//             }
//             else
//             {
//                 cout << "(" << _vertexs[min._srci] << "," << _vertexs[min._dsti] << "," << min._w << ",0)";
//             }
//         }

//         if (size == n - 1)
//             return totalW;
//         else
//             return W();
//     }

// private:
//     vector<V> _vertexs;        // 顶点集合
//     map<V, int> _indexMap;     // 顶点映射下标
//     vector<vector<W>> _matrix; // 邻接矩阵
//     size_t _arcnum;            // 边数
//     vector<bool> _chosen;      // 最小生成树是否选择该边
// };
// int main()
// {
//     size_t vexnum, arcnum;
//     cin >> vexnum >> arcnum;
//     char a[20];
//     cin >> a;
//     Graph<char, int> g(a, vexnum, arcnum);
//     g.CreatGraph();
//     Graph<char, int> kminTree;
//     g.Kruskal(kminTree);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// namespace link_table
//{
// template <class W>
// struct Edge
//{
// int _dsti; // 目标点的下标
// W _w;      // 权值
// Edge<W> *_next;

// Edge(int dsti, const W &w)
//: _dsti(dsti), _w(w), _next(nullptr)
//{
//}
//};
// template <class V, class W, bool Direction = false>
// class Graph
//{
// typedef Edge<W> edge;

// public:
// Graph(const V *a, size_t n)
//{
//_vertexs.reserve(n);
// for (size_t i = 0; i < n; i++)
//{
//_vertexs.push_back(a[i]);
//_indexMap[a[i]] = i;
//}
//_tables.resize(n,nullptr);
//}
// size_t GetVertexIndex(const V &v)
//{
// auto it = _indexMap.find(v);
// if (it != _indexMap.end())
// return it->second;
// throw invalid_argument("vertex error");
// return -1;
//}
// void AddEdge(const V &src, const V &dst, const W &w)
//{
// size_t srci = GetVertexIndex(src);
// size_t dsti = GetVertexIndex(dst);

// Edge *eg = new Edge(dsti, w);
// eg->_next = _tables[srci];
//_tables[srci] = eg;

// if (Direction == false)
//{
// Edge *eg = new Edge(srci, w);
// eg->_next = _tables[dsti];
//_tables[dsti] = eg;
//}
//}
// void Print()
//{
// for (size_t i = 0; i < _vertexs.size(); i++)
//{
// cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
//}
// for (size_t i = 0; i < _matrix.size(); i++)
//{
// for (size_t j = 0; j < _matrix[i].size(); j++)
//{
// if (_matrix[i][j] == MAX_W)
//{
// cout << "∞ ";
//}
// else
// cout << _matrix[i][j] << " ";
//}
// cout << endl;
//}
//}

// private:
// vector<V> _vertexs;     // 顶点集合
// map<V, int> _indexMap;  // 顶点映射下标
// vector<Edge *> _tables; // 邻接表
//};
// void TestGraph1()
//{
// Graph<char, int, true> g("0123", 4);
// g.AddEdge('0', '1', 1);
// g.AddEdge('0', '3', 4);
// g.AddEdge('1', '3', 2);
// g.AddEdge('1', '2', 9);
// g.AddEdge('2', '3', 8);
// g.AddEdge('2', '1', 5);
// g.AddEdge('2', '0', 3);
// g.AddEdge('3', '2', 6);
// g.Print();
//}
//}

// int main()
//{
// link_table::TestGraph1();
// return 0;
//}

// 7-2 实现求最小生成树的克鲁斯卡尔算法(Kruskal)
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// using namespace std;

// struct Edge
// {
//     Edge(int srci = 0, int dsti = 0, int weight = 0)
//         : srci(srci), dsti(dsti), weight(weight)
//     {
//     }
//     int srci;   // 边的起点
//     int dsti;   // 边的终点
//     int weight; // 边的权值
// };

// struct Graph
// {
//     vector<char> vertex;      // 顶点
//     vector<Edge> edges;       // 边
//     map<char, int> _indexMap; // 顶点映射下标
//     vector<int> ufs;          // 并查集
//     int vexnum, arcnum;       // 顶点和边的个数
//     int GetVertexIndex(const char &v)
//     {
//         auto it = _indexMap.find(v);
//         if (it != _indexMap.end())
//             return it->second;
//     }

//     void Kruskal()
//     {
//         sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b)
//              { return a.weight < b.weight; });
//         ufs.resize(vertex.size(), -1);
//         auto FindRoot = [&](int x)
//         {
//             while (ufs[x] >= 0)
//                 x = ufs[x];
//             return x;
//         };
//         for (int i = 0; i < arcnum; i++)
//         {
//             int root1 = FindRoot(edges[i].srci);
//             int root2 = FindRoot(edges[i].dsti);
//             if (root1 != root2)
//             {
//                 cout << "(" << vertex[edges[i].srci] << "," << vertex[edges[i].dsti] << "," << edges[i].weight << ",1)";
//                 ufs[root1] += ufs[root2];
//                 ufs[root2] = root1;
//             }
//             else
//             {
//                 cout << "(" << vertex[edges[i].srci] << "," << vertex[edges[i].dsti] << "," << edges[i].weight << ",0)";
//             }
//         }
//     }
// };

// void CreateGraph(Graph *G)
// {
//     scanf("%d %d", &G->vexnum, &G->arcnum);
//     G->vertex.resize(G->vexnum);
//     G->edges.resize(G->arcnum);
//     getchar();
//     string s;
//     cin >> s;
//     for (int i = 0; i < G->vexnum; i++)
//     {
//         G->vertex[i] = s[i];
//         G->_indexMap[G->vertex[i]] = i;
//     }
//     getchar();
//     for (int k = 0; k < G->arcnum; k++)
//     {
//         char src, dst;
//         int w;
//         scanf("(%c,%c,%d)", &src, &dst, &w);
//         Edge e(G->_indexMap[src], G->_indexMap[dst], w);
//         G->edges[k] = e;
//     }
// }

// int main()
// {
//     Graph G;
//     CreateGraph(&G);
//     G.Kruskal();
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAXVEX 20
// typedef char Vextype;
// typedef struct
// {
//     int arcs[MAXVEX + 1][MAXVEX + 1];
//     Vextype vex[MAXVEX + 1];
//     int vexnum;
//     int arcnum;
// } AdjMatrix;

// typedef struct ArcNode
// {
//     int adjvex;
//     struct ArcNode *next;
// } ArcNode;
// typedef struct
// {
//     Vextype vexdata;
//     ArcNode *head;
// } VertexNode;
// typedef struct
// {
//     VertexNode vertex[MAXVEX];
//     int vexnum;
//     int arcnum;
// } AdjList;

// void Creat_AdjMatrix(AdjMatrix *G); // 创建邻接矩阵
// int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v);

// void Print_AdjList(AdjList *G); // 输出邻接表

// void AdjMatrixToAdjList(AdjMatrix *M, AdjList *L); // 邻接矩阵转换为邻接表

// main()
// {
//     AdjMatrix gM;
//     AdjList gL;
//     Creat_AdjMatrix(&gM);
//     AdjMatrixToAdjList(&gM, &gL);
//     Print_AdjList(&gL);
// }

// void Creat_AdjMatrix(AdjMatrix *G) // 创建邻接矩阵
// {
//     int i, j, k;
//     char v1, v2;
//     scanf("%d\n", &(G->vexnum));
//     for (i = 1; i <= G->vexnum; i++)
//     {
//         scanf("%c", &(G->vex[i]));
//         for (j = 1; j <= G->vexnum; j++)
//             G->arcs[i][j] = 0;
//     }
//     scanf("%d\n", &(G->arcnum));
//     for (k = 1; k <= G->arcnum; k++)
//     {
//         scanf("<%c,%c>", &v1, &v2);
//         i = LocateVex_AdjMatrix(G, v1);
//         j = LocateVex_AdjMatrix(G, v2);
//         G->arcs[i][j] = 1;
//     }
// }

// int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v) // 输出邻接表
// {
//     int i;
//     for (i = 1; i <= G->vexnum; i++)
//         if (G->vex[i] == v)
//             return i;
//     return 0;
// }

// void Print_AdjList(AdjList *G)
// {
//     int i;
//     ArcNode *p;
//     for (i = 1; i <= G->vexnum; i++)
//     {
//         printf("%d:(%c)", i, G->vertex[i].vexdata);
//         for (p = G->vertex[i].head; p; p = p->next)
//         {
//             printf("->%d", p->adjvex);
//         }
//         printf("\n");
//     }
// }

// void AdjMatrixToAdjList(AdjMatrix *M, AdjList *L) // 邻接矩阵转换为邻接表
// {
//     L->vexnum = M->vexnum;
//     for (int i = 1; i <= M->vexnum; i++)
//     {
//         L->vertex[i].vexdata = M->vex[i];
//         L->vertex[i].head = NULL;
//         for (int j = 1; j <= M->vexnum; j++)
//         {
//             if (M->arcs[i][j] == 1)
//             {
//                 ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
//                 p->adjvex = j;
//                 p->next = L->vertex[i].head;
//                 L->vertex[i].head = p;
//                 L->arcnum++;
//             }
//         }
//     }
// }
// void AdjMatrixToAdjList(AdjMatrix *M, AdjList *L)
// {
//     L->vexnum = M->vexnum;
//     L->arcnum = M->arcnum;
//     ArcNode *p, *s;
//     for (int i = 1; i <= M->vexnum; i++)
//     {
//         L->vertex[i].vexdata = M->vex[i];
//         L->vertex[i].head = NULL;
//         for (int j = 1; j <= M->vexnum; j++)
//         {
//             if (M->arcs[i][j] == 1)
//             {
//                 s = (ArcNode *)malloc(sizeof(ArcNode));
//                 s->adjvex = j;
//                 s->next = NULL;
//                 p = L->vertex[i].head;
//                 if (p == NULL)
//                 {
//                     L->vertex[i].head = s;
//                 }
//                 else
//                 {
//                     while (p->next)
//                         p = p->next;
//                     s->next = p->next;
//                     p->next = s;
//                 }
//             }
//         }
//     }
// }

// #define MAXVEX 20
// typedef char Vextype;
// typedef struct
// {
//     int arcs[MAXVEX + 1][MAXVEX + 1];
//     Vextype vex[MAXVEX + 1];
//     int vexnum;
//     int arcnum;
// } AdjMatrix;
// #include <stdio.h>

// void Creat_AdjMatrix(AdjMatrix *G);
// int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v);
// int Path_AdjMatirx(AdjMatrix *G, Vextype v1, Vextype v2);

// main()
// {
//     int n, i;
//     Vextype a, b;
//     AdjMatrix gM;
//     Creat_AdjMatrix(&gM);
//     scanf("%d\n", &n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("[%c,%c]", &a, &b);
//         if (Path_AdjMatirx(&gM, a, b) == 1)
//             printf("From %c to %c: YES.\n", a, b);
//         else
//             printf("From %c to %c: NO.\n", a, b);
//     }
// }

// void Creat_AdjMatrix(AdjMatrix *G)
// {
//     int i, j, k;
//     char v1, v2;
//     scanf("%d\n", &(G->vexnum));
//     for (i = 1; i <= G->vexnum; i++)
//     {
//         scanf("%c", &(G->vex[i]));
//         for (j = 1; j <= G->vexnum; j++)
//             G->arcs[i][j] = 0;
//     }
//     scanf("%d\n", &(G->arcnum));
//     for (k = 1; k <= G->arcnum; k++)
//     {
//         scanf("<%c,%c>", &v1, &v2);
//         i = LocateVex_AdjMatrix(G, v1);
//         j = LocateVex_AdjMatrix(G, v2);
//         G->arcs[i][j] = 1;
//     }
// }

// int LocateVex_AdjMatrix(AdjMatrix *G, Vextype v)
// {
//     int i;
//     for (i = 1; i <= G->vexnum; i++)
//         if (G->vex[i] == v)
//             return i;
//     return 0;
// }
// int visited[MAXVEX + 1] = {0};
// int DFS(AdjMatrix *G, int cur, int end)
// {
//     if (cur == end)
//         return 1;
//     visited[cur] = 1;
//     for (int i = 1; i <= G->vexnum; i++)
//         if (G->arcs[cur][i] == 1 && !visited[i])
//             if (DFS(G, i, end))
//                 return 1;
//     return 0;
// }
// int Path_AdjMatirx(AdjMatrix *G, Vextype v1, Vextype v2) // 判断两个指定顶点之间是否存在路径。
// {
//     int start = LocateVex_AdjMatrix(G, v1);
//     int end = LocateVex_AdjMatrix(G, v2);
//     for (int i = 1; i <= G->vexnum; i++)
//         visited[i] = 0;
//     return DFS(G, start, end);
// }

// #include <iostream>
// #include <string>

// using namespace std;
// int hd[100], go[100], nxt[100], cst[100], dis[100], l;
// void Add(int u, int v, int t)
// {
//     nxt[++l] = hd[u], hd[u] = l, go[l] = v, cst[l] = t;
// }
// void dfs(int s, int f, int d)
// {
//     dis[s] = d;
//     for (int i = hd[s]; i; i = nxt[i])
//     {
//         if (go[i] == f)
//             continue;
//         dfs(go[i], s, d + cst[i]);
//     }
// }
// int main()
// {
//     int n, m, u, v, w, s = 1, i;
//     cin >> n;
//     m = n - 1;
//     for (i = 1; i <= m; i++)
//     {
//         cin >> u >> v >> w;
//         Add(u, v, w);
//         Add(v, u, w);
//     }
//     dfs(1, 0, 0);
//     for (i = 2; i <= n; i++)
//         if (dis[s] < dis[i])
//             s = i;
//     dfs(s, 0, 0);
//     for (i = 1; i <= n; i++)
//         if (dis[s] < dis[i])
//             s = i;
//     printf("%d\n", dis[s] * 10 + (dis[s] + 1) * dis[s] / 2);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <functional>
// using namespace std;
// int M, N, u, v, ans;
// #define maxn 10010
// vector<int> G[maxn];
// bool used[maxn];

// // u表示上一个顶点，dep表示当前寻找第dep+1个结点，s表示起点；
// void DFS(int u, int dep, int s)
// {
//     if (dep == 3)
//     {
//         for (int i = 0; i < G[u].size(); i++)
//         {
//             int v = G[u][i];
//             if (!used[v] || v == s)
//                 ans++;
//         }
//         return;
//     }
//     else
//     {
//         for (int i = 0; i < G[u].size(); i++)
//         {
//             int v = G[u][i];
//             if (!used[v])
//             {
//                 used[v] = true;
//                 DFS(v, dep + 1, s);
//                 used[v] = false;
//             }
//         }
//     }
//     return;
// }

// int main(void)
// {
//     cin >> N >> M;
//     while (M--)
//     {
//         cin >> u >> v;
//         G[u].push_back(v);
//         G[v].push_back(u);
//     }

//     memset(used, 0, sizeof used);
//     for (int i = 1; i <= N; i++)
//     {
//         used[i] = true;
//         DFS(i, 1, i);
//         used[i] = false;
//     }
//     cout << ans;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// const int N = 1e6;
// int n, m;
// int q[N], d[N];
// int h[N], e[N], ne[N], idx;

// void add(int a, int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// bool topsort()
// {
//     int hh = 0, tt = -1;
//     for (int i = 1; i <= n; i++)
//         if (!d[i])
//             q[++tt] = i;
//     while (hh <= tt)
//     {
//         auto t = q[hh++];
//         for (int i = h[t]; i != -1; i = ne[i])
//         {
//             int j = e[i];
//             d[j]--;
//             if (d[j] == 0)
//                 q[++tt] = j;
//         }
//     }
//     return tt == n - 1;
// }
// int main()
// {
//     memset(h, -1, sizeof h);
//     cin >> n >> m;
//     while (m--)
//     {
//         int a, b;
//         cin >> a >> b;
//         add(a, b);
//         d[b]++; // b的入度++
//     }
//     if (topsort())
//     {
//         for (int i = 0; i < n; i++)
//             cout << q[i] << " ";
//         puts("");
//     }
//     else
//         puts("-1");
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <map>
// #include <queue>
// using namespace std;
// const int N = 1e6;
// int n, m;
// int h[N], e[N], ne[N], idx;
// bool st[N] = {false};
// map<char, int> indexMap;
// string s;
// queue<int> q;
// void add(int a, int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// int getindex(char a)
// {
//     return indexMap[a];
// }
// void dfs(int u)
// {
//     st[u] = true;
//     cout << s[u] << " ";
//     for (int i = h[u]; i != -1; i = ne[i])
//     {
//         int j = e[i];
//         if (!st[j])
//             dfs(j);
//     }
// }
// void bfs(int u)
// {
//     st[0] = true;
//     q.push(0);
//     cout<<s[u]<<" ";
//     while (!q.empty())
//     {
//         int t = q.front();
//         q.pop();
//         for (int i = h[u]; i != -1; i = ne[i])
//         {
//             int j = e[i];
//             if (!st[j])
//             {
//                 st[j] = true;
//                 q.push(j);
//                 cout<<s[j]<<" ";
//             }
//         }
//     }
// }
// int main()
// {
//     idx = 0;
//     memset(h, -1, sizeof h);
//     cin >> n >> m;
//     cin >> s;
//     for (int i = 0; i < s.size(); i++)
//         indexMap[s[i]] = i;
//     while (m--)
//     {
//         char v1, v2;
//         cin >> v1 >> v2;
//         int a = getindex(v1);
//         int b = getindex(v2);
//         add(a, b);
//     }
//     //dfs(0);
//     st[N] = {false};
//     bfs(0);
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <queue>
// #include <string>
// #include <map>
// using namespace std;
// const int N = 1e3;
// int n, m;
// int h[N], e[N], ne[N], idx;
// int g[N][N];
// bool visited[N];
// map<char, int> index_map;
// string s;
// queue<int> q;
// int ufs[N];
// int id[N];
// int od[N];
// void add(int a, int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// void add2(int a, int b)
// {
//     g[a][b] = 1;
// }
// int getindex(char a)
// {
//     return index_map[a];
// }
// void dfs(int u)
// {
//     visited[u] = true;
//     cout << s[u] << " ";
//     for (int i = h[u]; i != -1; i = ne[i])
//     {
//         int j = e[i];
//         if (!visited[j])
//             dfs(j);
//     }
// }
// void dfs2(int u)
// {
//     visited[u] = true;
//     cout << s[u] << " ";
//     for (int i = 0; i < n; i++)
//         if (g[u][i] != 0 && !visited[i])
//             dfs2(i);
// }
// void bfs(int u)
// {
//     q.push(u);
//     visited[u] = true;
//     while (!q.empty())
//     {
//         int t = q.front();
//         q.pop();
//         cout << s[t] << " ";
//         for (int i = h[t]; i != -1; i = ne[i])
//         {
//             int j = e[i];
//             if (!visited[j])
//             {
//                 q.push(j);
//                 visited[j] = true;
//             }
//         }
//     }
// }
// void bfs2(int u)
// {
//     q.push(u);
//     visited[u] = true;
//     while (!q.empty())
//     {
//         int t = q.front();
//         q.pop();
//         cout << s[t] << " ";
//         for (int i = 0; i < n; i++)
//         {
//             if (g[t][i] != 0x3f3f3f3f && !visited[i])
//             {
//                 visited[i] = true;
//                 q.push(i);
//             }
//         }
//     }
// }
// void degree()
// {
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0 ;j < n;j++)
//         {
//             if(g[i][j]!=0x3f3f3f3f)
//             {
//                 od[i]++;
//                 id[j]++;
//             }
//         }
//     }
//     for(int i =0;i<n;i++)
//     {
//         cout<<s[i]<<" "<<od[i]<<" "<<id[i]<<" "<<od[i]+id[i]<<endl;
//     }
// }
// int main()
// {
//     memset(h, -1, sizeof h);
//     idx = 0;
//     memset(g, 0x3f, sizeof g);
//     memset(ufs, -1, sizeof ufs);
//     cin >> n >> m;
//     cin >> s;
//     for (int i = 0; i < s.size(); i++)
//         index_map[s[i]] = i;
//     while (m--)
//     {
//         char v1, v2;
//         cin >> v1 >> v2;
//         int a = getindex(v1);
//         int b = getindex(v2);
//         add(a, b);
//         add2(a, b);
//     }
//     // dfs(0);
//     // dfs2(0);
//     // cout<<endl;
//     // memset(visited,0,sizeof visited);
//     // bfs(0);
//     // bfs2(0);
//     degree();
//     dfs2(0);
//     cout<<endl;
//     memset(visited,0,sizeof visited);
//     bfs2(0);

// }

// #include <iostream>
// #include <cstring>
// #include <queue>
// #include <map>
// using namespace std;

// const int N = 1e6;
// int n, m;
// int q[N],d[N];
// int h[N], e[N], ne[N], idx;
// map<char, int> index_map;
// string s;
// void add(int a, int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// int getIndex(char a)
// {
//     return index_map[a];
// }
// bool topsort()
// {
//     int hh = 0, tt = -1;
//     for (int i = 0; i < n; i++)
//         if (!d[i])
//             q[++tt] = i;

//     while (hh<=tt)
//     {
//         auto t = q[hh++];
//         for (int i = h[t]; i != -1; i = ne[i])
//         {
//             int j = e[i];
//             d[j]--;
//             if (d[j] == 0) q[++tt] = j;
//         }
//     }
//     return tt == n - 1;
// }
// int main()
// {
//     memset(h, -1, sizeof h);
//     cin >> n >> m;
//     cin >> s;
//     for (int i = 0; i < n; i++)
//         index_map[s[i]] = i;
//     getchar();
//     while (m--)
//     {
//         char v1, v2;
//         scanf("<%c,%c>", &v1, &v2);
//         int a = getIndex(v1);
//         int b = getIndex(v2);
//         add(a, b);
//         d[b]++; // b的入度++
//     }
//     if (topsort())
//     {
//         for (int i = 0; i < n; i++)
//             cout << s[q[i]] << " ";
//     }
//     else
//         puts("-1");
//     return 0;
// }

//已知有向无权图G，求出其拓扑有序序列。(要求：用邻接矩阵存储图，用栈存储度为0的结点。)
// #include <iostream>
// #include <cstring>
// #include <queue>
// #include <map>
// #include <stack>
// using namespace std;

// const int N = 1e3;
// int n, m;
// int d[N];
// stack<int> st;
// int g[N][N];
// map<char, int> index_map;
// string s;
// string toop;
// void add(int a, int b)
// {
//     g[a][b] = 1;
// }
// int getIndex(char a)
// {
//     return index_map[a];
// }
// bool topsort()
// {

//     for (int i = 0; i < n; i++)
//         if (!d[i])
//             st.push(i);

//     while (!st.empty())
//     {
//         int t = st.top();
//         st.pop();
//         toop += s[t];
//         for (int i = 0; i < n; i++)
//         {
//             if (g[t][i] != 0x3f3f3f3f)
//                 d[i]--;
//             if (g[t][i] != 0x3f3f3f3f && d[i] == 0)
//                 st.push(i);
//         }
//     }
//     return toop.size() == n;
// }
// int main()
// {
//     memset(g, 0x3f, sizeof g);
//     cin >> n >> m;
//     cin >> s;
//     for (int i = 0; i < n; i++)
//         index_map[s[i]] = i;
//     getchar();
//     while (m--)
//     {
//         char v1, v2;
//         scanf("<%c,%c>", &v1, &v2);
//         int a = getIndex(v1);
//         int b = getIndex(v2);
//         add(a, b);
//         d[b]++; // b的入度++
//     }
//     if (topsort())
//         cout << toop;
//     else
//         puts("-1");
//     return 0;
// }
