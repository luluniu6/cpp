#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-size-subarray-sum/description/ 209. 长度最小的子数组

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int sum = 0, len = INT_MAX;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (sum >= target)
            {
                len = min(len, r - l + 1);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
//https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/  3. 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128]={0};
        int ret=0;
        for(int l=0,r=0;r<s.length();r++)
        {
            hash[s[r]]++;
            while(hash[s[r]]>1)
            {
                hash[s[l]]--;
                l++;
            }
            ret=max(ret,r-l+1);
        }
        return ret;
    }
};