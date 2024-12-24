#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <stack>
#include <map>
#include <set>
using namespace std;

// 洛谷1443 马 https://www.luogu.com.cn/problem/P1443
//  const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
//  const int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2}; // 8个方向
//  queue<pair<int, int>> q;
//  int f[500][500];    // 存步数
//  bool vis[500][500]; // 走没走过
//  int main()
//  {
//      int n, m, x, y;
//      memset(f, -1, sizeof(f));
//      memset(vis, false, sizeof(vis));
//      cin >> n >> m >> x >> y;
//      f[x][y] = 0;
//      vis[x][y] = true;
//      q.push(make_pair(x, y));
//      while (!q.empty())
//      {
//          int xx = q.front().first, yy = q.front().second;
//          q.pop(); // 取队首并出队
//          for (int i = 0; i < 8; i++)
//          {
//              int u = xx + dx[i], v = yy + dy[i];
//              if (u < 1 || u > n || v < 1 || v > m || vis[u][v])
//                  continue; // 出界或走过就不走
//              vis[u][v] = true;
//              q.push(make_pair(u, v));
//              f[u][v] = f[xx][yy] + 1;
//          }
//      }
//      for (int i = 1; i <= n; i++)
//      {
//          for (int j = 1; j <= m; j++)
//              printf("%-5d", f[i][j]);
//          printf("\n");
//      }
//      return 0;
//  }

// queue<int> q, q1;
// int a[401][401], ans[401][401];
// int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
// int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};
// int main()
// {
//     memset(ans, -1, sizeof(ans));
//     int n, m, startx, starty;
//     cin >> n >> m >> startx >> starty;
//     q.push(startx);
//     q1.push(starty);
//     ans[startx][starty] = 0;
//     a[startx][starty] = 1;
//     while (!q.empty())
//     {
//         for (int i = 0; i < 8; i++)
//         {
//             int tx = q.front() + dx[i];
//             int ty = q1.front() + dy[i];
//             if (tx > 0 && tx <= n && ty > 0 && ty <= m && a[tx][ty] == 0)
//             {
//                 a[tx][ty] = 1;
//                 ans[tx][ty] = ans[q.front()][q1.front()] + 1;
//                 q.push(tx);
//                 q1.push(ty);
//             }
//         }
//         q.pop();
//         q1.pop();
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             printf("%-5d", ans[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// leetcode 797. 所有可能的路径
// 98. 所有可达路径 https://kamacoder.com/problempage.php?pid=1170
//  vector<vector<int>> ret;
//  vector<int> path;
//  void dfs(const vector<list<int>> &graph, int x, int N)
//  {
//      if (x == N)
//      {
//          ret.push_back(path);
//          return;
//      }
//      auto it = graph[x].begin();
//      while (it != graph[x].end())
//      {
//          path.push_back(*it);
//          dfs(graph, *it, N);
//          path.pop_back();
//          ++it;
//      }
//      // for(int i:graph[x])
//      // {
//      //     path.push_back(i);
//      //     dfs(graph,i,N);
//      //     path.pop_back();
//      // }
//  }

// int main()
// {
//     int N, M, s, t;
//     cin >> N >> M;
//     vector<list<int>> graph(N + 1);
//     while (M--)
//     {
//         cin >> s >> t;
//         graph[s].push_back(t);
//     }
//     path.push_back(1);
//     dfs(graph, 1, N);
//     if (ret.size() == 0) cout << -1 << endl;
//     for (int i = 0; i < ret.size(); i++)
//     {
//         for (int j = 0; j < ret[i].size(); j++)
//         {
//             cout << ret[i][j];
//             if (j != ret[i].size() - 1) cout << " ";
//         }
//         if (i != ret.size() - 1) cout << endl;
//     }
//     return 0;
// }

// 99. 岛屿数量 https://kamacoder.com/problempage.php?pid=1171(acm)
// 200. 岛屿数量 https://leetcode.cn/problems/number-of-islands/description/

// 深度优先搜索版本acm

// int dx[4] = {0, 0, -1, 1};
// int dy[4] = {1, -1, 0, 0};
// int ret = 0;

// void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
//{
// if (visited[x][y] || grid[x][y] == 0)
// return;
// for (int i = 0; i < 4; i++)
//{
// visited[x][y] = true;
// int nextx = x + dx[i];
// int nexty = y + dy[i];
// if (nextx >= grid.size() || nextx < 0 || nexty >= grid[0].size() || nexty < 0)
// continue;
//;
// dfs(grid, visited, nextx, nexty);
//}
//}

// int main()
//{
// int N, M;
// cin >> N >> M;
// vector<vector<int>> grid(N, vector<int>(M, 0));
// vector<vector<bool>> visited(N, vector<bool>(M, false));
// for (int i = 0; i < N; i++)
//{
// for (int j = 0; j < M; j++)
//{
// cin >> grid[i][j];
//}
//}
// for (int i = 0; i < N; i++)
//{
// for (int j = 0; j < M; j++)
//{
// if (visited[i][j] == false && grid[i][j] == 1)
//{
// ret++;
// dfs(grid, visited, i, j);
//}
//}
//}
// cout << ret;
// return 0;
//}

// leetcode深度优先搜索版本

// class Solution {
// private:
// int dx[4] = {0, 0, -1, 1};
// int dy[4] = {1, -1, 0, 0};
// int ret = 0;
// void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
// if (visited[x][y] || grid[x][y] == '0')return;
// for (int i = 0; i < 4; i++) {
// visited[x][y] = true;
// int nextx = x + dx[i];
// int nexty = y + dy[i];
// if (nextx >= grid.size() || nextx < 0 || nexty >= grid[0].size() || nexty < 0) continue;
// dfs(grid, visited, nextx, nexty);
//}
//}

// public:
// int numIslands(vector<vector<char>>& grid) {
// vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));
// for (int i = 0; i < grid.size(); i++) {
// for (int j = 0; j < grid[i].size(); j++) {
// if (visited[i][j] == false && grid[i][j] == '1') {
// ret++;
// dfs(grid, visited, i, j);
//}
//}
//}
// return ret;
//}
//};

// 广度优先搜索版本acm

// int dx[4] = {0, 0, -1, 1};
// int dy[4] = {1, -1, 0, 0};
// int ret = 0;

// void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
//{
// queue<pair<int, int>> q;
// q.push({x, y});
// visited[x][y] = true;
// while (!q.empty())
//{
// pair<int, int> cur = q.front();
// q.pop();
// int curx = cur.first;
// int cury = cur.second;
// for (int i = 0; i < 4; i++)
//{
// int nextx = curx + dx[i];
// int nexty = cury + dy[i];
// if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
// continue;
// if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1)
//{
// q.push({nextx, nexty});
// visited[nextx][nexty] = true;
//}
//}
//}
//}

// int main()
//{
// int N, M;
// cin >> N >> M;
// vector<vector<int>> grid(N, vector<int>(M, 0));
// vector<vector<bool>> visited(N, vector<bool>(M, false));
// for (int i = 0; i < N; i++)
//{
// for (int j = 0; j < M; j++)
//{
// cin >> grid[i][j];
//}
//}
// for (int i = 0; i < N; i++)
//{
// for (int j = 0; j < M; j++)
//{
// if (visited[i][j] == false && grid[i][j] == 1)
//{
// ret++;
// bfs(grid, visited, i, j);
//}
//}
//}
// cout << ret << endl;
// return 0;
//}

// leetcode广度优先搜索版本

// class Solution {
// private:
//     int dx[4] = {0, 0, -1, 1};
//     int dy[4] = {1, -1, 0, 0};
//     int ret = 0;
//     void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
//         queue<pair<int, int>> q;
//         q.push({x,y});
//         visited[x][y] = true;
//         while (!q.empty()) {
//             pair<int, int> cur = q.front(); q.pop();
//             int curx = cur.first;
//             int cury = cur.second;
//             for (int i = 0; i < 4; i++) {
//                 int nextx = curx + dx[i];
//                 int nexty = cury + dy[i];
//                 if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
//                 if (visited[nextx][nexty] == false &&
//                     grid[nextx][nexty] == '1') {
//                     q.push({nextx, nexty});
//                     visited[nextx][nexty] = true;
//                 }
//             }
//         }
//     }

// public:
//     int numIslands(vector<vector<char>>& grid) {
//         vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[i].size(); j++) {
//                 if (visited[i][j] == false && grid[i][j] == '1') {
//                     ret++;
//                     bfs(grid, visited, i, j);
//                 }
//             }
//         }
//         return ret;
//     }
// };

// 695. 岛屿的最大面积 https://leetcode.cn/problems/max-area-of-island/description/
// 100. 岛屿的最大面积 https://kamacoder.com/problempage.php?pid=1172

// dfs

// class Solution {
// private:
//     int dx[4] = {0, 0, -1, 1};
//     int dy[4] = {1, -1, 0, 0};
//     int count;
//     void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
//         for (int i = 0; i < 4; i++) {
//             int nextx = x + dx[i];
//             int nexty = y + dy[i];
//             if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
//             if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1) {
//                 count++;
//                 visited[nextx][nexty] = true;
//                 dfs(grid, visited, nextx, nexty);
//             }
//         }
//     }

// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
//         int ret = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[i].size(); j++) {
//                 if (visited[i][j] == false && grid[i][j] == 1) {
//                     count = 1;
//                     visited[i][j] = true;
//                     dfs(grid, visited, i, j);
//                     ret = max(ret, count);
//                 }
//             }
//         }
//         return ret;
//     }
// };

// bfs

// class Solution {
// private:
//     int dx[4] = {0, 0, -1, 1};
//     int dy[4] = {1, -1, 0, 0};
//     int count;
//     void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
//         queue<pair<int, int>> q;
//         q.push({x,y});
//         visited[x][y] = true;
//         count++;
//         while (!q.empty()) {
//             pair<int, int> cur = q.front(); q.pop();
//             int curx = cur.first;
//             int cury = cur.second;
//             for (int i = 0; i < 4; i++) {
//                 int nextx = curx + dx[i];
//                 int nexty = cury + dy[i];
//                 if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
//                 if (visited[nextx][nexty] == false &&
//                     grid[nextx][nexty] == 1) {
//                     q.push({nextx, nexty});
//                     count++;
//                     visited[nextx][nexty] = true;
//                 }
//             }
//         }
//     }

// public:
//      int maxAreaOfIsland(vector<vector<int>>& grid){
//         vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
//         int ret = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[i].size(); j++) {
//                 if (visited[i][j] == false && grid[i][j] == 1) {
//                     count = 0;
//                     bfs(grid, visited, i, j);
//                     ret = max(ret,count);
//                 }
//             }
//         }
//         return ret;
//     }
// };

// int step = 1;
// int dx[8] = {1, 1, 2, 2, -2, -2, -1, -1};
// int dy[8] = {2, -2, 1, -1, 1, -1, 2, -2};
// vector<vector<int>> board(8, vector<int>(8, 0));

// void dfs(vector<vector<int>> board, vector<vector<bool>> visited, int x, int y)
// {
//     step++;
//     if (step >= 64)
//         return;
//     for (int i = 0; i < 8; i++)
//     {
//         int nextx = x + dx[i];
//         int nexty = y + dy[i];
//         if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size())
//             continue;
//         if (visited[nextx][nexty] == false)
//         {
//             visited[nextx][nexty] = true;
//             board[nextx][nexty] = step;
//             dfs(board, visited, nextx, nexty);
//         }
//     }
// }

// int main()
// {
//     vector<vector<bool>> visited(8, vector<bool>(8, false));
//     board[0][0] = 1;
//     dfs(board, visited, 0, 0);
//     for (int i = 0; i < board.size(); i++)
//     {
//         for (int j = 0; j < board[0].size(); j++)
//         {
//             cout << board[i][j] << "  ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// int dx[8] = { 1, 1, 2, 2, -2, -2, -1, -1 };
// int dy[8] = { 2, -2, 1, -1, 1, -1, 2, -2 };
// vector<vector<int>> board(6, vector<int>(6, 0));

// int cot = 0;
// void dfs(int x, int y,int step)
// {
//     board[x][y] = step;
//     if (step >= 25)
//     {
//         for (int i = 1; i < board.size(); i++) {
//             for (int j = 1; j < board[0].size(); j++) {
//                 cout << board[i][j] << "   ";
//             }
//             cout << endl;
//         }
//         return;
//     }
//     for (int i = 0; i < 8; i++)
//     {
//         int nextx = x + dx[i];
//         int nexty = y + dy[i];
//         if (nextx <= 0 || nextx >= board.size() || nexty <= 0 || nexty >= board[0].size()) continue;
//         if(board[nextx][nexty]==0)
//         dfs(nextx, nexty,step+1);
//     }
//     cot++;
//     board[x][y] = 0;
// }
// int main()
// {
//     //vector<vector<bool>> visited(8, vector<bool>(8, false));
//     int curx = 0, cury = 0;
//     cin >> curx >> cury;

//     dfs(1, 1,1);
//     // for (int i = 1; i < board.size(); i++) {
//     //     for (int j = 1; j < board[0].size(); j++) {
//     //         cout << board[i][j] << "  ";
//     //     }
//     //     cout << endl;
//     // }
//     return 0;
// }

// #define ROW 5
// #define COL 5

// int dx[8] = {1, 1, 2, 2, -2, -2, -1, -1};
// int dy[8] = {2, -2, 1, -1, 1, -1, 2, -2};
// vector<vector<int>> board(ROW, vector<int>(COL, 0));
// vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
// bool have;        // 判断是否有结果
// bool only = false; // 选择输出结果是否唯一
// int cot = 0;

// bool in(int x, int y)
// {
//     if (x < 0 || x >= ROW || y < 0 || y >= COL)
//         return false;
//     return true;
// }

// void getNext(int x, int y, int *Next)
// {
//     for (int i = 0; i < 8; i++)
//     {
//         int nextx = x + dx[i];
//         int nexty = y + dy[i];
//         if (in(nextx, nexty) && !visited[nextx][nexty])
//         {
//             for (int j = 0; j < 8; j++)
//             {
//                 int ttx = nextx + dx[j];
//                 int tty = nexty + dy[j];
//                 if (in(ttx, tty) && !visited[ttx][tty])
//                 {
//                     Next[i]++; // 统计每个移动方向后续点位个数
//                 }
//             }
//         }
//     }
// }
// void printboard()
// {
//     for (int i = 0; i < ROW; i++)
//     {
//         for (int j = 0; j < COL; j++)
//         {
//             printf("%-4d ", board[i][j]);
//         }
//         cout << endl;
//     }
// }

// void dfs(int x, int y, int step)
// {
//     if (have && only)
//         return;
//     board[x][y] = step;

//     if (step >= ROW * COL)
//     {
//         printboard();
//         have = true;
//         cot++;
//         cout<< endl;
//         cout<<cot<<endl;
//         return;
//     }

//     visited[x][y] = true;

//     int Next[8] = {0};
//     getNext(x, y, Next);

//     int seq[8] = {0, 1, 2, 3, 4, 5, 6, 7};
//     sort(seq, seq + 8, [&](int i, int j) -> bool
//          { return Next[i] < Next[j]; });

//     for (int i = 0; i < 8; i++)
//     {
//         int nextx = x + dx[seq[i]];
//         int nexty = y + dy[seq[i]];
//         if (in(nextx, nexty) == false)
//             continue;
//         if (visited[nextx][nexty] == false)
//             dfs(nextx, nexty, step + 1);
//     }
//     visited[x][y] = false;
//     board[x][y] = 0;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     dfs(n, m, 1);
//     cout << cot;
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;
typedef pair<int, int> PII;

int d[N][N];
int g[N][N];
int n, m;
PII q[N * N], Pre[N][N];

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                Pre[x][y] = t;
                q[++tt] = {x, y};
            }
        }
    }
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << " " << y << endl;
        auto t = Pre[x][y];
        x = t.first, y = t.second;
    }
    return d[n - 1][m - 1];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs();
    return 0;
}