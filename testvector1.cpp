#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/pascals-triangle/description/ 118. 杨辉三角
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vv.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            vv[i].resize(i + 1);
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }
        for (int i = 0; i < vv.size(); i++)
        {
            for (int j = 0; j < vv[i].size(); j++)
            {
                if (vv[i][j] != 1)
                {
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
            }
        }
        return vv;
    }
};

static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    // 以pair对的第2个数的大小从大往小排序
    return a.second > b.second;
}

int main()
{
    vector<pair<int, int>> scores;
    scores.push_back(make_pair(1, 3));
    scores.push_back(make_pair(2, 1));
    scores.push_back(make_pair(3, 2));
    cout << "before sort : " << endl;
    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i].first << " " << scores[i].second << endl;
    }
    // sort(scores.begin(), scores.end(), cmp); // 向算法传递函数
    sort(scores.begin(), scores.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; }); // lambda表达式
    cout << "after sort : " << endl;
    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i].first << " " << scores[i].second << endl;
    }
    return 0;
}

// 3273. 对 Bob 造成的最少伤害（https://leetcode.cn/problems/minimum-amount-of-damage-dealt-to-bob/description/） 贪心算法邻项交换法