/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> index;
        int ans = 1;
        for(int i = 0;i < n;i++)
        {
            if(index.count(arr[i] - difference))
            {
                if(index.count(arr[i]))
                    index[arr[i]] = max(index[arr[i] - difference] + 1,index[arr[i]]);
                else
                    index[arr[i]] = index[arr[i] - difference] + 1;
                ans = max(index[arr[i]],ans);
            }
            else 
                index[arr[i]] = 1;
                
            
        }
        return ans;
    }
};
// @lc code=end
// DP，用一个哈希表来保存“以该数字为终点的子序列的长度”
// 不断地遍历，查找是否有存在与当前数字相差difference的已经保存过的子序列
// 如果有则早此前基础上加1，否则令其等于一
// 在过程中维护结果ans

