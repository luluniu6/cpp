#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

//洛谷1443 马 https://www.luogu.com.cn/problem/P1443
// const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// const int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2}; // 8个方向
// queue<pair<int, int>> q;
// int f[500][500];    // 存步数
// bool vis[500][500]; // 走没走过
// int main()
// {
//     int n, m, x, y;
//     memset(f, -1, sizeof(f));
//     memset(vis, false, sizeof(vis));
//     cin >> n >> m >> x >> y;
//     f[x][y] = 0;
//     vis[x][y] = true;
//     q.push(make_pair(x, y));
//     while (!q.empty())
//     {
//         int xx = q.front().first, yy = q.front().second;
//         q.pop(); // 取队首并出队
//         for (int i = 0; i < 8; i++)
//         {
//             int u = xx + dx[i], v = yy + dy[i];
//             if (u < 1 || u > n || v < 1 || v > m || vis[u][v])
//                 continue; // 出界或走过就不走
//             vis[u][v] = true;
//             q.push(make_pair(u, v));
//             f[u][v] = f[xx][yy] + 1;
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//             printf("%-5d", f[i][j]);
//         printf("\n");
//     }
//     return 0;
// }

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

//leetcode 797. 所有可能的路径
//98. 所有可达路径 https://kamacoder.com/problempage.php?pid=1170
vector<vector<int>> ret;
vector<int> path;
void dfs(const vector<list<int>> &graph, int x, int N)
{
    if (x == N)
    {
        ret.push_back(path);
        return;
    }
    auto it = graph[x].begin();
    while (it != graph[x].end())
    {
        path.push_back(*it);
        dfs(graph, *it, N);
        path.pop_back();
        ++it;
    }
    // for(int i:graph[x])
    // {
    //     path.push_back(i);
    //     dfs(graph,i,N);
    //     path.pop_back();
    // }
}

int main()
{
    int N, M, s, t;
    cin >> N >> M;
    vector<list<int>> graph(N + 1);
    while (M--)
    {
        cin >> s >> t;
        graph[s].push_back(t);
    }
    path.push_back(1);
    dfs(graph, 1, N);
    if (ret.size() == 0) cout << -1 << endl;
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j];
            if (j != ret[i].size() - 1) cout << " ";
        }
        if (i != ret.size() - 1) cout << endl;
    }
    return 0;
}