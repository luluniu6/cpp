#include <bits/stdc++.h>
using namespace std;

//https://leetcode.cn/problems/unique-paths/  62. 不同路径
//1.利用排列组合
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         long long lala = 1;
//         for (int x = n, y = 1; y < m; ++x, ++y) {
//             lala = lala * x / y;
//         }
//         return lala;
//     }
// };
//2.动态规划
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector < vector<int>> dp(m+1, vector<int>(n+1));
//         dp[0][1] = 1;
//         for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//             }
//         }

//         return dp[m][n];
//     }
// };
//https://leetcode.cn/problems/unique-paths-ii/description/  63. 不同路径 II
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         dp[1][0] = 1;
//         for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (obstacleGrid[i - 1][j - 1] == 1)
//                 {
//                     dp[i][j] = 0;
//                 }
//                 else
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m][n];

//     }
// };

//https://leetcode.cn/problems/integer-break/description/  343. 整数拆分
//1.dp动态规划
// class Solution {
// public:
//     int integerBreak(int n) {
//         vector<int> dp(n+1,0);
//         dp[0]=0,dp[1]=0,dp[2]=1;
//         for(int i=3;i<=n;i++)
//         {
//             for(int j=1;j<=i/2;j++)
//             {
//                 dp[i]=max(dp[i],max(j*dp[i-j],j*(i-j)));
//                 //cout<<"dp["<<i<<"] = "<<dp[i]<<" ";
//             }
//         }
//         return dp[n];
//     }
// };
// int main()
// {
//     Solution la;
//     cout<<la.integerBreak(10);
//     return 0;
// }
//2.math
//通过数学可证明:
//数字拆分为更多的 3，其次为 2，最差为 1，可让乘积最大化。
//但是，若最终拆出来，剩下一个 1，我们将其中一个 3+1，组成一个4，可让乘积更大化
//If an optimal product contains a factor f >= 4, 
//then you can replace it with factors 2 and f-2 without losing optimality, 
//as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4, 
//meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd only use it for n=2 and n=3, where it's needed).
//For the rest I agree, 33 is simply better than 22*2, so you'd never use 2 more than twice.
// class Solution {
// public:
//     int integerBreak(int n) {
//         if (n <= 3) {
//             return n - 1;
//         }
//         int quotient = n / 3;
//         int remainder = n % 3;
//         if (remainder == 0) {
//             return (int)pow(3, quotient);
//         } else if (remainder == 1) {
//             return (int)pow(3, quotient - 1) * 4;
//         } else {
//             return (int)pow(3, quotient) * 2;
//         }
//     }
// };
//3.贪心
// class Solution {
// public:
//     int integerBreak(int n) {
//         if (n == 2)
//             return 1;
//         if (n == 3)
//             return 2;
//         if (n == 4)
//             return 4;
//         int result = 1;
//         while (n > 4) {
//             result *= 3;
//             n -= 3;
//         }
//         result *= n;
//         return result;
//     }
// };

//https://leetcode.cn/problems/unique-binary-search-trees/description/ 96. 不同的二叉搜索树
//动态规划
// class Solution {
// public:
//     int numTrees(int n) {
//         vector<int>dp(n+1,0);
//         dp[0]=1;//空二叉树也算一个
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=i;j++)
//             {
//                 dp[i]+=dp[j-1]*dp[i-j];//j为根，j左子树的数量×j右子树的数量
//             }
//         }
//         return dp[n];
//     }
// };
