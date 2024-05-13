#include <bits/stdc++.h>
using namespace std;
// 正数原码反码补码都相同
// 负数反码为原码符号位不变其余取反，补码为反码+1或者利用从后往前遇到第一个1后取反符号位不变

// 1.给一个数n，确定它的二进制表示中的第x位是0还是1   (n>>x) & 1
// 2.将一个数n的二进制表示的第x位修改成1             n |= (1<<x)
// 3.将一个数n的二进制表示的第x位修改成0             n &= (~(1<<x))
// 以上三个操作经常为位图服务

// 提取一个数(n)二进制表示中最右侧的1(lowbit)               n & (-n)     -n操作本质是将最右侧1左边的区域全部变成相反
// 干掉一个数(n)二进制表示中最右侧的1 Brian Kernighan算法   n & (n-1)    n-1操作本周是将最右侧1右边的区域(包括1)全部变成相反

//     s = 101100
//    ~s = 010011
//(~s)+1 = 010100 // 根据补码的定义，这就是 -s   效果：s 的最低 1 左侧取反，右侧不变
// s & -s = 000100 // lowbit

// 异或(^)运算的运算律
// 1.a ^ 0 = a;
// 2.a ^ a = 0;
// 3.a ^ b ^ c = a ^ (b ^ c);

// https://leetcode.cn/problems/power-of-two/description/ 231. 2 的幂
// class Solution
// {
// public:
//     bool isPowerOfTwo(int n)
//     {
//         return n > 0 && (n & (n - 1)) == 0;
//     }
// };

// https://leetcode.cn/problems/number-of-1-bits/description/ 191. 位1的个数
//  class Solution {
//  public:
//      int hammingWeight(uint32_t n) {
//          int ret = 0;
//          while (n) {
//              n &= n - 1;
//              ret++;
//          }
//          return ret;
//      }
//  };

// https://leetcode.cn/problems/counting-bits/description/ 338. 比特位计数
//  class Solution {
//  public:
//      int countBit(int num)
//      {
//          int ret=0;
//          while(num)
//          {
//              num&=(num-1);
//              ret++;
//          }
//          return ret;
//      }
//      vector<int> countBits(int n) {
//          vector<int> ans(n+1,0);
//          for(int i=0;i<=n;i++)
//          {
//              ans[i]=countBit(i);
//          }
//          return ans;
//      }
//  };

// https://leetcode.cn/problems/hamming-distance/description/ 461. 汉明距离
//  class Solution {
//  public:
//      int hammingDistance(int x, int y) {
//          int s=x^y,ret=0;
//          while(s)
//          {
//              s&=(s-1);
//              ret++;
//          }
//          return ret;
//      }
//  };

//  https://leetcode.cn/problems/single-number/description/ 136. 只出现一次的数字
//   class Solution {
//   public:
//       int singleNumber(vector<int>& nums) {
//           int a=0;
//           for(int i=0;i<nums.size();i++)
//           {
//              a^=nums[i];
//           }
//           return a;

//     }
// };

// https://leetcode.cn/problems/single-number-iii/description/ 260. 只出现一次的数字 III
// class Solution {
// public:
//     vector<int> singleNumber(vector<int> &nums) {
//         unsigned int xor_all = 0;
//         for (int x: nums) {
//             xor_all ^= x;
//         }
//         int lowbit = xor_all & -xor_all;
//         vector<int> ans(2);
//         for (int x: nums) {
//             ans[(x & lowbit) != 0] ^= x; // 分组异或
//         }
//         return ans;
//     }
// };

// https://leetcode.cn/problems/single-number-ii/description/ 137. 只出现一次的数字 II
//1.哈希表
// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         unordered_map<int,int> freq;
//         for(int i=0;i<nums.size();i++)
//         {
//             freq[nums[i]]++;
//         }
//         int ans=0;
//         for (auto [num, occ]: freq) {
//             if (occ == 1) {
//                 ans = num;
//                 break;
//             }
//         }
//         return ans;
//     }
// };
//2.位运算
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ans=0;
//         for(int i=0;i<32;i++)
//         {
//             int total=0;
//             for(int j=0;j<nums.size();j++)
//             {
//                 total+=nums[j]>>i&1;
//             }
//             if(total%3!=0)
//             {
//                 ans|=1<<i;
//             }
//         }
//         return ans;
//     }
// };

//https://leetcode.cn/problems/power-of-four/description/  342. 4的幂
class Solution {
public:
    bool isPowerOfFour(int n) {

    }
};
//https://leetcode.cn/problems/power-of-three/description/  326. 3 的幂
class Solution {
public:
    bool isPowerOfThree(int n) {

    }
};