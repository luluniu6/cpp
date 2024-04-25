#include <bits/stdc++.h>
using namespace std;

//https://leetcode.cn/problems/lemonade-change/ 860. 柠檬水找零
// class Solution {
// public:
//     bool lemonadeChange(vector<int> &bills) {
//         int five = 0, ten = 0;
//         for (int b: bills) {
//             if (b == 5) five++; // 无需找零
//             else if (b == 10) five--, ten++; // 返还 5
//             else if (ten) five--, ten--; // 此时 b=20，返还 10+5
//             //这里的贪心就在于：面对20元找零时，优先用掉10元面额的
//             else five -= 3; // 此时 b=20，返还 5+5+5
//             if (five < 0) return false; // 无法正确找零
//         }
//         return true;
//     }
// };