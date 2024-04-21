// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem763.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include "vector"
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> index;
        vector<int> ans;

        int n = s.size();
        int begin = 0,end = 0;
        for(int i = 0; i < n; i++)
        {
            if(!index.count(s[i]))
                index[s[i]] = {i, i};
            else
                index[s[i]].second = i;
        }
        while(begin < n)
        {
            for(int i = begin;i <= end;i++)
            {
                end = max(end,index[s[i]].second);
            }
            ans.push_back(end - begin + 1);
            begin = end + 1;
            end++;
        }
        
        return ans;

        /* 其实上面的做法可以进一步优化，在便利的过程中发现，其实起始位置begin是没什么作用的 */


        // int last[26];
        // int length = s.size();
        // for (int i = 0; i < length; i++)
        // {
        //     last[s[i] - 'a'] = i; // 记录最终的位置
        // }
        // vector<int> partition;
        // int start = 0, end = 0;
        // for (int i = 0; i < length; i++)
        // {
        //     end = max(end, last[s[i] - 'a']);
        //     if (i == end) // 当遍历到结尾时
        //     {
        //         partition.push_back(end - start + 1);
        //         start = end + 1;// 更新下一段的起点
        //     }
        // }
        // return partition;

    }
};
// @lc code=end

