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